/*******************************************************************/
/*******************************************************************/
/*******************************************************************/
/*****************   @Author:  AhmedMaher		********************/
/*****************   @Layer:   FIFO  			********************/
/*****************   @SWC:     Data Structure	********************/
/*****************	 @Version: 1.00				********************/
/*******************************************************************/
/*******************************************************************/

#include "FIFO.h"

/******************************************************************************
 * @func1 :  FIFO_Enqueue()
 *
 * Description:	the function Enqueue item To Your Buff
 *
 * Parameters:
 * @par[in]: 1- FIFO_Buff:  pointer to FIFO_Buf_t structure Data Type Which Holds the Buff Address which Want Add Data
 *		   : 2- item     : Integer Value Which want to add to Buffer
 * @par[out]:	FIFO_Status_E , Type:Enum For FIFO Statue -FIFO_NO_ERROR
 * 														  -FIFO_FULL
 * 														  -FIFO_EMPTY
 * 														  -FIFO_NULL
 *
 ******************************************************************************/
FIFO_Status_E FIFO_Enqueue (FIFO_Buf_t* FIFO_Buff , element_type item)
{
	/*Check FIFO BASE , HEAD & Tail is valid*/
	if(!FIFO_Buff->base || !FIFO_Buff->head || !FIFO_Buff->tail)
		return FIFO_NULL ;

	/*Check FIFO Is Full*/
	if(FIFO_STATUS(FIFO_Buff)==FIFO_FULL)
		return FIFO_FULL ;
	/*assign item in head then increment head */
	*(FIFO_Buff->head)= item ;
	FIFO_Buff->head++;
	FIFO_Buff->count++;


	return FIFO_NO_ERROR ;


}

/******************************************************************************
 * @func2 :  FIFO_EnqueueCircler()
 *
 * Description:	the function Enqueue Cirrculer FIFO item To Your Buff
 *
 * Parameters:
 * @par[in]: 1- FIFO_Buff:  pointer to FIFO_Buf_t structure Data Type Which Holds the Buff Address which Want Add Data
 *		   : 2- item     : Integer Value Which want to add to Buffer
 * @par[out]:	FIFO_Status_E , Type:Enum For FIFO Statue -FIFO_NO_ERROR
 * 														  -FIFO_FULL
 * 														  -FIFO_EMPTY
 * 														  -FIFO_NULL
 *
 ******************************************************************************/
FIFO_Status_E FIFO_EnqueueCircler (FIFO_Buf_t* FIFO_Buff , element_type item)
{
	/*Check FIFO BASE , HEAD & Tail is valid*/
	if(!FIFO_Buff->base || !FIFO_Buff->head || !FIFO_Buff->tail)
		return FIFO_NULL ;

	/*Check FIFO Is Full*/
	if(FIFO_STATUS(FIFO_Buff)==FIFO_FULL)
		return FIFO_FULL ;
	/*assign item in head then increment Count */
	*(FIFO_Buff->head)= item ;
	/*Increment counter of element*/
	FIFO_Buff->count++;
	if(FIFO_Buff->head ==((FIFO_Buff->base)+FIFO_Buff->lenght*(sizeof(element_type))))
	{
		/*Return To Point to First Element*/
		FIFO_Buff->head=FIFO_Buff->base ;
	}
	else
	{
		FIFO_Buff->head++;
	}

	return FIFO_NO_ERROR ;

}
/******************************************************************************
 * @func3 :  FIFO_Dequeue()
 *
 * Description:	the function Dequeue item To Your Buff
 *
 * Parameters:
 * @par[in]: 1- FIFO_Buff:  pointer to FIFO_Buf_t structure Data Type Which Holds the Buff Address Which want to Get Value From Buffer
 *		   : 2- item     : Integer Value Which want to Get Value From Buffer
 * @par[out]:	FIFO_Status_E , Type:Enum For FIFO Statue -FIFO_NO_ERROR
 * 														  -FIFO_FULL
 * 														  -FIFO_EMPTY
 * 														  -FIFO_NULL
 *
 ******************************************************************************/
