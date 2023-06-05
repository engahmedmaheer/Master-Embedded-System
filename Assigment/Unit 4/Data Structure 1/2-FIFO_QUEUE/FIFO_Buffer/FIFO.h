/*******************************************************************/
/*******************************************************************/
/*****************   @Author:  AhmedMaher		********************/
/*****************   @Layer:   DataStructure	********************/
/*****************   @SWC:     FIFO				********************/
/*****************	 @Version: 1.00				********************/
/*******************************************************************/
/*******************************************************************/


#ifndef FIFO_H_
#define FIFO_H_
#include <stdio.h>
#include <stdint.h>



/********User Configuration*************
 * Select element type
 * uint8_t
 * uint16_t
 * uint32_t
 * */
#define element_type uint8_t
#define width1		5

/***********Create Buffer*****************/
element_type Uart_Buffer[width1];


/***********FIFO Data Type***********************/
typedef struct
{
	unsigned int lenght ;
	unsigned int count  ;
	element_type* base  ;
	element_type* head  ;
	element_type* tail  ;


}FIFO_Buf_t;

typedef enum
{
	FIFO_NO_ERROR,
	FIFO_FULL,
	FIFO_EMPTY,
	FIFO_NULL

}FIFO_Status_E;

#define NO_ITEM		0

/******************************APIS*******************************************/
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
FIFO_Status_E FIFO_Enqueue (FIFO_Buf_t* FIFO_Buff , element_type item);
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
FIFO_Status_E FIFO_EnqueueCircler (FIFO_Buf_t* FIFO_Buff , element_type item);

/******************************************************************************
 * @func2 :  FIFO_Dequeue()
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

FIFO_Status_E FIFO_Dequeue (FIFO_Buf_t* FIFO_Buff , element_type* item);

/*********************************************************************************
 * @func3 :  FIFO_Init()
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
FIFO_Status_E FIFO_Init (FIFO_Buf_t* FIFO_Buff , element_type* FIFOBuff , unsigned int Length);

/*********************************************************************************
 * @func3 :  FIFO_STATUS()
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
FIFO_Status_E FIFO_STATUS (FIFO_Buf_t* FIFO_Buff );


/*********************************************************************************
 * @func5 :  FIFO_Print()
 *
 * Description:	the function Print Buffer
 *
 * Parameters:
 * @par[in] : 1- FIFO_Buff   :  pointer to FIFO_Buf_t structure Data Type Which Holds the Buff Address which Want Init
 * @par[out]:	FIFO_Status_E , Type: enum For FIFO Statue -FIFO_NO_ERROR
 * 														   -FIFO_FULL
 * 														   -FIFO_EMPTY
 * 														   -FIFO_NULL
 *
 ******************************************************************************/
FIFO_Status_E FIFO_Print (FIFO_Buf_t* FIFO_Buff );


#endif /* FIFO_H_ */
