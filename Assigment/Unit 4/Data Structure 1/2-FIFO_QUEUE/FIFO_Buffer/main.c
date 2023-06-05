/*******************************************************************/
/*******************************************************************/
/*****************   @Author:  AhmedMaher		********************/
/*****************   @Layer:   FIFO			********************/
/*****************   @SWC:     Data Structure	********************/
/*****************	 @Version: 1.00				********************/
/*******************************************************************/
/*******************************************************************/

#include "FIFO.h"
#include <stdio.h>
#include <stdlib.h>


void main()
{
	/*init FIFO BUFFER*/
	FIFO_Buf_t FIFO_UART ;
	int  temp =0;
	element_type i ;

	/*Check FIFO BUFFER Valid*/
	if(FIFO_Init(&FIFO_UART, &Uart_Buffer, 5) == FIFO_NO_ERROR)
	{
		printf("------------FIFO Init DONE---------- \n");
	}
	else
	{
		switch((FIFO_Init(&FIFO_UART, &Uart_Buffer, 5)))
		{
		case FIFO_EMPTY: printf("FIFO EMPTY \n"); break;
		case FIFO_FULL : printf("FIFO EMPTY \n"); break;
		case FIFO_NULL : printf("FIFO NULL \n"); break;
		default : printf("Undefined Error\n"); break;
		}
	}

	/*Enqueue Items From FIFO*/

	for(i=0 ; i<7 ; i++)
	{
		printf("FIFO Enqueue (%x) \n",i);
		if(FIFO_EnqueueCircler(&FIFO_UART, i) == FIFO_NO_ERROR)
		{
			printf("\t------------FIFO Enqueue DONE---------- \n");
		}
		else
		{
			switch((FIFO_Enqueue(&FIFO_UART, i)))
			{
			case FIFO_EMPTY: printf("\tFIFO EMPTY \n"); break;
			case FIFO_FULL : printf("\t FIFO EMPTY \n"); break;
			case FIFO_NULL : printf("\t FIFO NULL \n"); break;
			default : printf("\t Undefined Error \n"); break;
			}
		}
	}

	/*Print FIFO Item*/
	FIFO_Print(&FIFO_UART);

	/*FIFO Dequeue (Get item)*/
	if(FIFO_Dequeue(&FIFO_UART, &temp) == FIFO_NO_ERROR)
	{
		printf("\t------------FIFO Enqueue (%x) ---------- \n",temp);
	}
	else
	{
		switch((FIFO_Dequeue(&FIFO_UART, &temp)))
		{
		case FIFO_EMPTY: printf("\tFIFO EMPTY \n"); break;
		case FIFO_FULL : printf("\t FIFO EMPTY \n"); break;
		case FIFO_NULL : printf("\t FIFO NULL \n"); break;
		default : printf("\t Undefined Error \n"); break;
		}
	}
	/*FIFO Dequeue (Get item)*/
		if(FIFO_Dequeue(&FIFO_UART, &temp) == FIFO_NO_ERROR)
		{
			printf("\t------------FIFO Enqueue (%x) ---------- \n",temp);
		}
		else
		{
			switch((FIFO_Dequeue(&FIFO_UART, &temp)))
			{
			case FIFO_EMPTY: printf("\tFIFO EMPTY \n"); break;
			case FIFO_FULL : printf("\t FIFO EMPTY \n"); break;
			case FIFO_NULL : printf("\t FIFO NULL \n"); break;
			default : printf("\t Undefined Error \n"); break;
			}
		}
		FIFO_Print(&FIFO_UART);




}

