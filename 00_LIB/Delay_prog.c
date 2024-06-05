/**********************************************
		Name	: Delay_Prog.h
		Date	: 05/06/2024
		Author	: Mohamed Elhossien
		Version	: _V1_
***********************************************/

#include "STD_TYPES.h"
#include "Delay_interface.h"

extern void Delay_vMilliSeconds(u16 Copy_u16DelayMilliSeconds)
{
	volatile u16 L_u16Counter1=0;
	volatile u16 L_u16Counter2=0;
	for(L_u16Counter1=0;L_u16Counter1<=Copy_u16DelayMilliSeconds;L_u16Counter1++)
	{
		for(L_u16Counter2=0;L_u16Counter2<3180;L_u16Counter2++)
		{}
	}
}

extern void Delay_vMicroSeconds(u16 Copy_u16DelayMicroSeconds)
{
	volatile u16 L_u16Counter1=0;
	volatile u16 L_u16Counter2=0;
	for(L_u16Counter1=0;L_u16Counter1<=Copy_u16DelayMicroSeconds;L_u16Counter1++)
	{
		for(L_u16Counter2=0;L_u16Counter2<3;L_u16Counter2++)
		{}
	}
}
