/*
 * RTOS_private.h
 *
 *  Created on: Sep 2, 2022
 *      Author: Mario Ezzat
 */

#ifndef INCLUDE_SERVICES_RTOS_RTOS_PRIVATE_H_
#define INCLUDE_SERVICES_RTOS_RTOS_PRIVATE_H_

/* EACH TCB CONTAIN FirstDelay - Periodicity - FUNCTION FOR TASK*/
typedef struct
{
	u16 FirstDelay;
	u16 Periodicity;
	void (*ptr)(void);
}RTOS_TCB;


#endif /* INCLUDE_SERVICES_RTOS_RTOS_PRIVATE_H_ */
