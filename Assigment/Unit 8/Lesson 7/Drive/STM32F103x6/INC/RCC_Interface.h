/*
 * RCC_Interface.h
 *
 *  Created on: Aug 8, 2023
 *      Author: AhmedMaher
 */

#ifndef INC_RCC_INTERFACE_H_
#define INC_RCC_INTERFACE_H_



/**
 * You Should Configure MACRO
 */
#define HSI_CLCK	(uint32_t)8000000

#define HSE_CLCK	(uint32_t)16000000

#define PLL_CLCK	0

/**
 *
 * @return : HCLCK Frequency
 */
uint32_t RCC_GetSYSCLCK(void);
/**
 *
 * @return : HCLCK Frequency
 */
uint32_t RCC_GetHCLCK(void);

/**
 *
 * @return : PCLCK1 Frequency
 */
uint32_t RCC_GetPCLCK1(void);
/**
 *
 * @return : PCLCK2 Frequency
 */
uint32_t RCC_GetPCLCK2(void);


void RCC_EnableAPB2CLCK(uint8_t APB2_Peripheral_ID );



#endif /* INC_RCC_INTERFACE_H_ */
