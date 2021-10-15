/*********************************************************/
/* Author      : Mesbah Abdullah                         */
/* Date        : 14 Oct 2021                             */
/* Version     : V02                                     */
/* Brief       : NVIC driver                             */
/*********************************************************/

#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

void MNVIC_voidEnableInterrupt (u8 Copy_u8IntNumber);
void MNVIC_voidDisableInterrupt(u8 Copy_u8IntNumber);

void MNVIC_voidSetPendingFlag  (u8 Copy_u8IntNumber);
void MNVIC_voidClearPendingFlag(u8 Copy_u8IntNumber);

u8 MNVIC_u8GetActiveFlag       (u8 Copy_u8IntNumber);
#endif