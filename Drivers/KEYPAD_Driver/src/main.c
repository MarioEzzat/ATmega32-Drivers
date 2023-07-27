/*
 * main.c
 *
 *  Created on: Aug 9, 2022
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

void main(void)
{
	MDIO_voidInit();
	HLCD_voidInit();

	u8 local_u8Value;
	while(1)
	{
		local_u8Value = HKEYPAD_u8GetPressedKey();
		if(local_u8Value != KEY_NOT_PRESSED)
		{
			HLCD_voidSendData(local_u8Value);
		}
	}

}

