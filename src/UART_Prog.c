#include "StdTypes.h"
#include "Utils.h"
#include "UART_Interface.h"
#include "UART_Cfg.h"
#include "UART_Private.h"
#include "GPIO_Interface.h"



void(*UART_TX_Fptr)(void)=NULL_PTR;
void(*UART_RX_Fptr)(void)=NULL_PTR;

void UART_Init(void)
{   //Choose over Sampling
#if UART_OVERSAMPLING==UART_OVERSAMPLING_16
	UART1->CR1&=~(1<<OVER8);

	//Choose Clk  (16 MHZ Sampling ->16)
#if UART_BAUDRATE==UART_BAUDRATE_9600

	UART1->BRR=3;    //DIV/Factor-> div_factor* OVERSAMPLING ->.1875 *16
	UART1->BRR|=(104<<4);  //DIV_Mantissa

	//UART1->BRR=0xD03;
#elif UART_BAUDRATE==UART_BAUDRATE_115200

	UART1->BRR=11;    //DIV/Factor-> div_factor* OVERSAMPLING ->.6875 *16
	UART1->BRR|=(8<<4);  //DIV_Mantissa


#elif  UART_BAUDRATE==UART_BAUDRATE_19200


#endif


#elif   UART_OVERSAMPLING==UART_OVERSAMPLING_8
	UART1->CR1|=(1<<OVER8);
#endif


#if UART_WORDLENGTH == UART_DATA8_NOPARITY
	UART1->CR1&=~(1<<M);//Data length(8)
	UART1->CR1&=~(1<<PCE);//NO PArity
#elif 	UART_WORDLENGTH==UART_DATA8_PARITY_EVEN
	UART1->CR1&=~(1<<M);//Data length(8)
	UART1->CR1|=(1<<PCE);  //Parity Enable
	UART1->CR1&=~(1<<PS);   //Parity Even

#elif 	UART_WORDLENGTH==UART_DATA8_PARITY_ODD
	UART1->CR1&=~(1<<M);//Data length(8)
	UART1->CR1|=(1<<PCE);  //Parity Enable
	UART1->CR1|=(1<<PS);   //Parity Odd
#elif UART_WORDLENGTH == UART_DATA8_NOPARITY
	UART1->CR1|=(1<<M);//Data length(9)
	UART1->CR1&=~(1<<PCE);//NO PArity
#endif

//Choose Stop_Bit Length
	UART1->CR2&=~(TWO_BIT_MASK<<12);
	UART1->CR2|=(UART_STOPBIT_LENGTH<<12);


	//TX Enable
	UART1->CR1|=(1<<TE);
	//RX Enable
	UART1->CR1|=(1<<RE);
	//UART ENABLE
	UART1->CR1|=(1<<UE);


}

void UART_SendSynchronous(u16 data)
{
	while(!READ_BIT(UART1->SR,TXE));
	UART1->DR=data;
}

u16 UART_ReceiveSynchronous(void)
{
	while(READ_BIT(UART1->SR,RXNE)==0);

	return (UART1->DR);
}
UART_TimeOutStatus UART_ReceiveSynchronous_TimeOut(u16*data)
{
	UART_TimeOutStatus flag=UART_NOTIMEOUT;
	u32 Time_Out_count=0;

	while((READ_BIT(UART1->SR,RXNE)==0)&&flag==UART_NOTIMEOUT)
	{
		Time_Out_count++;
		if(Time_Out_count>1000000)
		{
			flag=UART_TIMEOUT;
		}
	}
	if(flag==UART_NOTIMEOUT)
	{
		*data=(UART1->DR);
	}
	else
	{
		*data=0;

	}

	return flag;
}

void UART_SendASynchronous(u16 data)
{

	UART1->DR=data;
}

u16 UART_ReceiveASynchronous(void)
{

	return (UART1->DR);
}


void UART_TX_InterruptEnable(void)
{
	UART1->CR1|=(1<<TCIE);
}
void UART_RX_InterruptEnable(void)
{
	UART1->CR1|=(1<<RXNEIE);
}
void UART_TX_InterruptDisable(void)
{
	UART1->CR1&=~(1<<TCIE);
}
void UART_RX_InterruptDisable(void)
{
	UART1->CR1&=~(1<<RXNEIE);
}

void UART_TX_CallBackFunction(void(*local_fptr)(void))
{
  UART_TX_Fptr=local_fptr;
}

void UART_RX_CallBackFunction(void(*local_fptr)(void))
{
  UART_RX_Fptr=local_fptr;
}

/* UART Service  */
void UART_SendString(u8*str)
{
	for(u8 i=0;str[i];i++)
	{
		UART_SendSynchronous(str[i]);

	}
}

//special for wifi
void UART_ReceiveString(u8*str)
{
	u8 i=0;

	UART_ReceiveSynchronous_TimeOut(str);
	while(str[i])
	{
		i++;
		UART_ReceiveSynchronous_TimeOut(str+i);

	}
}


static u8 flag_st;
static u8 flag_finished=0;
volatile u8 data_write[100][50]={0},data_read[100][50]={0},flag_rec;
void UART_ReceiveString_Init(void)
{

	UART_RX_CallBackFunction(UART_ReciveString_Func);
	UART_RX_InterruptEnable();


}

void UART_ReciveString_Func(void)
{
	static u8 i,j;
	if(flag_st==0)
	{
		data_write[j][0]=UART_ReceiveASynchronous();
		flag_st=1;
	}

	else if(data_write[j][i]!='\n')
	{
		i++;
		data_write[j][i]=UART_ReceiveASynchronous();
		if(data_write[j][i]=='\n')
		{
			data_write[j][i+1]=0;

			for(i=0;data_write[j][i];i++)
			{
				data_read[j][i]=data_write[j][i];
			}
			data_read[j][i]=0;
// 			LCD_WriteStringGoTo(0,0,data_read[0]);
// 			_delay_ms(3000);
			flag_rec++;
			flag_st=0;
			j++;
			i=0;

		}

		if(data_read[j][i]=='D'&&data_read[j][i-1]=='E')
		{
			flag_finished=1;
		}



	}




}

UART_Status_type UART_GetRecivedStrings(u8**str)
{
	u8 i=0;

	while(i<flag_rec)
	{
		str[i]=data_read[i];
		i++;

	}

	if (flag_finished==0)
	{
		return UART_IN_PROGRESS;
	}
	else
	{
		return UART_FINISHED_RECEIVED;

	}


}



void USART1_IRQHandler(void)
{
	if(READ_BIT(UART1->SR,TC)==1)
	{
		if(UART_TX_Fptr!=NULL_PTR)
		{
			UART_TX_Fptr();
		}

	   //Clear TC(TX_interrupt_flag)
	    UART1->SR&=~(1<<TC);
	}

	if(READ_BIT(UART1->SR,RXNE)==1)
		{
			if(UART_RX_Fptr!=NULL_PTR)
			{
				UART_RX_Fptr();
			}

		   //Clear TC(TX_interrupt_flag)
		    UART1->SR&=~(1<<RXNE);
		}
}



void USART6_IRQHandler(void)
{


}
