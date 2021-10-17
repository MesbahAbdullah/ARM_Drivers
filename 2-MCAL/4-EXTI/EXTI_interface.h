/*********************************************************/
/* Author      : Mesbah Abdullah                         */
/* Date        : 16 Oct 2021                             */
/* Version     : V01                                     */
/* Brief       : EXTI driver                             */
/*********************************************************/

#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H
/* line and node */
void MEXTI_voidInit();
void MEXTI_voidEnableEXTI ( u8 Copy_u8Line);
void MEXTI_voidDisableEXTI( u8 Copy_u8Line);
void MEXTI_voidSwTrigger  ( u8 Copy_u8Line);
    
#endif