/*
 * NVIC_Interface.h
 *
 *  Created on: Jan 17, 2024
 *      Author: HIFINE
 */

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_




typedef enum {
	WWDG=0,
	PVD_EXI161,
	TAMPSTAMP_EXI21,
	EXTI22_RTC_WKUP,
	FLASH,
	RCC,
	EXTI0,
	EXTI1,
	EXTI2,
	EXTI3,
	EXTI4,
	DMA1_Stream0,
	DMA1_Stream1,
	DMA1_Stream2,
	DMA1_Stream3,
	DMA1_Stream4,
	DMA1_Stream5,
	DMA1_Stream6,
	ADC,
	EXI5_9=23,
	TIM1_BRK_TIM9,
	TIM1_UP_TIM10,
	TIM1_TRG_COM_TIM11,
	TIM1_CC,
	TIM2,
	TIM3,
	TIM4,
	I2C1_EV,
	I2C1_ER,
	I2C2_EV,
	I2C2_ER,
	SPI1,
	SPI2,
	USART1,
	USART2,
	EXTI15_10=40,
	EXTI17_RTC_Alarm,
	EXTI18_OTG_FS_WKUP,
	DMA1_Stream7=47,
	SDIO=49,
	TIM5,
	SPI3

}INT_Source_t;

typedef enum{
 Group16Sub0=3,
 Group8Sub2,
 Group4Sub4,
 Group2Sub8,
 Group0Sub16


}MNVIC_Group_t;


#endif /* NVIC_INTERFACE_H_ */
