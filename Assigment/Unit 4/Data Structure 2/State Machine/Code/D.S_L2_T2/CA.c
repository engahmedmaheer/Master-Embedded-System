/*******************************************************************/
/*******************************************************************/
/*****************   @Author:  AhmedMaher		********************/
/*****************   @Layer:   AC				********************/
/*****************   @Date:    6-June2023       ********************/
/*****************	 @Version: 1.00				********************/
/*******************************************************************/
/*******************************************************************/
#include "CA.h"

/**attribute value (Block Only)****/
static int CA_speed = 0;
static int CA_distance = 0;
static int CA_thresholed = 50;

/**State Pointer to Function*******/

void (*CA_state)();


/*********APIS********************/


/******************************************************************************
 * @func1 :  CA_waiting
 *
 * Description:	the function initialize For Status Waiting
 *
 * Parameters:
 * @par[in]: any Type
 *
 * @par[out]:	void()
 *
 ******************************************************************************/
STATE_define(CA_waiting)
{
	/* 1- State Name */

	CA_state_id = CA_waiting ;

	printf("CA_waiting : Distance : %d , Speed= %d \n",CA_distance , CA_speed);
	/* 2- State Action */
	CA_speed=SLEEP_STATE;
	/* ACTION */
	DC_MOTOR(CA_speed);

	/*4- Print Distance & Speed*/



}

/******************************************************************************
 * @func2 :  CA_driving
 *
 * Description:	the function initialize For Status driving when the object want move form waiting status
 *
 * Parameters:
 * @par[in]: any Type
 *
 * @par[out]:	void()
 *
 ******************************************************************************/


STATE_define(CA_driving)
{
	/* 1- State Name */

		CA_state_id = CA_driving ;
		/* Print Distance & Speed*/

				printf("CA_driving : Distance : %d , Speed= %d \n",CA_distance , CA_speed);


		/* 2- State Action */
		CA_speed=  DRIVING_SPEED;

		/* ACTION */
		DC_MOTOR(CA_speed);
		/* 3- Event Check */



}

/******************************************************************************
 * @func3 :  US_Set_Distance
 *
 * Description:	the function initialize For Set Distance From Ultrasonic Sensor
 *
 * 			   --> For Test We Use rand Function
 *
 * Parameters:
 * @par[in]:   int d --> Distance
 * @par[out]:	Void
 *
 ******************************************************************************/

void US_Set_Distance(int d)
{
	CA_distance=d;
	(CA_distance <=CA_thresholed) ? (CA_state =STATE(CA_waiting) ) :(CA_state =STATE(CA_driving) );
	printf("US------Distance=%d--------CA \n",CA_distance);

}

