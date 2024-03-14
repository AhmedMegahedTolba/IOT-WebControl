
#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_



#define VECTKEY   (0x05FA)   //IN AIRCR In SCB
#define Reg_div 32

#define NVIVC_BASE_ADDRESS  (0xE000E100)
#define SCB_BASE_ADDRESS    (0xE000ED00)

typedef struct {

	volatile u32 ISER[8];
	volatile u32 arr_reserver0[24];
	volatile u32 ICER[8];
	volatile u32 arr_reserver1[24];
	volatile u32 ISPR[8];
	volatile u32 arr_reserver2[24];
	volatile u32 ICPR[8];
	volatile u32 arr_reserver3[24];
	volatile u32 IABR[8];
	volatile u32 arr_reserver4[56];
	volatile u8 IPR[240];
	volatile u32 arr_reserver5[580];
	volatile u32 STIR;
}NVIC_t;

#define NVIC         ((volatile NVIC_t*)NVIVC_BASE_ADDRESS)

#define SCB_AIRCR        (*(volatile u32*)(SCB_BASE_ADDRESS+0x0C))







#endif /* NVIC_PRIVATE_H_ */
