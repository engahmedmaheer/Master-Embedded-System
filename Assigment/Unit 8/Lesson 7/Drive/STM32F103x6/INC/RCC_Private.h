/*
 * RCC_Private.h
 *
 *  Created on: Aug 9, 2023
 *      Author: AhmedMaher
 */

#ifndef INC_RCC_PRIVATE_H_
#define INC_RCC_PRIVATE_H_

#define PCLCK1_BIT	8

#define SWS_BIT		2

#define SWS_MASK	0b11

#define PCLCK2_BIT	11

#define HPRE_BIT	4

#define APB_SHIFT_NUM	8U

#define AHB_SHIFT_NUM	16U

#define PCLCK_MASK	0b111
#define HPRE_MASK	0xf



typedef enum
{
	HSI,
	HSE,
	PLL


}System_clock_E ;

#endif /* INC_RCC_PRIVATE_H_ */
