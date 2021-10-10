/*********************************************************/
/* Author      : Mesbah Abdullah                         */
/* Date        : 29 Jul 2020                             */
/* Version     : V01                                     */
/* Brief       : BIT Math library                        */
/*********************************************************/

#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(VAR,BIT)        VAR |=  (1<<(BIT)  )
#define CLR_BIT(VAR,BIT)        VAR &= ~(1<<(BIT)  )
#define GET_BIT(VAR,BIT)        ((VAR >> BIT) & 1  )
#define TOG_BIT(VAR,BIT)        VAR ^=  (1 <<(BIT) )
#define BIT_IS_CLEAR(REG,BIT)   ( !(REG & (1<<BIT)))
#endif  

