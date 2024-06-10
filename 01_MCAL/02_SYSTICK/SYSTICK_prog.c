/**********************************************
		Name	: SYSTICK_Prog.h
		Date	: 08/06/2024
		Author	: Mohamed Elhossien
		Version	: _V1_
***********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STM32F401xx.h"
#include "SYSTICK_private.h"
#include "SYSTICK_config.h"
#include "SYSTICK_interface.h"


static void (*PtoFuncISR) (void) = NULL ;
static u8 G_u8IntervalFlag = MSTK_INTERVAL_SINGLE;

void MSTK_vInit(void)
{
#if MSTK_CLK_SRC == CLK_AHB_8

	CLR_BIT(MSTK->CTRL,MSTK_ENABLE);
	MSTK->LOAD = 0;
	MSTK->VAL  = 0;
	CLR_BIT(MSTK->CTRL,MSTK_CLKSOURCE);

#elif MSTK_CLK_SRC == CLK_AHB

	CLR_BIT(MSTK->CTRL,MSTK_ENABLE);
	MSTK->LOAD = 0;
	MSTK->VAL  = 0;
	SET_BIT(MSTK->CTRL,MSTK_CLKSOURCE);

#else

	#error "Wrong Choice"

#endif
}

u8 MSTK_u8SetBusyWait(u32 Copy_u32NumOfTicks)
{
	STD_STATE STATE = STD_NOT_OK;

	if(Copy_u32NumOfTicks<MSTK_MAX_COUNT)
	{
		MSTK->LOAD = Copy_u32NumOfTicks;
		SET_BIT(MSTK->CTRL,MSTK_ENABLE);
		while(GET_BIT(MSTK->CTRL,MSTK_COUNTFLAG)==0);
		CLR_BIT(MSTK->CTRL,MSTK_ENABLE);
		MSTK->LOAD = 0;
		MSTK->VAL  = 0;
		STATE = STD_OK;
	}
	return STATE;
}

u8 MSTK_u8SetIntervalSingle(u32 Copy_u32NumOfTicks, void (*Copy_pfunc)(void))
{
	STD_STATE STATE = STD_NOT_OK;
	if((Copy_u32NumOfTicks<MSTK_MAX_COUNT) && (Copy_pfunc!=NULL))
	{
		MSTK->LOAD = Copy_u32NumOfTicks;
		SET_BIT(MSTK->CTRL,MSTK_ENABLE);
		PtoFuncISR = Copy_pfunc;
		G_u8IntervalFlag = MSTK_INTERVAL_SINGLE;
		SET_BIT(MSTK->CTRL,MSTK_TICKINT);
		STATE = STD_OK;
	}
	return STATE;
}

u8 MSTK_u8SetIntervalPeriodic(u32 Copy_u32NumOfTicks, void (*Copy_pfunc)(void))
{
	STD_STATE STATE = STD_NOT_OK;
	if((Copy_u32NumOfTicks<MSTK_MAX_COUNT) && (Copy_pfunc!=NULL))
	{
		MSTK->LOAD = Copy_u32NumOfTicks-1;
		SET_BIT(MSTK->CTRL,MSTK_ENABLE);
		PtoFuncISR = Copy_pfunc;
		G_u8IntervalFlag = MSTK_INTERVAL_PERIODIC;
		SET_BIT(MSTK->CTRL,MSTK_TICKINT);
		STATE = STD_OK;
	}
	return STATE;
}

void MSTK_vStopTimer(void)
{
	CLR_BIT(MSTK->CTRL,MSTK_ENABLE);
	MSTK->LOAD = 0;
	MSTK->VAL  = 0;
}


u8 MSTK_u8GetElapsedTime(u32* Copy_pu32ElapsedTime)
{
	STD_STATE STATE = STD_NOT_OK;
	if(Copy_pu32ElapsedTime==NULL)
	{
		return STATE;
	}
	else
	{
		*Copy_pu32ElapsedTime = MSTK->LOAD - MSTK->VAL;
		STATE = STD_OK;
	}
	return STATE;
}

u8 MSTK_u8GetRemaningTime(u32* Copy_pu32RemainingTime)
{
	STD_STATE STATE = STD_NOT_OK;
	if(Copy_pu32RemainingTime==NULL)
	{
		return STATE;
	}
	else
	{
		*Copy_pu32RemainingTime = MSTK->VAL;
		STATE = STD_OK;
	}
	return STATE;
}

void SysTick_Handler (void)
{
	u8 L_u8Temp;
	if(G_u8IntervalFlag == MSTK_INTERVAL_SINGLE)
	{
		CLR_BIT(MSTK->CTRL,MSTK_TICKINT);
		CLR_BIT(MSTK->CTRL,MSTK_ENABLE);
		MSTK->LOAD = 0;
		MSTK->VAL  = 0;
	}

	if(PtoFuncISR!=NULL)
	{
			PtoFuncISR();
	}
	L_u8Temp = GET_BIT(MSTK->CTRL,MSTK_COUNTFLAG);
}

