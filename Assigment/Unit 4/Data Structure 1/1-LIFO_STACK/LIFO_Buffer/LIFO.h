/*******************************************************************/
/*******************************************************************/
/*****************   @Author:  AhmedMaher		********************/
/*****************   @Layer:   DataStructure	********************/
/*****************   @SWC:     LIFO				********************/
/*****************	 @Version: 1.00				********************/
/*******************************************************************/
/*******************************************************************/


#ifndef LIFO_H_
#define LIFO_H_
#include <stdint.h>

/*TypeDefination*/

typedef struct
{
	unsigned int lenght ;
	unsigned int count  ;
	unsigned int* base  ;
	unsigned int* head  ;

}LIFO_Buf_t;

typedef enum
{
LIFO_NO_ERROR,
LIFO_FULL,
LIFO_EMPTY,
LIFO_NULL

}LIFO_Status_E;

#define NO_ITEM		0

/******************************APIS*******************************************/
/******************************************************************************
 * @func1 :  LIFO_Add_Item()
 *
 * Description:	the function Add item To Your Buff
 *
 * Parameters:
 * @par[in]: 1- LIFO_Buff:  pointer to LIFO_Buf_t structure Data Type Which Holds the Buff Address which Want Add Data
 *		   : 2- item     : Integer Value Which want to add to Buffer
 * @par[out]:	LIFO_Status_E , Type:Enum For LIFO Statue -LIFO_NO_ERROR
 * 														  -LIFO_FULL
 * 														  -LIFO_EMPTY
 * 														  -LIFO_NULL
 *
 ******************************************************************************/
LIFO_Status_E LIFO_Add_Item (LIFO_Buf_t* LIFO_Buff , uint8_t item);

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
LIFO_Status_E LIFO_Get_Item (LIFO_Buf_t* LIFO_Buff , unsigned int* item);

/*********************************************************************************
 * @func3 :  LIFO_Init()
 *
 * Description:	the function Create Buffer
 *
 * Parameters:
 * @par[in]: 1- LIFO_Buff:  pointer to LIFO_Buf_t structure Data Type Which Holds the Buff Address which Want Init
 *		   : 2- Buff     :  Integer Pointer Which Hold Address Of Array Which Want To Make it Your Buffer
 *		   : 3- Length 	 :  Length of Buffer Which i want init
 * @par[out]:	LIFO_Status_E , Type: enum For LIFO Statue -LIFO_NO_ERROR
 * 														   -LIFO_FULL
 * 														   -LIFO_EMPTY
 * 														   -LIFO_NULL
 *
 ******************************************************************************/
LIFO_Status_E LIFO_Init (LIFO_Buf_t* LIFO_Buff , unsigned int* Buff , unsigned int Length);


#endif /* LIFO_H_ */
