/*
 * LCD_program.c
 *
 *  Created on: Aug 5, 2022
 *      Author: Mario Ezzat
 */
#include"../include/LIB/STD_TYPES.h"
#include"../include/LIB/BIT_MATH.h"


#include"../include/MCAL/DIO/DIO_interface.h"
#include"../include/MCAL/DIO/DIO_private.h"
#include"../include/MCAL/DIO/DIO_configuration.h"

#include"../include/HAL/LCD/LCD_interface.h"
#include"../include/HAL/LCD/LCD_private.h"
#include"../include/HAL/LCD/LCD_configuration.h"

#include <util/delay.h>
#define  F_CPU 8000000UL


void HLCD_voidSendCommand(u8 A_u8Command)
{
    /*    RS --> 0 , RW --> 0 */
    MDIO_voidSetPinValue(LCD_CONTROL_PORT, RS_PIN, PIN_LOW);
    MDIO_voidSetPinValue(LCD_CONTROL_PORT, RW_PIN, PIN_LOW);

    /* SEND COMMAND TO LCD */
    MDIO_voidSetPortValue(LCD_DATA_PORT, A_u8Command);

    /* SET PULSE ON ENABLE PIN WITH 2 (MS) DELAY */
    MDIO_voidSetPinValue(LCD_CONTROL_PORT, EN_PIN, PIN_HIGH);
    _delay_ms(2);
    MDIO_voidSetPinValue(LCD_CONTROL_PORT, EN_PIN, PIN_LOW);
}

void HLCD_voidSendData(u8 A_u8Data)
{
    /*   RS --> 1 , RW --> 0 */
    MDIO_voidSetPinValue(LCD_CONTROL_PORT, RS_PIN, PIN_HIGH);
    MDIO_voidSetPinValue(LCD_CONTROL_PORT, RW_PIN, PIN_LOW);

    /* SEND COMMAND TO LCD */
    MDIO_voidSetPortValue(LCD_DATA_PORT, A_u8Data);

    /* SET PULSE ON ENABLE PIN WITH 2 (MS) DELAY */
    MDIO_voidSetPinValue(LCD_CONTROL_PORT, EN_PIN, PIN_HIGH);
    _delay_ms(2);
    MDIO_voidSetPinValue(LCD_CONTROL_PORT, EN_PIN, PIN_LOW);
}

void HLCD_voidInit(void)
{
    /* WAIT FOR MORE THAN 30(MS) AFTER VDD RISES TO 4.5(V) */
    _delay_ms(30);

    /* FUNCTION SET THEN WAIT FOR MORE THAN 39(MS) */
    HLCD_voidSendCommand(FUNCTION_SET);
    _delay_ms(1);

    /* DISPLAY ON/OFF COMTROL THEN WAIT MORE THAN 39(MS) */
    HLCD_voidSendCommand(DISPLAY_ON_OFF_CONTROL);
    _delay_ms(1);

    /* DISPLAY CLEAR THEN WAIT MORE THAN 1.53(MS) */
    HLCD_voidSendCommand(DISPLAY_CLEAR);
    _delay_ms(2);
    /* ENTRY MODE SET */
    HLCD_voidSendCommand(ENTRY_MODE_SET);

    /* End of Initialization */
}

void HLCD_voidClearDisplay(void)
{
	 /* DISPLAY CLEAR THEN WAIT MORE THAN 1.53(MS) */
	HLCD_voidSendCommand(DISPLAY_CLEAR);
    _delay_ms(2);
}

void HLCD_voidSendString(u8 *A_Pu8String)
{
    /* WHILE CHAR NOT EQUAL NULL*/
	while (*A_Pu8String > 0)
    {
        HLCD_voidSendData(*A_Pu8String++);
    }
}
void HLCD_voidGoToPos(u8 A_u8RowNum, u8 A_u8ColNum)
{
	switch(A_u8RowNum)
	{
	case LCD_ROW_ONE: HLCD_voidSendCommand(LCD_ROW_ONE_ADDRESS + A_u8ColNum);
					  break;
	case LCD_ROW_TWO: HLCD_voidSendCommand(LCD_ROW_TWO_ADDRESS + A_u8ColNum);
	 	 	 	 	  break;
	default:
			break;

	}
}
void HLCD_voidDisplayNumber(u32 A_u32Number)
{
	u32 local_u32Number = 1;
	if(A_u32Number == 0)
	{
		HLCD_voidSendData('0');
	}
	else
	{
		while(A_u32Number != 0)
		{
			local_u32Number =((local_u32Number * 10) + (A_u32Number % 10));
			A_u32Number = A_u32Number / 10;
		}
		while(local_u32Number != 1)
		{
			/* SEND DATA IN ASCI CODE(+48) */
			HLCD_voidSendData((local_u32Number%10)+48);
			local_u32Number = local_u32Number / 10;
		}
	}
}
