
#include "StdTypes.h"
#include "Utils.h"
#include "NVIC_Private.h"
#include "NVIC_Interface.h"
#include "NVIC_Cfg.h"

static MNVIC_Group_t Group_SubGoroup=Group0Sub16;

void NVIC_EnableInterrupt(INT_Source_t INT_num)
{
	NVIC->ISER[INT_num/Reg_div]|=1<<(INT_num%Reg_div);
}
void NVIC_DisableInterrupt(INT_Source_t INT_num)
{
	NVIC->ICER[INT_num/Reg_div]|=1<<(INT_num%Reg_div);
}
void NVIC_EnableInterruptPendingFlag(INT_Source_t INT_num)
{
	NVIC->ISPR[INT_num/Reg_div]|=1<<(INT_num%Reg_div);
}
void NVIC_DisableInterruptPendingFlag(INT_Source_t INT_num)
{
	NVIC->ICPR[INT_num/Reg_div]|=1<<(INT_num%Reg_div);
}

u8 NVIC_ReadActiveFlag(INT_Source_t INT_num)
{
	u8 flag=0;
	flag=READ_BIT(NVIC->IABR[INT_num/Reg_div],(INT_num%Reg_div));
	return flag;

}
void NVIC_SetInterruptGroupMode(MNVIC_Group_t group_SubGroup)
{
	u32 Group_SubGroupModeReg=0;
	Group_SubGroupModeReg|=(VECTKEY<<16) | (group_SubGroup<<8);
	SCB_AIRCR=Group_SubGroupModeReg;
	Group_SubGoroup=group_SubGroup;
}

void NVIC_VoidSetInterruptPriority(u8 INT_Num,u8 Group,u8 sub)
{

    switch(Group_SubGoroup)
    {
    case Group16Sub0:
    	if(Group<16)
    	{
    	   NVIC->IPR[INT_Num]= (Group<<4) ;
    	}
    	break;
    case Group8Sub2:
    	if(Group<8&&sub<2)
    	{
    	   NVIC->IPR[INT_Num]= (Group<<5) |(sub<<4)  ;
    	}
    	break;
    case Group4Sub4:
    	if(Group<4&&sub<4)
    	{
    	  NVIC->IPR[INT_Num]= (Group<<6) |(sub<<4) ;
    	}
    	 break;
    case Group2Sub8:
    	if(Group<2&&sub<8)
    	{
    	   NVIC->IPR[INT_Num]= (Group<<7) |(sub<<4)  ;
    	}
    	break;
    case Group0Sub16:
    	if(sub<16)
    	{
    	   NVIC->IPR[INT_Num]= (sub<<4) ;
    	}
    	break;
    default: break;
    }

}


