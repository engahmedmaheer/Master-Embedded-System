/*
 * EXTI.h
 *
 * Created: 6/30/2023 2:28:02 PM
 *  Author: AhmedMaher
 */ 
#ifndef EXTI_H_
#define EXTI_H_


#define EXTI_MCUCR	(*(volatile uint8_t*)0x55)
#define EXTI_MCUCSR (*(volatile uint8_t*)0x54)
#define EXTI_GICR	(*(volatile uint8_t*)0x5B)
#define EXTI_GIFR	(*(volatile uint8_t*)0x5A)

#define ISC00	0
#define ISC01	1
#define ISC10	2
#define ISC11	3

#define ISC2 6


#define INT1	7
#define INT0	6
#define INT2	5

//*foe GIE*/
#define  GIE_SREG  (*(volatile uint8_t*)0x5F)
#define I	7


void Enable_INIT(void);


#endif