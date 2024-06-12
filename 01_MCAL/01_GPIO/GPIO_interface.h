/**********************************************************************************************
									Name	: GPIO_interface.h
									Date	: 03/06/2024
									Author	: Mohamed Elhossien
									Version	: _V1_
************************************************************************************************/

/***********************************************************************************************
 ****************************** guard of file call on time in .c *******************************
 ***********************************************************************************************/
#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

/*************** MACROS OF PORT ***************/
#define GPIOA_PORT				0U
#define GPIOB_PORT				1U
#define GPIOC_PORT				2U
#define GPIOD_PORT				3U
#define GPIOE_PORT				4U
#define GPIOH_PORT				5U

/*************** MACROS OF PINS ***************/
#define GPIOx_PIN0				0U
#define GPIOx_PIN1				1U
#define GPIOx_PIN2				2U
#define GPIOx_PIN3				3U
#define GPIOx_PIN4				4U
#define GPIOx_PIN5				5U
#define GPIOx_PIN6				6U
#define GPIOx_PIN7				7U
#define GPIOx_PIN8				8U
#define GPIOx_PIN9				9U
#define GPIOx_PIN10				10U
#define GPIOx_PIN11				11U
#define GPIOx_PIN12				12U
#define GPIOx_PIN13				13U
#define GPIOx_PIN14				14U
#define GPIOx_PIN15				15U

/*************** MACROS OF MODE ***************/
#define MODE_INPUT				(0b00)
#define MODE_OUTPUT  			(0b01)
#define MODE_ALTF    			(0b10)
#define MODE_ANALOG  			(0b11)

/************ MACROS OF OUTPUT TYPE ***********/
#define OUTPUT_TYPE_PUSH_PULL	0
#define OUTPUT_TYPE_OPEN_DRAIN	1

/*********** MACROS OF OUTPUT SPEED ***********/
#define OUTPUT_SPEED_LOW	  	(0b00)
#define OUTPUT_SPEED_MEDIUM	  	(0b01)
#define OUTPUT_SPEED_HIGH		(0b10)
#define OUTPUT_SPEED_VERY_HIGH	(0b11)

/*********** MACROS OF INPUT PULL ***********/
#define INTPUT_NO_PULL	  		(0b00)
#define INTPUT_PULL_UP		  	(0b01)
#define INTPUT_PULL_DOWN		(0b10)

/*********** MACROS OF WRITE DATA ***********/
#define OUTPUT_PIN_LOW			0
#define OUTPUT_PIN_HIGH			1
#define OUTPUT_PORT_LOW			0
#define OUTPUT_PORT_HIGH		0xFFFFFFFFU
/*************** MACROS OF ALTF ***************/
#define ALTF0					0b0000
#define ALTF1					0b0001
#define ALTF2					0b0010
#define ALTF3					0b0011
#define ALTF4					0b0100
#define ALTF5					0b0101
#define ALTF6					0b0110
#define ALTF7					0b0111
#define ALTF8					0b1000
#define ALTF9					0b1001
#define ALTF10					0b1010
#define ALTF11					0b1011
#define ALTF12					0b1100
#define ALTF13					0b1101
#define ALTF14					0b1110
#define ALTF15					0b1111
/********************************** 	Functions Prototypes	********************************/
/***********************************************************************************************/
/**************************** 	1. Function Set The Mode Of Pin	********************************
								=> Options:	1- MODE_INPUT
											2- MODE_OUTPUT
											3- MODE_ALTF
											4- MODE_ANALOG
*************************************************************************************************/
void MGPIO_vSetPinMode(u8 Copy_u8PortName,u8 Copy_u8PinName,u8 Copy_u8Mode);
/*==============================================================================================*/
/****************************	2. Function Set The Output Type Of Pin **************************
								=> Options:	1- OUTPUT_TYPE_PUSH_PULL
											2- OUTPUT_TYPE_OPEN_DRAIN
*************************************************************************************************/
void MGPIO_vSetPinOutType(u8 Copy_u8PortName,u8 Copy_u8PinName,u8 Copy_u8OutType);
/*==============================================================================================*/
/**************************** 	3. Function Set The Speed Of Pin ********************************
								=> Options:	1- OUTPUT_SPEED_LOW
											2- OUTPUT_SPEED_MEDIUM
											3- OUTPUT_SPEED_HIGH
											4- OUTPUT_SPEED_VERY_HIGH
*************************************************************************************************/
void MGPIO_vSetPinOutSpeed(u8 Copy_u8PortName,u8 Copy_u8PinName,u8 Copy_u8OutSpeed);
/*==============================================================================================*/
/**************************** 	4. Function Set Pin Pull Type ***********************************
								=> Options:	1- INTPUT_NO_PULL
											2- INTPUT_PULL_UP
											3- INTPUT_PULL_DOWN
*************************************************************************************************/
void MGPIO_vSetInputPullType(u8 Copy_u8PortName,u8 Copy_u8PinName,u8 Copy_u8PullType);
/*==============================================================================================*/
/****************************	5. Function Get The Value Of Pin *******************************
*************************************************************************************************/
u8 MGPIO_u8GetPinVal(u8 Copy_u8PortName,u8 Copy_u8PinName);
/*==============================================================================================*/
/****************************	6. Function Toggle The Value Of Pin *****************************
*************************************************************************************************/
void MGPIO_vTogglePinVal(u8 Copy_u8PortName,u8 Copy_u8PinName);
/*==============================================================================================*/
/****************************	7. Function Set The Value Of Pin *******************************
								=> Mode Options:	1- OUTPUT_LOW
													2- OUTPUT_HIGH
*************************************************************************************************/
void MGPIO_vSetPinVal(u8 Copy_u8PortName,u8 Copy_u8PinName,u8 Copy_u8OutVal);
/*==============================================================================================*/
/****************************	8. Function Lock Pin Configuration *******************************
*************************************************************************************************/
void MGPIO_vLckPinConfg(u8 Copy_u8PortName,u8 Copy_u8PinName);
/*==============================================================================================*/
/****************************	9. Function SET Pin Alternate Func ******************************
*************************************************************************************************/
void MGPIO_vSetPinAltFunc(u8 Copy_u8PortName,u8 Copy_u8PinName,u8 Copy_u8AltFunc);
/*==============================================================================================*/
/****************************	10. Function Get The Value Of Port *******************************
*************************************************************************************************/
u32 MGPIO_u32GetPortVal(u8 Copy_u8PortName);
/*==============================================================================================*/
/****************************	11. Function Set The Value Of Port *******************************
*************************************************************************************************/
void MGPIO_vSetPortVal(u8 Copy_u8PortName,u32 Copy_u32OutVal);

#endif /* GPIO_INTERFACE_H_ */
