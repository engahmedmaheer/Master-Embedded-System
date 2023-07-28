/*
 * EXTI_Interface.h
 *
 *  Created on: Jul 17, 2023
 *      Author: AhmedMaher
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_



typedef enum
{
	RISING_EDGE,
	FAILING_EDGE,
	ON_CHANGE,
	UNUSED

}EXTI_TRIGGER_E;


typedef enum
{
	UNENABLE,
	ENABLE

}EXTI_EN_E;
typedef enum
{
	EXTI_IRQ0,      /**< EXTI_LINE0 */
	EXTI_IRQ1,      /**< EXTI_LINE1 */
	EXTI_IRQ2,      /**< EXTI_LINE2 */
	EXTI_IRQ3,      /**< EXTI_LINE3 */
	EXTI_IRQ4,      /**< EXTI_LINE4 */
	EXTI_IRQ5,      /**< EXTI_LINE5 */
	EXTI_IRQ6,      /**< EXTI_LINE6 */
	EXTI_IRQ7,      /**< EXTI_LINE7 */
	EXTI_IRQ8,      /**< EXTI_LINE8 */
	EXTI_IRQ9,      /**< EXTI_LINE9 */
	EXTI_IRQ10,     /**< EXTI_LINE10 */
	EXTI_IRQ11,     /**< EXTI_LINE11 */
	EXTI_IRQ12,     /**< EXTI_LINE12 */
	EXTI_IRQ13,     /**< EXTI_LINE13 */
	EXTI_IRQ14,     /**< EXTI_LINE14 */
    EXTI_IRQ15,     /**< EXTI_LINE15 */
	EXTI_IRQ16,     /**< EXTI_LINE16 */
	EXTI_IRQ17,     /**< EXTI_LINE17 */
	EXTI_IRQ18,     /**< EXTI_LINE18 */
	EXTI_IRQ19,     /**< EXTI_LINE19 */
	EXTI_IRQ20,     /**< EXTI_LINE20 */
	EXTI_IRQ21,     /**< EXTI_LINE21 */
	EXTI_IRQ22,     /**< EXTI_LINE22 */
//	EXTI_UNVALID_LINE/**< EXTI_UNVALID_LINE */
}EXTI_IRQ_LINE_E;


//typedef enum
//{
//	EXTI_IRQ_LINE0,      /**< EXTI_LINE0 */
//	EXTI_IRQ_LINE1,      /**< EXTI_LINE1 */
//	EXTI_IRQ_LINE2,      /**< EXTI_LINE2 */
//	EXTI_IRQ_LINE3,      /**< EXTI_LINE3 */
//	EXTI_IRQ_LINE4,      /**< EXTI_LINE4 */
//	EXTI_IRQ_LINE5_9,
//	EXTI_IRQ_LINE10_15
//
//}EXTI_IRQ_LINE_E;


typedef struct
{
	EXTI_IRQ_LINE_E 	EXTI_LINE_NUM;
	EXTI_TRIGGER_E 		TriggerType;
	EXTI_EN_E	  		 EnableState;

}EXTI_CONFIG_S;



/**
 * @brief : Function to init EXTI Configuration
 * @pre
 * @post
 * @param EXTIConfig : pointer to struct for Configuration of EXTI
 */
uint8_t EXTI_Init (EXTI_CONFIG_S* EXTIConfig);
/**
 * @brief  Function to Disable EXTI LINE
 * @pre
 * @post
 * @param EXTI_LINE : Enum For Lines
 * @return
 */
uint8_t EXTI_Disable(EXTI_IRQ_LINE_E EXTI_LINE);
/**
 * @brief  Function to Enable EXTI LINE
 * @pre
 * @post
 * @param EXTI_LINE : Enum For Lines
 * @return
 */
uint8_t EXTI_Enable(EXTI_IRQ_LINE_E EXTI_LINE);
/**
 * @brief : Function To Clear Pending Flag Of EXTI Line
 * @pre
 * @post
 * @param EXTI_LINE
 * @return
 */
uint8_t EXTI_ClearPendingFlag(EXTI_IRQ_LINE_E EXTI_LINE);
/**
 * @brief : Function To Read Pending Flag Of EXTI Line
 * @pre
 * @post
 * @param EXTI_LINE , VAL
 * @return
 */
uint8_t EXTI_ReadPendingFlag(EXTI_IRQ_LINE_E EXTI_LINE , uint8_t* VAL);
/**
 * @brief : Function To SoftwareInterruptEvent
 * @pre
 * @post
 * @param EXTI_LINE
 * @return
 */
uint8_t SoftwareInterruptEvent(EXTI_IRQ_LINE_E EXTI_LINE);
/**
 * @brief : Set Call Back Function To Handler
 * @pre
 * @post
 * @param EXTI_LINE_E
 * @param Copy_pvCallBackFunc
 * @return
 */
uint8_t EXTI_u8SetCallBack(EXTI_IRQ_LINE_E EXTI_LINE,void(*Copy_pvCallBackFunc)(void));


/**
 * @brief :Change Line Trigger
 * @pre
 * @post
 * @param Copy_TriggerSRC
 * @param EXTI_LINE_NUM
 * @return
 */
uint8_t EXTI_SetTriggerSRC(EXTI_TRIGGER_E Copy_TriggerSRC , EXTI_IRQ_LINE_E EXTI_LINE_NUM);



#endif /* EXTI_INTERFACE_H_ */
