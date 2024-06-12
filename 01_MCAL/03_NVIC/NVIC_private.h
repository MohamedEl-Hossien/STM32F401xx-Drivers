/**********************************************
		Name	: NVIC_Pivate.h
		Date	: 11/06/2024
		Author	: Mohamed Elhossien
		Version	: _V1_
***********************************************/

#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_

/*************** MACROS OF VECTKEY ***************/
#define VECTKEY				0x05FA

/*************** MACROS OF NVIC GROUP PRIORITY ***************/
#define NVIC_16_GROUP_NO_SUB              	0b011
#define NVIC_8_GROUP_2_SUB                	0b100
#define NVIC_4_GROUP_4_SUB                	0b101
#define NVIC_2_GROUP_8_SUB                	0b110
#define NVIC_NO_GROUP_16_SUB              	0b111

#endif /* NVIC_PRIVATE_H_ */
