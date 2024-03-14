
#include "StdTypes.h"
#include "Utils.h"
#include "RCC_Interface.h"
#include "RCC_Private.h"
#include "RCC_Cfg.h"


void RCC_Init(void)
{
#if SYSTEM_CLK == RCC_HSE

	//output clk 1 pin or 2pin( BYPASS Crystal Or RC )
   #if RCC_CLKSOURCE ==RCC_TWOPIN
	CLR_BIT(RCC->CR,HSEBYP);
   #else
	SET_BIT(RCC->CR,HSEBYP);
   #endif

  //Enable HSE and wait for ready flag
	SET_BIT(RCC->CR,HSEON);
	while(!READ_BIT(RCC->CR,HSERDY));

  //choose from mux any system clk
   RCC->CFGR&=SWITCH_MASK;
   RCC->CFGR|=SWITCH_HSE;

#elif SYSTEM_CLK == RCC_HSI

   //Enable HSI and wait for ready flag
 	SET_BIT(RCC->CR,HSION);
 	while(!READ_BIT(RCC->CR,HSIRDY));

   //choose from mux any system clk
    RCC->CFGR&=SWITCH_MASK;
    RCC->CFGR|=SWITCH_HSI;


#endif
}

void RCC_EnablePeripheral(Bus_t bus,u8 periehral)
{
	switch (bus)
	{
	case RCC_AHB1 :
		SET_BIT(RCC->AHB1ENR,periehral);

		break;
	case RCC_AHB2 :
		SET_BIT(RCC->AHB2ENR,periehral);

		break;
	case RCC_APB1 :
		SET_BIT(RCC->APB1ENR,periehral);

		break;
	case RCC_APB2 :
		SET_BIT(RCC->APB2ENR,periehral);


		break;

	case RCC_AHB1_LOW_POWER:
	SET_BIT(RCC->AHB1LPENR,periehral);

	break;

	default :

		break;

	}
}
void RCC_DisablePeripheral(Bus_t bus,u8 periehral)
{
	switch (bus)
	{
	case RCC_AHB1 :
		CLR_BIT(RCC->AHB1ENR,periehral);

		break;
	case RCC_AHB2 :
		CLR_BIT(RCC->AHB2ENR,periehral);

		break;
	case RCC_APB1 :
		CLR_BIT(RCC->APB1ENR,periehral);

		break;
	case RCC_APB2 :
		CLR_BIT(RCC->APB2ENR,periehral);
		break;

	case RCC_AHB1_LOW_POWER:
	    CLR_BIT(RCC->AHB1LPENR,periehral);

	break;
	default :

		break;

	}
}
