/*********************************************************/
/* Author      : Mesbah Abdullah                         */
/* Date        : 11 Aug 2020                             */
/* Version     : V01                                     */
/* Brief       : RCC driver                              */
/*********************************************************/

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#define RCC_AHB      0
#define RCC_APB1     1
#define RCC_APB2     2

void RCC_voidInitSysClock();
void RCC_voidEnableClock (u8 Copy_u8BusName,u8 Copy_u8PerName);
void RCC_voidDisableClock(u8 Copy_u8BusName,u8 Copy_u8PerName);

#endif