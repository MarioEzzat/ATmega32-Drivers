/*
 * RTOS_interface.h
 *
 *  Created on: Sep 2, 2022
 *      Author: Mario Ezzat
 */

#ifndef INCLUDE_SERVICES_RTOS_RTOS_INTERFACE_H_
#define INCLUDE_SERVICES_RTOS_RTOS_INTERFACE_H_

void SRTOS_voidInit();
void SRTOS_voidScheduler(void);
void SRTOS_voidInitArryFunctions(void);
void SRTOS_voidCreatTask(u8 A_u8Periorty, u16 A_u8Periodicity, u16 A_u8FirtsDelay, void(*A_PtrToFunc)(void));



#endif /* INCLUDE_SERVICES_RTOS_RTOS_INTERFACE_H_ */
