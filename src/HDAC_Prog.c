#include "StdTypes.h"
#include "Utils.h"
#include "GPIO_Interface.h"
#include "S2P_Interfcae.h"
#include "HDAC_Interface.h"
#include "HDAC_Cfg.h"


void HR2RDAC_Init(void)
{

}



void HR2RDAC_SetData1(const u8*Audio_Arr,u32 size)
{
	for(u32 i;i<size;i++)
	{
	    DIO_WritePin(DAC_PIN0,READ_BIT(Audio_Arr[i],0));
	    DIO_WritePin(DAC_PIN1,READ_BIT(Audio_Arr[i],1));
	    DIO_WritePin(DAC_PIN2,READ_BIT(Audio_Arr[i],2));
	    DIO_WritePin(DAC_PIN3,READ_BIT(Audio_Arr[i],3));
	    DIO_WritePin(DAC_PIN4,READ_BIT(Audio_Arr[i],4));
	    DIO_WritePin(DAC_PIN5,READ_BIT(Audio_Arr[i],5));
	    DIO_WritePin(DAC_PIN6,READ_BIT(Audio_Arr[i],6));
	    DIO_WritePin(DAC_PIN7,READ_BIT(Audio_Arr[i],7));

	    //Delay( 125 us)
	    MYSYSTICK_VoidDelayUs(125);
	}


}

void HR2RDAC_SetData2(const u8*Audio_Arr,u32 size)
{
	for(u32 i;i<size;i++)
	{

		S2P_SendU8data(Audio_Arr[i]);
	    //Delay( 125 us)
	    //MYSYSTICK_VoidDelayUs(10);
	}


}

