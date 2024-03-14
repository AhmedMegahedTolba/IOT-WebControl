/*
 * SYSTIC_Private.h
 *
 *  Created on: Jan 25, 2024
 *      Author: HIFINE
 */

#ifndef SYSTIC_PRIVATE_H_
#define SYSTIC_PRIVATE_H_

#define SYSTIC_BASEADD   (0xE000E010)

typedef struct
{
	volatile u32	CTRL;
	volatile u32	LOAD;
	volatile u32	VAL;
	volatile u32	CALIB;

}STK_Type;

#define	STK		((volatile STK_Type *)(SYSTIC_BASEADD))

#define STK_EN 			0
#define STK_INT 	    1
#define STK_CLKSRC 		2
#define STK_CFLAG		16


#define STK_AHB_NOSACALER   1
#define STK_AHB_SACALER8    0

#endif /* SYSTIC_PRIVATE_H_ */
