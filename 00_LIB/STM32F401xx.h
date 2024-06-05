/**********************************************
		Name	: STM32F401xx.h
		Date	: 03/06/2024
		Author	: Mohamed Elhossien
		Version	: _V1_
***********************************************/

#ifndef STM32F401xx_H
#define STM32F401xx_H


/************************************** RCC Registers ***********************************/
/**********************************************
	---- > Macros
			• Base Address RCC
***********************************************/
#define MRCC_BASE_ADDRESS			0x40023800U
/**********************************************
	---- > Structure
			• Reset and Clock Control
***********************************************/
typedef struct {
	volatile u32 CR;			       	//MRCC_BASE_ADDRESS + 0x00
	volatile u32 PLLCFGR;		       	//MRCC_BASE_ADDRESS + 0x04
	volatile u32 CFGR;		           	//MRCC_BASE_ADDRESS + 0x08
	volatile u32 CIR;			       	//MRCC_BASE_ADDRESS + 0x0C
	volatile u32 AHB1RSTR;	           	//MRCC_BASE_ADDRESS + 0x10
	volatile u32 AHB2RSTR;	           	//MRCC_BASE_ADDRESS + 0x14
	volatile u32 REVERSED0[2];			//REVERSED
	volatile u32 APB1RSTR;	           	//MRCC_BASE_ADDRESS + 0x20
	volatile u32 APB2RSTR;	           	//MRCC_BASE_ADDRESS + 0x24
	volatile u32 REVERSED1[2];			//REVERSED
	volatile u32 AHB1ENR;		       	//MRCC_BASE_ADDRESS + 0x30
	volatile u32 AHB2ENR;		       	//MRCC_BASE_ADDRESS + 0x34
	volatile u32 APB1ENR;		       	//MRCC_BASE_ADDRESS + 0x40
	volatile u32 APB2ENR;		       	//MRCC_BASE_ADDRESS + 0x44
	volatile u32 REVERSED2[2];			//REVERSED
	volatile u32 AHB1LPENR;	           	//MRCC_BASE_ADDRESS + 0x50
	volatile u32 AHB2LPENR;	           	//MRCC_BASE_ADDRESS + 0x54
	volatile u32 REVERSED3[2];			//REVERSED
	volatile u32 APB1LPENR;	           	//MRCC_BASE_ADDRESS + 0x60
	volatile u32 APB2LPENR;	           	//MRCC_BASE_ADDRESS + 0x64
	volatile u32 REVERSED4[2];			//REVERSED
	volatile u32 BDCR;		           	//MRCC_BASE_ADDRESS + 0x70
	volatile u32 CSR;			       	//MRCC_BASE_ADDRESS + 0x74
	volatile u32 REVERSED5[2];			//REVERSED
	volatile u32 SSCGR;		           	//MRCC_BASE_ADDRESS + 0x80
	volatile u32 PLLI2SCFGR;	       	//MRCC_BASE_ADDRESS + 0x84
	volatile u32 REVERSED6;				//REVERSED
	volatile u32 DCKCFGR;		       	//MRCC_BASE_ADDRESS + 0x8C
}RCC_RegDef_t;
/**********************************************
	---- > Struct Macros
			• Base Address RCC
***********************************************/
#define MRCC					((RCC_RegDef_t*)MRCC_BASE_ADDRESS)


/************************************** GPIO Registers **********************************/
/**********************************************
	---- > Macros
			• Base Address GPIOx
***********************************************/
#define MGPIOA_BASE_ASSRESS			0x40020000U
#define MGPIOB_BASE_ASSRESS			0x40020400U
#define MGPIOC_BASE_ASSRESS			0x40020800U
#define MGPIOD_BASE_ASSRESS			0x40020C00U
#define MGPIOE_BASE_ASSRESS			0x40021000U
#define MGPIOH_BASE_ASSRESS			0x40021C00U
/**********************************************
	---- > Structure
			• General Purpose I/O
***********************************************/
typedef struct{
	volatile u32 MODER;          /* GPIO port mode register,                  Address offset: 0x0c     	*/
	volatile u32 OTYPER;         /* GPIO port output type register,           Address offset: 0x04     	*/
	volatile u32 OSPEEDR;        /* GPIO port output speed register,          Address offset: 0x0B     	*/
	volatile u32 PUPDR;          /* GPIO port pull-up/ pull-down register,    Address offset: 0x0c     	*/
	volatile u32 IDR;            /* GPIO port input data register,            Address offset: 0xl0     	*/
	volatile u32 ODR;            /* GPIO port output data register,           Address offset: 0x14    	*/
	volatile u32 BSRR;           /* GPIO port bit set/ reset register,        Address offset: 0x18   	*/
	volatile u32 LCKR;           /* GPIO port configuration lock register,    Address offset: 0xIC     	*/
	volatile u32 AFRL;           /* GPIO port alternate function registers,   Address offset: 0x20-ox24	*/
	volatile u32 AFRH;
}GPIOx_RegDef_t;

/**********************************************
	---- > Struct Macros
			• Base Address GPIOA
***********************************************/
#define MGPIOA				((GPIOx_RegDef_t*)MGPIOA_BASE_ASSRESS)
/**********************************************
	---- > Struct Macros
			• Base Address GPIOB
***********************************************/
#define MGPIOB				((GPIOx_RegDef_t*)MGPIOB_BASE_ASSRESS)
/**********************************************
	---- > Struct Macros
			• Base Address GPIOC
***********************************************/
#define MGPIOC              ((GPIOx_RegDef_t*)MGPIOC_BASE_ASSRESS)
/**********************************************
	---- > Struct Macros
			• Base Address GPIOD
***********************************************/
#define MGPIOD              ((GPIOx_RegDef_t*)MGPIOD_BASE_ASSRESS)
/**********************************************
	---- > Struct Macros
			• Base Address GPIOE
***********************************************/
#define MGPIOE              ((GPIOx_RegDef_t*)MGPIOE_BASE_ASSRESS)
/**********************************************
	---- > Struct Macros
			• Base Address GPIOH
***********************************************/
#define MGPIOH              ((GPIOx_RegDef_t*)MGPIOH_BASE_ASSRESS)

#endif //STM32F401xx_H
