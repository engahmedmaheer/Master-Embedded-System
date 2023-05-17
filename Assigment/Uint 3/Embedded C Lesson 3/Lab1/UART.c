#include <stdio.h>

#include "UART.h"
#define UART0DR 	*((volatile unsigned int* const)((unsigned int*)0x101f1000))

void uartsendstring(unsigned char *p_tx_string)
{
	/*pull untill '/0'*/
	while (*p_tx_string != '\0')
	{
		UART0DR = (unsigned int )(*p_tx_string);
			p_tx_string++ ;/*Next char */
	}

}
