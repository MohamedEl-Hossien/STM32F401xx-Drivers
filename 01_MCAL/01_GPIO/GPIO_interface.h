/**********************************************
		Name	: GPIO_interface.h
		Date	: 03/06/2024
		Author	: Mohamed Elhossien
		Version	: _V1_
***********************************************/
/**********************************************
******* guard of file call on time in .c ******
***********************************************/
#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

#define GPIOA_PORT			0U
#define GPIOB_PORT			1U
#define GPIOC_PORT			2U
#define GPIOD_PORT			3U
#define GPIOE_PORT			4U
#define GPIOH_PORT			5U

#define GPIOx_PIN0			0U
#define GPIOx_PIN1			1U
#define GPIOx_PIN2			2U
#define GPIOx_PIN3			3U
#define GPIOx_PIN4			4U
#define GPIOx_PIN5			5U
#define GPIOx_PIN6			6U
#define GPIOx_PIN7			7U
#define GPIOx_PIN8			8U
#define GPIOx_PIN9			9U
#define GPIOx_PIN10			10U
#define GPIOx_PIN11			11U
#define GPIOx_PIN12			12U
#define GPIOx_PIN13			13U
#define GPIOx_PIN14			14U
#define GPIOx_PIN15			15U
/************** Start FUNCION ******************
	Function Set The Mode Of Pin Mode Take 2Bits
				1- MODE_INPUT
				2- MODE_OUTPUT
				3- MODE_ALTF
				4- MODE_ANALOG
*************************************************/
#define MODE_INPUT			(0b00)
#define MODE_OUTPUT  		(0b01)
#define MODE_ALTF    		(0b10)
#define MODE_ANALOG  		(0b11)

void MGPIO_vSetPinMode(u8 Copy_u8PortName,u8 Copy_u8PinName,u8 Copy_u8Mode);

#define OUTPUT_TYPE_PUSH_PULL	0
#define OUTPUT_TYPE_OPEN_DRAIN	1

void MGPIO_vSetOutType(u8 Copy_u8PortName,u8 Copy_u8PinName,u8 Copy_u8OutType);

#define OUTPUT_SPEED_LOW	  	(0b00)
#define OUTPUT_SPEED_MEDIUM	  	(0b01)
#define OUTPUT_SPEED_HIGH		(0b10)
#define OUTPUT_SPEED_VERY_HIGH	(0b11)

void MGPIO_vSetOutSpeed(u8 Copy_u8PortName,u8 Copy_u8PinName,u8 Copy_u8OutSpeed);

#define OUTPUT_NO_PULL	  		(0b00)
#define OUTPUT_PULL_UP		  	(0b01)
#define OUTPUT_PULL_DOWN		(0b10)

void MGPIO_vSetOutPullType(u8 Copy_u8PortName,u8 Copy_u8PinName,u8 Copy_u8PullType);

u8 MGPIO_u8GetPinVal(u8 Copy_u8PortName,u8 Copy_u8PinName);

#define OUTPUT_LOW				0
#define OUTPUT_HIGH				1

void MGPIO_vSetPinVal(u8 Copy_u8PortName,u8 Copy_u8PinName,u8 Copy_u8OutVal);

#endif /* GPIO_INTERFACE_H_ */
