/*
 * EXTI.c
 *
 * Created: 6/30/2023 2:29:28 PM
 *  Author: AhmedMaher
 */ 
#include <stdlib.h>
#include <stdio.h>
#include "EXTI.h"
#include "BIT_MATH.h"
#include <avr/interrupt.h>
#include <util/delay.h>

void Enable_INIT(void)
{
	
	SET_BIT(EXTI_GICR,INT0);
	SET_BIT(EXTI_GICR,INT1);
	SET_BIT(EXTI_GICR,INT2);
	
	/* Edge IN0*/
	SET_BIT(EXTI_MCUCR,0);
	TOG_BIT(EXTI_MCUCR,1);
	
	/* Edge IN1*/
	SET_BIT(EXTI_MCUCR,2);
	SET_BIT(EXTI_MCUCR,3);
	
	/* Edge IN2*/
	TOG_BIT(EXTI_MCUCSR,6);
	
	/*Enable PIE (MASK)*/
	EXTI_GICR|=(1<<INT0);
	
	sei();
}
