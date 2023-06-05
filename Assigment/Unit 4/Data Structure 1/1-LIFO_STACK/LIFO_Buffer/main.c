/*******************************************************************/
/*******************************************************************/
/*****************   @Author:  AhmedMaher		********************/
/*****************   @Layer:   STACK			********************/
/*****************   @SWC:     Data Structure	********************/
/*****************	 @Version: 1.00				********************/
/*******************************************************************/
/*******************************************************************/

#include "LIFO.h"
#include <stdio.h>
#include <stdlib.h>


uint8_t Buffer1[5];


void main()
{
	int i , temp =0 ;
	LIFO_Buf_t Uart_LIFO  , I2C_LIFO;
	/*Static Allocation*/
	LIFO_Init(&Uart_LIFO, &Buffer1 ,5);
	/*Dynamic Allocation*/
	unsigned int* Buffer2 = (unsigned int*) malloc(5*sizeof(unsigned int));
	LIFO_Init(&I2C_LIFO, &Buffer2 ,5);

	for(i=0 ; i<5 ; i++)
	{
		if(LIFO_Add_Item(&Uart_LIFO , i) == LIFO_NO_ERROR)
		{
			printf("UART LIFO Add : %d \n", i);
		}
		else
			{
						switch(LIFO_Add_Item(&Uart_LIFO , i))
					{
						case LIFO_EMPTY :
							printf("LIFO IS EMPTY"); break;
						case LIFO_FULL :
							printf("LIFO IS FULL"); break;
						case LIFO_NULL :
							printf("LIFO IS NULL"); break;
						default:
							printf("LIFO Undefined Error");
					}
			}


	}
	for(i=0 ; i<5 ; i++)
		{
		if(LIFO_Get_Item(&Uart_LIFO, &temp) == LIFO_NO_ERROR)
			printf("UART LIFO get : %d \n", temp);
		else
			{
				switch(LIFO_Get_Item(&Uart_LIFO, &temp))
				{
				case LIFO_EMPTY :
					printf("LIFO IS EMPTY"); break;
				case LIFO_FULL :
					printf("LIFO IS FULL"); break;
				case LIFO_NULL :
					printf("LIFO IS NULL"); break;
				default:
					printf("LIFO Undefined Error");
				}
			}
		}




}

