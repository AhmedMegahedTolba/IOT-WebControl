#include "StdTypes.h"
#include "Utils.h"
#include "SYSTIC_Inteface.h"
#include "SYSTIC_Private.h"
#include "SYSTIC_Cfg.h"

void (*STK_Fptr)(void)=0;
SYSTIC_INTStatus_t SYSTIC_Flag_INTStatus=STK_SINGLE_INT;

void MSYSTICK_VoidInit(void)
{
	//Choose AHBNOScaler  or AHB/8
#if STK_CLKSOURCE==STK_AHB_NOSACALER
	SET_BIT(STK_CTRL,STK_CLKSRC);
#elif 	STK_CLKSOURCE==STK_AHB_SACALER8
	CLR_BIT(STK->CTRL,STK_CLKSRC);
#endif

}

//put load Value in load_REG - CLR VAL_REG -Enable TIMER(star Count down )
void MSYSTICK_voidStart(u32 copy_u32LoadValue)
{
	STK->LOAD=copy_u32LoadValue;
	STK->VAL=0;
	STK->CTRL|=(1<<STK_EN);
}
void MSYSTICK_voidDisableSystick(void)
{
	STK->LOAD=0;
	STK->VAL=0;
	STK->CTRL&=~(1<<STK_EN);
}


u8 MYSYSTICK_U8ReadFlag(void)
{

	return READ_BIT(STK->CTRL,STK_CFLAG);

}

void MSYSTICK_voidEnableINT(void)
{
	STK->CTRL|=(1<<STK_INT);
}

void MSYSTICK_voidDisableINT(void)
{
	STK->CTRL&=~(1<<STK_INT);
}
void MYSYSTICK_VoidDelayUs(u32 copy_u32DelayValue)
{
	u32 Load_REG=copy_u32DelayValue*STK_CLK;      //STK_CLK->MHZ    -  Delay -> Us
	MSYSTICK_voidDisableINT();
	MSYSTICK_voidStart(copy_u32DelayValue*2);
	while(MYSYSTICK_U8ReadFlag()==0);

}

void MYSYSTICK_VoidDelayMs(u32 copy_u32DelayValue)
{
	u32 Load_REG=copy_u32DelayValue*STK_CLK*1000;      //STK_CLK->MHZ    -  Delay -> Ms
	MSYSTICK_voidDisableINT();
	MSYSTICK_voidStart(Load_REG);
	while(MYSYSTICK_U8ReadFlag()==0);

}


u32 MSYSTICK_U32GetElapsedTime_US(void)
{
	return ((STK->LOAD-STK->VAL)/STK_CLK);
}

u32 MSYSTICK_U32GetRemainingTime_US(void)
{
	return (STK->VAL)/STK_CLK;
}

u32 MSYSTICK_U32GetElapsedTime_MS(void)
{
	return ((STK->LOAD-STK->VAL)/STK_CLK/1000);
}

u32 MSYSTICK_U32GetRemainingTime_MS(void)
{
	return ((STK->VAL)/STK_CLK/1000);
}


void MSYSTICK_SetInterval_Single_MS(u32 Copy_U32DelayTime,void(*localptr)(void))//ms
{
	u32 Load_REG=(u32)Copy_U32DelayTime*STK_CLK*1000;
	STK_Fptr=localptr;
	SYSTIC_Flag_INTStatus=STK_SINGLE_INT;
	MSYSTICK_voidEnableINT();
	MSYSTICK_voidStart(Load_REG);


}

void MSYSTICK_SetInterval_Periodic_MS(u32 Copy_U32DelayTime,void(*localptr)(void))//ms
{
	u32 Load_REG=(u32)Copy_U32DelayTime*STK_CLK*1000;
	STK_Fptr=localptr;
	SYSTIC_Flag_INTStatus=STK_PERIODIC_INT;
	MSYSTICK_voidEnableINT();
	MSYSTICK_voidStart(Load_REG);


}


void SysTick_Handler(void)
{
	if(SYSTIC_Flag_INTStatus==STK_SINGLE_INT)
	{
		if(STK_Fptr!=NULL_PTR)
		{
			STK_Fptr();
			MSYSTICK_voidDisableINT();
			MSYSTICK_voidDisableSystick();

		}
	}
	else if(SYSTIC_Flag_INTStatus==STK_PERIODIC_INT)
	{
		if(STK_Fptr!=NULL_PTR)
		{
			STK_Fptr();

		}

	}







	MYSYSTICK_U8ReadFlag();

}
