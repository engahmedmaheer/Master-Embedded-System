/*******************************************************************/
/*******************************************************************/
/*****************   @Author:  AhmedMaher		********************/
/*****************   @Layer:   AC				********************/
/*****************   @Date:    6-June2023       ********************/
/*****************	 @Version: 1.00				********************/
/*******************************************************************/
/*******************************************************************/


#ifndef CA_H_
#define CA_H_

#include "state.h"
enum
{
	CA_waiting,
	CA_driving
}CA_state_id;

/*Declare States Function For CA*/

STATE_define(CA_waiting);
STATE_define(CA_driving);
int US_GET_DS_Random();



extern void (*CA_state)();


#define SLEEP_STATE		0
#define DRIVING_SPEED	30



#endif /* CA_H_ */
