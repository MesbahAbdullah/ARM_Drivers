/*********************************************************/
/* Author      : Mesbah Abdullah                         */
/* Date        : 14 Oct 2021                             */
/* Version     : V02                                     */
/* Brief       : NVIC driver                             */
/*********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

void MNVIC_voidEnableInterrupt(u8 Copy_u8IntNumber) /* u8 because max external peripherals are 240 */
{
    if (Copy_u8IntNumber <= 31)
    {
        NVIC_ISER0 = (1 << Copy_u8IntNumber);
    }
    else if (Copy_u8IntNumber <= 59)
    {
        Copy_u8IntNumber -= 32; /* to start form the begining of the register */
        NVIC_ISER1 = (1 << Copy_u8IntNumber);
    }
    else
    {
        /* return error */
    }
}

void MNVIC_voidDisableInterrupt(u8 Copy_u8IntNumber)
{
    if (Copy_u8IntNumber <= 31)
    {
        NVIC_ICER0 = (1 << Copy_u8IntNumber);
    }
    else if (Copy_u8IntNumber <= 59)
    {
        Copy_u8IntNumber -= 32; /* to start form the begining of the register */
        NVIC_ICER1 = (1 << Copy_u8IntNumber);
    }
    else
    {
        /* return error */
    }
}

void MNVIC_voidSetPendingFlag(u8 Copy_u8IntNumber)
{
    if (Copy_u8IntNumber <= 31)
    {
        NVIC_ISPR0 = (1 << Copy_u8IntNumber);
    }
    else if (Copy_u8IntNumber <= 59)
    {
        Copy_u8IntNumber -= 32; /* to start form the begining of the register */
        NVIC_ISPR1 = (1 << Copy_u8IntNumber);
    }
    else
    {
        /* return error */
    }
}

void MNVIC_voidClearPendingFlag(u8 Copy_u8IntNumber)
{
    if (Copy_u8IntNumber <= 31)
    {
        NVIC_ICPR0 = (1 << Copy_u8IntNumber);
    }
    else if (Copy_u8IntNumber <= 59)
    {
        Copy_u8IntNumber -= 32; /* to start form the begining of the register */
        NVIC_ICPR1 = (1 << Copy_u8IntNumber);
    }
    else
    {
        /* return error */
    }
}

u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber)
{
    u8 Local_u8Result;
    if (Copy_u8IntNumber <= 31)
    {
        Local_u8Result = GET_BIT(NVIC_IABR0, Copy_u8IntNumber);
    }
    else if (Copy_u8IntNumber <= 59)
    {
        Copy_u8IntNumber -= 32; /* to start form the begining of the register */
        Local_u8Result = GET_BIT(NVIC_IABR1, Copy_u8IntNumber);
    }
    else
    {
        /* return error */
    }
    return Local_u8Result;
}

void MNVIC_voidSetPriority(s8 Copy_s8IntID, u8 Copy_u8GroupPriority, u8 Copy_u8SupPriority, u32 Copy_u32Group)
{
    /* getting the value of the high part of the 8 bits in IPR register */
    u8 Local_u8Priority = Copy_u8SupPriority | Copy_u8GroupPriority << ((Copy_u32Group - 0X05FA0300) / 265);
    /* is it core peripheral */
    /* is it external peripheral */
    if (Copy_s8IntID >= 0)
    {
        NVIC_IPR[Copy_s8IntID] = Local_u8Priority << 4;
    }
    /* setting the lock */
    SCB_AIRCR = Copy_u32Group;
}