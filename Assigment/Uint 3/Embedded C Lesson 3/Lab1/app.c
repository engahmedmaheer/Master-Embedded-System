#include "UART.h"

unsigned char string_buffer[50]="Ahmed Maher" ;  
unsigned char const string_buffer2[50]="Ahmed Maher" ;  


void main(void)

{   /*pass string*/
	uartsendstring(string_buffer);
	
	
	
}