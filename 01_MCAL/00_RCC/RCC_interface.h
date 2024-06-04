/**********************************************
		Name	: RCC_Interface.h
		Date	: 13/5/2022
		Author	: Mohamed Elhossien
		Version	: _V1_
***********************************************/

#ifndef RCC_INTERFACE_H
#define	RCC_INTERFACE_H

#define RCC_HSI					0
#define RCC_HSE					1
#define RCC_PLL					2
#define RCC_PLL_I2S				3
#define RCC_SYSCLK				4
#define RCC_LSE					5
#define RCC_LSI					6

#define RCC_HSE_CRYSTAL			0
#define RCC_HSE_RC	 			1

#define RCC_MCOUT_1				0
#define RCC_MCOUT_2				1

#define RCC_MCO_PRE_1			0
#define RCC_MCO_PRE_2			4
#define RCC_MCO_PRE_3			5
#define RCC_MCO_PRE_4			6
#define RCC_MCO_PRE_5			7

#define RCC_AHB_BUS				0
#define RCC_APB1_BUS			1
#define RCC_APB2_BUS			2
#define RCC_AHB1_BUS			3
#define RCC_AHB2_BUS			4

#define RCC_DISABLE				0
#define RCC_ENABLE				1

#define RCC_AHB_BUS_PRE_1		0
#define RCC_AHB_BUS_PRE_2		8
#define RCC_AHB_BUS_PRE_4		9
#define RCC_AHB_BUS_PRE_8		10
#define RCC_AHB_BUS_PRE_16		11
#define RCC_AHB_BUS_PRE_64		12
#define RCC_AHB_BUS_PRE_128		13
#define RCC_AHB_BUS_PRE_256		14
#define RCC_AHB_BUS_PRE_512		15

#define RCC_APB_BUS_PRE_1		0
#define RCC_APB_BUS_PRE_2		4
#define RCC_APB_BUS_PRE_4		5
#define RCC_APB_BUS_PRE_8		6
#define RCC_APB_BUS_PRE_16		7

#define RCC_GPIOA				0
#define RCC_GPIOB              	1
#define RCC_GPIOC              	2
#define RCC_GPIOD              	3
#define RCC_GPIOE              	4
#define RCC_GPIOH              	7
#define RCC_CRC                 12
#define RCC_DMA1				21
#define RCC_DMA2				22

#define RCC_OTGFS				39

#define RCC_TIM2				64
#define RCC_TIM3                65
#define RCC_TIM4                66
#define RCC_TIM5                67
#define RCC_WWDG				75
#define RCC_SPI2				78
#define RCC_SPI3				79
#define RCC_USART2				81
#define RCC_I2C1				85
#define RCC_I2C2				86
#define RCC_I2C3				87
#define RCC_PWR					92

#define RCC_TIM1				96
#define RCC_USART1           	100
#define RCC_USART6           	101
#define RCC_ADC1          		104
#define RCC_SDIO	           	107
#define RCC_SPI1           		108
#define RCC_SPI4            	109
#define RCC_SYSCFG				110
#define RCC_TIM9                112
#define RCC_TIM10               113
#define RCC_TIM8				114


void MRCC_vInitSysClk(void);

void MRCC_vEnableClk(u8 Copy_u8SysClk);

void MRCC_vDisableClk(u8 Copy_u8SysClk);

void MRCC_vPLLConf(u8 Copy_u8PLLSrc);

u8	MRCC_u8CheckClkFlag(u8 Copy_u8SysClk);

void MRCC_vClkSecuritySysState(u8 Copy_u8State);

void MRCC_vMC_OutputX(u8 Copyu8_MCOx,u8 Copy_u8Src,u8 Copy_u8Pre);

void MRCC_vBusPreScaler(u8 Copy_u8xBus,u8 Copy_u8BusPre);

void MRCC_vEnablePeripheralClk(u8 Copy_u8Peripheral);

void MRCC_vDisablePeripheralClk(u8 Copy_u8Peripheral);

#endif	//RCC_INTERFACE_H
