/**********************************************
		Name	: RCC_private.h
		Date	: 13/5/2022
		Author	: Mohamed Elhossien
		Version	: _V1_
***********************************************/

#ifndef RCC_PRIVATE_H
#define	RCC_PRIVATE_H

/*
#define MRCC_BASE_ADDRESS		0x40023800
#define RCC_CR				(*((volatile u32*) (MRCC_BASE_ADDRESS + 0x00)))
#define RCC_PLLCFGR			(*((volatile u32*) (MRCC_BASE_ADDRESS + 0x04)))
#define RCC_CFGR			(*((volatile u32*) (MRCC_BASE_ADDRESS + 0x08)))
#define RCC_CIR				(*((volatile u32*) (MRCC_BASE_ADDRESS + 0x0C)))
#define RCC_AHB1RSTR		(*((volatile u32*) (MRCC_BASE_ADDRESS + 0x10)))
#define RCC_AHB2RSTR		(*((volatile u32*) (MRCC_BASE_ADDRESS + 0x14)))
#define RCC_APB1RSTR		(*((volatile u32*) (MRCC_BASE_ADDRESS + 0x20)))
#define RCC_APB2RSTR		(*((volatile u32*) (MRCC_BASE_ADDRESS + 0x24)))
#define RCC_AHB1ENR			(*((volatile u32*) (MRCC_BASE_ADDRESS + 0x30)))
#define RCC_AHB2ENR			(*((volatile u32*) (MRCC_BASE_ADDRESS + 0x34)))
#define RCC_APB1ENR			(*((volatile u32*) (MRCC_BASE_ADDRESS + 0x40)))
#define RCC_APB2ENR			(*((volatile u32*) (MRCC_BASE_ADDRESS + 0x44)))
#define RCC_AHB1LPENR		(*((volatile u32*) (MRCC_BASE_ADDRESS + 0x50)))
#define RCC_AHB2LPENR		(*((volatile u32*) (MRCC_BASE_ADDRESS + 0x54)))
#define RCC_APB1LPENR		(*((volatile u32*) (MRCC_BASE_ADDRESS + 0x60)))
#define RCC_APB2LPENR		(*((volatile u32*) (MRCC_BASE_ADDRESS + 0x64)))
#define RCC_BDCR			(*((volatile u32*) (MRCC_BASE_ADDRESS + 0x70)))
#define RCC_CSR				(*((volatile u32*) (MRCC_BASE_ADDRESS + 0x74)))
#define RCC_SSCGR			(*((volatile u32*) (MRCC_BASE_ADDRESS + 0x80)))
#define RCC_PLLI2SCFGR		(*((volatile u32*) (MRCC_BASE_ADDRESS + 0x84)))
#define RCC_DCKCFGR			(*((volatile u32*) (MRCC_BASE_ADDRESS + 0x8C)))
*/
#define RCC_HSI_ON				0
#define RCC_HSE_ON				16
#define RCC_PLL_ON				24
#define RCC_PLLI2S_ON			26

#define RCC_HSI_RDY				1
#define RCC_HSE_RDY				17
#define RCC_PLL_RDY				25
#define RCC_PLLI2S_RDY			27

#define RCC_HSE_BYP				18
#define RCC_CSS_ON				19
#define RCC_HSICAL				8
#define RCC_HSUTRIM				3

#define RCC_PLLM				0
#define RCC_PLLN				6
#define RCC_PLLP0				16
#define RCC_PLLP1				16
#define RCC_PLLSRC				22
#define RCC_PLLQ				24

#define RCC_MCO10				21
#define RCC_MCO11				22
#define RCC_MCO1PRE				24
#define RCC_MCO2PRE				27
#define RCC_MCO20				30
#define RCC_MCO21				31


#define RCC_HPRE				4
#define RCC_PPRE1				10
#define RCC_PPRE2				13

#endif	//RCC_PRIVATE_H
