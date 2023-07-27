/*
 * I2C_private.h
 *
 *  Created on: Aug 29, 2022
 *      Author: Mario Ezzat
 */

#ifndef INCLUDE_MCAL_I2C_I2C_PRIVATE_H_
#define INCLUDE_MCAL_I2C_I2C_PRIVATE_H_


#define TWBR (*(volatile u8 *)0x20)
#define TWSR (*(volatile u8 *)0x21)
#define TWAR (*(volatile u8 *)0x22)
#define TWDR (*(volatile u8 *)0x23)
#define TWCR (*(volatile u8 *)0x56)



#endif /* INCLUDE_MCAL_I2C_I2C_PRIVATE_H_ */
