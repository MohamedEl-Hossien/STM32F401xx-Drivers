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
#include "GPIO_interface.h"

static GPIOx_RegDef_t* GPIOx_AStr[GPIO_NUMBERS]={MGPIOA,MGPIOB,MGPIOC,MGPIOD,MGPIOE,MGPIOH};

void MGPIO_vSetPinMode(u8 Copy_u8PortName,u8 Copy_u8PinName,u8 Copy_u8Mode)
{
	GPIOx_AStr[Copy_u8PortName]->MODER |= (u32) (Copy_u8Mode<<(2U*Copy_u8PinName));
}

void MGPIO_vSetPinOutType(u8 Copy_u8PortName,u8 Copy_u8PinName,u8 Copy_u8OutType)
{
	GPIOx_AStr[Copy_u8PortName]->OTYPER |= (u32) (Copy_u8OutType<<Copy_u8PinName);
}

void MGPIO_vSetPinOutSpeed(u8 Copy_u8PortName,u8 Copy_u8PinName,u8 Copy_u8OutSpeed)
{
	GPIOx_AStr[Copy_u8PortName]->OSPEEDR |= (u32) (Copy_u8OutSpeed<<(2U*Copy_u8PinName));
}

void MGPIO_vSetInputPullType(u8 Copy_u8PortName,u8 Copy_u8PinName,u8 Copy_u8PullType)
{
	GPIOx_AStr[Copy_u8PortName]->PUPDR |= (u32) (Copy_u8PullType<<(2U*Copy_u8PinName));
}

u8 MGPIO_u8GetPinVal(u8 Copy_u8PortName,u8 Copy_u8PinName)
{
	u8 L_u8PinVal = GET_BIT(GPIOx_AStr[Copy_u8PortName]->IDR,Copy_u8PinName);
	return L_u8PinVal;
}

void MGPIO_vSetPinVal(u8 Copy_u8PortName,u8 Copy_u8PinName,u8 Copy_u8OutVal)
{
	switch(Copy_u8OutVal)
	{
	case OUTPUT_PIN_LOW:		CLR_BIT(GPIOx_AStr[Copy_u8PortName]->ODR,Copy_u8PinName); break;
	case OUTPUT_PIN_HIGH: 	SET_BIT(GPIOx_AStr[Copy_u8PortName]->ODR,Copy_u8PinName); break;
	default: break;
	}
}


void MGPIO_vLckPinConfg(u8 Copy_u8PortName,u8 Copy_u8PinName)
{
	SET_BIT(GPIOx_AStr[Copy_u8PortName]->LCKR,Copy_u8PinName);
	SET_BIT(GPIOx_AStr[Copy_u8PortName]->LCKR,GPIO_LCKK_PIN);
	while(!GET_BIT(GPIOx_AStr[Copy_u8PortName]->LCKR,GPIO_LCKK_PIN));
}

void MGPIO_vSetPinAltFunc(u8 Copy_u8PortName,u8 Copy_u8PinName,u8 Copy_u8AltFunc)
{
	if(Copy_u8PinName<=7)
	{
		GPIOx_AStr[Copy_u8PortName]->AFRL |= (u32) (Copy_u8AltFunc<<(4*Copy_u8PinName));
	}
	else
	{
		Copy_u8PinName -=8;
		GPIOx_AStr[Copy_u8PortName]->AFRH |= (u32) (Copy_u8AltFunc<<(4*Copy_u8PinName));
	}
}

u32 MGPIO_u32GetPortVal(u8 Copy_u8PortName)
{
	u32 L_u32PortVal = GPIOx_AStr[Copy_u8PortName]->IDR;
	return L_u32PortVal;
}

void MGPIO_vSetPortVal(u8 Copy_u8PortName,u32 Copy_u32OutVal)
{
	GPIOx_AStr[Copy_u8PortName]->ODR = Copy_u32OutVal;
}

