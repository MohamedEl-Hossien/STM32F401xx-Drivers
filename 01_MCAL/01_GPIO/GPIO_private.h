/**********************************************
		Name	: GPIO_private.h
		Date	: 03/06/2024
		Author	: Mohamed Elhossien
		Version	: _V1_
***********************************************/
/**********************************************
 * Developer can't Edit in It
 * register_definition
 * Design:
		- #define	:	NO
		- Union		:	NO
		- Structure	:	NO
***********************************************/
/**********************************************
******* guard of file call on time in .c ******
***********************************************/
#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_
/**********************************************
	---- > Macros
			• Base Address GPIOx
***********************************************/
/*
#define MGPIOA_BASE_ASSRESS			0x40020000
#define MGPIOB_BASE_ASSRESS			0x40020400
#define MGPIOC_BASE_ASSRESS			0x40020800
#define MGPIOD_BASE_ASSRESS			0x40020C00
#define MGPIOE_BASE_ASSRESS			0x40021000
#define MGPIOH_BASE_ASSRESS			0x40021C00

typedef struct{
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

}GPIOx_RegDef_t;

#define MGPIOA				((GPIOx_RegDef_t*)MGPIOA_BASE_ASSRESS)
#define MGPIOB				((GPIOx_RegDef_t*)MGPIOB_BASE_ASSRESS)
#define MGPIOC              ((GPIOx_RegDef_t*)MGPIOC_BASE_ASSRESS)
#define MGPIOD              ((GPIOx_RegDef_t*)MGPIOD_BASE_ASSRESS)
#define MGPIOE              ((GPIOx_RegDef_t*)MGPIOE_BASE_ASSRESS)
#define MGPIOH              ((GPIOx_RegDef_t*)MGPIOH_BASE_ASSRESS)
*/
#endif /* GPIO_PRIVATE_H_ */
