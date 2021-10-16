/*********************************************************/
/* Author      : Mesbah Abdullah                         */
/* Date        : 14 Oct 2021                             */
/* Version     : V02                                     */
/* Brief       : NVIC driver                             */
/*********************************************************/

#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

/* Interrupt set-enable registers */
#define NVIC_ISER0 *((volatile u32 *)0xE000E100) /* Enable external interrupt from 0 to 31  */
#define NVIC_ISER1 *((volatile u32 *)0xE000E104) /* Enable external interrupt from 32 to 63 */

/* Interrupt clear-enable registers */
#define NVIC_ICER0 *((volatile u32 *)0xE000E180) /* Disbale external interrupt from 0 to 31  */
#define NVIC_ICER1 *((volatile u32 *)0xE000E184) /* Disbale external interrupt from 32 to 63 */

/* Interrupt set-pending registers */
#define NVIC_ISPR0 *((volatile u32 *)0xE000E200) /*force interrupts into the pending state from 0 to 31  */
#define NVIC_ISPR1 *((volatile u32 *)0xE000E204) /*force interrupts into the pending state from 32 to 63 */

/* Interrupt clear-pending registers */
#define NVIC_ICPR0 *((volatile u32 *)0xE000E280) /* remove the pending state from interrupts 0 to 31  */
#define NVIC_ICPR1 *((volatile u32 *)0xE000E284) /* remove the pending state from interrupts 32 to 63 */

/* Interrupt active bit registers (read only) */
#define NVIC_IABR0 *((volatile u32 *)0xE000E300)
#define NVIC_IABR1 *((volatile u32 *)0xE000E304)

/* Interrupt priority registers */
#define NVIC_IPR   ((volatile u8 *)0xE000E400)

/* System control block peripheral                  */
/* Application interrupt and reset control register */
#define SCB_AIRCR  *((volatile u32 *)0xE000ED0C)

#endif