/**********************************************
		Name	: RCC_Config.h
		Date	: 13/5/2022
		Author	: Mohamed Elhossien
		Version	: _V1_
***********************************************/

#ifndef RCC_CONFIG_H
#define	RCC_CONFIG_H


/*	RCC_SYS_CLK OPTIONS:*
 *	1. RCC_HSI			*
 *	2. RCC_HSE			*
 *	3. RCC_PLL 			*/
#define RCC_SYS_CLK			RCC_PLL

/*	RCC_HSE OPTIONS:*
 *	1. RCC_HSE_CRYSTAL	*
 *	2. RCC_HSE_RC	 	*/
#define RCC_HSE_SRC			RCC_HSE_RC

/*	RCC_PLL OPTIONS:*
 *	1. RCC_HSI			*
 *	2. RCC_HSE			*/
#define RCC_PLL_SRC			RCC_HSE


#define RCC_PLLN_FACTOR		192		//192 ≤ PLLN ≤ 432
#define RCC_PLLM_FACTOR		2		//2 ≤ PLLM ≤ 63
#define RCC_PLLQ_FACTOR		2		//2 ≤ PLLQ ≤15
#define RCC_PLLP_FACTOR		2		//PLLP = 2, 4, 6, or 8

#endif	//RCC_CONFIG_H
