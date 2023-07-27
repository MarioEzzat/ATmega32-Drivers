/*
 * main.c
 *
 *  Created on: Aug 23, 2022
 *      Author: Mario Ezzat
 */

#include"../include/LIB/STD_TYPES.h"
#include"../include/LIB/BIT_MATH.h"


#include"../include/MCAL/DIO/DIO_interface.h"
#include"../include/MCAL/GI/GI_interface.h"

#include "../include/MCAL/TIMER/TIMER_interface.h"

#include <util/delay.h>
#define F_CPU 8000000UL
void Toggel_LED_OVF(void);
void Toggel_LED_CTC(void);

void main(void)
{
	MDIO_voidInit();
	MGI_voidEnable();
	while(1)
	{
		MWDT_voidEnable();
		if(MDIO_u8GetPinValue(PORTA,PIN1) == PIN_LOW)
		{
			MWDT_voidDisable();
		}
	}

}
/*NORMAL MODE TOGGEL EACH 1 SEC */
void Toggel_LED_OVF(void)
{
	static u16 local_u16Counter = 0;
	static u8 local_u8Flag = 0;
	local_u16Counter++;
	if (local_u16Counter == 3907)
	{
		MTIMER0_voidSetPreloadValue(192);
		local_u16Counter = 0;
		if(local_u8Flag == 0)
		{
			MDIO_voidSetPinValue(PORTA,PIN0,PIN_HIGH);
			local_u8Flag = 1;
		}
		else
		{
			MDIO_voidSetPinValue(PORTA,PIN0,PIN_LOW);
			local_u8Flag = 0;
		}
	}
}
/*CTC MODE TOGGEL EACH 1 SEC */
void Toggel_LED_CTC(void)
{
	static u16 local_u16Counter = 0;
	static u8 local_u8Flag = 0;
	local_u16Counter++;
	if (local_u16Counter == 10000)
	{
		local_u16Counter = 0;
		if(local_u8Flag == 0)
		{
			MDIO_voidSetPinValue(PORTA,PIN0,PIN_HIGH);
			local_u8Flag = 1;
		}
		else
		{
			MDIO_voidSetPinValue(PORTA,PIN0,PIN_LOW);
			local_u8Flag = 0;
		}
	}
}
