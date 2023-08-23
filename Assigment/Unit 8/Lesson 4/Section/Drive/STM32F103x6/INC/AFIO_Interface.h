/*
 * AFIO_Interface.h
 *
 *  Created on: Jul 28, 2023
 *      Author: AhmedMaher
 */

#ifndef INC_MCAL_AFIO_INTERFACE_H_
#define INC_MCAL_AFIO_INTERFACE_H_



typedef enum
{
	AFIO_PORTA						,      /**< PORTA */
	AFIO_PORTB 						,      /**< PORTB */
	AFIO_PORTC 						,      /**< PORTC */
	AFIO_PORTD 						,      /**< PORTD */
	AFIO_PORTE 						,      /**< PORTE */
	AFIO_PORTF 						,      /**< PORTF */
	AFIO_PORTG 						,      /**< PORTG */
	AFIO_PORTH 						,      /**< PORTH */
	AFIO_INVALIED_PORT				,/**< INVALIED_PORT */
}AFIO_GPIO_PORT_E;

typedef enum
{
	AFIO_LINE0,      /**< EXTI_LINE0 */
	AFIO_LINE1,      /**< EXTI_LINE1 */
	AFIO_LINE2,      /**< EXTI_LINE2 */
	AFIO_LINE3,      /**< EXTI_LINE3 */
	AFIO_LINE4,      /**< EXTI_LINE4 */
	AFIO_LINE5,      /**< EXTI_LINE5 */
	AFIO_LINE6,      /**< EXTI_LINE6 */
	AFIO_LINE7,      /**< EXTI_LINE7 */
	AFIO_LINE8,      /**< EXTI_LINE8 */
	AFIO_LINE9,      /**< EXTI_LINE9 */
	AFIO_LINE10,     /**< EXTI_LINE10 */
	AFIO_LINE11,     /**< EXTI_LINE11 */
	AFIO_LINE12,     /**< EXTI_LINE12 */
	AFIO_LINE13,     /**< EXTI_LINE13 */
	AFIO_LINE14,     /**< EXTI_LINE14 */
    AFIO_LINE15,  /**< EXTI_LINE15 */
	AFIO_UNVALID/**< EXTI_UNVALID_LINE */
}AFIO_LINE_E;


void AFIO_voidSelectEXTIPort(AFIO_LINE_E AFIO_LINE_NUMBER,AFIO_GPIO_PORT_E GPIO_PORT);




#endif /* INC_MCAL_AFIO_INTERFACE_H_ */
