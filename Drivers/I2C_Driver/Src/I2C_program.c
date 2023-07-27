/*
 * I2C_program.c
 *
 *  Created on: Aug 29, 2022
 *      Author: Mario Ezzat
 */
/****************************************************/
/*	LIBRARIES									    */
/****************************************************/
#include"../include/LIB/STD_TYPES.h"
#include"../include/LIB/BIT_MATH.h"
/****************************************************/
/*	DIO Directives								    */
/****************************************************/
#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/DIO/DIO_private.h"
#include "../Include/MCAL/DIO/DIO_configuration.h"
/****************************************************/
/*	I2C Directives								    */
/****************************************************/
#include "../include/MCAL/I2C/I2C_interface.h"
#include "../include/MCAL/I2C/I2C_private.h"
#include "../include/MCAL/I2C/I2C_configuration.h"
/****************************************************/
#define F_CPU 8000000UL

