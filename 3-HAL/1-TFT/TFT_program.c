/*********************************************************/
/* Author      : Mesbah Abdallah                         */
/* Date        : 20 OCT 2020                             */
/* Version     : V01                                     */
/* Brief       : TFT  driver                             */
/*********************************************************/
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "SPI_interface.h"
#include "SYSTICK_interface.h"

#include "TFT_interface.h"
#include "TFT_private.h"
#include "TFT_config.h"

void HTFT_voidInit(void)
{
    /* Reset Pulse */
    MGPIO_VidSetPinValue(TFT_RST_PIN, HIGH);
    MSTK_voidSetBusyWait(100);
    MGPIO_VidSetPinValue(TFT_RST_PIN, LOW);
    MSTK_voidSetBusyWait(1);
    MGPIO_VidSetPinValue(TFT_RST_PIN, HIGH);
    MSTK_voidSetBusyWait(100);
    MGPIO_VidSetPinValue(TFT_RST_PIN, LOW);
    MSTK_voidSetBusyWait(100);
    MGPIO_VidSetPinValue(TFT_RST_PIN, HIGH);
    MSTK_voidSetBusyWait(120000); /* end of Rest Pulse*/
    /* sleep out command */
    voidWriteCommand(0x11);
    /* wait 150 ms */
    MSTK_voidSetBusyWait(150000);
    /*color mode command */
    voidWriteCommand(0x3A);
    voidWriteData(0x05);
    /* display on command */
    voidWriteCommand(0x29);
}
void HTFT_voidDispalyImage(const u16 *Copy_Image)
{
    /*set x address*/
    voidWriteCommand(0x2A);
    /* start point  */
    voidWriteData(0);
    voidWriteData(0);
    /* end point */
    voidWriteData(0);
    voidWriteData(127);
    /*set y address*/
    voidWriteCommand(0x2B);
    /* start point */
    voidWriteData(0);
    voidWriteData(0);
    /* end point */
    voidWriteData(0);
    voidWriteData(159);
    /* RAM write*/
    voidWriteCommand(0x2c);
    voidWriteData(0xff);
    for (u16 i = 0; i < 20480; i++)
    {
        /* write the high byte */
        voidWriteData(Copy_Image[i] >> 8);
        /* write the low byte */
        voidWriteData(Copy_Image[i] && 0x00ff);
    }
}
/* static to make it only used here private function */
static void voidWriteCommand(u8 Copy_u8Command)
{
    u8 Local_u8Temp;
    /* set A0 pin to low */
    MGPIO_VidSetPinValue(TFT_A0_PIN, LOW);
    /* send command via SPI */
    MSPI1_VoidSendReciveSynch(Copy_u8Command, &Local_u8Temp);
}
static void voidWriteData(u8 Copy_u8Data)
{
    /* no need for that */
    u8 Local_u8Temp;
    /* set A0 pin to high to send data */
    MGPIO_VidSetPinValue(TFT_A0_PIN, HIGH);
    /* send data via SPI */
    MSPI1_voidSendReciveSynch(Copy_u8Data, &Local_u8Temp);
}
