/**********************************************
		Name	: EXIT_Prog.h
		Date	: 11/06/2024
		Author	: Mohamed Elhossien
		Version	: _V1_
***********************************************/
/******************************************** INCLUDES ********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STM32F401xx.h"
#include "EXIT_private.h"
#include "EXIT_config.h"
#include "EXIT_interface.h"

typedef void(*PtoFun)(void);
static PtoFun G_APtoFun[7]={NULL,NULL,NULL,NULL,NULL,NULL,NULL};
/***********************************************************************************************/
/*********************************	 Functions Implementations	********************************/
/***********************************************************************************************/
/**************************** 	1. Function Set Interrupt Status	****************************
								=> Options:	1- EXIT_MASKED
											2- EXIT_NOT_MASKED
*************************************************************************************************/
u8 MEXIT_u8SetInterruptStatus(u8 Copy_u8EXITNumber, u8 Copy_u8EXITStatus)
{
	u8 L_u8ErrorState = STD_NOT_OK;
	if(Copy_u8EXITNumber<=EXIT_15)
	{
		switch(Copy_u8EXITStatus)
		{
			case EXIT_MASKED:
				L_u8ErrorState = STD_OK;
				CLR_BIT(MEXIT->IMR,Copy_u8EXITNumber);
				break;
			case EXIT_NOT_MASKED:
				L_u8ErrorState = STD_OK;
				SET_BIT(MEXIT->IMR,Copy_u8EXITNumber);
				break;
			default: /*Wrong Choice*/ break;
		}
	}
	else
	{
		/* Wrong Choice*/
	}
	return L_u8ErrorState;
}
/*==============================================================================================*/
/****************************	2. Function Set Interrupt Edge 		*****************************
								=> Options:	1- EXIT_RISING_EDGE
											2- EXIT_FALLING_EDGE
											3- EXIT_RISING_FALLING_EDGE
*************************************************************************************************/
u8 MEXIT_u8SetInterruptEdge(u8 Copy_u8EXITNumber, u8 Copy_u8EXITEdge)
{
	u8 L_u8ErrorState = STD_NOT_OK;
	if(Copy_u8EXITNumber<=EXIT_15)
	{
		switch(Copy_u8EXITEdge)
		{
			case EXIT_RISING_EDGE:
				L_u8ErrorState = STD_OK;
				CLR_BIT(MEXIT->FTSR,Copy_u8EXITNumber);
				SET_BIT(MEXIT->RTSR,Copy_u8EXITNumber);
				break;
			case EXIT_FALLING_EDGE:
				L_u8ErrorState = STD_OK;
				CLR_BIT(MEXIT->RTSR,Copy_u8EXITNumber);
				SET_BIT(MEXIT->FTSR,Copy_u8EXITNumber);
				break;
			case EXIT_RISING_FALLING_EDGE:
				SET_BIT(MEXIT->RTSR,Copy_u8EXITNumber);
				SET_BIT(MEXIT->FTSR,Copy_u8EXITNumber);
				break;
			default: /*Wrong Choice*/ break;
		}

	}
	else
	{
		/* Wrong Choice*/
	}
	return L_u8ErrorState;
}
/*==============================================================================================*/
/****************************	3. Function Clear Interrupt Pending *****************************
*************************************************************************************************/
u8 MEXIT_u8ClrInterruptPending(u8 Copy_u8EXITNumber)
{
	u8 L_u8ErrorState = STD_NOT_OK;
	if(Copy_u8EXITNumber<=EXIT_15)
	{
		SET_BIT(MEXIT->PR,Copy_u8EXITNumber);
	}
	else
	{
		/* Wrong Choice*/
	}
	return L_u8ErrorState;
}
/*==============================================================================================*/
/****************************	4. Function Get Interrupt Status 	*****************************
*************************************************************************************************/
u8 MEXIT_u8IsInterruptActive(u8 Copy_u8EXITNumber, u8* Copy_pu8EXITStatus)
{
	u8 L_u8ErrorState = STD_NOT_OK;
	if(Copy_u8EXITNumber<=EXIT_15)
	{
		*Copy_pu8EXITStatus = GET_BIT(MEXIT->PR,Copy_u8EXITNumber);
	}
	else
	{
		/* Wrong Choice*/
	}
	return L_u8ErrorState;
}
/*==============================================================================================*/
/****************************	5. Function Set EXITx Source Input 	*****************************
*************************************************************************************************/
u8 MEXIT_u8SetInputSrc(u8 Copy_u8EXITNumber,u8 Copy_u8PortNumber)
{
	u8 L_u8ErrorState = STD_NOT_OK;
	if(Copy_u8EXITNumber<=EXIT_3)
	{
		MSYSCFG_EXTICR1 &= ~(0b1111<<(Copy_u8EXITNumber%4)*4);
		MSYSCFG_EXTICR1 |= (Copy_u8PortNumber<<(Copy_u8EXITNumber%4)*4);

	}
	else if(Copy_u8EXITNumber<=EXIT_7)
	{
		MSYSCFG_EXTICR2 &= ~(0b1111<<(Copy_u8EXITNumber%4)*4);
		MSYSCFG_EXTICR2 |= (Copy_u8PortNumber<<(Copy_u8EXITNumber%4)*4);
	}
	else if(Copy_u8EXITNumber<=EXIT_11)
	{
		MSYSCFG_EXTICR3 &= ~(0b1111<<(Copy_u8EXITNumber%4)*4);
		MSYSCFG_EXTICR3 |= (Copy_u8PortNumber<<(Copy_u8EXITNumber%4)*4);
	}
	else if(Copy_u8EXITNumber<=EXIT_15)
	{
		MSYSCFG_EXTICR4 &= ~(0b1111<<(Copy_u8EXITNumber%4)*4);
		MSYSCFG_EXTICR4 |= (Copy_u8PortNumber<<(Copy_u8EXITNumber%4)*4);
	}
	else
	{
		/* Wrong Choice*/
	}
	return L_u8ErrorState;
}
/*==============================================================================================*/
/****************************	5. Function Set Call Back to Define Handlers 	*****************
*************************************************************************************************/
u8 MEXIT_u8SetCallBack(u8 Copy_u8EXITNumber,void (*Copy_PFun)(void))
{
	u8 L_u8ErrorState = STD_NOT_OK;
	if(Copy_PFun != NULL && Copy_u8EXITNumber<=EXIT_15)
	{
		L_u8ErrorState = STD_OK;
		if(Copy_u8EXITNumber>=EXIT_4 && Copy_u8EXITNumber<=EXIT_9)
		{
			Copy_u8EXITNumber = 5;
		}
		else if(Copy_u8EXITNumber>=EXIT_10 && Copy_u8EXITNumber<=EXIT_15)
		{
			Copy_u8EXITNumber = 6;
		}
		G_APtoFun[Copy_u8EXITNumber] = Copy_PFun;
	}
	else
	{
		/* Wrong Choice*/
	}
	return L_u8ErrorState;
}
/***********************************************************************************************/
/*********************************	 EXIT ISRs Implementations	********************************/
/***********************************************************************************************/
void EXTI0_IRQHandler(void)
{
	SET_BIT(MEXIT->PR,EXIT_0);
	if(G_APtoFun[0]!=NULL)
	{
		G_APtoFun[0]();
	}
	else
	{
		/* DO NOTHING*/
	}
}
/*==============================================================================================*/
void EXTI1_IRQHandler(void)
{
	SET_BIT(MEXIT->PR,EXIT_1);
	if(G_APtoFun[1]!=NULL)
	{
		G_APtoFun[1]();
	}
	else
	{
		/* DO NOTHING*/
	}
}
/*==============================================================================================*/
void EXTI2_IRQHandler(void)
{
	SET_BIT(MEXIT->PR,EXIT_2);
	if(G_APtoFun[2]!=NULL)
	{
		G_APtoFun[2]();
	}
	else
	{
		/* DO NOTHING*/
	}
}
/*==============================================================================================*/
void EXTI3_IRQHandler(void)
{
	SET_BIT(MEXIT->PR,EXIT_3);
	if(G_APtoFun[3]!=NULL)
	{
		G_APtoFun[3]();
	}
	else
	{
		/* DO NOTHING*/
	}
}
/*==============================================================================================*/
void EXTI4_IRQHandler(void)
{
	SET_BIT(MEXIT->PR,EXIT_4);
	if(G_APtoFun[4]!=NULL)
	{
		G_APtoFun[4]();
	}
	else
	{
		/* DO NOTHING*/
	}
}
/*==============================================================================================*/
void EXTI9_5_IRQHandler(void)
{
	MEXIT->PR |= (0b11111<<EXIT_5);
	if(G_APtoFun[5]!=NULL)
	{
		G_APtoFun[5]();
	}
	else
	{
		/* DO NOTHING*/
	}
}
/*==============================================================================================*/
void EXTI15_10_IRQHandler(void)
{
	MEXIT->PR |= (0b111111<<EXIT_10);
	if(G_APtoFun[6]!=NULL)
	{
		G_APtoFun[6]();
	}
	else
	{
		/* DO NOTHING*/
	}
}
