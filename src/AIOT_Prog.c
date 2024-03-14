
#include "StdTypes.h"
#include "Utils.h"
#include "RCC_Interface.h"
#include "GPIO_Interface.h"
#include "NVIC_Interface.h"
#include "SPI_Interface.h"
#include "HLED__MATRIX_Interface.h"
#include "TFT_Interface.h"
#include "HDAC_Interface.h"
#include "S2P_Interfcae.h"
#include "AIOT_Interface.h"
#include "song.h"



#include "IMAGE.h"
#include "HLED__MATRIX_Cfg.h"

u8 Led_MatrixArr1[8]={129, 129, 129, 129, 129, 153, 165, 227};
u8 Led_MatrixArr2[8]={127, 4, 4, 4, 4, 4, 4, 4};
u8 Led_MatrixArr3[8]={0, 0, 68, 170, 146, 130, 130, 0};
u8 Led_MatrixArr4[8]={124, 4, 4, 4, 124, 4, 4, 124};
u8 Led_MatrixArr5[8]={14, 18, 34, 66, 66, 34, 26, 6};
u8 LED_Matrix_Name[5][8]={

		{129, 129, 129, 129, 129, 153, 165, 227},
		{127, 4, 4, 4, 4, 4, 4, 4},
		{0, 0, 68, 170, 146, 130, 130, 0},
		{124, 4, 4, 4, 124, 4, 4, 124},
		{14, 18, 34, 66, 66, 34, 26, 6}



};

void IOT_Init(void)
{

	RCC_Init();
	RCC_EnablePeripheral(RCC_AHB1,AHB1_GPIOA);
	RCC_EnablePeripheral(RCC_AHB1,AHB1_GPIOB);
	RCC_EnablePeripheral(RCC_AHB1,AHB1_GPIOC);
	RCC_EnablePeripheral(RCC_APB2,APB2_SYSCFG);
	RCC_EnablePeripheral(RCC_APB2,APB2_SPI1);
	RCC_EnablePeripheral(RCC_APB2,APB2_USART1);
	DIO_Init();

	DIO_SetAlternateFunction(PINA4,GPIO_AF_SPI1_4);
	DIO_SetAlternateFunction(PINA5,GPIO_AF_SPI1_4);
	DIO_SetAlternateFunction(PINA6,GPIO_AF_SPI1_4);
	DIO_SetAlternateFunction(PINA7,GPIO_AF_SPI1_4);


	DIO_SetAlternateFunction(PINA9,GPIO_AF_UART1_2);
	DIO_SetAlternateFunction(PINA10,GPIO_AF_UART1_2);

    MSYSTICK_VoidInit();
	SPI_Master_Init();

	UART_Init();
	NVIC_EnableInterrupt(USART1);

	TFT_Init();

	ESP_voidInit();

}

void IOT_Runnable(void)
{
	static IOT_Status_t data=NOTHING_SENT;

    ESP_Wifi_ServerConnect("a","12345678","185.176.43.112");
	//ESP_Wifi_ServerConnect("WE_AEADCC","jb704100","185.176.43.112");
	ESP_SendHttpRequest("http://tolbino.atwebpages.com/write.txt","45");
	data=ESP_ReadData();

	if(data==IMAGE)
	{
		TFT_Display(Image);
		LedMatrix_Off();

	}
	else if(data==VIDEO)
	{
		TFT_Display_NoThing();
		for(u8 i=0;i<10;i++)
		{
		   LED_MATRIX_Animation(LED_Matrix_Name,2,8);
		   MYSYSTICK_VoidDelayUs(1);
		}

	}
	else if(data==AUDIO)
	{
		 LedMatrix_Off();
		 TFT_Display_NoThing();
		 HR2RDAC_SetData2(song_raw,103627);

	}


}

