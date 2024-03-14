/*
 * SPI_Private.h
 *
 *  Created on: Feb 4, 2024
 *      Author: HIFINE
 */

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#define SPI1_BASEADD                   (0x40013000)

typedef struct {

	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 CRCPR;
	volatile u32 RXCRCR;
	volatile u32 TXCRCR;
	volatile u32 I2SCFGR;
	volatile u32 I2SPR;


}SPI_t;

#define SPI1               ((volatile SPI_t* )(SPI1_BASEADD))

#define SPI_DATA_8_BIT        0
#define SPI_DATA_16_BIT       1

#define SPI_MSB               0
#define SPI_LSB               1


#define SPI_LEADING_RISING_IDLE_0           0
#define SPI_LEADING_FALLING_IDLE_1          1

#define SPI_LEADING_SAMPLE                   0
#define SPI_LADING_SETUP                     1

#define  SPI_FPCLK_SCALER_2                                   0
#define  SPI_FPCLK_SCALER_4                                   1
#define  SPI_FPCLK_SCALER_8                                   2
#define  SPI_FPCLK_SCALER_16                                  3
#define  SPI_FPCLK_SCALER_32                                  4
#define  SPI_FPCLK_SCALER_64                                  5
#define  SPI_FPCLK_SCALER_128                                 6
#define  SPI_FPCLK_SCALER_256                                 7

#define THREE_BIT_MASK                         (7)
//CR1
#define DF                     11
#define MSTR                   2
#define LSBFIRST               7
#define CPOL                   1
#define CPHA                   0
#define SPE                    6

//SR
#define RXNE                   0
#define TXE                    1


#endif /* SPI_PRIVATE_H_ */
