/*
 * SYSTIC_Inteface.h
 *
 *  Created on: Jan 25, 2024
 *      Author: HIFINE
 */

#ifndef SYSTIC_INTEFACE_H_
#define SYSTIC_INTEFACE_H_

typedef enum {
	SYSTIC_DISABLE,
	SYSTIC_ENABLE
}SYSTIC_Status_t;

typedef enum {

	STK_SINGLE_INT,
	STK_PERIODIC_INT

}SYSTIC_INTStatus_t;

void MSYSTICK_VoidInit(void);
void MSYSTICK_voidStart(u32 copy_u32LoadValue);
void MYSYSTICK_VoidReadFlag(void);

void MYSYSTICK_VoidDelayMs(u32 copy_u32DelayValue);

#endif /* SYSTIC_INTEFACE_H_ */
