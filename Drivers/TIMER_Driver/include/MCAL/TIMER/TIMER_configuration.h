/*
 * TIMER_configuration.h
 *
 *  Created on: Aug 18, 2022
 *      Author: Mario Ezzat
 */

#ifndef INCLUDE_MCAL_TIMER_TIMER_CONFIGURATION_H_
#define INCLUDE_MCAL_TIMER_TIMER_CONFIGURATION_H_


/****************************************************/
/* 						TIMER0						*/
/****************************************************/

/* TIMER_MODE :- NORMAL_MODE - PHASE_CORRECT_MODE - CTC_MODE - FAST_PWM_MODE */
#define TIMER_MODE FAST_PWM_MODE

/*
 * 0b000 --> NO CLK (TIMER STOPPED)
 * 0b001 --> CLK / NO PRESCALER
 * 0b010 --> CLK / 8 PRESCALER
 * Ob011 --> CLK / 64 PRESCALER
 * 0b100 --> CLK / 256 PRESCALER
 * 0b101 --> CLK / 1024 PRESCALER
 * 0b110 --> EXTERNAL CLK SOURCE (FALLING EDGE)
 * 0b111 --> EXTERNAL CLK SOURCE (RISING EDGE) */
#define CLK_CONFIGURATION_TIMER0 0b010


/* CTC_OC0_PIN_ACTION:- NORMAL_DIO - TOGGEL_CTC - CLEAR_CTC - SET_CTC */
#define  CTC_OC0_PIN_ACTION NORMAL_DIO

/* FAST_PWM_OC0_PIN_ACTION:- NORMAL_DIO - NON_INVERTING - INVERTING */
#define  FAST_PWM_OC0_PIN_ACTION INVERTING

/*OCR0_VALUE:- 0-->255*/
#define OCR0_VALUE 99

/****************************************************/
/* 						TIMER1						*/
/****************************************************/

#define TIMER1_MODE FAST_PWM_ICR1

/*
 * 0b000 --> NO CLK (TIMER STOPPED)
 * 0b001 --> CLK / NO PRESCALER
 * 0b010 --> CLK / 8 PRESCALER
 * Ob011 --> CLK / 64 PRESCALER
 * 0b100 --> CLK / 256 PRESCALER
 * 0b101 --> CLK / 1024 PRESCALER
 * 0b110 --> EXTERNAL CLK SOURCE (FALLING EDGE)
 * 0b111 --> EXTERNAL CLK SOURCE (RISING EDGE) */
#define CLK_CONFIGURATION_TIMER1 0b010

/* FAST_PWM_OC1_PIN_ACTION:- NORMAL_DIO - NON_INVERTING - INVERTING */
#define  FAST_PWM_OC1A_PIN_ACTION NON_INVERTING
#define  FAST_PWM_OC1B_PIN_ACTION INVERTING
/*ICR1:- 0 --> 65535*/
#define ICR1_VALUE 19999

/****************************************************/
/* 					WATCH DOG TIMER					*/
/****************************************************/
/*
 * 0b000 -->  3.3V (17.1ms) - 5V (16.3ms)
 * 0b001 -->  3.3V (34.3ms) - 5V (32.5ms)
 * 0b010 -->  3.3V (68.5ms) - 5V (65.0ms)
 * Ob011 -->  3.3V (0.14s) - 5V (0.13s)
 * 0b100 -->  3.3V (0.27s) - 5V (0.26s)
 * 0b101 -->  3.3V (0.55s) - 5V (0.52s)
 * 0b110 -->  3.3V (1.10s) - 5V (1.00s)
 * 0b111 -->  3.3V (2.20s) - 5V (2.00s) */
#define WDT_PRESCALER_SLECT 0b111

#endif /* INCLUDE_MCAL_TIMER_TIMER_CONFIGURATION_H_ */
