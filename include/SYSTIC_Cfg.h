/*
 * SYSTIC_Cfg.h
 *
 *  Created on: Jan 25, 2024
 *      Author: HIFINE
 */

#ifndef SYSTIC_CFG_H_
#define SYSTIC_CFG_H_

#define STK_CLKSOURCE        STK_AHB_SACALER8
											/*
											 STK_AHB_NOSACALER
											 STK_AHB_SACALER8

											 */
//HSI
#define STK_CLK                  (2)
                                                   /*
                                                    AHB->    16  (MHZ)
                                                    AHB/8->  2   (MHZ)
                                                    */


#endif /* SYSTIC_CFG_H_ */
