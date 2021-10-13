/*********************************************************/
/* Author      : Mesbah Abdullah                         */
/* Date        : 11 Aug 2020                             */
/* Version     : V01                                     */
/* Brief       : RCC driver                              */
/*********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

/* choose clock source */
void RCC_voidInitSysClock()
{
#if RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
    SET_BIT(RCC_CR, 16);  /* Enaple HSE crystal mode      */
    SET_BIT(RCC_CFGR, 0); /* choose HSE as a System clock */
    CLR_BIT(RCC_CFGR, 1); /* choose HSE as a System clock */

#elif RCC_CLOCK_TYPE == RCC_HSE_RC
    SET_BIT(RCC_CR, 18);  /* oscillator bypassed          */
    SET_BIT(RCC_CR, 16);  /* Enaple HSE RC mode           */
    SET_BIT(RCC_CFGR, 0); /* choose HSE as a System clock */
    CLR_BIT(RCC_CFGR, 1); /* choose HSE as a System clock */

#elif RCC_CLOCK_TYPE == RCC_HSI
    SET_BIT(RCC_CR, 0);   /* Enable HSI no trimming       */
    CLR_BIT(RCC_CFGR, 0); /* choose HSI as a System clock */
    CLR_BIT(RCC_CFGR, 1); /* choose HSI as a System clock */

#elif RCC_CLOCK_TYPE == RCC_PLL
    /* mul value */
    RCC_CFGR &= ~((0b1111) << 18);
    RCC_CFGR |= (RCC_PLL_MUL_VAL) << 18;

#if RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
    SET_BIT(RCC_CR, 1);    /* Enable HSI                   */
    RCC_CFGR = 0x00000000; /* HSI as input for pll div by 2*/

#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_CRYSTAL_DIV_2
    SET_BIT(RCC_CR, 16);   /* Enable HSE                    */
    SET_BIT(RCC_CFGR, 16); /* HSE as input for PLL          */
    SET_BIT(RCC_CFGR, 17); /* HSE as input for PLL DIV by 2 */

#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_RC_DIV_2
    SET_BIT(RCC_CR, 18);   /* oscillator bypassed           */
    SET_BIT(RCC_CR, 16);   /* Enable HSE                    */
    SET_BIT(RCC_CFGR, 16); /* HSE as input for PLL          */
    SET_BIT(RCC_CFGR, 17); /* HSE as input for PLL DIV by 2 */
#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_CRYSTAL
    SET_BIT(RCC_CR, 16);   /* Enable HSE                    */
    SET_BIT(RCC_CFGR, 16); /* HSE as input for PLL          */
    CLR_BIT(RCC_CFGR, 17); /* HSE as input for PLL not DIV by 2 */
#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_RC
    SET_BIT(RCC_CR, 18);   /* oscillator bypassed           */
    SET_BIT(RCC_CR, 16);   /* Enable HSE                    */
    SET_BIT(RCC_CFGR, 16); /* HSE as input for PLL          */
    CLR_BIT(RCC_CFGR, 17); /* HSE as input for PLL not DIV by 2 */
#endif
    SET_BIT(RCC_CR, 24);   // Enable PLL
    while (GET_BIT(RCC_CR, 25) == 0)
        ;                  /* waiting PLL to be ready*/
    RCC_CFGR = 0X00000002; // choose PLL as a System clock
#else
#error("you choses wrong clock type")
#endif
}

/* Ebable RCC for peripheral */
void RCC_voidEnableClock(u8 Copy_u8BusName, u8 Copy_u8PerName)
{
    if (Copy_u8PerName <= 31)
    {
        switch (Copy_u8BusName)
        {
        case RCC_AHB:
            SET_BIT(RCC_AHBENR, Copy_u8PerName);
            break;
        case RCC_APB1:
            SET_BIT(RCC_APB1ENR, Copy_u8PerName);
            break;
        case RCC_APB2:
            SET_BIT(RCC_APB2ENR, Copy_u8PerName);
            break;
        default:
            /* Return Error*/
            break;
        }
    }
    else
    {
        /* Return Error */
    }
}

/* disable the RCC for peripheral */
void RCC_voidDisableClock(u8 Copy_u8BusName, u8 Copy_u8PerName)
{
    if (Copy_u8PerName <= 31)
    {
        switch (Copy_u8BusName)
        {
        case RCC_AHB:
            CLR_BIT(RCC_AHBENR, Copy_u8PerName);
            break;
        case RCC_APB1:
            CLR_BIT(RCC_APB1ENR, Copy_u8PerName);
            break;
        case RCC_APB2:
            CLR_BIT(RCC_APB2ENR, Copy_u8PerName);
            break;
        default: /* Return Error*/
            break;
        }
    }
    else
    {
        /* Return Error */
    }
}
