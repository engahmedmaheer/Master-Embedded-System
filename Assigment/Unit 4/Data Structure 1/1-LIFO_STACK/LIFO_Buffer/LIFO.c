/*******************************************************************/
/*******************************************************************/
/*******************************************************************/
/*****************   @Author:  AhmedMaher		********************/
/*****************   @Layer:   STACK			********************/
/*****************   @SWC:     Data Structure	********************/
/*****************	 @Version: 1.00				********************/
/*******************************************************************/
/*******************************************************************/


#include "LIFO.h"

/******************************************************************************
 * @func1 :  LIFO_Add_Item()
 *
 * Description:	the function Add item To Your Buff
 *
 * Parameters:
 * @par[in]: 1- LIFO_Buff:  pointer to LIFO_Buf_t structure Data Type Which Holds the Buff Address which Want Add Data
 *		   : 2- item     : Integer Value Which want to add to Buffer
 * @par[out]:	LIFO_Status_E , Type: Enum For LIFO Statue -LIFO_NO_ERROR
 * 														  -LIFO_FULL
 * 														  -LIFO_EMPTY
 * 														  -LIFO_NULL
 *
 ******************************************************************************/
LIFO_Status_E LIFO_Add_Item (LIFO_Buf_t* LIFO_Buff , uint8_t item)
{
	/* 1- Check LIFO Is Valid  (!= Null) */
	if(!LIFO_Buff->base ||!LIFO_Buff->head )
	{
		return LIFO_NULL ;
	}

	/*2- Check LIFO if Full*/
	if (LIFO_Buff->count == LIFO_Buff->lenght)
	{
		return LIFO_FULL ;
	}

	/*Set LIFO Item*/
	/*Assign item value into LIFO Head */
	*(LIFO_Buff->head) = item ;

	/*Increment Head To Point to Next Element */
	LIFO_Buff->head++;

	/*Increment Count */
	LIFO_Buff->count++;


	return LIFO_NO_ERROR ;
}

/******************************************************************************
 * @func2 :  LIFO_Get_Item()
 *
 * Description:	the function Get item To Your Buff
 *
 * Parameters:
 * @par[in]: 1- LIFO_Buff:  pointer to LIFO_Buf_t structure Data Type Which Holds the Buff Address Which want to Get Value From Buffer
 *		   : 2- item     : Integer Value Which want to Get Value From Buffer
 * @par[out]:	LIFO_Status_E , Type:Enum For LIFO Statue -LIFO_NO_ERROR
 * 														  -LIFO_FULL
 * 														  -LIFO_EMPTY
 * 														  -LIFO_NULL
 *
 ******************************************************************************/
LIFO_Status_E LIFO_Get_Item (LIFO_Buf_t* LIFO_Buff , unsigned int* item)
{
	/* 1- Check LIFO Is Valid  (!= Null) */
		if(!LIFO_Buff->base ||!LIFO_Buff->head )
		{
			return LIFO_NULL ;
		}

	/* 2- Check LIFO IS EMPTY  */
		 if ((LIFO_Buff->count = NO_ITEM))
		{
				return LIFO_EMPTY ;
		}
   /* 3- Decrement Head To Point to Last Element */

		 	LIFO_Buff->head--;

  /* 4- Assign Value in Item */

		 	*item=*(LIFO_Buff->head);

  /* 5- Decrement Count of item*/
		 	LIFO_Buff->count--;

		return LIFO_NO_ERROR ;
}

/******************************************************************************
 * @func3 :  LIFO_Init()
 *
 * Description:	the function Create Buffer
 *
 * Parameters:
 * @par[in] : 1- LIFO_Buff:  pointer to LIFO_Buf_t structure Data Type Which Holds the Buff Address which Want Init
 *		    : 2- Buff     :  Integer Pointer Which Hold Address Of Array Which Want To Make it Your Buffer
 *		    : 3- Length 	 :  Length of Buffer Which i want init
 * @par[out]: 1- LIFO_Status_E , Type: enum For LIFO Statue -LIFO_NO_ERROR
 * 														   -LIFO_FULL
 * 														   -LIFO_EMPTY
 * 														   -LIFO_NULL
 *
 ******************************************************************************/
LIFO_Status_E LIFO_Init (LIFO_Buf_t* LIFO_Buff , unsigned int* Buff , unsigned int Length)
{
	/*Check The Buff If Valid Or Not Before Init*/
	if(Buff != NULL)
	{

	/*LIFO Base Address = Buff[0] */
	LIFO_Buff->base = Buff ;

	/*LIFO Head Address = Buff[0] */
	LIFO_Buff->head = Buff ;

	/*LIFO Length  = Length */
	LIFO_Buff->lenght = Length ;

	/*LIFO Count  = 0 */
	LIFO_Buff->count = NO_ITEM ;
	}
	else
	{
		return LIFO_NULL ;
	}

	return LIFO_NO_ERROR ;
}




