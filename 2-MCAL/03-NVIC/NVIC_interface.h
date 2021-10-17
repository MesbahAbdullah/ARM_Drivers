/*********************************************************/
/* Author      : Mesbah Abdullah                         */
/* Date        : 14 Oct 2021                             */
/* Version     : V02                                     */
/* Brief       : NVIC driver                             */
/*********************************************************/

#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

/* controlling the IPR */

/* 4 bits for group and 0 bit for sup group  */ 
#define GROUP3      0X05FA0300
/* 3 bits for group and 1 bit for sup group  */
#define GROUP4      0X05FA0400
/* 2 bits for group and 2 bits for sup group */
#define GROUP5      0X05FA0500
/* 1 bit for group and 3 bits for sup group  */
#define GROUP6      0X05FA0600
/* 0 bit for group and 4 bits for sup group  */
#define GROUP7      0X05FA0700

void MNVIC_voidEnableInterrupt (u8 Copy_u8IntNumber);
void MNVIC_voidDisableInterrupt(u8 Copy_u8IntNumber);

void MNVIC_voidSetPendingFlag  (u8 Copy_u8IntNumber);
void MNVIC_voidClearPendingFlag(u8 Copy_u8IntNumber);

u8 MNVIC_u8GetActiveFlag       (u8 Copy_u8IntNumber);

void MNVIC_voidSetPriority(s8 Copy_s8IntID, u8 Copy_u8GroupPriority, u8 Copy_u8SupPriority, u32 Copy_u32Group);

#endif