/*
 * USART_program.c
 *
 *  Created on: Aug 24, 2022
 *      Author: Mario Ezzat
 */
#include"../include/LIB/STD_TYPES.h"
#include"../include/LIB/BIT_MATH.h"
/****************************************************/
/* USART Directives								    */
/****************************************************/
#include "../include/MCAL/USART/USART_interface.h"
#include "../include/MCAL/USART/USART_private.h"
#include "../include/MCAL/USART/USART_configuration.h"
#define F_CPU 8000000UL


void MUSART_voidInit(void)
{
	/*UBRR*/
	u16 local_u16BoudRateValue = BOUDRATE_EQUATION;
	/*STORE THE LOW BYTE*/
	UBRRL = (u8)local_u16BoudRateValue;
	/*STORE THE HIGH BYTE*/
	UBRRH = (u8)((local_u16BoudRateValue)>>8);
	#if USART_DOUBLE_SPEED == DOUBLE_SPEED_ON
		SET_BIT(UCSRA,U2X);
	#else
		CLR_BIT(UCSRA,U2X);
	#endif
	#if CHARACTER_SIZE == CHAR_NINE_BIT
		#define UCSZ2_VALUE 1
		#define UCSZ1_VALUE 1
		#define UCSZ0_VALUE 1
	#elif CHARACTER_SIZE == CHAR_EIGHT_BIT
		#define UCSZ2_VALUE 0
		#define UCSZ1_VALUE 1
		#define UCSZ0_VALUE 1
	#elif CHARACTER_SIZE == CHAR_SEVEN_BIT
		#define UCSZ2_VALUE 0
		#define UCSZ1_VALUE 1
		#define UCSZ0_VALUE 0

	#elif CHARACTER_SIZE == CHAR_FIVE_BIT
		#define UCSZ2_VALUE 0
		#define UCSZ1_VALUE 0
		#define UCSZ0_VALUE 0

	#endif
	#if PARITY_MODE == PARITY_DISABLE
		#define UPM1_VALUE 0
		#define UPM0_VALUE 0
	#elif PARITY_MODE == PARITY_EVEN
		#define UPM1_VALUE 0
		#define UPM0_VALUE 1
	#elif PARITY_MODE == PARITY_ODD
		#define UPM1_VALUE 1
		#define UPM0_VALUE 1
	#endif

	/* UCSRB */
	/* (USART_RX_INTERRUPT, USART_RX_INTERRUPT, USART_DATA_REGISTER_INTERRUPT,ENABLE_RX,ENABLE_TX, UCSZ2_VALUE, 0, 0) */
	UCSRB = CONC_BIT(RXCIE, TXCIE, UDRIE, RXEN, TXEN, UCSZ2, DONOT_CARE, DONOT_CARE);
	/* UCSRC */
	/* (UCSZ2_VALUE, MODE_OF_OPERATION, UPM1_VALUE, UPM0_VALUE, STOP_BITS_MODE,UCSZ1_VALUE, UCSZ0_VALUE, 0) */
	UCSRC = CONC_BIT(URSEL, UMSEL, UPM1, UPM0, USBS, UCSZ1, UCSZ0, 0);
}

/****************************************************/
/* 					SYNCHRONOUS					    */
/****************************************************/
void MUSART_voidSendByteSynchNonBlocking(u8 A_u8Byte)
{
	u32 local_u32TimeOut = 0;
	/* CHECK DATA INTERRUPT FLAG */
	while(GET_BIT(UCSRA,UDRE) == 0)
	{
		local_u32TimeOut++;
		/* IF BLOCKS */
		if (local_u32TimeOut == TIME_OUT)
		{
			break;
		}
	}
	/* IF NO BLOCKS */
	if (local_u32TimeOut != TIME_OUT)
	{
		local_u32TimeOut = 0 ;
		/* SEND DATA */
		UDR = A_u8Byte;
		/* CHECK DATA INTERRUPT FLAG */
		while(GET_BIT(UCSRA,UDRE) == 0)
			{
				local_u32TimeOut++;
				if (local_u32TimeOut == TIME_OUT)
				{
					break ;
				}
			}
		/* CLEAR TRANSMIT FLAG */
		SET_BIT(UCSRA,TXC);
	}
}

void MUSART_voidSendByteSynchBlocking(u8 A_u8Byte)
{
	/* CHECK DATA INTERRUPT FLAG */
	while(GET_BIT(UCSRA,UDRE) == 0){};
	/* SEND DATA */
	UDR = A_u8Byte;
	/* CHECK DATA INTERRUPT FLAG */
	while(GET_BIT(UCSRA,UDRE) == 0){};
	/* CLEAR TRANSMIT FLAG */
	SET_BIT(UCSRA,TXC);
}
void MUSART_voidSendStringSynchBlocking(u8 *A_Pu8String)
{
	u8 i=0;
	while(A_Pu8String[i]!='\0')
	{
		MUSART_voidSendByteSynchBlocking(A_Pu8String[i]);
		i++;
	}
}

u8 MUSART_voidReadByteSynchNonBlocking(void)
{
	u32 local_u32TimeOut = 0;
	u8 local_u8Value = 255;
	while(GET_BIT(UCSRA,RXC) == 0)
	{
		local_u32TimeOut = local_u32TimeOut + 1;
		if (local_u32TimeOut == TIME_OUT)
		{
			break;
		}
	}
	if (local_u32TimeOut != TIME_OUT)
	{
		local_u8Value = UDR;

	}
	return local_u8Value;
}

u8 MUSART_voidReadByteSynchBlocking(void)
{
	while(GET_BIT(UCSRA,RXC) == 0);
	return UDR;
}

/****************************************************/
/* 					ASYNCHRONOUS				    */
/****************************************************/
void UART_voidSendByteAsynch(u8 copy_u8Byte)
{
	/* Set byte to be transmitted */
	UDR= copy_u8Byte;
}
u8 UART_u8READByteAsynch (void)
{
	return UDR;
}

/* INTERRUPT */
static void (*FuncPtr[3])(void) = {NULL,NULL,NULL};

void MUSART_voidSetCallBack(u8 A_u8InterruptType, void(*A_PtrFunc)(void))
{
	if((A_u8InterruptType <=2)&&(A_PtrFunc != NULL))
	{
		FuncPtr[A_u8InterruptType] = A_PtrFunc;
	}
}
void __vector_13(void)	__attribute__((signal));
void __vector_13(void)
{

}

void __vector_14(void)	__attribute__((signal));
void __vector_14(void)
{

}

void __vector_15(void)	__attribute__((signal));
void __vector_15(void)
{

}
