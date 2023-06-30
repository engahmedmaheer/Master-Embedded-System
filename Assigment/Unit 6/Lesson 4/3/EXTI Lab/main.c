/*
 * EXTI Lab.c
 *
 * Created: 6/30/2023 2:27:21 PM
 * Author : AhmedMaher
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include "EXTI.h"
#include "BIT_MATH.h"
#include <util/delay.h>




void ConfigPins(void);

int main(void)
{
	
	ConfigPins();


	Enable_INIT();
	
    /* Replace with your application code */
    while (1) 
    {
		PORTD=0x00;
    }
}


/*ISR INT0*/
void __vector_1 (void)	__attribute__((signal));
void __vector_1 (void)
{
	
	SET_BIT(PORTD,5);
	_delay_ms(1000);
}
void __vector_2 (void)	__attribute__((signal));
void __vector_2 (void)
{
	
		SET_BIT(PORTD,6);
		_delay_ms(1000);
}
void __vector_3 (void)	__attribute__((signal));
void __vector_3 (void)
{
	
		SET_BIT(PORTD,7);
		_delay_ms(1000);
}
void ConfigPins(void)
{
	SET_BIT(DDRD,5);
	SET_BIT(DDRD,6);
	SET_BIT(DDRD,7);
}