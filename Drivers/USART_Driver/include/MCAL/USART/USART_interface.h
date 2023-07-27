/*
 * USART_interface.h
 *
 *  Created on: Aug 24, 2022
 *      Author: Mario Ezzat
 */

#ifndef INCLUDE_MCAL_USART_USART_INTERFACE_H_
#define INCLUDE_MCAL_USART_USART_INTERFACE_H_

void MUSART_voidInit(void);

void MUSART_voidSendByteSynchNonBlocking(u8 A_u8Byte);
void MUSART_voidSendByteSynchBlocking(u8 A_u8Byte);

u8 MUSART_voidReadByteSynchNonBlocking(void);
u8 MUSART_voidReadByteSynchBlocking(void);

void MUSART_voidSetCallBack(u8 A_u8InterruptType, void(*A_PtrFunc)(void));



#endif /* INCLUDE_MCAL_USART_USART_INTERFACE_H_ */
