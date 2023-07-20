/*
 * GccApplication1.c
 *
 * Created: 7/20/2023 4:50:30 PM
 * Author : AhmedMaher
 */ 
# define F_CPU 8000000UL
#include <avr/io.h>
#include "BIT_MATH.h"
#include <util/delay.h>

int main(void)
{
    /* Replace with your application code */
	
	TOG_BIT(DDRD,0);
	
	SET_BIT(DDRD,4);
		
    while (1) 
    {
		
		while(GET_BIT(PIND,0)==1)
		{
			SET_BIT(PORTD,4);
			_delay_ms(500);
		}
    }
}

