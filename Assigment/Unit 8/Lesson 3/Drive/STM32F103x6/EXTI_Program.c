#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "BIT_MATH.h"
#include "ERR_TYPE.h"

#include "STM32F103x6.h"
#include "EXTI_Private.h"
#include "EXTI_Interface.h"
#include "EXTI_Config.h"

/**
 * @brief :static Global array of pointer to functions for EXTI IRQ Handler
 * @pre
 * @post
 */
static void (*EXTI_pvCallBackFunc[NUM_EXTI_LINE])(void)={NULL};
/**
 * @brief : Function to init EXTI Configuration
 * @pre
 * @post
 * @param EXTIConfig : pointer to struct for Configuration of EXTI
 */
uint8_t EXTI_Init(EXTI_CONFIG_S* EXTIConfig)
{
	uint8_t LocalErrorState = OK ;


	//	EXTI->IMR << (EXTIConfig->EXTI_LINE_NUM)=EXTIConfig->EnableState;


	switch(EXTIConfig->TriggerType)
	{
	case RISING_EDGE  :SET_BIT(EXTI->RTSR,EXTIConfig->EXTI_LINE_NUM );
	CLR_BIT(EXTI->FTSR,EXTIConfig->EXTI_LINE_NUM ); break;
	case FAILING_EDGE :SET_BIT(EXTI->FTSR,EXTIConfig->EXTI_LINE_NUM );
	CLR_BIT(EXTI->RTSR,EXTIConfig->EXTI_LINE_NUM );break;
	case ON_CHANGE :
		SET_BIT(EXTI->RTSR,EXTIConfig->EXTI_LINE_NUM ) ;
		SET_BIT(EXTI->FTSR,EXTIConfig->EXTI_LINE_NUM ) ;
		break;

	default :LocalErrorState = NOK;
	}
	switch(EXTIConfig->EnableState)
	{
	case ENABLE :		SET_BIT(EXTI->IMR,EXTIConfig->EXTI_LINE_NUM);			break;
	case UNENABLE :		CLR_BIT(EXTI->IMR,EXTIConfig->EXTI_LINE_NUM);			break;
	default:			LocalErrorState=NOK;									break;
	}

	return LocalErrorState;
}
/**
 * @brief  Function to Enable EXTI LINE
 * @pre
 * @post
 * @param EXTI_LINE : Enum For Lines
 * @return
 */
uint8_t EXTI_Enable(EXTI_IRQ_LINE_E EXTI_LINE)
{
	uint8_t LocalErrorState = OK ;

	SET_BIT(EXTI->IMR,EXTI_LINE);

	return LocalErrorState;
}
/**
 * @brief  Function to Disable EXTI LINE
 * @pre
 * @post
 * @param EXTI_LINE : Enum For Lines
 * @return LocalErrorState
 */
uint8_t EXTI_Disable(EXTI_IRQ_LINE_E EXTI_LINE)
{
	uint8_t LocalErrorState = OK ;

	CLR_BIT(EXTI->IMR,EXTI_LINE);

	return LocalErrorState;

}
/**
 * @brief : Function To Clear Pending Flag Of EXTI Line
 * @pre
 * @post
 * @param EXTI_LINE
 * @return LocalErrorState
 */
uint8_t EXTI_ClearPendingFlag(EXTI_IRQ_LINE_E EXTI_LINE)
{
	uint8_t LocalErrorState = OK ;


	SET_BIT(EXTI->PR,EXTI_LINE);


	return LocalErrorState;

}
/**
 * @brief : Function To Read Pending Flag Of EXTI Line
 * @pre
 * @post
 * @param EXTI_LINE
 * @return LocalErrorState
 */
uint8_t EXTI_ReadPendingFlag(EXTI_IRQ_LINE_E EXTI_LINE , uint8_t* VAL)
{
	uint8_t LocalErrorState = OK ;

	if(VAL != NULL)
	{
		*VAL = GET_BIT(EXTI->PR,EXTI_LINE);
	}
	else
	{
		//error
	}

	return LocalErrorState;

}
/**
 * @brief : Function To SoftwareInterruptEvent
 * @pre
 * @post
 * @param EXTI_LINE
 * @return
 */
uint8_t SoftwareInterruptEvent(EXTI_IRQ_LINE_E EXTI_LINE)
{

	uint8_t LocalErrorState = OK ;


	SET_BIT(EXTI->SWIER,EXTI_LINE);


	return LocalErrorState;


}

/**
 * @brief
 * @pre
 * @post
 * @param Copy_TriggerSRC
 * @param EXTI_LINE_NUM
 * @return
 */
uint8_t EXTI_SetTriggerSRC(EXTI_TRIGGER_E Copy_TriggerSRC , EXTI_IRQ_LINE_E EXTI_LINE_NUM)
{
	uint8_t LocalErrorState = OK ;



	switch(Copy_TriggerSRC)
	{
	case RISING_EDGE  :SET_BIT(EXTI->RTSR,EXTI_LINE_NUM );
	CLR_BIT(EXTI->FTSR,EXTI_LINE_NUM ); break;
	case FAILING_EDGE :SET_BIT(EXTI->FTSR,EXTI_LINE_NUM );
	CLR_BIT(EXTI->RTSR,EXTI_LINE_NUM );break;
	case ON_CHANGE :
		SET_BIT(EXTI->RTSR,EXTI_LINE_NUM ) ;
		SET_BIT(EXTI->FTSR,EXTI_LINE_NUM ) ;
		break;

	default :LocalErrorState = NOK;
	}


	return LocalErrorState;
}
/**
 * @brief : Set Call Back Function To Handler
 * @pre
 * @post
 * @param EXTI_LINE
 * @param Copy_pvCallBackFunc
 * @return LocalErrorState
 */
