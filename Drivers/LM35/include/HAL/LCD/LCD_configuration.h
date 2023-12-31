/*
 * LCD_configuration.h
 *
 *  Created on: Aug 5, 2022
 *      Author: Mario Ezzat
 */

#ifndef INCLUDE_HAL_LCD_CONFIGURATION_H_
#define INCLUDE_HAL_LCD_CONFIGURATION_H_

/*MODE OF OPERATION:- 8_BIT - 4_BIT*/
#define MODE_OF_OPERATION 8

#if MODE_OF_OPERATION == 8

#define LCD_DATA_PORT PORTD
#define LCD_CONTROL_PORT PORTC

#define RS_PIN PIN2
#define RW_PIN PIN1
#define EN_PIN PIN0

#define FUNCTION_SET 0b00111000
#define DISPLAY_ON_OFF_CONTROL 0b00001111
#define DISPLAY_CLEAR 0b00000001
#define ENTRY_MODE_SET 0b00000110

#elif MODE_OF_OPERATION == 4

#define LCD_DATA_PORT PORTA
#define D4_PIN PIN4
#define D5_PIN PIN5
#define D6_PIN PIN6
#define D7_PIN PIN7

#define LCD_CONTROL_PORT PORTB

#define RS_PIN PIN0
#define RW_PIN PIN1
#define EN_PIN PIN2

#define FUNCTION_SET_1 0b00100000
#define FUNCTION_SET_2 0b10000000
#define DISPLAY_ON_OFF_CONTROL 0b00001111
#define DISPLAY_CLEAR 0b00000001
#define ENTRY_MODE_SET 0b00000110
#else
#error "MODE_OF_OPERATION NOT DEFINED"
#endif

#endif /* INCLUDE_HAL_LCD_CONFIGURATION_H_ */
