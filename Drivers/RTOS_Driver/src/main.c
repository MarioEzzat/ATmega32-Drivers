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

#include "../include/SERVICES/RTOS/RTOS_interface.h"

#include <util/delay.h>
#define F_CPU 8000000UL
void Toggel_LED1(void);
void Toggel_LED2(void);
void Toggel_LED3(void);



void main(void)
{
	MDIO_voidInit();
	MGI_voidEnable();

	SRTOS_voidInitArryFunctions();
	SRTOS_voidCreatTask(0,1000,0,Toggel_LED1);
	SRTOS_voidCreatTask(1,2000,0,Toggel_LED2);
	SRTOS_voidCreatTask(2,3000,0,Toggel_LED3);

	SRTOS_voidInit();
	while(1)
	{

	}

}

void Toggel_LED1(void)
{
	static u8 local_u8Flag = 0;

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
void Toggel_LED2(void)
{
	static u8 local_u8Flag = 0;

	if(local_u8Flag == 0)
	{
		MDIO_voidSetPinValue(PORTA,PIN1,PIN_HIGH);
		local_u8Flag = 1;
	}
	else
	{
		MDIO_voidSetPinValue(PORTA,PIN1,PIN_LOW);
		local_u8Flag = 0;
	}
}
void Toggel_LED3(void)
{

	static u8 local_u8Flag = 0;

	if(local_u8Flag == 0)
	{
		MDIO_voidSetPinValue(PORTA,PIN2,PIN_HIGH);
		local_u8Flag = 1;
	}
	else
	{
		MDIO_voidSetPinValue(PORTA,PIN2,PIN_LOW);
		local_u8Flag = 0;
	}
}

