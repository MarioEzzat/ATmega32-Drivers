/*
 * main.c
 *
 *  Created on: Aug 3, 2022
 *      Author: abdelrahmanhossam
 */

#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"

#include <util/delay.h>
#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/DIO/DIO_priivate.h"
#include "../Include/MCAL/DIO/DIO_configuration.h"



#include "../Include/MCAL/GI/GI_interface.h"
#include "../Include/MCAL/GI/GI_private.h"
#include "../Include/MCAL/GI/GI_configuration.h"

#include"../Include/MCAL/UART/UART_Interface.h"
#include"../Include/MCAL/UART/UART_Private.h"
#include"../Include/MCAL/UART/UART_Configuration.h"

#define F_CPU 8000000UL
void main(void)
{

	MDIO_voidInit();
	UART_voidInit();
	u8 local_value = 0;
	while (1)
	{

		UART_voidSendByteSynchBlocking('Q');
		local_value = UART_u8READByteSynchNonBlocking();
		if (local_value == 'a')
		{
			MDIO_voidSetPinValue(PORTA, PIN0, PIN_HIGH);
		}
		else if (local_value == 'o')
		{
			MDIO_voidSetPinValue(PORTA, PIN0, PIN_LOW);
		}
	}
}
