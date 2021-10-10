/*********************************************************/
/* Author      : Mesbah Abdallah                         */
/* Date        : 24 OCT 2020                             */
/* Version     : V01                                     */
/* Brief       : SD   driver                             */
/*********************************************************/

#ifndef INTERFACE_H
#define INTERFACE_H

/* sd initialization*/
void HSD_voidInit();
u8 HSD_u8Command(u8 cmd, u32 arg, u8 crc);
u8 HSD_readRes1();
u8 HSD_Response();
u8 HSD_readSingleBlock(u32 addr, u8 *buf, u8 *token);
void HSD_Init();

#endif