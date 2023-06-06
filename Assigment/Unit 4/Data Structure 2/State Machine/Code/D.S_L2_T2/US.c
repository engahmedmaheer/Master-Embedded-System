/*******************************************************************/
/*******************************************************************/
/*****************   @Author:  AhmedMaher		********************/
/*****************   @Layer:   AC				********************/
/*****************   @Date:    6-June2023       ********************/
/*****************	 @Version: 1.00				********************/
/*******************************************************************/
/*******************************************************************/
#include "US.h"

/**attribute value (Block Only)****/

static int US_distance = 0;


/**State Pointer to Function*******/

void (*US_state)();


/*********APIS********************/




/******************************************************************************
 * @func1 :  US_Busy
 *
 * Description:	the function initialize For Status Busy For the object
 * Parameters:
 * @par[in]: any Type
 *
 * @par[out]:	void()
 *
 ******************************************************************************/


STATE_define(US_busy)
{
	/* 1- State Name */

	US_state_id = US_busy ;



	/* ACTION ----> DC_MOTOR(US_speed)*/
	/*Get Distance From UltraSonic*/
	US_distance =US_GET_DS_Random(45,55,1);
	/* 3- Event Check */

	/*4- Print Distance & Speed*/

	printf("US_Waiting : Distance : %d  \n",US_distance );

	US_Set_Distance(US_distance);
	/*Looping*/
	US_state = STATE(US_busy);

}
/******************************************************************************
 * @func3 :  US_GET_DS_Random
 *
 * Description:	the function initialize For Get Distance From Ultrasonic Sensor
 *
 * 			   --> For Test We Use rand Function
 *
 * Parameters:
 * @par[in]:   -1 Max Value
 *			   -2 Min Value
 *			   -3 Count Number Which Want Rand
 * @par[out]:	integer Value --->	(Distance)
 *
 ******************************************************************************/

int US_GET_DS_Random(int max , int min , int count)
{
	int i;
	for (i=0 ;i< count ; i++)
	{
		int rand_num=(rand()% (min-max +1))+max ;
		return rand_num;
	}

}

/******************************************************************************
 * @func4 :  US_Init
 *
 * Description:	the function initialize  Ultrasonic Sensor
 *
 * 			   --> For Test We Use rand Function
 *
 * Parameters:
 * @par[in]:  	any type
 * @par[out]:	void
 *
 ******************************************************************************/

void US_Init()
{

	/*init all Drivers*/
	printf("====US Init=== \n");

}




