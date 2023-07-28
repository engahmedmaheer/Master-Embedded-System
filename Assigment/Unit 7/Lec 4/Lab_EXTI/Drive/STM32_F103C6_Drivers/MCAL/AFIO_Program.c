/*
 * AFIO_Program.c
 *
 *  Created on: Jul 28, 2023
 *      Author: AhmedMaher
 */

#include <stdlib.h>
#include <stdio.h>


#include "BIT_MATH.h"
#include "ERR_TYPE.h"
#include "STM32F103x6.h"
#include "AFIO_Private.h"
#include "AFIO_Interface.h"

void AFIO_voidSelectEXTIPort(AFIO_LINE_E AFIO_LINE_NUMBER,AFIO_GPIO_PORT_E GPIO_PORT)
{
	uint8_t LocalErrorStatue = OK ;

	/*Enable external interrupt configuration register*/
	if(AFIO_LINE_NUMBER < AFIO_UNVALID && GPIO_PORT < AFIO_INVALIED_PORT)
	{
		uint8_t LocalBitNum=((AFIO_LINE_NUMBER % EXTI_PIN_ACCESS_BITS)*EXTI_PIN_ACCESS_BITS);
		uint8_t LocalRegNum=(AFIO_LINE_NUMBER/EXTI_PIN_ACCESS_BITS);

		(AFIO->EXTICR[LocalRegNum] ) &= (~(AFIO_MASK)<< LocalBitNum) ;
		(AFIO->EXTICR[LocalRegNum] ) |= GPIO_PORT<< LocalBitNum ;
	}
	else
	{
		LocalErrorStatue = NOK;
	}



}
