/*
 * SSD_program.c
 *
 *  Created on: Aug 4, 2022
 *      Author: Mario Ezzat
 */
#include"../include/LIB/STD_TYPES.h"
#include"../include/LIB/BIT_MATH.h"

#include"../include/MCAL/DIO/DIO_interface.h"
#include"../include/MCAL/DIO/DIO_private.h"
#include"../include/MCAL/DIO/DIO_configuration.h"

#include "../include/HAL/SSD/SSD_interface.h"
#include "../include/HAL/SSD/SSD_private.h"
#include "../include/HAL/SSD/SSD_configuration.h"
#include <util/delay.h>
#define F_CPU 8000000UL
#define ZERO  0b00111111
#define ONE   0b00000110
#define TWO   0b01011011
#define THREE 0b01001111
#define FOUR  0b01100110
#define FIVE  0b01101101
#define SIX   0b01111101
#define SEVEN 0b00000111
#define EIGHT 0b01111111
#define NINE  0b01101111


// SSD_PORT:- SSD_configuration.h
void HSSD_voidDisplay(u8 A_u8Number)
{
	switch(A_u8Number)
	{
	case ZERO:
			MDIO_voidSetPortValue(SSD_PORT, ZERO);
			break;
	case ONE:
			MDIO_voidSetPortValue(SSD_PORT, ONE);
			break;
	case TWO:
			MDIO_voidSetPortValue(SSD_PORT, TWO);
			break;
	case THREE:
			MDIO_voidSetPortValue(SSD_PORT, THREE);
			break;
	case FOUR:
			MDIO_voidSetPortValue(SSD_PORT, FOUR);
			break;
	case FIVE:
			MDIO_voidSetPortValue(SSD_PORT, FIVE);
			break;
	case SIX:
			MDIO_voidSetPortValue(SSD_PORT, SIX);
			break;
	case SEVEN:
			MDIO_voidSetPortValue(SSD_PORT, SEVEN);
			break;
	case EIGHT:
			MDIO_voidSetPortValue(SSD_PORT, EIGHT);
			break;
	case NINE:
			MDIO_voidSetPortValue(SSD_PORT, NINE);
			break;
	default: break;
	}
}

// PORT ID:- PORTA - PORTB - PORTC - PORTD
void HSSD_voidDisplayByPort(u8 A_u8PortId,u8 A_u8Number)
{
	switch(A_u8Number)
	{
	case ZERO:
			MDIO_voidSetPortValue(A_u8PortId, ZERO);
			break;
	case ONE:
			MDIO_voidSetPortValue(A_u8PortId, ONE);
			break;
	case TWO:
			MDIO_voidSetPortValue(A_u8PortId, TWO);
			break;
	case THREE:
			MDIO_voidSetPortValue(A_u8PortId, THREE);
			break;
	case FOUR:
			MDIO_voidSetPortValue(A_u8PortId, FOUR);
			break;
	case FIVE:
			MDIO_voidSetPortValue(A_u8PortId, FIVE);
			break;
	case SIX:
			MDIO_voidSetPortValue(A_u8PortId, SIX);
			break;
	case SEVEN:
			MDIO_voidSetPortValue(A_u8PortId, SEVEN);
			break;
	case EIGHT:
			MDIO_voidSetPortValue(A_u8PortId, EIGHT);
			break;
	case NINE:
			MDIO_voidSetPortValue(A_u8PortId, NINE);
			break;
	default: break;
	}
}

void HSSD_voidDisplayAscending(void)
{
	u8 local_u8Arr[10] ={ZERO, ONE, TWO, THREE, FOUR,FIVE,SIX, SEVEN,EIGHT,NINE};
	u8 i;
	for(i=0;i<10;i++)
	{
		MDIO_voidSetPortValue(SSD_PORT, local_u8Arr[i]);
		_delay_ms(SSD_DISPLAY_TIME);
	}
}
void HSSD_voidDisplayDecending(void)
{
	u8 local_u8Arr[10] ={ZERO, ONE, TWO, THREE, FOUR,FIVE,SIX, SEVEN,EIGHT,NINE};
	u8 i;
	for(i=0;i<10;i++)
	{
		MDIO_voidSetPortValue(SSD_PORT, local_u8Arr[9-i]);
		_delay_ms(SSD_DISPLAY_TIME);
	}
}