FIFO_Status_E FIFO_Dequeue (FIFO_Buf_t* FIFO_Buff , element_type* item)
{
	/*Check FIFO BASE , HEAD & Tail is valid*/
	if(!FIFO_Buff->base || !FIFO_Buff->head || !FIFO_Buff->tail)
		return FIFO_NULL ;
	/*Check FIFO Empty */
	if(FIFO_STATUS(FIFO_Buff)==FIFO_EMPTY)
		return FIFO_EMPTY ;
	/*Want Return Data*/
	*item=*(FIFO_Buff->tail) ;
	/*dECREMNT Count item*/
	FIFO_Buff->count--;
	if(FIFO_Buff->tail ==((FIFO_Buff->base)+FIFO_Buff->lenght*(sizeof(element_type))))
	{
		/*Return To Point to First Element (Reference)*/
		FIFO_Buff->tail=FIFO_Buff->base ;
	}
	else
	{
		FIFO_Buff->tail++;
	}

	return FIFO_NO_ERROR;

}

/*********************************************************************************
 * @func4 :  FIFO_Init()
 *
 * Description:	the function Create Buffer
 *
 * Parameters:
 * @par[in] : 1- FIFO_Buff   :  pointer to FIFO_Buf_t structure Data Type Which Holds the Buff Address which Want Init
 *		    : 2- FIFOBuff    :  Integer Pointer Which Hold Address Of Array Which Want To Make it Your Buffer
 *		    : 3- Length 	 :  Length of Buffer Which i want init
 * @par[out]:	FIFO_Status_E , Type: enum For FIFO Statue -FIFO_NO_ERROR
 * 														   -FIFO_FULL
 * 														   -FIFO_EMPTY
 * 														   -FIFO_NULL
 *
 ******************************************************************************/
FIFO_Status_E FIFO_Init (FIFO_Buf_t* FIFO_Buff , element_type* FIFOBuff , unsigned int Length)
{
	/*Check FIFO Buff Null or Not*/
	if (!FIFO_Buff)
		return FIFO_NULL;
	/*init element of Buff*/
	FIFO_Buff->base=FIFOBuff;
	FIFO_Buff->head=FIFOBuff;
	FIFO_Buff->tail=FIFOBuff;
	FIFO_Buff->lenght=Length;
	FIFO_Buff->count=NO_ITEM;

	return FIFO_NO_ERROR ;

}

/*********************************************************************************
 * @func5 :  FIFO_STATUS()
 *
 * Description:	the function Check FIFO Is Full Or Not
 *
 * Parameters:
 * @par[in] : 1- FIFO_Buff   :  pointer to FIFO_Buf_t structure Data Type Which Holds the Buff Address which Want Init
 * @par[out]:	FIFO_Status_E , Type: enum For FIFO Statue -FIFO_NO_ERROR
 * 														   -FIFO_FULL
 * 														   -FIFO_EMPTY
 * 														   -FIFO_NULL
 *
 ******************************************************************************/
FIFO_Status_E FIFO_STATUS (FIFO_Buf_t* FIFO_Buff )
{
	/*Check FIFO BASE , HEAD & Tail is valid*/
	if(!FIFO_Buff->base || !FIFO_Buff->head || !FIFO_Buff->tail)
		return FIFO_NULL ;
	/*Check FIFO Is Full */
	if(FIFO_Buff->lenght == FIFO_Buff->count)
		return FIFO_FULL ;
	if(FIFO_Buff->count == NO_ITEM)
		return FIFO_EMPTY;
	/*Return Status NO Error*/
	return FIFO_NO_ERROR ;
}
/*********************************************************************************
 * @func6 :  FIFO_Print()
 *
 * Description:	the function Print Buffer item
 *
 * Parameters:
 * @par[in] : 1- FIFO_Buff   :  pointer to FIFO_Buf_t structure Data Type Which Holds the Buff Address which Want Init
 * @par[out]:	FIFO_Status_E , Type: enum For FIFO Statue -FIFO_NO_ERROR
 * 														   -FIFO_FULL
 * 														   -FIFO_EMPTY
 * 														   -FIFO_NULL
 *
 ******************************************************************************/
FIFO_Status_E FIFO_Print (FIFO_Buf_t* FIFO_Buff )
{

	element_type* temp ;
	int i ;
	if(FIFO_STATUS(FIFO_Buff)==FIFO_EMPTY)
	{
		printf("\n-------------FIFO Empty-------\n");
		return FIFO_EMPTY;
	}
		else
	{
			temp = FIFO_Buff->tail;
			printf("\n------FIFO Print---------\n");
			for(i=0 ; i < FIFO_Buff->count ; i++)
			{
				printf("\t %x \n", *temp);
				temp++;
			}
			printf("-----------------\n");
	}









}
