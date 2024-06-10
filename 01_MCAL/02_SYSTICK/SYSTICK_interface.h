/**********************************************
		Name	: SYSTICK_interface.h
		Date	: 08/06/2024
		Author	: Mohamed Elhossien
		Version	: _V1_
***********************************************/

#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_


void MSTK_vInit(void);

u8 MSTK_u8SetBusyWait(u32 Copy_u32NumOfTicks);

u8 MSTK_u8SetIntervalSingle(u32 Copy_u32NumOfTicks, void (*Copy_pfunc)(void));

u8 MSTK_u8SetIntervalPeriodic(u32 Copy_u32NumOfTicks, void (*Copy_pfunc)(void));

void MSTK_vStopTimer(void);

u8 MSTK_u8GetElapsedTime(u32* Copy_pu32ElapsedTime);

u8 MSTK_u8GetRemaningTime(u32* Copy_pu32RemainingTime);


#endif /* SYSTICK_INTERFACE_H_ */
