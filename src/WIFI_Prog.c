#include "StdTypes.h"
#include "Utils.h"
#include "GPIO_Interface.h"
#include "SYSTIC_Inteface.h"
#include "Strings_Service.h"
#include "UART_Interface.h"
#include "WIFI_Interface.h"


static u8 ESP_Data_Return=0;
void ESP_voidInit(void)
{
	u8 str[100]={0};
	u8 data;
	WIFI_Status flag=WIFI_NOK;
	//Disable Echo
	while(flag==WIFI_NOK)
	{
		UART_SendString("ATE0\r\n");
		UART_ReceiveString(str);


		//data=UART_ReceiveSynchronous();
		if( str[2]=='O'&&str[3]=='K')
		{
			flag=WIFI_OK;
			//DIO_WritePin(PINA0,HIGH);

		}

	}

	//Station Mode

	flag=WIFI_NOK;
	while(flag==WIFI_NOK)
	{
		UART_SendString("AT+CWMODE=1\r\n");
		UART_ReceiveString(str);
		if( str[2]=='O'&&str[3]=='K')
		{
			flag=WIFI_OK;
			//DIO_WritePin(PINA1,HIGH);

		}
	}



}
/*
void ESP_WifiConnect(u8 * Copy_Name , u8 * Copy_Password)
{
	u8 str[100]={0};
    WIFI_Status flag=WIFI_NOK;

    while(flag==WIFI_NOK)
    {

    	UART_SendString("AT+CWJAP=\"");
    	UART_SendString(Copy_Name);
    	UART_SendString("\",\"");
    	UART_SendString(Copy_Password);
    	UART_SendString("\"\r\n");

    	//UART_SendString("AT+CWJAP=\"a\",\"12345678\"\r\n");
    	str[0]=UART_ReceiveSynchronous();
    	UART_ReceiveString(str+1);

		if( str[2]=='O'&&str[3]=='K')
		{
			flag=WIFI_OK;
			DIO_WritePin(PINA2,HIGH);

		}


    }

}

void ESP_ServerConnect (u8 * Copy_IP , u8 Copy_Port)
{
	u8 str[100]={0};
	   WIFI_Status flag=WIFI_NOK;

	    while(flag==WIFI_NOK)
	    {

	    	UART_SendString("AT+CIPSTART=\"TCP\",\"");
	    	UART_SendString(Copy_IP);
	    	UART_SendString("\",");
	    	UART_SendString(Copy_Port);
	    	UART_SendString("\r\n");

	    	UART_SendString("AT+CIPSTART=\"TCP\",\"185.176.43.112\",80\r\n");

	    	str[0]=UART_ReceiveSynchronous();
	    	UART_ReceiveString(str+1);

			if( str[9]=='O'&&str[10]=='K')
			{
				flag=WIFI_OK;
				DIO_WritePin(PINA3,HIGH);

			}


	    }

}
*/

WIFI_Status ESP_WifiConnect(u8 * Copy_Name , u8 * Copy_Password)
{
	u8 str[100]={0};
    WIFI_Status flag=WIFI_NOK;


    	UART_SendString("AT+CWJAP=\"");
    	UART_SendString(Copy_Name);
    	UART_SendString("\",\"");
    	UART_SendString(Copy_Password);
    	UART_SendString("\"\r\n");

    	//UART_SendString("AT+CWJAP=\"a\",\"12345678\"\r\n");
    	str[0]=UART_ReceiveSynchronous();
    	UART_ReceiveString(str+1);

		if( str[2]=='O'&&str[3]=='K')
		{
			flag=WIFI_OK;
			//DIO_WritePin(PINA2,HIGH);

		}


    return flag;

}

WIFI_Status ESP_ServerConnect (u8 * Copy_IP , u8 *Copy_Port)
{
	u8 str[100]={0};
	 WIFI_Status flag=WIFI_NOK;



	    	UART_SendString("AT+CIPSTART=\"TCP\",\"");
	    	UART_SendString(Copy_IP);
	    	UART_SendString("\",");
	    	UART_SendString(Copy_Port);
	    	UART_SendString("\r\n");

	    	//UART_SendString("AT+CIPSTART=\"TCP\",\"185.176.43.112\",80\r\n");

	    	str[0]=UART_ReceiveSynchronous();
	    	UART_ReceiveString(str+1);

			if( str[11]=='O'&&str[12]=='K')
			{
				flag=WIFI_OK;
				//DIO_WritePin(PINA3,HIGH);

			}


	  return flag;

}

void ESP_Wifi_ServerConnect(u8 * Copy_Name , u8 * Copy_Password,u8 * Copy_IP )
{
	u8 str[100]={0};
	 WIFI_Status flag=WIFI_NOK;
	 while(flag==WIFI_NOK)
	 {
		 flag=ESP_WifiConnect(Copy_Name,Copy_Password);
		 //DIO_WritePin(PINA1,HIGH);
         if(flag==WIFI_OK)
         {
        	 flag=WIFI_NOK;
		    flag=ESP_ServerConnect(Copy_IP,"80");
		   // DIO_WritePin(PINA2,HIGH);
         }
	 }

}

void ESP_SendHttpRequest(u8 * Copy_URL , u8 * Length )
{

	u8 str[2000]={0};
	u8* str2[100];
	WIFI_Status flag=WIFI_NOK;



	    	UART_SendString("AT+CIPSEND=");
	    	UART_SendString(Length);
	    	UART_SendString("\r\n");

		//UART_SendString("AT+CIPSEND=43\r\n");
	    	str[0]=UART_ReceiveSynchronous();
	    	UART_ReceiveString(str+1);

			if( str[2]=='O'&&str[3]=='K')
			{
				flag=WIFI_OK;
				//DIO_WritePin(PINA4,HIGH);

			}

			flag=WIFI_NOK;
			UART_SendString("GET ");
			UART_SendString(Copy_URL);
			UART_SendString("\r\n");
	    	str[0]=UART_ReceiveSynchronous();
	    	UART_ReceiveString(str+1);


			if( str[7]=='O'&&str[8]=='K')
			{
				flag=WIFI_OK;
				//DIO_WritePin(PINA5,HIGH);

			}

			ESP_Data_Return=str[20];


}

u8 ESP_ReadData(void)
{



     return ESP_Data_Return;

}
