 /*******************************************************************/
/*******************************************************************/
/*****************   @Author:  AhmedMaher		********************/
/*****************   @Layer:   AC				********************/
/*****************   @Date:    6-June2023       ********************/
/*****************	 @Version: 1.00				********************/
/*******************************************************************/
/*******************************************************************/
#include "DC.h"

/**attribute value (Block Only)****/
static int DC_speed = 0;

/**State Pointer to Function*******/

void (*DC_state)();


/*********APIS********************/
void DC_init();
void DC_MOTOR(int S);

/******************************************************************************
 * @func1 :  DC_waiting
 *
 * Description:	the function initialize For Status Waiting
 *
 * Parameters:
 * @par[in]: any Type
 *
 * @par[out]:	void()
 *
 ******************************************************************************/
STATE_define(DC_ideal)
{
	/* 1- State Name */

	DC_state_id = DC_ideal ;

	/****CALL PWM*********/

	/*4- Print Distance & Speed*/

	printf("DC_ideal :  Speed= %d \n", DC_speed);

}

/******************************************************************************
 * @func2 :  void ST_DC_Busy()
 *
 * Description:	the function initialize For Status driving when the object want move form waiting status
 *
 * Parameters:
 * @par[in]: any Type
 *
 * @par[out]:	void()
 *
 ******************************************************************************/


STATE_define(DC_Busy)
{
	/* 1- State Name */

		DC_state_id = DC_Busy ;

		/* 2- State Action */
		DC_speed=  SLEEP_STATE;

		/* ACTION ----> DC_MOTOR(DC_speed)*/

		DC_state=STATE(DC_ideal);
		printf("DC_Busy :  Speed= %d \n", DC_speed);




}
/******************************************************************************
 * @func4 :  DC_Init
 *
 * Description:	the function initialize DC
 * Parameters:
 *
 * @par[in]: any Type
 *
 * @par[out]:	void()
 *
 ******************************************************************************/
void DC_init()
{
	/*Init PWM*/
	printf("=====DC INIT========= \n");
}
/******************************************************************************
 * @func5 :  DC_MOTOR
 *
 * Description:	the function initialize DC Motor
 * Parameters:
 *
 * @par[in]:  	S -> Speed
 *
 * @par[out]:	void()
 *
 ******************************************************************************/
void DC_MOTOR(int S)
{
	DC_speed=S;
	DC_state=STATE(DC_Busy);
	printf("CA ======Speed = %d ======> DC \n",DC_speed);


}
