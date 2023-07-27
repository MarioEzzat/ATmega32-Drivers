/*
 * main.c
 *
 *  Created on: Aug 16, 2022
 *      Author: Mario Ezzat
 */
#include"../include/LIB/STD_TYPES.h"
#include"../include/LIB/BIT_MATH.h"


#include"../include/MCAL/DIO/DIO_interface.h"
#include "../include/MCAL/ADC/ADC_interface.h"
#include "../include/HAL/LCD/LCD_interface.h"
#include <util/delay.h>


void main(void)
{
	MDIO_voidInit();
	MADC_voidInit();
	HLCD_voidInit();
	u16 Digital = 0;
	u32 Analog  = 0;

	while(1)
	{
		Digital = MADC_u16GetDigitalValue(0);
		Analog = (u32)((Digital*5000UL)/1024);
		Analog= Analog/10;
		HLCD_voidDisplayNumber(Analog);
		_delay_ms(500);
		HLCD_voidClearDisplay();

	}
}
