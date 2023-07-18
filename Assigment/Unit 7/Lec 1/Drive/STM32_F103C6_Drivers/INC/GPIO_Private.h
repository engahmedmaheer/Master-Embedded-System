/*
 * GPIO_Private.h
 *
 *  Created on: May 5, 2023
 *      Author: AhmedMaher
 */

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_


#define UNUSED				0
#define GPIO_PERIPHERAL_NUM	7U




#define	CRL_MASK					 	 	   0b1111
#define CNF_MASK							   0b11


#define CR_PIN_ACCESS_BITS               	    4
#define BSSR_PIN_ACCESS_BITS					16



#define LOW_PINS								7
#define HIGH_PINS								15

#define Reset_Val								0x44444444
#define Reset_Val0								0x00000000



#endif /* GPIO_PRIVATE_H_ */
