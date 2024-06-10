/**********************************************
		Name	: RCC_Prog.h
		Date	: 13/5/2022
		Author	: Mohamed Elhossien
		Version	: _V1_
***********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STM32F401xx.h"
#include "RCC_private.h"
#include "RCC_config.h"
#include "RCC_interface.h"

void MRCC_vInitSysClk(void)
{
#if 	RCC_SYS_CLK == RCC_HSI

	MRCC_vEnableClk(RCC_HSI);
	CLR_BIT(MRCC->CFGR,RCC_SW0);
	CLR_BIT(MRCC->CFGR,RCC_SW1);
	while ((MRCC->CR & (1<<RCC_HSI_RDY)) == 0);

#elif 	RCC_SYS_CLK ==	RCC_HSE

		MRCC_vEnableClk(RCC_HSE);
		while ((MRCC->CR & (1<<RCC_HSE_RDY)) == 0);
		SET_BIT(MRCC->CFGR,RCC_SW0);
		CLR_BIT(MRCC->CFGR,RCC_SW1);

		#if RCC_HSE_SRC == RCC_HSE_CRYSTAL

			CLR_BIT(MRCC->CR,RCC_HSE_BYP);

		#elif RCC_HSE_SRC == RCC_HSE_RC

			SET_BIT(MRCC->CR,RCC_HSE_BYP);

		#else "Wrong Choice"

		#endif

#elif 	RCC_SYS_CLK ==  RCC_PLL

		#if RCC_PLL_SRC == RCC_HSI

			MRCC_vEnableClk(RCC_HSI);
			MRCC_vPLLConf(RCC_HSI);
			MRCC_vEnableClk(RCC_PLL);
			while ((MRCC->CR & (1<<RCC_PLL_RDY)) == 0);
			CLR_BIT(MRCC->CFGR,RCC_SW0);
			SET_BIT(MRCC->CFGR,RCC_SW1);


		#elif RCC_PLL_SRC == RCC_HSE

			MRCC_vEnableClk(RCC_HSE);
			MRCC_vPLLConf(RCC_HSE);
			MRCC_vEnableClk(RCC_PLL);
			while ((MRCC->CR & (1<<RCC_PLL_RDY)) == 0);
			CLR_BIT(MRCC->CFGR,RCC_SW0);
			SET_BIT(MRCC->CFGR,RCC_SW1);

			#if RCC_HSE_SRC == RCC_HSE_CRYSTAL

				CLR_BIT(MRCC->CR,RCC_HSE_BYP);

			#elif RCC_HSE_SRC == RCC_HSE_RC

				SET_BIT(MRCC->CR,RCC_HSE_BYP);

			#else
				#error "Wrong Choice"

			#endif


		#else
			#error "Wrong Choice"

		#endif

#else

		#error "Wrong Choice"

#endif

}

void MRCC_vEnableClk(u8 Copy_u8SysClk)
{
	switch(Copy_u8SysClk)
	{
	case RCC_HSI: 	 SET_BIT(MRCC->CR,RCC_HSI_ON); break;
	case RCC_HSE:	 SET_BIT(MRCC->CR,RCC_HSE_ON); break;
	case RCC_PLL: 	 SET_BIT(MRCC->CR,RCC_PLL_ON); break;
	case RCC_PLL_I2S:SET_BIT(MRCC->CR,RCC_PLLI2S_ON); break;
	default: /*Error*/;
	}
}

void MRCC_vDisableClk(u8 Copy_u8SysClk)
{
	switch(Copy_u8SysClk)
	{
	case RCC_HSI: 	 CLR_BIT(MRCC->CR,RCC_HSI_ON); break;
	case RCC_HSE: 	 CLR_BIT(MRCC->CR,RCC_HSE_ON); break;
	case RCC_PLL: 	 CLR_BIT(MRCC->CR,RCC_PLL_ON); break;
	case RCC_PLL_I2S:CLR_BIT(MRCC->CR,RCC_PLLI2S_ON); break;
	default: /*Wrong Choice */;
	}
}

