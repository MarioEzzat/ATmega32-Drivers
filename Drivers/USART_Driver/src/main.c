/*
 * main.c
 *
 *  Created on: Aug 26, 2022
 *      Author: Mario Ezzat
 */
#include"../include/LIB/STD_TYPES.h"
#include"../include/LIB/BIT_MATH.h"

#include "../include/MCAL/GI/GI_interface.h"

#include"../include/MCAL/DIO/DIO_interface.h"
#include"../include/MCAL/DIO/DIO_private.h"
#include"../include/MCAL/DIO/DIO_configuration.h"

#include"../include/MCAL/USART/USART_interface.h"
#include"../include/MCAL/USART/USART_private.h"
#include"../include/MCAL/USART/USART_configuration.h"

#include <util/delay.h>

#define F_CPU 8000000UL


void main(void)
{
	MDIO_voidInit();
	MUSART_voidInit();
	u8 local_u8Value = 1;
	while(1)
	{
		MUSART_voidSendStringSynchBlocking("MARIO\r\n");
	}
}
