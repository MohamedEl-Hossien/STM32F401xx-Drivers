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

/***********************************************************************************************/
/**************************** 	1. Function Enable Interrupt_x	********************************
*************************************************************************************************/
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
/*==============================================================================================*/
/**************************** 	2. Function Disable Interrupt_x	********************************
*************************************************************************************************/
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
/*==============================================================================================*/
/**************************** 	3. Function Set Pending of Interrupt_x 	************************
*************************************************************************************************/
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
/*==============================================================================================*/
/**************************** 	4. Function Clear Pending of Interrupt_x 	*********************
*************************************************************************************************/
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
/*==============================================================================================*/
/**************************** 	5. Function Get Current Active Interrupt	*********************
*************************************************************************************************/
u8 MNVIC_u8GetCurrentActiveIRQ(u32* Copy_pu32CurrentActive)
{
	u8 L_u8ErrorState = STD_NOT_OK;
	*Copy_pu32CurrentActive = 0;
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
/*==============================================================================================*/
/**************************** 	6. Function Get Active State of Interrupt_x	*********************
*************************************************************************************************/
u8 MNVIC_u8GetIRQActiveState(u8 Copy_u8IRQn,u8* Copy_pu8AvtiveState)
{
	u8 L_u8ErrorState = STD_NOT_OK;
	if(Copy_u8IRQn<239)
	{
		L_u8ErrorState = STD_OK;
		u8 L_u8RegNum = Copy_u8IRQn/32;
		Copy_u8IRQn -= (L_u8RegNum*32);
		*Copy_pu8AvtiveState = GET_BIT(MNVIC->IABR[L_u8RegNum],Copy_u8IRQn);
	}
	else
	{
		/* Wrong Choice*/
	}
	return L_u8ErrorState;
}
/*==============================================================================================*/
/**************************** 	7. Function Set Group Priority	*********************************
*************************************************************************************************/
u8 MNVIC_u8SetGroupPriority()
{
	u8 L_u8ErrorState = STD_NOT_OK;
	if(NVIC_GROUP_PRIORITY>=NVIC_16_GROUP_NO_SUB && NVIC_GROUP_PRIORITY<=NVIC_NO_GROUP_16_SUB)
	{
		L_u8ErrorState = STD_OK;
		MSCB_AIRCR = (VECTKEY<<16) | (NVIC_GROUP_PRIORITY<<8);
	}
	return L_u8ErrorState;
}
/*==============================================================================================*/
/**************************** 	8. Function Set Group Priority of Interrupt_x	*****************
*************************************************************************************************/
u8 MNVIC_u8SetIRQPriority(u8 Copy_u8IRQn, u8 Copy_u8GroupPriority)
{
	u8 L_u8ErrorState = STD_NOT_OK;
	if(Copy_u8IRQn<239 && Copy_u8GroupPriority<NVIC_PRIORITY_GROUP_15)
	{
		L_u8ErrorState = STD_OK;
		u8 L_u8RegNum = Copy_u8IRQn/4;
		u8 L_u8ByteNum = Copy_u8IRQn%4;
		MNVIC->IPR[L_u8RegNum] &= ~(0xF<<((L_u8ByteNum*8)+4));
		MNVIC->IPR[L_u8RegNum] |= (Copy_u8GroupPriority<<((L_u8ByteNum*8)+4));
	}

	return L_u8ErrorState;
}
/*==============================================================================================*/
