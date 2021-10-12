/*********************************************************/
/* Author      : Mesbah Abdullah                         */
/* Date        : 11 Aug 2020                             */
/* Version     : V01                                     */
/* Brief       : RCC driver                              */
/*********************************************************/

#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/*********************************************************/
/*1-RCC_HSE_CRYSTAL                                      */
/*2-RCC_HSE_RC                                           */
/*3-RCC_HSI                                              */
/*4-RCC_PLL                                              */
/*********************************************************/
#define RCC_CLOCK_TYPE      RCC_HSI

#if RCC_CLOCK_TYPE == RCC_PLL

/*********************************************************/
/*1-RCC_PLL_IN_HSI_DIV_2                                 */
/*2-RCC_PLL_IN_HSE_CRYSTAL_DIV_2                         */
/*3-RCC_PLL_IN_HSE_RC_DIV_2                              */
/*4-RCC_PLL_IN_HSE_CRYSTAL                               */
/*5-RCC_PLL_IN_HSE_RC                                    */
/*********************************************************/
#define RCC_PLL_INPUT       RCC_PLL_IN_HSE_CRYSTAL_DIV_2

/*********************************************************/
/*1-PLL_CLOCK_MUL_BY_2                                   */
/*2-PLL_CLOCK_MUL_BY_3                                   */
/*3-PLL_CLOCK_MUL_BY_4                                   */
/*4-PLL_CLOCK_MUL_BY_5                                   */
/*5-PLL_CLOCK_MUL_BY_6                                   */
/*6-PLL_CLOCK_MUL_BY_7                                   */
/*7-PLL_CLOCK_MUL_BY_8                                   */
/*8-PLL_CLOCK_MUL_BY_9                                   */
/*9-PLL_CLOCK_MUL_BY_10                                  */
/*10-PLL_CLOCK_MUL_BY_11                                 */
/*11-PLL_CLOCK_MUL_BY_12                                 */
/*12-PLL_CLOCK_MUL_BY_13                                 */
/*13-PLL_CLOCK_MUL_BY_14                                 */
/*14-PLL_CLOCK_MUL_BY_15                                 */
/*15-PLL_CLOCK_MUL_BY_16                                 */
/*********************************************************/
#define RCC_PLL_MUL_VAL         PLL_CLOCK_MUL_BY_4

#endif

/*MUL VAL 2 TO 16 */
#endif
