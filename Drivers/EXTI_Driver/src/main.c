/*
 * main.c
 *
 *  Created on: Aug 16, 2022
 *      Author: Mario Ezzat
 */
#include"../include/LIB/STD_TYPES.h"
#include"../include/LIB/BIT_MATH.h"


#include"../include/MCAL/DIO/DIO_interface.h"

#include "../include/MCAL/EXTI/EXTI_interface.h"

#include "../include/MCAL/GI/GI_interface.h"

void ToggelLed(void);
void main(void)
{
	MDIO_voidInit();
	MGI_voidEnable();
	MEXTI_voidSetCallBack(ToggelLed,EXTI0);
	MEXTI_voidConfig(EXTI0,FALLING_EDGE);
	MEXTI_voidDisable(EXTI0);

	while(1)
	{

	}
}



void ToggelLed(void)
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
