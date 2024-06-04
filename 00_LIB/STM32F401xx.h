/**********************************************
		Name	: STM32F401xx.h
		Date	: 03/06/2024
		Author	: Mohamed Elhossien
		Version	: _V1_
***********************************************/

#ifndef STM32F401xx_H
#define STM32F401xx_H

#define MRCC_BASE_ADDRESS			0x40023800

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

#define MRCC					((RCC_RegDef_t*)MRCC_BASE_ADDRESS)

#define MGPIOA_BASE_ADDRESS			0x40020000
#define MGPIOB_BASE_ADDRESS			0x40020400
#define MGPIOC_BASE_ADDRESS			0x40020800
#define MGPIOD_BASE_ADDRESS			0x40020C00
#define MGPIOE_BASE_ADDRESS			0x40021000
#define MGPIOH_BASE_ADDRESS			0x40021C00

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

}GPIOx_RegDef_t;

#define MGPIOA				((GPIOx_RegDef_t*)MGPIOA_BASE_ADDRESS)
#define MGPIOB				((GPIOx_RegDef_t*)MGPIOB_BASE_ADDRESS)
#define MGPIOC              ((GPIOx_RegDef_t*)MGPIOC_BASE_ADDRESS)
#define MGPIOD              ((GPIOx_RegDef_t*)MGPIOD_BASE_ADDRESS)
#define MGPIOE              ((GPIOx_RegDef_t*)MGPIOE_BASE_ADDRESS)
#define MGPIOH              ((GPIOx_RegDef_t*)MGPIOH_BASE_ADDRESS)








#endif //STM32F401xx_H
