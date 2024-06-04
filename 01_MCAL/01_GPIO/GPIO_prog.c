/**********************************************
		Name	: GPIO_Prog.h
		Date	: 03/06/2024
		Author	: Mohamed Elhossien
		Version	: _V1_
***********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STM32F401xx.h"
#include "GPIO_private.h"
#include "GPIO_config.h"
#include "GPIO_interface.h"

void MGPIO_vSetPinMode(u8 Copy_u8PortName,u8 Copy_u8PinName,u8 Copy_u8Mode)
{
	switch(Copy_u8PortName)
	{
	case GPIOA_PORT:	MGPIOA->MODER |= (Copy_u8Mode<<(2U*Copy_u8PinName)); break;
	case GPIOB_PORT:    MGPIOB->MODER |= (Copy_u8Mode<<(2U*Copy_u8PinName)); break;
	case GPIOC_PORT:    MGPIOC->MODER |= (Copy_u8Mode<<(2U*Copy_u8PinName)); break;
	case GPIOD_PORT:    MGPIOD->MODER |= (Copy_u8Mode<<(2U*Copy_u8PinName)); break;
	case GPIOE_PORT:    MGPIOE->MODER |= (Copy_u8Mode<<(2U*Copy_u8PinName)); break;
	case GPIOH_PORT:    MGPIOH->MODER |= (Copy_u8Mode<<(2U*Copy_u8PinName)); break;
	default: /*Wrong Choice*/ break;
	}
}

void MGPIO_vSetOutType(u8 Copy_u8PortName,u8 Copy_u8PinName,u8 Copy_u8OutType)
{
	switch(Copy_u8PortName)
	{
	case GPIOA_PORT:	MGPIOA->OTYPER |= (Copy_u8OutType<<Copy_u8PinName); break;
	case GPIOB_PORT:    MGPIOB->OTYPER |= (Copy_u8OutType<<Copy_u8PinName); break;
	case GPIOC_PORT:    MGPIOC->OTYPER |= (Copy_u8OutType<<Copy_u8PinName); break;
	case GPIOD_PORT:    MGPIOD->OTYPER |= (Copy_u8OutType<<Copy_u8PinName); break;
	case GPIOE_PORT:    MGPIOE->OTYPER |= (Copy_u8OutType<<Copy_u8PinName); break;
	case GPIOH_PORT:    MGPIOH->OTYPER |= (Copy_u8OutType<<Copy_u8PinName); break;
	default: /*Wrong Choice*/ break;
	}
}


void MGPIO_vSetOutSpeed(u8 Copy_u8PortName,u8 Copy_u8PinName,u8 Copy_u8OutSpeed)
{
	switch(Copy_u8PortName)
	{
	case GPIOA_PORT:	MGPIOA->OSPEEDR |= (Copy_u8OutSpeed<<(2U*Copy_u8PinName)); break;
	case GPIOB_PORT:    MGPIOB->OSPEEDR |= (Copy_u8OutSpeed<<(2U*Copy_u8PinName)); break;
	case GPIOC_PORT:    MGPIOC->OSPEEDR |= (Copy_u8OutSpeed<<(2U*Copy_u8PinName)); break;
	case GPIOD_PORT:    MGPIOD->OSPEEDR |= (Copy_u8OutSpeed<<(2U*Copy_u8PinName)); break;
	case GPIOE_PORT:    MGPIOE->OSPEEDR |= (Copy_u8OutSpeed<<(2U*Copy_u8PinName)); break;
	case GPIOH_PORT:    MGPIOH->OSPEEDR |= (Copy_u8OutSpeed<<(2U*Copy_u8PinName)); break;
	default: /*Wrong Choice*/ break;
	}
}


void MGPIO_vSetOutPullType(u8 Copy_u8PortName,u8 Copy_u8PinName,u8 Copy_u8PullType)
{
	switch(Copy_u8PortName)
	{
	case GPIOA_PORT:	MGPIOA->PUPDR |= (Copy_u8PullType<<(2U*Copy_u8PinName)); break;
	case GPIOB_PORT:    MGPIOB->PUPDR |= (Copy_u8PullType<<(2U*Copy_u8PinName)); break;
	case GPIOC_PORT:    MGPIOC->PUPDR |= (Copy_u8PullType<<(2U*Copy_u8PinName)); break;
	case GPIOD_PORT:    MGPIOD->PUPDR |= (Copy_u8PullType<<(2U*Copy_u8PinName)); break;
	case GPIOE_PORT:    MGPIOE->PUPDR |= (Copy_u8PullType<<(2U*Copy_u8PinName)); break;
	case GPIOH_PORT:    MGPIOH->PUPDR |= (Copy_u8PullType<<(2U*Copy_u8PinName)); break;
	default: /*Wrong Choice*/ break;
	}
}

u8 MGPIO_u8GetPinVal(u8 Copy_u8PortName,u8 Copy_u8PinName)
{
	u8 L_u8PinVal=0;
	switch(Copy_u8PortName)
	{
	case GPIOA_PORT:	L_u8PinVal = GET_BIT(Copy_u8PortName,Copy_u8PinName); break;
	case GPIOB_PORT:    L_u8PinVal = GET_BIT(Copy_u8PortName,Copy_u8PinName); break;
	case GPIOC_PORT:    L_u8PinVal = GET_BIT(Copy_u8PortName,Copy_u8PinName); break;
	case GPIOD_PORT:    L_u8PinVal = GET_BIT(Copy_u8PortName,Copy_u8PinName); break;
	case GPIOE_PORT:    L_u8PinVal = GET_BIT(Copy_u8PortName,Copy_u8PinName); break;
	case GPIOH_PORT:    L_u8PinVal = GET_BIT(Copy_u8PortName,Copy_u8PinName); break;
	default: /*Wrong Choice*/ break;
	}
	return L_u8PinVal;
}


void MGPIO_vSetPinVal(u8 Copy_u8PortName,u8 Copy_u8PinName,u8 Copy_u8OutVal)
{
	switch(Copy_u8PortName)
	{
	case GPIOA_PORT:	SET_BIT(Copy_u8PortName,Copy_u8PinName); break;
	case GPIOB_PORT:    SET_BIT(Copy_u8PortName,Copy_u8PinName); break;
	case GPIOC_PORT:    SET_BIT(Copy_u8PortName,Copy_u8PinName); break;
	case GPIOD_PORT:    SET_BIT(Copy_u8PortName,Copy_u8PinName); break;
	case GPIOE_PORT:    SET_BIT(Copy_u8PortName,Copy_u8PinName); break;
	case GPIOH_PORT:    SET_BIT(Copy_u8PortName,Copy_u8PinName); break;
	default: /*Wrong Choice*/ break;
	}
}
