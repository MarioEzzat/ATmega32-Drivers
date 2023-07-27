/*
 * main.c
 *
 *  Created on: Aug 5, 2022
 *      Author: Mario Ezzat
 */
#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"

#include "../include/MCAL/DIO/DIO_interface.h"
#include "../include/MCAL/DIO/DIO_private.h"
#include "../include/MCAL/DIO/DIO_configuration.h"

#include "../include/HAL/LCD/LCD_interface.h"
#include "../include/HAL/LCD/LCD_private.h"
#include "../include/HAL/LCD/LCD_configuration.h"

#include <util/delay.h>

void main(void)
{
	MDIO_voidInit();
	HLCD_voidInit();
	HLCD_voidSendString("MARIO");

	while (1)
	{
	}
}
