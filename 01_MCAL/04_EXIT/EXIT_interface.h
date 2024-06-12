/**********************************************
		Name	: EXIT_interface.h
		Date	: 11/06/2024
		Author	: Mohamed Elhossien
		Version	: _V1_
***********************************************/
/***********************************************************************************************
 ****************************** guard of file call on time in .c *******************************
 ***********************************************************************************************/
#ifndef EXIT_INTERFACE_H_
#define EXIT_INTERFACE_H_

#define EXIT_0					0U
#define EXIT_1					1U
#define EXIT_2					2U
#define EXIT_3					3U
#define EXIT_4					4U
#define EXIT_5					5U
#define EXIT_6					6U
#define EXIT_7					7U
#define EXIT_8					8U
#define EXIT_9					9U
#define EXIT_10					10U
#define EXIT_11					11U
#define EXIT_12					12U
#define EXIT_13					13U
#define EXIT_14					14U
#define EXIT_15					15U
/*************** MACROS OF INTERRUPT STATUS **************/
#define EXIT_MASKED						0U
#define EXIT_NOT_MASKED					1U
/*************** MACROS OF INTERRUPT EDGE ****************/
#define EXIT_RISING_EDGE				0U
#define EXIT_FALLING_EDGE				1U
#define EXIT_RISING_FALLING_EDGE		2U
/*************** MACROS OF EXITx SOURCE INPUT ************/
#define EXIT_PORT_A                       0b0000
#define EXIT_PORT_B                       0b0001
#define EXIT_PORT_C                       0b0010
#define EXIT_PORT_D                       0b0011
#define EXIT_PORT_E                       0b0100
#define EXIT_PORT_H                       0b0111
/***********************************************************************************************/
/********************************** 	Functions Prototypes	********************************/
/***********************************************************************************************/
/**************************** 	1. Function Set Interrupt Status	****************************
								=> Options:	1- EXIT_MASKED
											2- EXIT_NOT_MASKED
*************************************************************************************************/
u8 MEXIT_u8SetInterruptStatus(u8 Copy_u8EXITNumber, u8 Copy_u8EXITStatus);
/*==============================================================================================*/
/****************************	2. Function Set Interrupt Edge 		*****************************
								=> Options:	1- EXIT_RISING_EDGE
											2- EXIT_FALLING_EDGE
											3- EXIT_RISING_FALLING_EDGE
*************************************************************************************************/
u8 MEXIT_u8SetInterruptEdge(u8 Copy_u8EXITNumber, u8 Copy_u8EXITEdge);
/*==============================================================================================*/
/****************************	3. Function Clear Interrupt Pending *****************************
*************************************************************************************************/
u8 MEXIT_u8ClrInterruptPending(u8 Copy_u8EXITNumber);
/*==============================================================================================*/
/****************************	4. Function Get Interrupt Status 	*****************************
*************************************************************************************************/
u8 MEXIT_u8IsInterruptActive(u8 Copy_u8EXITNumber, u8* Copy_pu8EXITStatus);
/*==============================================================================================*/
/****************************	5. Function Set EXITx Source Input 	*****************************
*************************************************************************************************/
u8 MEXIT_u8SetInputSrc(u8 Copy_u8EXITNumber,u8 Copy_u8PortNumber);
/*==============================================================================================*/
/****************************	6. Function Set Call Back to Define Handlers 	*****************
*************************************************************************************************/
u8 MEXIT_u8SetCallBack(u8 Copy_u8EXITNumber,void (*Copy_PFun)(void));

#endif /* EXIT_INTERFACE_H_ */
