/*
 * KEYPAD_configuration.h
 *
 *  Created on: Aug 8, 2022
 *      Author: Mario Ezzat
 */

#ifndef INCLUDE_HAL_KEYPAD_KEYPAD_CONFIGURATION_H_
#define INCLUDE_HAL_KEYPAD_KEYPAD_CONFIGURATION_H_

/*ROWS_NUMBER X COLS_NUMBER :- 4X4 - 4X3 - 3X3....*/
#define ROWS_NUMBER 4
#define COLS_NUMBER 4

/* KEYPAD_PORT:- PORTA - PORTB - PORTC - PORTD */
#define KEYPAD_PORT PORTD

/*DEPENDS ON ROWS_NUMBER AND COLS_NUMBER*/
#define ROWS_PINS {PIN0, PIN1, PIN2, PIN3}
#define COLS_PINS {PIN4, PIN5, PIN6, PIN7}

/* KEYPAD_KEYS : VALUE OF EACH KEY */
#define KEYPAD_KEYS {{'1', '2', '3', '+'},\
					 {'4', '5', '6', '-'},\
					 {'7', '8', '9', '*'},\
					 {'C', '0', '=', '/'}}

/* BOUNCING DELAY IN (ms) */
#define DEBOUNCING_DELAY 150

#define KEY_NOT_PRESSED 255

#endif /* INCLUDE_HAL_KEYPAD_KEYPAD_CONFIGURATION_H_ */
