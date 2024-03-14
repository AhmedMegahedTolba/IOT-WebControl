/*
 * RCC_Private.h
 *
 *  Created on: Jan 15, 2024
 *      Author: HIFINE
 */

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

typedef struct {
u32 CR;
u32 PLLCFGR;
u32 CFGR;
u32 CIR;
u32 AHB1RSTR;
u32 AHB2RSTR;
u32 reserved0;
u32 reserved1;
u32 APB1RSTR;
u32 APB2RSTR;
u32 reserved2;
u32 reserved3;
u32 AHB1ENR;
u32 AHB2ENR;
u32 reserved4;
u32 reserved5;
u32 APB1ENR;
u32 APB2ENR;
u32 reserved6;
u32 reserved7;
u32 AHB1LPENR;
u32 AHB2LPENR;
u32 reserved8;
u32 reserved9;
u32 APB1LPENR;
u32 APB2LPENR;
u32 reserved10;
u32 reserved11;
u32 BDCR;
u32 CSR;
u32 reserved12;
u32 reserved13;
u32 SSCGR;
u32 PLLI2SCFGR;
u32 reserved14;
u32 DCKCFGR;
}RCC_t;

#define RCC_BASE_ADD  (0x40023800)

#define RCC             ((volatile RCC_t*)(RCC_BASE_ADD))


#define RCC_HSI     0
#define RCC_HSE     1
#define RCC_PLL     2

#define RCC_TWOPIN  0
#define RCC_ONEPIN  1

/***    RCC_CR Register   ***************/
#define HSION                 0
#define HSIRDY                1
#define HSEON                 16
#define HSERDY                17
#define HSEBYP                18
#define CSSON                 19
#define PLLON                 24
#define PLLRDY                25


/***    RCC_CFGR Register   ***************/
#define MCO20                               30
#define MCO21                               31
#define MCO2PRE0                            27
#define MCO2PRE1                            28
#define MCO2PRE2                            29
#define MCO10                               21
#define MCO11                               22
#define MCO1PRE0                            24
#define MCO1PRE1                            25
#define MCO1PRE2                            26
#define SWS1                                3
#define SWS0                                2
#define SW1                                 1
#define SW0                                 0


#define SWITCH_MASK   (0xfffffffc)
#define SWITCH_HSI      0
#define SWITCH_HSE      1
#define SWITCH_PLL      2
#endif /* RCC_PRIVATE_H_ */
