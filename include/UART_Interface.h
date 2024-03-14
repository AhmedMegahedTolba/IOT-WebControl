/*
 * UART_Interface.h
 *
 *  Created on: Jan 31, 2024
 *      Author: HIFINE
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_


typedef enum {
	UART_NOTIMEOUT=0,
	UART_TIMEOUT

}UART_TimeOutStatus;


typedef enum{
	UART_IN_PROGRESS,
	UART_FINISHED_SEND,
	UART_FINISHED_RECEIVED

}UART_Status_type;

void UART_ReciveString_Func(void);
#endif /* UART_INTERFACE_H_ */
