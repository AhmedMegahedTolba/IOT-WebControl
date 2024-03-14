#include "StdTypes.h"
#include "Utils.h"
#include "GPIO_Interface.h"
#include "SYSTIC_Inteface.h"
#include "S2P_Interfcae.h"
#include "S2P_Cfg.h"


void S2P_Shift_Clk_Delay(void)
{
	DIO_WritePin(S2P_SHIFT_CLK,HIGH);
	MYSYSTICK_VoidDelayUs(1);
	DIO_WritePin(S2P_SHIFT_CLK,LOW);
	MYSYSTICK_VoidDelayUs(1);

}

void S2P_Latch_Clk_Delay(void)
{
	DIO_WritePin(S2P_LATCH_CLK,HIGH);
	MYSYSTICK_VoidDelayUs(1);
	DIO_WritePin(S2P_LATCH_CLK,LOW);
	MYSYSTICK_VoidDelayUs(1);

}
void S2P_Reset(void)
{
	DIO_WritePin(S2P_RESET,HIGH);
	MYSYSTICK_VoidDelayUs(50);
	DIO_WritePin(S2P_RESET,LOW);
	MYSYSTICK_VoidDelayUs(50);
	DIO_WritePin(S2P_RESET,HIGH);
	MYSYSTICK_VoidDelayUs(50);

}
void S2P_SendU16data(u16 data)
{
	//S2P_Reset();
	for(s8 i=15;i>=0;i--)
	{
		DIO_WritePin(S2P_SERIAL_DATA_INPUT,READ_BIT(data,i));
		S2P_Shift_Clk_Delay();

	}
	S2P_Latch_Clk_Delay();
}

void S2P_SendU8data(u8 data)
{
	//S2P_Reset();
	for(s8 i=7;i>=0;i--)
	{
		DIO_WritePin(S2P_SERIAL_DATA_INPUT,READ_BIT(data,i));
		S2P_Shift_Clk_Delay();

	}
	S2P_Latch_Clk_Delay();
}


