/*******************************************************************/
/*******************************************************************/
/*****************   @Author:  AhmedMaher		********************/
/*****************   @Layer:   MCAL				********************/
/*****************   @SWC:     NVIC				********************/
/*****************	 @Version: 1.00				********************/
/*******************************************************************/
/*******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "BIT_MATH.h"
#include "ERR_TYPE.h"

#include "NVIC_Private.h"
#include "STM32F103x6.h"
#include "NVIC_Interface.h"


/**
 * @brief  : Function used For Enable IRQ Peripheral
 * @post   :
 * @param  : IRQ Number (IRQNUM_E)
 * @return : LocalErrorStatus
 */
uint8_t NVICEnable (IRQNUM_E IRQ )
{
	uint8_t LocalErrorState = OK;

	uint8_t LocalRegisterNum = IRQ/32 ;

	uint8_t LocalBitNum = IRQ%32;

	if(IRQ<MAX_IRQ)
	{
		ATOMIC_SET_BIT(NVIC->NVIC_ISER[LocalRegisterNum],LocalBitNum);
	}
	else
	{
		LocalErrorState =NOK;
	}
	return LocalErrorState;

}
/**
 * @brief  : Function used For Disable IRQ Peripheral
 * @post
 * @param  : IQR Number (IRQNUM_E)
 * @return : LocalErrorStatus
 */
uint8_t NVICDisable (IRQNUM_E IRQ )
{
	uint8_t LocalErrorState = OK;

	uint8_t LocalRegisterNum = IRQ/32 ;

	uint8_t LocalBitNum = IRQ%32;

	if(IRQ<MAX_IRQ)
	{
		ATOMIC_SET_BIT(NVIC->NVIC_ICER[LocalRegisterNum],LocalBitNum);
	}
	else
	{
		LocalErrorState =NOK;
	}
	return LocalErrorState;

}
/**
 * @brief  : Function used For Set Pending Flag For Peripheral
 * @post
 * @param  : IRQ Number (IRQNUM_E)
 * @return : LocalErrorStatus
 */
uint8_t NVIC_SetPendingFlag(IRQNUM_E IRQ)
{
	uint8_t LocalErrorState = OK;

	uint8_t LocalRegisterNum = IRQ/32 ;

	uint8_t LocalBitNum = IRQ%32;

	if(IRQ<MAX_IRQ)
	{
		ATOMIC_SET_BIT(NVIC->NVIC_ISPR[LocalRegisterNum],LocalBitNum);
	}
	else
	{
		LocalErrorState =NOK;
	}
	return LocalErrorState;


}
/**
 * @brief  : Function used For Clear Pending Flag For Peripheral
 * @post
 * @param  : IRQ Number (IRQNUM_E)
 * @return : LocalErrorStatus
 */
uint8_t NVIC_ClearPendingFlag(IRQNUM_E IRQ)
{
	uint8_t LocalErrorState = OK;

	uint8_t LocalRegisterNum = IRQ/32 ;

	uint8_t LocalBitNum = IRQ%32;

	if(IRQ<MAX_IRQ)
	{
		ATOMIC_SET_BIT(NVIC->NVIC_ICPR[LocalRegisterNum],LocalBitNum);
	}
	else
	{
		LocalErrorState =NOK;
	}


	return LocalErrorState;
}
/**
 * @brief  : Function used For Get Status Pending Flag For Peripheral
 * @post
 * @param  : IQR Number (IRQNUM_E)
 * @param  : Pointer to Active Flag Value
 * @return : LocalErrorStatus | Value Of Flag
 */
uint8_t NVIC_GetActiveFlag(IRQNUM_E IQR , uint8_t* ActiveVal)
{
	uint8_t LocalErrorState = OK;
	uint8_t LocalRegisterNum = IQR/32 ;

	uint8_t LocalBitNum = IQR%32;


	if (IQR< MAX_IRQ && ActiveVal != NULL)
	{
		*ActiveVal=GET_BIT(NVIC->NVIC_IPR[LocalRegisterNum],LocalBitNum);
	}
	else
	{
		LocalErrorState = NOK ;
	}
	return LocalErrorState;

}

/**
 * @brief  : Function To Set Priority For IRQ I
 * @param  :   IQR Number , Priority Number
 * @post   :
 * @return : LocalErrorStatus
 */
uint8_t NVIC_U8SetIRQPriorty(IRQNUM_E IRQ , uint8_t CopyU8_Priorty)
{
	uint8_t LocalErrorState = OK;

	NVIC->NVIC_IPR[IRQ]=CopyU8_Priorty<<IPR_MASK;


	return LocalErrorState ;
}



