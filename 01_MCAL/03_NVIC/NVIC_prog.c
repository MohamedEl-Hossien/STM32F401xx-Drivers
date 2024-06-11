/**********************************************
		Name	: NVIC_Prog.h
		Date	: 11/06/2024
		Author	: Mohamed Elhossien
		Version	: _V1_
***********************************************/

/******************************************** INCLUDES ********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STM32F401xx.h"
#include "NVIC_private.h"
#include "NVIC_config.h"
#include "NVIC_interface.h"


u8 MNVIC_u8EnableIRQ(u8 Copy_u8IRQn)
{
	u8 L_u8ErrorState = STD_NOT_OK;
	if(Copy_u8IRQn<239)
	{
		L_u8ErrorState = STD_OK;
		u8 L_u8RegNum = Copy_u8IRQn/32;
		Copy_u8IRQn -= (L_u8RegNum*32);
		SET_BIT(MNVIC->ISER[L_u8RegNum],Copy_u8IRQn);
	}
	else
	{
		/* Wrong Choice*/
	}
	return L_u8ErrorState;
}

u8 MNVIC_u8DisableIRQ(u8 Copy_u8IRQn)
{
	u8 L_u8ErrorState = STD_NOT_OK;
	if(Copy_u8IRQn<239)
	{
		L_u8ErrorState = STD_OK;
		u8 L_u8RegNum = Copy_u8IRQn/32;
		Copy_u8IRQn -= (L_u8RegNum*32);
		SET_BIT(MNVIC->ICER[L_u8RegNum],Copy_u8IRQn);
	}
	else
	{
		/* Wrong Choice*/
	}
	return L_u8ErrorState;
}

u8 MNVIC_u8SetPendingIRQ(u8 Copy_u8IRQn)
{
	u8 L_u8ErrorState = STD_NOT_OK;
	if(Copy_u8IRQn<239)
	{
		L_u8ErrorState = STD_OK;
		u8 L_u8RegNum = Copy_u8IRQn/32;
		Copy_u8IRQn -= (L_u8RegNum*32);
		SET_BIT(MNVIC->ISPR[L_u8RegNum],Copy_u8IRQn);
	}
	else
	{
		/* Wrong Choice*/
	}
	return L_u8ErrorState;
}

u8 MNVIC_u8ClearPendingIRQ(u8 Copy_u8IRQn)
{
	u8 L_u8ErrorState = STD_NOT_OK;
	if(Copy_u8IRQn<239)
	{
		L_u8ErrorState = STD_OK;
		u8 L_u8RegNum = Copy_u8IRQn/32;
		Copy_u8IRQn -= (L_u8RegNum*32);
		SET_BIT(MNVIC->ICPR[L_u8RegNum],Copy_u8IRQn);
	}
	else
	{
		/* Wrong Choice*/
	}
	return L_u8ErrorState;
}

u8 MNVIC_u8GetCurrentActiveIRQ(u32* Copy_pu32CurrentActive)
{
	u8 L_u8ErrorState = STD_NOT_OK;
	for(u8 L_u8Counter=0;L_u8Counter<=7;L_u8Counter++)
	{
		if(MNVIC->IABR[L_u8Counter]!=0)
		{
			L_u8ErrorState = STD_OK;
			*Copy_pu32CurrentActive = MNVIC->IABR[L_u8Counter];
			break;
		}
	}
	return L_u8ErrorState;
}

u8 MNVIC_u8SetIRQPriority(u8 Copy_u8IRQn, u8 Copy_u8GroupPriority)
{
	u8 L_u8ErrorState = STD_NOT_OK;
	if(Copy_u8IRQn<239 && Copy_u8GroupPriority<NVIC_PRIORITY_GROUP_15)
	{
		L_u8ErrorState = STD_OK;
		u8 L_u8RegNum = Copy_u8IRQn/4;
		u8 L_u8PinNum = Copy_u8IRQn%4;
		MNVIC->IPR[L_u8RegNum] &= ~(0xF<<(L_u8PinNum*8));
		MNVIC->IPR[L_u8RegNum] |= (Copy_u8GroupPriority<<(L_u8PinNum*8));
	}

	return L_u8ErrorState;
}