uint8_t EXTI_u8SetCallBack(EXTI_IRQ_LINE_E EXTI_LINE,void(*Copy_pvCallBackFunc)(void))
{
	uint8_t LocalErrorState = OK ;
	if(Copy_pvCallBackFunc != NULL)
	{

		EXTI_pvCallBackFunc[EXTI_LINE] =Copy_pvCallBackFunc;
	}
	else
	{
		/*********NULL ERROR**********/
		LocalErrorState =NULL_POINTER;
	}

	return LocalErrorState;
}

void EXTI0_IRQHandler()
{

	/*Clear pending flag*/
	SET_BIT(EXTI->PR,EXTI_IRQ0);
	/*CALLING IRQ Handler*/
	EXTI_pvCallBackFunc[EXTI_IRQ0]();

}
void EXTI1_IRQHandler()
{
	/*Clear pending flag*/
	SET_BIT(EXTI->PR,EXTI_IRQ1);
	/*CALLING IRQ Handler*/
	EXTI_pvCallBackFunc[EXTI_IRQ1]();

}
void EXTI2_IRQHandler()
{

	/*Clear pending flag*/
	SET_BIT(EXTI->PR,EXTI_IRQ2);
	/*CALLING IRQ Handler*/
	EXTI_pvCallBackFunc[EXTI_IRQ2]();

}
void EXTI3_IRQHandler()
{

	/*Clear pending flag*/
	SET_BIT(EXTI->PR,EXTI_IRQ3);
	/*CALLING IRQ Handler*/
	EXTI_pvCallBackFunc[EXTI_IRQ3]();

}
void EXTI9_5_IRQHandler()
{

	/*Switch Flag if raised*/
	if(EXTI5_FLAG==Raised)
	{
		/*Clear pending flag*/
		SET_BIT(EXTI->PR,EXTI_IRQ5);
		/*CALLING IRQ Handler*/
		EXTI_pvCallBackFunc[EXTI_IRQ5]();
	}
	if(EXTI6_FLAG==Raised)
	{
		/*Clear pending flag*/
		SET_BIT(EXTI->PR,EXTI_IRQ6);
		/*CALLING IRQ Handler*/
		EXTI_pvCallBackFunc[EXTI_IRQ6]();
	}
	if(EXTI7_FLAG==Raised)
	{
		/*Clear pending flag*/
		SET_BIT(EXTI->PR,EXTI_IRQ7);
		/*CALLING IRQ Handler*/
		EXTI_pvCallBackFunc[EXTI_IRQ7]();
	}
	if(EXTI8_FLAG==Raised)
	{
		/*Clear pending flag*/
		SET_BIT(EXTI->PR,EXTI_IRQ8);
		/*CALLING IRQ Handler*/
		EXTI_pvCallBackFunc[EXTI_IRQ8]();
	}
	if(EXTI9_FLAG==Raised)
	{
		/*Clear pending flag*/
		SET_BIT(EXTI->PR,EXTI_IRQ9);
		/*CALLING IRQ Handler*/
		EXTI_pvCallBackFunc[EXTI_IRQ9]();
	}
	else
	{
		//error
	}

}
void EXTI15_10_IRQHandler()
{
	/*Switch Flag if raised*/
	if(EXTI10_FLAG==Raised)
	{
		/*Clear pending flag*/
		SET_BIT(EXTI->PR,EXTI_IRQ10);
		/*CALLING IRQ Handler*/


		EXTI_pvCallBackFunc[EXTI_IRQ10]();
	}
	if(EXTI11_FLAG==Raised)
	{
		/*Clear pending flag*/
		SET_BIT(EXTI->PR,EXTI_IRQ11);
		/*CALLING IRQ Handler*/
		EXTI_pvCallBackFunc[EXTI_IRQ11]();
	}
	if(EXTI12_FLAG==Raised)
	{
		/*Clear pending flag*/
		SET_BIT(EXTI->PR,EXTI_IRQ12);
		/*CALLING IRQ Handler*/
		EXTI_pvCallBackFunc[EXTI_IRQ12]();
	}
	if(EXTI13_FLAG==Raised)
	{
		/*Clear pending flag*/
		SET_BIT(EXTI->PR,EXTI_IRQ13);
		/*CALLING IRQ Handler*/
		EXTI_pvCallBackFunc[EXTI_IRQ13]();
	}
	if(EXTI14_FLAG==Raised)
	{
		/*Clear pending flag*/
		SET_BIT(EXTI->PR,EXTI_IRQ14);
		/*CALLING IRQ Handler*/
		EXTI_pvCallBackFunc[EXTI_IRQ14]();
	}
	if(EXTI15_FLAG==Raised)
	{
		/*Clear pending flag*/
		SET_BIT(EXTI->PR,EXTI_IRQ15);
		/*CALLING IRQ Handler*/
		EXTI_pvCallBackFunc[EXTI_IRQ15]();
	}
	else
	{
		//error
	}
}

