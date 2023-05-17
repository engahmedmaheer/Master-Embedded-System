/*Startup with C code | Eng Ahmed Maher*/

#include <stdio.h>
void Reset_Handler();
void Default_Handler();
extern void main() ; 

void Default_Handler()
{
	Reset_Handler();
}
void NMI_Handler() __attribute__((weak,alias("Default_Handler")));;

void H_Fault_Handler() __attribute__((weak,alias("Default_Handler")));;

void MM_Fault_Handler() __attribute__((weak,alias("Default_Handler")));;

void Bus_Fault_Handler()  __attribute__((weak,alias("Default_Handler")));;

void Usage_Fault_Handler()  __attribute__((weak,alias("Default_Handler")));;

extern unsigned int _stack_top ;

uint32_t Vectors[]  __attribute__((section(".vectors")))=
{
(uint32_t) &_stack_top , 
(uint32_t) &Reset_Handler,
(uint32_t) &NMI_Handler,
(uint32_t) &H_Fault_Handler,
(uint32_t) &MM_Fault_Handler,
(uint32_t) &Bus_Fault_Handler,
(uint32_t) &Usage_Fault_Handler
};

extern unsigned int _E_text ;
extern unsigned int _S_DATA ;
extern unsigned int _E_DATA ;
extern unsigned int _S_BSS ;
extern unsigned int _E_BSS ;



void Reset_Handler()
{
	/*COPY DATA SECTION FROM FLASH TO RAM*/
	unsigned int DATA_SIZE = (unsigned char*)&_E_DATA -(unsigned char*)&_S_DATA ;
	unsigned char* P_SRC = (unsigned char*)&_E_DATA ;
	unsigned char* P_DST = (unsigned char*)&_S_DATA ;
	for (int i = 0 ; i < DATA_SIZE ; i++)
	{
		*(unsigned char*)(P_DST++) = *(unsigned char*)(P_SRC++);
	}
	/*init .bss section in sram = 0*/
	unsigned int BSS_SIZE = *((unsigned char *)_E_DATA) - *((unsigned char *)_S_DATA) ; 
	for (int i = 0 ; i < BSS_SIZE ; i++)
	{
		*((unsigned char*)P_DST++) = *(unsigned char*)0;
	}
	/*Call Main*/


}