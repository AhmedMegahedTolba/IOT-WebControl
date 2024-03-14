
#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

typedef struct {
	volatile u32 MODER;
	volatile u32 OTYPER;
	volatile u32 OSPEEDR;
	volatile u32 PUPDR;
	volatile u32 IDR;
	volatile u32 ODR;
	volatile u32 BSRR;
	volatile u32 LCKR;
	volatile u32 AFRL;
	volatile u32 AFRH;
}GPIO_t;

#define     GPIOA_BASE_ADDRESS          0x40020000
#define     GPIOB_BASE_ADDRESS          0x40020400
#define     GPIOC_BASE_ADDRESS          0x40020800

#define     GPIOA                       ((volatile GPIO_t *)GPIOA_BASE_ADDRESS)
#define     GPIOB                       ((volatile GPIO_t *)GPIOB_BASE_ADDRESS)
#define     GPIOC                       ((volatile GPIO_t *)GPIOC_BASE_ADDRESS)

#define TWO_BIT_MASK      (3)
#define FOUR_BIT_MASK     (15)

extern DIO_PinStatus_t DIO_ArrStatus[TOTAL_PINS];


#endif /* GPIO_PRIVATE_H_ */
