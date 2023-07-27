/*
 * LCD_interface.h
 *
 *  Created on: Aug 5, 2022
 *      Author: Mario Ezzat
 */

#ifndef INCLUDE_HAL_LCD_INTERFACE_H_
#define INCLUDE_HAL_LCD_INTERFACE_H_

void HLCD_voidSendCommand(u8 A_u8Command);
void HLCD_voidSendData(u8 A_u8Data);
void HLCD_voidInit(void);
void HLCD_voidClearDisplay(void);
void HLCD_voidSendString(u8 *A_Pu8String);
void HLCD_voidGoToPos(u8 A_u8RowNum, u8 A_u8ColNum);


#endif /* INCLUDE_HAL_LCD_INTERFACE_H_ */
