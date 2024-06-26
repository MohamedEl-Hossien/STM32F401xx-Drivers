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
	volatile u32 REVERSED2[2];			//REVERSED
	volatile u32 APB1ENR;		       	//MRCC_BASE_ADDRESS + 0x40
	volatile u32 APB2ENR;		       	//MRCC_BASE_ADDRESS + 0x44
	volatile u32 REVERSED3[2];			//REVERSED
	volatile u32 AHB1LPENR;	           	//MRCC_BASE_ADDRESS + 0x50
	volatile u32 AHB2LPENR;	           	//MRCC_BASE_ADDRESS + 0x54
	volatile u32 REVERSED4[2];			//REVERSED
	volatile u32 APB1LPENR;	           	//MRCC_BASE_ADDRESS + 0x60
	volatile u32 APB2LPENR;	           	//MRCC_BASE_ADDRESS + 0x64
	volatile u32 REVERSED5[2];			//REVERSED
	volatile u32 BDCR;		           	//MRCC_BASE_ADDRESS + 0x70
	volatile u32 CSR;			       	//MRCC_BASE_ADDRESS + 0x74
	volatile u32 REVERSED6[2];			//REVERSED
	volatile u32 SSCGR;		           	//MRCC_BASE_ADDRESS + 0x80
	volatile u32 PLLI2SCFGR;	       	//MRCC_BASE_ADDRESS + 0x84
	volatile u32 REVERSED7;				//REVERSED
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


/************************************** SYSTICK Registers **********************************/
/**********************************************
	---- > Macros
			• Base Address SYSTICK
***********************************************/
#define MSYSTICK_BASE_ASSRESS			0xE000E010U
/**********************************************
	---- > Structure
			• SysTick timer
***********************************************/
typedef struct{
	volatile u32 CTRL;          /* SysTick control and status register,     	Address offset: 0x0C */
	volatile u32 LOAD;         	/* SysTick reload value register,           	Address offset: 0x04 */
	volatile u32 VAL;        	/* SysTick current value register,          	Address offset: 0x0B */
	volatile u32 CALIB;        	/* SysTick calibration value register,    		Address offset: 0x0C */
}STK_RegDef_t;

/**********************************************
	---- > Struct Macros
			• Base Address SYSTICK
***********************************************/
#define MSTK				((STK_RegDef_t*)MSYSTICK_BASE_ASSRESS)

/************************************** NVIC Registers **********************************/
/**********************************************
	---- > Macros
			• Base Address NVIC
***********************************************/
#define MNVIC_BASE_ASSRESS			0xE000E100U
/**********************************************
	---- > Structure
			• Nested Vectored Interrupt Controller
***********************************************/
typedef struct{
	volatile u32 ISER[8];       		/* Interrupt set-enable register,     	Address offset: 0x100 */
	volatile u32 REVERSED1[24];			//REVERSED
	volatile u32 ICER[8];         		/* Interrupt clear-enable register,     Address offset: 0x180 */
	volatile u32 REVERSED2[24];			//REVERSED
	volatile u32 ISPR[8];        		/* Interrupt set-pending register,      Address offset: 0x200 */
	volatile u32 REVERSED3[24];			//REVERSED
	volatile u32 ICPR[8];        		/* Interrupt clear-pending register,   	Address offset: 0x280 */
	volatile u32 REVERSED4[24];			//REVERSED
	volatile u32 IABR[8];        		/* Interrupt active bit register,   	Address offset: 0x300 */
	volatile u32 REVERSED5[56];			//REVERSED
	volatile u32 IPR[60];        		/* Interrupt priority register,    		Address offset: 0x400 */
}NVIC_RegDef_t;

/**********************************************
	---- > Struct Macros
			• Base Address NVIC
***********************************************/
#define MNVIC				((NVIC_RegDef_t*)MNVIC_BASE_ASSRESS)
#define MSCB_AIRCR			(*(volatile u32*)(0xE000ED00))

/************************************** EXIT Registers **********************************/
/**********************************************
	---- > Macros
			• Base Address EXIT
***********************************************/
#define MEXIT_BASE_ASSRESS			0x40013C00U
/**********************************************
	---- > Structure
			• External Interrupt/Event Controller
***********************************************/
typedef struct{
	volatile u32 IMR;          	/* Interrupt mask register,     			Address offset: 0x00 */
	volatile u32 EMR;         	/* Event mask register,           			Address offset: 0x04 */
	volatile u32 RTSR;        	/* Rising trigger selection register,     	Address offset: 0x08 */
	volatile u32 FTSR;        	/* Falling trigger selection register,   	Address offset: 0x0C */
	volatile u32 SWIER;        	/* Software interrupt event register,    	Address offset: 0x10 */
	volatile u32 PR;        	/* Pending register,    					Address offset: 0x14 */
}EXIT_RegDef_t;

/**********************************************
	---- > Struct Macros
			• Base Address EXIT
***********************************************/
#define MEXIT					((EXIT_RegDef_t*)MEXIT_BASE_ASSRESS)
#define MSYSCFG_EXTICR1			(*(volatile u32*)(0x40013800U + 0x08))
#define MSYSCFG_EXTICR2			(*(volatile u32*)(0x40013800U + 0x0C))
#define MSYSCFG_EXTICR3			(*(volatile u32*)(0x40013800U + 0x10))
#define MSYSCFG_EXTICR4			(*(volatile u32*)(0x40013800U + 0x14))

#endif //STM32F401xx_H