void MRCC_vPLLConf(u8 Copy_u8PLLSrc)
{
	MRCC->PLLCFGR |= (RCC_PLLQ_FACTOR<<RCC_PLLQ) | (RCC_PLLN_FACTOR<<RCC_PLLN) | (RCC_PLLM_FACTOR<<RCC_PLLM);

	switch(Copy_u8PLLSrc)
	{
	case RCC_HSI:	CLR_BIT(MRCC->PLLCFGR,RCC_PLLSRC); break;
	case RCC_HSE:	SET_BIT(MRCC->PLLCFGR,RCC_PLLSRC); break;
	default: /*Wrong Choice */;
	}

	switch(RCC_PLLP_FACTOR)
	{
	case 2:
		CLR_BIT(MRCC->PLLCFGR,RCC_PLLP0);
		CLR_BIT(MRCC->PLLCFGR,RCC_PLLP1);
		break;
	case 4:
		SET_BIT(MRCC->PLLCFGR,RCC_PLLP0);
		CLR_BIT(MRCC->PLLCFGR,RCC_PLLP1);
		break;
	case 6:
		CLR_BIT(MRCC->PLLCFGR,RCC_PLLP0);
		SET_BIT(MRCC->PLLCFGR,RCC_PLLP1);
		break;
	case 8:
		SET_BIT(MRCC->PLLCFGR,RCC_PLLP0);
		SET_BIT(MRCC->PLLCFGR,RCC_PLLP1);
		break;
	default: /*Wrong Choice */;
	}
}

u8	MRCC_u8CheckClkFlag(u8 Copy_u8SysClk)
{
	u8 result=0;
	switch(Copy_u8SysClk)
	{
	case RCC_HSI: 	 result = GET_BIT(MRCC->CR,RCC_HSI_RDY); break;
	case RCC_HSE: 	 result = GET_BIT(MRCC->CR,RCC_HSE_RDY); break;
	case RCC_PLL: 	 result = GET_BIT(MRCC->CR,RCC_PLL_RDY); break;
	case RCC_PLL_I2S:result = GET_BIT(MRCC->CR,RCC_PLLI2S_RDY); break;
	default: /*Wrong Choice */;
	}
	return result;
}

void MRCC_vClkSecuritySysState(u8 Copy_u8State)
{
	switch(Copy_u8State)
	{
	case RCC_ENABLE:	SET_BIT(MRCC->CR,RCC_CSS_ON); break;
	case RCC_DISABLE:	CLR_BIT(MRCC->CR,RCC_CSS_ON); break;
	default: /*Wrong Choice */;
	}
}

void MRCC_vMC_OutputX(u8 Copyu8_MCOx,u8 Copy_u8Src,u8 Copy_u8Pre)
{
	switch(Copyu8_MCOx)
	{
	case RCC_MCOUT_1:
		MRCC->CFGR &= ~(7<<RCC_MCO1PRE);
		MRCC->CFGR |= (Copy_u8Pre<<RCC_MCO1PRE);
		switch(Copy_u8Src)
		{
		case RCC_HSI:
			CLR_BIT(MRCC->CFGR,RCC_MCO10);
			CLR_BIT(MRCC->CFGR,RCC_MCO11);
			break;
		case RCC_LSE:
			SET_BIT(MRCC->CFGR,RCC_MCO10);
			CLR_BIT(MRCC->CFGR,RCC_MCO11);
			break;
		case RCC_HSE:
			CLR_BIT(MRCC->CFGR,RCC_MCO10);
			SET_BIT(MRCC->CFGR,RCC_MCO11);
			break;
		case RCC_PLL:
			SET_BIT(MRCC->CFGR,RCC_MCO10);
			SET_BIT(MRCC->CFGR,RCC_MCO11);
			break;
		default: /*Wrong Choice */;
		}
		break;
	case RCC_MCOUT_2:
		MRCC->CFGR &= ~(7<<RCC_MCO2PRE);
		MRCC->CFGR |= (Copy_u8Pre<<RCC_MCO2PRE);
		switch(Copy_u8Src)
		{
		case RCC_SYSCLK:
			CLR_BIT(MRCC->CFGR,RCC_MCO20);
			CLR_BIT(MRCC->CFGR,RCC_MCO21);
			break;
		case RCC_PLL_I2S:
			SET_BIT(MRCC->CFGR,RCC_MCO20);
			CLR_BIT(MRCC->CFGR,RCC_MCO21);
			break;
		case RCC_HSE:
			CLR_BIT(MRCC->CFGR,RCC_MCO20);
			SET_BIT(MRCC->CFGR,RCC_MCO21);
			break;
		case RCC_PLL:
			SET_BIT(MRCC->CFGR,RCC_MCO20);
			SET_BIT(MRCC->CFGR,RCC_MCO21);
			break;
		default: /*Wrong Choice */;
		}
		break;
	default: /*Wrong Choice */;
	}
}


