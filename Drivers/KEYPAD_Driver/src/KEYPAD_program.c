/*
 * KEYPAD_program.c
 *
 *  Created on: Aug 8, 2022
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

#include"../include/HAL/KEYPAD/KEYPAD_interface.h"
#include"../include/HAL/KEYPAD/KEYPAD_private.h"
#include"../include/HAL/KEYPAD/KEYPAD_configuration.h"

#include <util/delay.h>
#define  F_CPU 8000000UL


u8 KEYPAD_Au8RowsPins[ROWS_NUMBER] = ROWS_PINS ;
u8 KEYPAD_Au8ColsPins[COLS_NUMBER] = COLS_PINS ;

u8 KEYPAD_Au8Keys[ROWS_NUMBER][COLS_NUMBER] = KEYPAD_KEYS;
u8 HKEYPAD_u8GetPressedKey(void)
{
	u8 local_u8RowCounter, local_u8ColCounter, local_u8PinValue, local_u8KeyValue = KEY_NOT_PRESSED, local_u8Flag = FLAG_DOWN;

	/* ROWS CHECK LOOP */
	for(local_u8RowCounter = START_LOOP; (local_u8RowCounter<ROWS_NUMBER)&&(local_u8Flag == FLAG_DOWN); local_u8RowCounter++)
	{
		/* ACTIVATE ONE ROW */
		MDIO_voidSetPinValue(KEYPAD_PORT,KEYPAD_Au8RowsPins[local_u8RowCounter],PIN_LOW);

		/* CLOUMNS CHECK LOOP */
		for(local_u8ColCounter =START_LOOP; (local_u8ColCounter < COLS_NUMBER) &&(local_u8Flag == FLAG_DOWN); local_u8ColCounter++)
		{
			/* CHECK COLUMN ONE BY ONE */
			local_u8PinValue = MDIO_u8GetPinValue(KEYPAD_PORT,KEYPAD_Au8ColsPins[local_u8ColCounter]);

			/* IF THE KEY IS PRESSED */
			if(local_u8PinValue == PIN_LOW)
			{
				/* DELAY FOR DEBOUNCING */
				_delay_ms(DEBOUNCING_DELAY);

				/* READ THE KEY AGAIN TILL THE PIN RETURN TO HIGH  */
				local_u8PinValue = MDIO_u8GetPinValue(KEYPAD_PORT,KEYPAD_Au8ColsPins[local_u8ColCounter]);
				while(local_u8PinValue == PIN_LOW){local_u8PinValue = MDIO_u8GetPinValue(KEYPAD_PORT,KEYPAD_Au8ColsPins[local_u8ColCounter]);}
				/*SAVE THE VALUE OF THE KEY*/
				local_u8KeyValue = KEYPAD_Au8Keys[local_u8RowCounter][local_u8ColCounter];

				/* THE KEY IS FOUND*/
				local_u8Flag = FLAG_UP;
			}
		}
		/*DEACTIVATE THE ROW BEFOR BREAKING THE LOOP*/
		MDIO_voidSetPinValue(KEYPAD_PORT,KEYPAD_Au8RowsPins[local_u8RowCounter],PIN_HIGH);
	}
	return local_u8KeyValue;
}
