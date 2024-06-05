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

#define GPIO_NUMBERS		6
#define GPIO_LCKK_PIN		16
///**********************************************
//	---- > Macros
//			• Base Address GPIOx
//***********************************************/
//#define MGPIOA_BASE_ASSRESS			0x40020000
//#define MGPIOB_BASE_ASSRESS			0x40020400
//#define MGPIOC_BASE_ASSRESS			0x40020800
//#define MGPIOD_BASE_ASSRESS			0x40020C00
//#define MGPIOE_BASE_ASSRESS			0x40021000
//#define MGPIOH_BASE_ASSRESS			0x40021C00
///**********************************************
//	---- > Structure
//			• General Purpose I/O
//***********************************************/
//typedef struct{
//	volatile u32 MODER;          /* GPIO port mode register,                  Address offset: 0x0c     	*/
//	volatile u32 OTYPER;         /* GPIO port output type register,           Address offset: 0x04     	*/
//	volatile u32 OSPEEDR;        /* GPIO port output speed register,          Address offset: 0x0B     	*/
//	volatile u32 PUPDR;          /* GPIO port pull-up/ pull-down register,    Address offset: 0x0c     	*/
//	volatile u32 IDR;            /* GPIO port input data register,            Address offset: 0xl0     	*/
//	volatile u32 ODR;            /* GPIO port output data register,           Address offset: 0x14    	*/
//	volatile u32 BSRR;           /* GPIO port bit set/ reset register,        Address offset: 0x18   	*/
//	volatile u32 LCKR;           /* GPIO port configuration lock register,    Address offset: 0xIC     	*/
//	volatile u32 AFRL;           /* GPIO port alternate function registers,   Address offset: 0x20-ox24	*/
//	volatile u32 AFRH;
//}GPIOx_RegDef_t;
//
///**********************************************
//	---- > Macros
//			• Base Address GPIOA
//***********************************************/
//#define MGPIOA				((GPIOx_RegDef_t*)MGPIOA_BASE_ASSRESS)
///**********************************************
//	---- > Macros
//			• Base Address GPIOB
//***********************************************/
//#define MGPIOB				((GPIOx_RegDef_t*)MGPIOB_BASE_ASSRESS)
///**********************************************
//	---- > Macros
//			• Base Address GPIOC
//***********************************************/
//#define MGPIOC              ((GPIOx_RegDef_t*)MGPIOC_BASE_ASSRESS)
///**********************************************
//	---- > Macros
//			• Base Address GPIOD
//***********************************************/
//#define MGPIOD              ((GPIOx_RegDef_t*)MGPIOD_BASE_ASSRESS)
///**********************************************
//	---- > Macros
//			• Base Address GPIOE
//***********************************************/
//#define MGPIOE              ((GPIOx_RegDef_t*)MGPIOE_BASE_ASSRESS)
///**********************************************
//	---- > Macros
//			• Base Address GPIOH
//***********************************************/
//#define MGPIOH              ((GPIOx_RegDef_t*)MGPIOH_BASE_ASSRESS)
//
#endif /* GPIO_PRIVATE_H_ */
