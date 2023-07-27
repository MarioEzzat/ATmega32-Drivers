/*
 * USART_private.h
 *
 *  Created on: Aug 24, 2022
 *      Author: Mario Ezzat
 */

#ifndef INCLUDE_MCAL_USART_USART_PRIVATE_H_
#define INCLUDE_MCAL_USART_USART_PRIVATE_H_

#define UDR 	(*(volatile u8 *)0x2C)
#define UCSRA 	(*(volatile u8 *)0x2B)
#define UCSRB 	(*(volatile u8 *)0x2A)
#define UCSRC 	(*(volatile u8 *)0x40)
#define UBRRL 	(*(volatile u8 *)0x29)
#define UBRRH 	(*(volatile u8 *)0x40)

#define BOUDRATE_EQUATION	(F_CPU/16/BOUDRATE-1)

#define INTERRUPT_ENABLE 	1
#define INTERRUPT_DISABLE 	0

#define DOUBLE_SPEED_ON 	1
#define DOUBLE_SPEED_OFF	0

#define ENABLE_TX	1
#define ENABLE_RX	1

#define UCSRC_REGISTER_SELECT 1

#define ASYNCHRONOUS	0
#define SYNCHRONOUS		0

#define DONOT_CARE	0

/*UCSRA BITS*/
#define RXC		7
#define TXC		6
#define UDRE	5
#define FE		4
#define DOR		3
#define PE		2
#define U2X		1
#define MPCM	0

/*UCSRB BITS*/
#define RXCIE	USART_RX_INTERRUPT_MODE				//7
#define TXCIE	USART_TX_INTERRUPT_MODE				//6
#define UDRIE	USART_DATA_REGISTER_INTERRUPT_MODE	//5
#define RXEN	ENABLE_RX							//4
#define TXEN	ENABLE_TX							//3
#define UCSZ2	UCSZ2_VALUE							//2
#define RXB8	DONOT_CARE							//1
#define TXB8	DONOT_CARE							//0

/*UCSRC BITS*/
#define URSEL	UCSRC_REGISTER_SELECT		//7
#define UMSEL	MODE_OF_OPERATION			//6
#define UPM1	UPM1_VALUE					//5
#define UPM0	UPM0_VALUE					//4
#define USBS	STOP_BITS_MODE				//3
#define UCSZ1	UCSZ1_VALUE					//2
#define UCSZ0	UCSZ0_VALUE					//1
#define UCPOL	CLOCK_POLARITY				//0

/*DATA SIZE*/
#define CHAR_FIVE_BIT  5
#define CHAR_SIX_BIT   6
#define CHAR_SEVEN_BIT 7
#define CHAR_EIGHT_BIT 8
#define CHAR_NINE_BIT  9

/*PARITY ERROR CHECK*/
#define PARITY_DISABLE   0
#define PARITY_EVEN  	 2
#define PARITY_ODD 		 3

/*STOP*/
#define ONE_STOP_BIT	 0
#define TWO_STOP_BIT	 1

#define NULL 0
#endif /* INCLUDE_MCAL_USART_USART_PRIVATE_H_ */
