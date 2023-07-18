/*
 * BitMath.h
 *
 *  Created on: Oct 3, 2021
 *      Author: Ahmed Maher
 */

#ifndef BITMATH_H_
#define BITMATH_H_


#define SET_BIT(VAR,BIT_NO) (VAR=VAR|(1<<BIT_NO))
#define CLR_BIT(VAR,BIT_NO) (VAR&=(~(1<<BIT_NO)))
#define TOG_BIT(VAR,BIT_NO)  (VAR ^=(1<<BIT_NO))
#define ASSIGN_BIT(VAR,BIT_NO,VAL)  (VAR=(VAR&(~(1<<BIT_NO)))|(VAL<<BIT_NO))
#define GET_BIT(VAR,BIT_NO) ((VAR>>BIT_NO)&1)


#endif /* BITMATH_H_ */
