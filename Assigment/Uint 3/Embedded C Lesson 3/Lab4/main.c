#include <stdint.h>

#include "Private.h"


unsigned char g_variables[3] = {1,2,3} ; 
unsigned char const const_variable[3] = {1,2,3};


void main ()
{
RCC_APB2ENR |= GPIOA_IOPAEN ;
GPIOA_CRH &= 0xFF0FFFFF; 
GPIOA_CRH |= 0x00200000 ; 
 while(1)
 {
 	R_ODR->pin.P_13 = 1 ; 
 	for(int i =0 ; i < 5000 ; i++);

	R_ODR->pin.P_13 = 0 ; 
 	for(int i =0 ; i < 5000 ; i++);


 }

}