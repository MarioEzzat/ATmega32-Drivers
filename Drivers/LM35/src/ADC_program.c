/*
 * ADC_program.c
 *
 *  Created on: Aug 16, 2022
 *      Author: Mario Ezzat
 */

#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"

#include "../include/MCAL/ADC/ADC_interface.h"
#include "../include/MCAL/ADC/ADC_private.h"
#include "../include/MCAL/ADC/ADC_configuration.h"


void MADC_voidInit(void)
{
	SET_BIT(ADMUX,6);
	CLR_BIT(ADMUX,7);
	/* RIGHT ADJUSTMENT */
	CLR_BIT(ADMUX,5);
	/* DISABLE AUTO TRIGGER */
	CLR_BIT(ADCSRA,5);
	/*CLK/64 */
	CLR_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
	/* ENABLE ADC */
	SET_BIT(ADCSRA,7);
}

u16 MADC_u16GetDigitalValue(u8 A_u8Channel)
{
	u16 local_u16DigitalValue = 0;
	if(A_u8Channel <32)
	{
		/* APPLY MASK ON ADMUX BIT5 --> BIT 0 */
		ADMUX &= 0b11100000;
		ADMUX |= A_u8Channel;
		/*START CONVERSION*/
		SET_BIT(ADCSRA,6);
		/* Polling on ADC Complete Flag */
		while (GET_BIT(ADCSRA,4)==0);
		/* Clear INT Flag */
		SET_BIT(ADCSRA,4);
		/* Read Conversion value */
		local_u16DigitalValue = ADCHL;
	}
	return local_u16DigitalValue;
}
