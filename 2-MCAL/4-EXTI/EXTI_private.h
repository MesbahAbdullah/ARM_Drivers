/*********************************************************/
/* Author      : Mesbah Abdullah                         */
/* Date        : 16 Oct 2021                             */
/* Version     : V01                                     */
/* Brief       : EXTI driver                             */
/*********************************************************/

#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

#define LINE_0 0
#define LINE_1 1
#define LINE_2 2
#define LINE_3 3
#define LINE_4 4
#define LINE_5 5
#define LINE_6 6
#define LINE_7 7
#define LINE_8 8
#define LINE_9 9
#define LINE_10 10
#define LINE_11 11
#define LINE_12 12
#define LINE_13 13
#define LINE_14 14
#define LINE_15 15

typedef struct
{
    u32 EXTI_IMR;
    u32 EXTI_EMR;
    u32 EXTI_RSTR;
    u32 EXTI_FTSR;
    u32 EXTI_SWIER;
    u32 EXTI_PR;
} EXTI_t;

#define EXTI ((volatile EXTI_t *)0x40010400)

#endif