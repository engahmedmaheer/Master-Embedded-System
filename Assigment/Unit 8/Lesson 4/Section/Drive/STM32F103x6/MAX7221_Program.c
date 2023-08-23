/*
 * MAX7221_Program.c
 *
 *  Created on: Aug 21, 2023
 *      Author: AhmedMaher
 */
#include <stdint.h>
#include <stdlib.h>

#include  "STM32F103x6.h"

#include "MAX7221_Private.h"
#include "MAX7221_Config.h"
#include "MAX7221_Interface.h"


#include "STK_interface.h"
#include "GPIO_Interface.h"
#include "SPI_Interface.h"



void MAX7211_VoidInit(void)
{
	/*Decode Mode &  displaying 11111111 Code B decode for digits 7–0*/
	MAX7211_SendData(MAX2721_DECODE_MODE ,MAX7221_DIGIT0_DIGIT7);
	/*Intensity Format*/
	MAX7211_SendData(MAX2721_INTENSITY ,MAX2721_INTENSITY_MAX);
	/*Scan Limit  Display digits 0 1 2 3 4 5 6 7 */
	MAX7211_SendData(MAX2721_SCAN_LIMT ,MAX2721_DIGIT_DISPLAY_0_7);
	/*Shutdown Normal Operation*/
	MAX7211_SendData(MAX7221_SHUTDOWN ,MAX2721_NORMAL_OPERATION);

}

void MAX7211_SendData(uint8_t Command , uint8_t Data )
{
	GPIO_u8SetPinValue(CSS_PORT, CSS_PIN, GPIO_PINLOW);

	SPI_U16SendData(SPI1, &Command, Polling_Enable);

	SPI_U16SendData(SPI1, &Data, Polling_Enable);

	GPIO_u8SetPinValue(CSS_PORT, CSS_PIN, GPIO_PINHIGH);


}


