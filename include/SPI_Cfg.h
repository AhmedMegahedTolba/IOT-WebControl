/*
 * SPI_Cfg.h
 *
 *  Created on: Feb 4, 2024
 *      Author: HIFINE
 */

#ifndef SPI_CFG_H_
#define SPI_CFG_H_


#define SPI_DATA_FORMAT                         SPI_DATA_8_BIT

                                                      /*
                                                       SPI_DATA_8_BIT
                                                       SPI_DATA_16_BIT

                                                      */

#define SPI_FRAME_FORMAT                           SPI_MSB
                                                            /*
                                                             SPI_MSB
                                                             SPI_LSB
                                                             */


#define SPI_CLK_POLARITY                            SPI_LEADING_FALLING_IDLE_1
                                                         /*
                                                          SPI_LEADING_RISING_IDLE_0
                                                          SPI_LEADING_FALLING_IDLE_1

                                                          */


#define SPI_CLK_PHASE                                      SPI_LEADING_SAMPLE
                                                                  /*

                                                                   SPI_LEADING_SAMPLE
                                                                   SPI_LADING_SETUP

                                                                   */
#define SPI_SCALER                           SPI_FPCLK_SCALER_2
                                                                  /*

																	 SPI_FPCLK_SCALER_2
																	 SPI_FPCLK_SCALER_4
																	 SPI_FPCLK_SCALER_8
																	 SPI_FPCLK_SCALER_16
																	 SPI_FPCLK_SCALER_32
																	 SPI_FPCLK_SCALER_64
																	 SPI_FPCLK_SCALER_128
																	 SPI_FPCLK_SCALER_256

                                                                 */
#endif /* SPI_CFG_H_ */
