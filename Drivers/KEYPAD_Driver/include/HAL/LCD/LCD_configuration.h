/*
 * LCD_configuration.h
 *
 *  Created on: Aug 5, 2022
 *      Author: Mario Ezzat
 */

#ifndef INCLUDE_HAL_LCD_CONFIGURATION_H_
#define INCLUDE_HAL_LCD_CONFIGURATION_H_

#define LCD_DATA_PORT    PORTA
#define LCD_CONTROL_PORT PORTB

#define RS_PIN PIN0
#define RW_PIN PIN1
#define EN_PIN PIN2

#define FUNCTION_SET 			0b00111000
#define DISPLAY_ON_OFF_CONTROL 	0b00001111
#define DISPLAY_CLEAR 			0b00000001
#define ENTRY_MODE_SET			0b00000110


#endif /* INCLUDE_HAL_LCD_CONFIGURATION_H_ */
