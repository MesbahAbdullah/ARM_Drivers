/*********************************************************/
/* Author      : Mesbah Abdallah                         */
/* Date        : 24 OCT 2020                             */
/* Version     : V01                                     */
/* Brief       : SD   driver                             */
/*********************************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "SPI_interface.h"

#include "SD_interface.h"
#include "SD_private.h"
#include "SD_config.h"
/* initalizing SD*/
void HSD_Init()
{
    u8 Nothing_here;
    MGPIO_VoidSetPinValue(MSPI1_SLAVE_PIN,LOW);
    // give SD card time to power up
    MSTK_voidSetBusyWait(1000);
    // send 80 clock cycles to synchronize
    for(u8 i = 0; i < 10; i++)
        MSPI1_SendReciveSynch(0xff,&Nothing_here)

    // deselect SD card
    MGPIO_VoidSetPinValue(MSPI1_SLAVE_PIN,LOW);
    MSPI1_SendReciveSynch(0xff,&Nothing_here)
}

u8 HSD_u8Command(u8 cmd, u32 arg, u8 crc)
{
    
    u8 Temp=0;
        MGPIO_VoidSetPinValue(MSPI1_SLAVE_PIN,HIGH);

    // transmit command to sd card
    MSPI1_SendReciveSynch((cmd|0x40),&Temp);
   
    // transmit argument
    MSPI1_SendReciveSynch((u8)(arg >> 24),&Temp);
    MSPI1_SendReciveSynch((u8)(arg >> 16),&Temp);
    MSPI1_SendReciveSynch((u8)(arg >> 8),&Temp);
    MSPI1_SendReciveSynch((u8)(arg),&Temp);

    // transmit crc
    MSPI1_SendReciveSynch((crc|0x01),&Temp);
    MGPIO_VoidSetPinValue(MSPI1_SLAVE_PIN,LOW);       

    return Response;
}
u8 HSD_Response()
{
    u8 temp;
    u8 Rresponse[4]={0};

    Rresponse[0] = MSPI1_SendReciveSynch();
    Rresponse[1] = MSPI1_SendReciveSynch();
    Rresponse[2] = MSPI1_SendReciveSynch();
    Rresponse[3] = MSPI1_SendReciveSynch();
    Rresponse[4] = MSPI1_SendReciveSynch();
    return Rresponse;
}

u8 HSD_readRes1()
{
    u8 i = 0, res1;
    u8 Temp;
    // keep polling until actual data received
    while((res1 = MSPI1_SendReciveSynch(0xFF),&Temp) == 0xFF)
    {
        i++;
        // if no data received for 8 bytes, break
        if(i > 8) break;
    }

    return res1;
}
/*******************************************************************************
 Read single 512 byte block
 token = 0xFE - Successful read
 token = 0x0X - Data error
 token = 0xFF - Timeout
*******************************************************************************/
u8 HSD_readSingleBlock(u32 addr, u8 *buf, u8 *token)
{
    u8 res1, read;
    u16 readAttempts;
    u8 temp=0;
    // set token to none
    *token = 0xFF;

    // assert chip select
    MSPI1_SendReciveSynch(0xFF,&temp);
    MGPIO_VoidSetPinValue(MSPI1_SLAVE_PIN,HIGH);

    MSPI1_SendReciveSynch(0xFF,&temp);

    // send CMD17
    HSD_u8Command(CMD17, addr, CMD17_CRC);

    // read R1
    res1 = HSD_readRes1();

    // if response received from card
    if(res1 != 0xFF)
    {
        // wait for a response token (timeout = 100ms)
        readAttempts = 0;
        while(++readAttempts != SD_MAX_READ_ATTEMPTS)
            if((read = MSPI1_SendReciveSynch(0xFF,&temp)) != 0xFF) break;

        // if response token is 0xFE
        if(read == 0xFE)
        {
            // read 512 byte block
            for(u16 i = 0; i < 512; i++) *buf++ = MSPI1_SendReciveSynch(0xFF,&temp);

            // read 16-bit CRC
            MSPI1_SendReciveSynch(0xFF,&temp);
            MSPI1_SendReciveSynch(0xFF,&temp);
        }

        // set token to card response
        *token = read;
    }

    // deassert chip select
    MSPI1_SendReciveSynch(0xFF,&temp);
    MGPIO_VoidSetPinValue(MSPI1_SLAVE_PIN,LOW);
    MSPI1_SendReciveSynch(0xFF,&temp);

    return res1;
}