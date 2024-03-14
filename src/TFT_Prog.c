#include "StdTypes.h"
#include "Utils.h"
#include "GPIO_Interface.h"
#include "SYSTIC_Inteface.h"
#include "SPI_Interface.h"
#include "TFT_Interface.h"
#include "TFT_Private.h"
#include "TFT_Cfg.h"


static void TFT_WriteData(u8 data)
{
	DIO_WritePin(TFT_A0,HIGH);
	SPI_Send_Receive(data);

}
static void TFT_WriteCommand(u8 cmd)
{
	 DIO_WritePin(TFT_A0,LOW);

	 SPI_Send_Receive(cmd);


}
static void TFT_RESET(void)
{
   DIO_WritePin(TFT_RESET_PIN,HIGH);
   MYSYSTICK_VoidDelayUs(100);
   DIO_WritePin(TFT_RESET_PIN,LOW);
   MYSYSTICK_VoidDelayUs(3);
   DIO_WritePin(TFT_RESET_PIN,HIGH);
   MYSYSTICK_VoidDelayUs(100);
   DIO_WritePin(TFT_RESET_PIN,LOW);
   MYSYSTICK_VoidDelayUs(100);
   DIO_WritePin(TFT_RESET_PIN,HIGH);
   MYSYSTICK_VoidDelayMs(120);


}
void TFT_Init(void)
{
	TFT_RESET();

	//Sleep OUT
	TFT_WriteCommand(TFT_CMD_SLEEP_OUT_MODE);


	 MYSYSTICK_VoidDelayMs(10);


	//COLOR_MODE
	TFT_WriteCommand(TFT_CMD_COLOR_MODE);

	TFT_WriteData(TFT_COLOR_STANDARD);

	//Display_Mode
	TFT_WriteCommand(TFT_CMD_DISPLAY_MODE);




}

void TFT_Display(const u16*Image)
{
	//SET X-Axis
	TFT_WriteCommand(TFT_CMD_SET_X_POSITION_MODE);

	//Start X0
	TFT_WriteData(0);//msb->high Byte
	TFT_WriteData(0);//LSb->LOW  byte

	//End Xn
	TFT_WriteData(0);//msb->high Byte
	TFT_WriteData(127);//LSb->LOW  byte


	//SET Y-Axis
	TFT_WriteCommand(TFT_CMD_SET_Y_POSITION_MODE);

	//Start Y0
	TFT_WriteData(0);//msb->high Byte
	TFT_WriteData(0);//LSb->LOW  byte

	//End Ynn
	TFT_WriteData(0);//msb->high Byte
	TFT_WriteData(159);//LSb->LOW  byte


	//Write on Ram
	TFT_WriteCommand(TFT_CMD_WRITEON_RAM_MODE);


	//Display Data
	for(u16 i=0;i<20480;i++)
	{
		u8 High_byte=(u8)(Image[i]>>8);
		u8 Low_bye=(u8)(Image[i]);

		TFT_WriteData(~High_byte);
		TFT_WriteData(~Low_bye);

	}



}

void TFT_Display_NoThing(void)
{
	//SET X-Axis
	TFT_WriteCommand(TFT_CMD_SET_X_POSITION_MODE);

	//Start X0
	TFT_WriteData(0);//msb->high Byte
	TFT_WriteData(0);//LSb->LOW  byte

	//End Xn
	TFT_WriteData(0);//msb->high Byte
	TFT_WriteData(127);//LSb->LOW  byte


	//SET Y-Axis
	TFT_WriteCommand(TFT_CMD_SET_Y_POSITION_MODE);

	//Start Y0
	TFT_WriteData(0);//msb->high Byte
	TFT_WriteData(0);//LSb->LOW  byte

	//End Ynn
	TFT_WriteData(0);//msb->high Byte
	TFT_WriteData(159);//LSb->LOW  byte


	//Write on Ram
	TFT_WriteCommand(TFT_CMD_WRITEON_RAM_MODE);


	//Display Data
	for(u16 i=0;i<20480;i++)
	{
		u8 High_byte=(u8)(0>>8);
		u8 Low_bye=(u8)(0);

		TFT_WriteData(~High_byte);
		TFT_WriteData(~Low_bye);

	}



}
