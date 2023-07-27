/*
 * STEPPER_program.c
 *
 *  Created on: Aug 10, 2022
 *      Author: Mario Ezzat
 */

#include"../include/LIB/STD_TYPES.h"
#include"../include/LIB/BIT_MATH.h"


#include"../include/MCAL/DIO/DIO_interface.h"
#include"../include/MCAL/DIO/DIO_private.h"
#include"../include/MCAL/DIO/DIO_configuration.h"

#include "../include/HAL/STEPPER/STEPPER_interface.h"
#include "../include/HAL/STEPPER/STEPPER_private.h"
#include "../include/HAL/STEPPER/STEPPER_configuration.h"

void HSTEPPER_voidFullStep(void)
{
	/*STEP ONE*/
	MDIO_voidSetPinValue(STEPPER_PORT,STEPPER_PIN1, PIN_LOW);
	MDIO_voidSetPinValue(STEPPER_PORT,STEPPER_PIN2, PIN_HIGH);
	MDIO_voidSetPinValue(STEPPER_PORT,STEPPER_PIN3, PIN_HIGH);
	MDIO_voidSetPinValue(STEPPER_PORT,STEPPER_PIN4, PIN_HIGH);
	_delay_ms(10);
	/*STEP TWO*/
	MDIO_voidSetPinValue(STEPPER_PORT,STEPPER_PIN1, PIN_HIGH);
	MDIO_voidSetPinValue(STEPPER_PORT,STEPPER_PIN2, PIN_LOW);
	MDIO_voidSetPinValue(STEPPER_PORT,STEPPER_PIN3, PIN_HIGH);
	MDIO_voidSetPinValue(STEPPER_PORT,STEPPER_PIN4, PIN_HIGH);
	_delay_ms(10);
	/*STEP THREE*/
	MDIO_voidSetPinValue(STEPPER_PORT,STEPPER_PIN1, PIN_HIGH);
	MDIO_voidSetPinValue(STEPPER_PORT,STEPPER_PIN2, PIN_HIGH);
	MDIO_voidSetPinValue(STEPPER_PORT,STEPPER_PIN3, PIN_LOW);
	MDIO_voidSetPinValue(STEPPER_PORT,STEPPER_PIN4, PIN_HIGH);
	_delay_ms(10);
	/*STEP Four*/
	MDIO_voidSetPinValue(STEPPER_PORT,STEPPER_PIN1, PIN_HIGH);
	MDIO_voidSetPinValue(STEPPER_PORT,STEPPER_PIN2, PIN_HIGH);
	MDIO_voidSetPinValue(STEPPER_PORT,STEPPER_PIN3, PIN_HIGH);
	MDIO_voidSetPinValue(STEPPER_PORT,STEPPER_PIN4, PIN_LOW);
	_delay_ms(10);
}
