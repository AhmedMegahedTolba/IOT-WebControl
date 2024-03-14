
#include "StdTypes.h"
#include "Utils.h"
#include "GPIO_Interface.h"
#include "GPIO_Private.h"




void DIO_SetPinDirection(DIO_Pin_t pin,DIO_PinStatus_t status)
{

	if(pin==13 || pin==14 || pin==15 || pin==18 || pin==19 || pin==20)

	{
		return;
	}



	DIO_Port_t port=pin/16;
	u8 pin_num=pin%16;

	switch(port)
	{
	  case PA :
		 GPIOA->MODER&=~(TWO_BIT_MASK<<(2*pin_num));
		 GPIOA->MODER|=(((u32)status<<30>>30)<<(2*pin_num));


		 GPIOA->PUPDR&=~(TWO_BIT_MASK<<2*pin_num);
		 GPIOA->PUPDR|=(((u32)status>>2<<30>>30)<<(2*pin_num));

		 GPIOA->OTYPER &=~ (1 << (pin_num));
		 GPIOA->OTYPER |=(((u32)status>>6)<< (pin_num));

		 GPIOA->OSPEEDR&=~(TWO_BIT_MASK<<2*pin_num);
		 GPIOA->OSPEEDR|=(((u32)status>>4<<30>>30)<<(2*pin_num));
		 break;

	  case PB :
		 GPIOB->MODER&=~(TWO_BIT_MASK<<(2*pin_num));
		 GPIOB->MODER|=(((u32)status<<30>>30)<<(2*pin_num));


		 GPIOB->PUPDR&=~(TWO_BIT_MASK<<2*pin_num);
		 GPIOB->PUPDR|=(((u32)status>>2<<30>>30)<<(2*pin_num));

		 GPIOB->OTYPER &=~ (1 << (pin_num));
		 GPIOB->OTYPER |=(((u32)status>>6)<< (pin_num));

		 GPIOB->OSPEEDR&=~(TWO_BIT_MASK<<2*pin_num);
		 GPIOB->OSPEEDR|=(((u32)status>>4<<30>>30)<<(2*pin_num));
		 break;


	  case PC :
		 GPIOC->MODER&=~(TWO_BIT_MASK<<(2*pin_num));
		 GPIOC->MODER|=(((u32)status<<30>>30)<<(2*pin_num));


		 GPIOC->PUPDR&=~(TWO_BIT_MASK<<2*pin_num);
		 GPIOC->PUPDR|=(((u32)status>>2<<30>>30)<<(2*pin_num));

		 GPIOC->OTYPER &=~ (1 << (pin_num));
		 GPIOC->OTYPER |=(((u32)status>>6)<< (pin_num));

		 GPIOC->OSPEEDR&=~(TWO_BIT_MASK<<2*pin_num);
		 GPIOC->OSPEEDR|=(((u32)status>>4<<30>>30)<<(2*pin_num));
		 break;


	}




}
void DIO_Init(void)
{
	DIO_Pin_t i;
	for(i=PINA0;i<TOTAL_PINS;i++)
	{
		if(i<=PINB15)
		{
		  DIO_SetPinDirection(i,DIO_ArrStatus[i]);
		}
		else
		{
			DIO_SetPinDirection(i+13,DIO_ArrStatus[i]);
		}


	}
}


void DIO_WritePin(DIO_Pin_t pin,DIO_PinVolt_t volt)
{

	if(pin==13 || pin==14 || pin==15 || pin==18 || pin==19 || pin==20)
		{
			return;
		}

		DIO_Port_t port=pin/16;
		u8 pin_num=pin%16;

		switch(volt)
		{
		  case HIGH:
			  switch(port)
			  	{
			  	  case PA :
			  	   SET_BIT(GPIOA->ODR,pin_num);
			  		break;
			  	  case PB :
			  	   SET_BIT(GPIOB->ODR,pin_num);
			  		break;
			  	  case PC :
			  	   SET_BIT(GPIOC->ODR,pin_num);
			  		break;
			  	  default:
					break;

			  	}
			  break;
			  case LOW:
			  switch(port)
				{
				  case PA :
				   CLR_BIT(GPIOA->ODR,pin_num);
					break;
				  case PB :
				   CLR_BIT(GPIOB->ODR,pin_num);
					break;
				  case PC :
				   CLR_BIT(GPIOC->ODR,pin_num);
					break;
				  default:
					break;

				}
			  break;
		}



}

DIO_PinVolt_t DIO_ReadPin(DIO_Pin_t pin)
{
	DIO_PinVolt_t volt;

	DIO_Port_t port=pin/16;
	u8 pin_num=pin%16;

	if(pin==13 || pin==14 || pin==15 || pin==18 || pin==19 || pin==20)
	{
		  return 0;
	}


	switch(port)
	{
	    case PA : volt=READ_BIT(GPIOA->IDR,pin_num);break;

	    case PB : volt=READ_BIT(GPIOB->IDR,pin_num);break;

	    case PC : volt=READ_BIT(GPIOC->IDR,pin_num);break;
	}


   return volt;
}

void DIO_TogglePin(DIO_Pin_t pin)
{
	DIO_Port_t port=pin/16;
	u8 pin_num=pin%16;

	if(pin==13 || pin==14 || pin==15 || pin==18 || pin==19 || pin==20)
	{
		  return ;
	}


	switch(port)
	{
	    case PA : TOG_BIT(GPIOA->ODR,pin_num);break;

	    case PB : TOG_BIT(GPIOB->ODR,pin_num);break;

	    case PC : TOG_BIT(GPIOC->ODR,pin_num);break;
	}

}
DIO_SetAlternateFunction(DIO_Pin_t pin,DIO_AF_Choose_Peripheral_t Peripheral_type)
{
	DIO_Port_t port=pin/16;
	u8 pin_num=pin%16;

	if(pin_num<=7)
	{
		switch(port)
		{
		case PA :
			GPIOA->AFRL&=~(FOUR_BIT_MASK<<(4*pin_num));
			GPIOA->AFRL|=(Peripheral_type<<(4*pin_num));
			break;

		case PB :
			GPIOB->AFRL&=~(FOUR_BIT_MASK<<(4*pin_num));
			GPIOB->AFRL|=(Peripheral_type<<(4*pin_num));
			break;

		case PC :
			GPIOC->AFRL&=~(FOUR_BIT_MASK<<(4*pin_num));
			GPIOC->AFRL|=(Peripheral_type<<(4*pin_num));
			break;



		}

	}
	else
	{
		switch(port)
				{
				case PA :
					GPIOA->AFRH&=~(FOUR_BIT_MASK<<(4*(pin_num%8)));
					GPIOA->AFRH|=(Peripheral_type<<(4*(pin_num%8)));
					break;

				case PB :
					GPIOB->AFRH&=~(FOUR_BIT_MASK<<(4*(pin_num%8)));
					GPIOB->AFRH|=(Peripheral_type<<(4*(pin_num%8)));
					break;

				case PC :
					GPIOC->AFRH&=~(FOUR_BIT_MASK<<(4*(pin_num%8)));
					GPIOC->AFRH|=(Peripheral_type<<(4*(pin_num%8)));
					break;



				}

	}

}
