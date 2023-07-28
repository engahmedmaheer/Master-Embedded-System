/****************************************************************************************/
/****************************************************************************************/
/******************************		Author:	Ahmed Maher		    *************************/
/******************************		Layer:	MCAL		            *************************/
/******************************		SWC:	SYSTICK	*************************/
/******************************		Version:	1.00		    *************************/
/****************************************************************************************/
/****************************************************************************************/
#include "STM32F103x6.h"
#include "BIT_MATH.h"
#include <stdio.h>
#include <stdlib.h>
#include "STK_interface.h"


/*millsec*/
void STK_voidDelayMilleSec(uint32_t Copy_u32DelayMS)
{
	uint32_t Local_u32Value;
	/*Select ClK Source*/
	/*1.Program reload value.*/
	Local_u32Value=Copy_u32DelayMS*1000;
	STK_LOAD = Local_u32Value;
	/*2. Clear current value.*/
	STK_VALUE=0;
	/*3. Program Control and Status register*/
	STK_CTRL |= (1<<0);
	STK_CTRL &= ~(1<<2);

	while((((STK_CTRL)>>16)&1)==0);
	STK_CTRL &= ~(1<<0);
	
}
