/**********************************************
		Name	: NVIC_interface.h
		Date	: 11/06/2024
		Author	: Mohamed Elhossien
		Version	: _V1_
***********************************************/

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

#define NVIC_PRIORITY_GROUP_0				0b0000
#define NVIC_PRIORITY_GROUP_1				0b0001
#define NVIC_PRIORITY_GROUP_2				0b0010
#define NVIC_PRIORITY_GROUP_3				0b0011
#define NVIC_PRIORITY_GROUP_4				0b0100
#define NVIC_PRIORITY_GROUP_5				0b0101
#define NVIC_PRIORITY_GROUP_6				0b0110
#define NVIC_PRIORITY_GROUP_7				0b0111
#define NVIC_PRIORITY_GROUP_8				0b1000
#define NVIC_PRIORITY_GROUP_9				0b1001
#define NVIC_PRIORITY_GROUP_10				0b1010
#define NVIC_PRIORITY_GROUP_11				0b1011
#define NVIC_PRIORITY_GROUP_12				0b1100
#define NVIC_PRIORITY_GROUP_13				0b1101
#define NVIC_PRIORITY_GROUP_14				0b1110
#define NVIC_PRIORITY_GROUP_15				0b1111

u8 MNVIC_u8EnableIRQ(u8 Copy_u8IRQn);

u8 MNVIC_u8DisableIRQ(u8 Copy_u8IRQn);

u8 MNVIC_u8SetPendingIRQ(u8 Copy_u8IRQn);

u8 MNVIC_u8ClearPendingIRQ(u8 Copy_u8IRQn);

u8 MNVIC_u8GetCurrentActiveIRQ(u32* Copy_pu32CurrentActive);

u8 MNVIC_u8SetIRQPriority(u8 Copy_u8IRQn, u8 Copy_u8GroupPriority);

#endif /* NVIC_INTERFACE_H_ */