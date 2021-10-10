/*********************************************************/
/* Author      : Mesbah Abdallah                         */
/* Date        : 24 OCT 2020                             */
/* Version     : V01                                     */
/* Brief       : SD   driver                             */
/*********************************************************/

#ifndef PRIVATE_H
#define PRIVATE_H

/* to send SD_CMD */

#define HSD_CMD0    0,0x00000000,0x94  
#define HSD_CMD8    8,0x0000001AA,0x86
#define HSD_CMD58   58,0x00000000,0x00
#define HSD_CMD55   55,0x00000000,0x00
#define HSD_ACMD41  41,0x40000000,0x00



#define CMD17                   17
#define CMD17_CRC               0x00
#define SD_MAX_READ_ATTEMPTS    1563


#define HSD_SUCCESS  1
#define HSD_ERROR    0

#endif