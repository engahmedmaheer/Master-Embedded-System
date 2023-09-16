/*
 * RCC_Program.c
 *
 *  Created on: Aug 8, 2023
 *      Author: AhmedMaher
 */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "STM32F103x6.h"
#include "RCC_Private.h"
#include "RCC_Interface.h"

/**
 * @brief: APB1PrescTable For APB1 Bits
 * @ref:PPRE1: APB low-speed prescaler (APB1)
 */
const uint8_t APBPrescTable[APB_SHIFT_NUM] = {0,0,0,0,1,2,3,4};
/**
 * @brief: APB1PrescTable For APB1 Bits
 * @ref:PPRE1: APB low-speed prescaler (APB1)
 */
const uint8_t AHBPrescTable[AHB_SHIFT_NUM] = {0,0,0,0,0,0,0,0,1,2,3,4,5,6,7,8,9};
/**
 *
 * @return : SYSTEM CLCK  Frequency
 */
uint32_t RCC_GetSYSCLCK(void)
{
	/*Bits 3:2 SWS: System clock switch status
	Set and cleared by hardware to indicate which clock source is used as system clock.
	00: HSI oscillator used as system clock
	01: HSE oscillator used as system clock
	10: PLL used as system clock
	11: not applicable*/

	switch( (RCC->CFGR.Reg >>SWS_BIT) & SWS_MASK  )
	{
	case HSI :  return HSI_CLCK                 ;break;
	case HSE :  return HSE_CLCK                 ;break;
	case PLL :  return PLL_CLCK                 ;break; /*16MHZ*/
	default  :  								;break;

	}


}
/**
 *
 * @return : HCLCK Frequency
 */
uint32_t RCC_GetHCLCK(void)
{

	/****************  SYSCLCK --> |AHB PRESCALLER | --> HCLCK  ***********/
/*	Bits 7:4 HPRE: AHB prescaler
	Set and cleared by software to control the division factor of the AHB clock.
	0xxx: SYSCLK not divided
	1000: SYSCLK divided by 2
	1001: SYSCLK divided by 4
	1010: SYSCLK divided by 8
	1011: SYSCLK divided by 16
	1100: SYSCLK divided by 64
	1101: SYSCLK divided by 128
	1110: SYSCLK divided by 256
	1111: SYSCLK divided by 512*/

	return (RCC_GetSYSCLCK() >> AHBPrescTable[(RCC->CFGR.Reg >> HPRE_BIT ) &HPRE_MASK ] );


}

/**
 *
 * @return : PCLCK1 Frequency
 */
uint32_t RCC_GetPCLCK1(void)
{

	/****************  HCLCK --> |APB1 PRESCALLER | --> PCLCK1  ***********/
	/*
	 PPRE1: APB low-speed prescaler (APB1)
	Set and cleared by software to control the division factor of the APB low-speed clock
	(PCLK1).
	Warning: the software has to set correctly these bits to not exceed 36 MHz on this domain.
	0xx: HCLK not divided
	100: HCLK divided by 2
	101: HCLK divided by 4
	110: HCLK divided by 8
	111: HCLK divided by 16	 */

	return (RCC_GetHCLCK() >> APBPrescTable[((RCC-> CFGR.Reg )>> PCLCK1_BIT )&PCLCK_MASK] );

}
/**
 *
 * @return : PCLCK2 Frequency
 */
uint32_t RCC_GetPCLCK2(void)
{
	/****************  HCLCK --> |APB2 PRESCALLER | --> PCLCK2  ***********/
	/*PPRE2: APB high-speed prescaler (APB2)
	Set and cleared by software to control the division factor of the APB high-speed clock
	(PCLK2).
	0xx: HCLK not divided
	100: HCLK divided by 2
	101: HCLK divided by 4
	110: HCLK divided by 8
	111: HCLK divided by 16*/


	return (RCC_GetHCLCK() >> APBPrescTable[((RCC-> CFGR.Reg )>> PCLCK2_BIT )&PCLCK_MASK] );


}
void RCC_EnableAPB2CLCK(uint8_t APB2_Peripheral_ID )
{

	RCC->APB2ENR |=1<<APB2_Peripheral_ID ;


}
