/*
 * SERVO_interface.h
 *
 *  Created on: Aug 27, 2022
 *      Author: Mario Ezzat
 */

#ifndef INCLUDE_HAL_SERVO_SERVO_INTERFACE_H_
#define INCLUDE_HAL_SERVO_SERVO_INTERFACE_H_

void HSERVO_voidCCW(u8 A_u8ServoNum);
void HSERVO_voidCW(u8 A_u8ServoNum);
void HSERVO_voidSetServoAngle(u8 A_u8ServoNum,u8 A_u8Angle);

#endif /* INCLUDE_HAL_SERVO_SERVO_INTERFACE_H_ */
