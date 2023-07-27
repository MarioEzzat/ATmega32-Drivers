/*
 * ADC_private.h
 *
 *  Created on: Aug 16, 2022
 *      Author: Mario Ezzat
 */

#ifndef INCLUDE_MCAL_ADC_ADC_PRIVATE_H_
#define INCLUDE_MCAL_ADC_ADC_PRIVATE_H_

#define ADMUX (*(volatile u8 *)0x27)
#define ADCSRA (*(volatile u8 *)0x26)
#define ADCH (*(volatile u8 *)0x25)
#define ADCL (*(volatile u8 *)0x24)
#define ADCHL (*(volatile u16 *)0x24)


#endif /* INCLUDE_MCAL_ADC_ADC_PRIVATE_H_ */
