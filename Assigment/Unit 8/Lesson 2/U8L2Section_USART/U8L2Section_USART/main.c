/*
 * U8L2Section_USART.c
 *
 * Created: 8/4/2023 12:18:13 PM
 * Author : AhmedMaher
 */ 
#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#define F_CPU 8000000UL

#include "DIO_interface.h"
#include "PORT_interface.h"
#include "CLCD_interface.h"
#include "USART_interface.h"

int main(void)
{
	
	PORT_voidInit();
	CLCD_voidInit();
	
	USART_VoidInit();
	
	uint8_t Data = 0 ;

    /* Replace with your application code */
	CLCD_voidSendString("USARTTEST");
	_delay_ms(1000);
	CLCD_voidSendCommand(0x01);
	USART_u8SendData('Ahmed Maher');
  while (1)
  {
	
  }
}




