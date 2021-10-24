/*********************************************************/
/* Author      : Mesbah Abdullah                         */
/* Date        : 16 Oct 2021                             */
/* Version     : V01                                     */
/* Brief       : EXTI driver                             */
/*********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

void MEXTI_voidInit()
{
#if EXTI_MODE == RISING
    SET_BIT(EXTI->EXTI_RTSR, EXTI_LINE);
#elif EXTI_MODE == FAILING
    SET_BIT(EXTI->EXTI_FTSR, EXTI_LINE);
#elif EXTI_MODE == ON_CHANGE
    SET_BIT(EXTI->EXTI_RTSR, EXTI_LINE);
    SET_BIT(EXTI->EXTI_FTSR, EXTI_LINE);
#else
    /* ERROR */
#endif
    /* Disable interrupt */
}
void MEXTI_voidEnableEXTI(u8 Copy_u8Line)
{
    SET_BIT(EXTI->EXTI_IMR, Copy_u8Line);
}
void MEXTI_voidDisableEXTI(u8 Copy_u8Line)
{
    CLR_BIT(EXTI->EXTI_IMR, Copy_u8Line);
}
/* SW interrupt */
void MEXTI_voidSwTrigger(u8 Copy_u8Line)
{
    SET_BIT(EXTI->EXTI_SWIER, Copy_u8Line);
}

/* changing in run time */
void MEXTI_voidSetSignalLatch(u8 Copy_u8Line, u8 Copy_u8Mode)
{
    switch (Copy_u8Mode)
    {
    case RISING:
        SET_BIT(EXTI->EXTI_RTSR, EXTI_LINE);
        break;
    case FALLING:
        SET_BIT(EXTI->EXTI_FTSR, EXTI_LINE);
        break;
    case ON_CHANGE:
        SET_BIT(EXTI->EXTI_RTSR, EXTI_LINE);
        SET_BIT(EXTI->EXTI_FTSR, EXTI_LINE);
        break;
    default:
        /* Error */
        break;
    }
}
