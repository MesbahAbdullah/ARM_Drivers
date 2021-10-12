/*********************************************************/
/* Author      : Mesbah Abdullah                         */
/* Date        : 12 Oct 2021                             */
/* Version     : V02                                     */
/* Brief       : GPIO driver                             */
/*********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

void MGPIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 u8Copy_u8Mode)
{

	switch (Copy_u8Port)
	{
	case GPIOA:
		/* configuring the firs 8 pins in a port by using port configuration register low */
		if (Copy_u8Pin <= 7)
		{
			/* clearing the CNF and MODE bits  */
			GPIOA_CRL &= ~((0b1111) << (Copy_u8Pin * 4));
			/* seeting the CNF and MODE bits  */
			GPIOA_CRL |= (u8Copy_u8Mode) << (Copy_u8Pin * 4);
		}
		/* configuring the second 8 pins in a port by using port configuration register high */
		else if (Copy_u8Pin <= 15)
		{
			Copy_u8Pin = Copy_u8Pin - 8;
			/* clearing the CNF and MODE bits  */
			GPIOA_CRH &= ~((0b1111) << (Copy_u8Pin * 4));
			/* seeting the CNF and MODE bits  */
			GPIOA_CRH |= (u8Copy_u8Mode) << (Copy_u8Pin * 4);
		}

		break;

	case GPIOB:
		/* configuring the firs 8 pins in a port by using port configuration register low */
		if (Copy_u8Pin <= 7)
		{
			/* clearing the CNF and MODE bits  */
			GPIOB_CRL &= ~((0b1111) << (Copy_u8Pin * 4));
			/* seeting the CNF and MODE bits  */
			GPIOB_CRL |= (u8Copy_u8Mode) << (Copy_u8Pin * 4);
		}
		/* configuring the second 8 pins in a port by using port configuration register high */
		else if (Copy_u8Pin <= 15)
		{
			Copy_u8Pin = Copy_u8Pin - 8;
			/* clearing the CNF and MODE bits  */
			GPIOB_CRH &= ~((0b1111) << (Copy_u8Pin * 4));
			/* seeting the CNF and MODE bits  */
			GPIOB_CRH |= (u8Copy_u8Mode) << (Copy_u8Pin * 4);
		}
		break;
	case GPIOC:
		/* configuring the firs 8 pins in a port by using port configuration register low */
		if (Copy_u8Pin <= 7)
		{
			/* clearing the CNF and MODE bits  */
			GPIOC_CRL &= ~((0b1111) << (Copy_u8Pin * 4));
			/* seeting the CNF and MODE bits  */
			GPIOC_CRL |= (u8Copy_u8Mode) << (Copy_u8Pin * 4);
		}
		/* configuring the second 8 pins in a port by using port configuration register high */
		else if (Copy_u8Pin <= 15)
		{
			Copy_u8Pin = Copy_u8Pin - 8;
			/* clearing the CNF and MODE bits  */
			GPIOC_CRH &= ~((0b1111) << (Copy_u8Pin * 4));
			/* seeting the CNF and MODE bits  */
			GPIOC_CRH |= (u8Copy_u8Mode) << (Copy_u8Pin * 4);
		}
		break;
	default:
		break;
	}
}

/* setting the value to high or low of a pin in a port */
void MGPIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 u8Copy_u8Value)
{

	switch (Copy_u8Port)
	{
	case GPIOA:
		/* output high to a pin in PORTA */
		if (u8Copy_u8Value == HIGH)
		{
			SET_BIT(GPIOA_ODR, Copy_u8Pin);
		}
		/* output low to a pin in PORTA */
		else if (u8Copy_u8Value == LOW)
		{
			CLR_BIT(GPIOA_ODR, Copy_u8Pin);
		}
		break;

	case GPIOB:
		/* output high to a pin in PORTB */
		if (u8Copy_u8Value == HIGH)
		{
			SET_BIT(GPIOB_ODR, Copy_u8Pin);
		}
		/* output low to a pin in PORTB */
		else if (u8Copy_u8Value == LOW)
		{
			CLR_BIT(GPIOB_ODR, Copy_u8Pin);
		}
		break;

	case GPIOC:
		/* output high to a pin in PORTC */
		if (u8Copy_u8Value == HIGH)
		{
			SET_BIT(GPIOC_ODR, Copy_u8Pin);
		}
		/* output low to a pin in PORTC */
		else if (u8Copy_u8Value == LOW)
		{
			CLR_BIT(GPIOC_ODR, Copy_u8Pin);
		}
		break;
	default:
		break;
	}
}
/* getting the value of a bin in a port */
u8 MGPIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	u8 LOC_u8Result = 0;

	switch (Copy_u8Port)
	{
	case GPIOA:
		LOC_u8Result = GET_BIT(GPIOA_IDR, Copy_u8Pin);
		break;
	case GPIOB:
		LOC_u8Result = GET_BIT(GPIOB_IDR, Copy_u8Pin);
		break;
	case GPIOC:
		LOC_u8Result = GET_BIT(GPIOC_IDR, Copy_u8Pin);
		break;
	}
	return LOC_u8Result;
}
