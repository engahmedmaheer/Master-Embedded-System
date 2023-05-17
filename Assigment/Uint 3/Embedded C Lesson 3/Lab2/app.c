#include "UART.h"

unsigned char string_buffer[50]="Ahmed Maher" ;  
unsigned char const string_buffer2[50]="Ahmed Maher Mohamed" ;  
unsigned char const string_buffer3[50]="Ahmed Maher Fawzy" ; 
unsigned char const string_buffer4[50]="string_buffer4" ; 

void main(void)

{   /*pass string*/
	uartsendstring(string_buffer);
}