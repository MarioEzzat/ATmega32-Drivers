/*
 * main.c
 *
 *  Created on: Aug 27, 2022
 *      Author: Mario Ezzat
 */

#include"../include/LIB/STD_TYPES.h"
#include"../include/LIB/BIT_MATH.h"

#include"../include/MCAL/DIO/DIO_interface.h"
#include"../include/MCAL/DIO/DIO_private.h"
#include"../include/MCAL/DIO/DIO_configuration.h"

#include"../include/MCAL/TIMER/TIMER_interface.h"
#include"../include/MCAL/TIMER/TIMER_private.h"
#include"../include/MCAL/TIMER/TIMER_configuration.h"

#include"../include/HAL/SERVO/SERVO_interface.h"
#include"../include/HAL/SERVO/SERVO_private.h"
#include"../include/HAL/SERVO/SERVO_configuration.h"

#include <util/delay.h>
void main(void)
{
	MDIO_voidInit();
	MTIMER1_voidInit();
//	HSERVO_voidCCW(OCR1B_PIN);
//	_delay_ms(1000);
//	HSERVO_voidCW(OCR1B_PIN);
	u16 i;
	while(1)
	{
		for(i=0;i<=2000;i++)
		{
			HSERVO_voidSetServoAngle(OCR1B_PIN,i);
			_delay_ms(100);
		}
	}

}