void MRCC_vBusPreScaler(u8 Copy_u8xBus,u8 Copy_u8BusPre)
{
	switch(Copy_u8xBus)
	{
	case RCC_AHB_BUS:
		MRCC->CFGR &= ~(15<<RCC_HPRE);
		MRCC->CFGR |= (Copy_u8BusPre<<RCC_HPRE);
		break;
	case RCC_APB1_BUS:
		MRCC->CFGR &= ~(7<<RCC_PPRE1);
		MRCC->CFGR |= (Copy_u8BusPre<<RCC_PPRE1);
		break;
	case RCC_APB2_BUS:
		MRCC->CFGR &= ~(7<<RCC_PPRE2);
		MRCC->CFGR |= (Copy_u8BusPre<<RCC_PPRE2);
		break;
	default: /*Wrong Choice */;
	}
}

void MRCC_vEnablePeripheralClk(u8 Copy_u8Peripheral)
{
	if(Copy_u8Peripheral>=0 && Copy_u8Peripheral<32)
	{
		SET_BIT(MRCC->AHB1ENR,Copy_u8Peripheral);
	}
	else if(Copy_u8Peripheral>=32 && Copy_u8Peripheral<64)
	{
		Copy_u8Peripheral -=32;
		SET_BIT(MRCC->AHB2ENR,Copy_u8Peripheral);
	}
	else if(Copy_u8Peripheral>=64 && Copy_u8Peripheral<96)
	{
		Copy_u8Peripheral -=64;
		SET_BIT(MRCC->APB1ENR,Copy_u8Peripheral);
	}
	else if(Copy_u8Peripheral>=96 && Copy_u8Peripheral<128)
	{
		Copy_u8Peripheral -=96;
		SET_BIT(MRCC->APB2ENR,Copy_u8Peripheral);
	}
	else
	{
		/*Wrong Choice*/
	}
}

void MRCC_vDisablePeripheralClk(u8 Copy_u8Peripheral)
{
	if(Copy_u8Peripheral>=0 && Copy_u8Peripheral<32)
	{
		CLR_BIT(MRCC->AHB1ENR,Copy_u8Peripheral);
	}
	else if(Copy_u8Peripheral>=32 && Copy_u8Peripheral<64)
	{
		Copy_u8Peripheral -=32;
		CLR_BIT(MRCC->AHB2ENR,Copy_u8Peripheral);
	}
	else if(Copy_u8Peripheral>=64 && Copy_u8Peripheral<96)
	{
		Copy_u8Peripheral -=64;
		CLR_BIT(MRCC->APB1ENR,Copy_u8Peripheral);
	}
	else if(Copy_u8Peripheral>=96 && Copy_u8Peripheral<128)
	{
		Copy_u8Peripheral -=96;
		CLR_BIT(MRCC->APB2ENR,Copy_u8Peripheral);
	}
	else
	{
		/*Wrong Choice*/
	}
}
