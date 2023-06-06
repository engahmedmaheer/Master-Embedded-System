/*******************************************************************/
/*******************************************************************/
/*****************   @Author:  AhmedMaher		********************/
/*****************   @Layer:   AC				********************/
/*****************   @Date:    6-June2023       ********************/
/*****************	 @Version: 1.00				********************/
/*******************************************************************/
/*******************************************************************/


#ifndef DC_H_
#define DC_H_

#include "state.h"
enum
{
	DC_ideal,
	DC_Busy
}DC_state_id;

/*Declare States Function For DC*/
void DC_init();

STATE_define(DC_ideal);
STATE_define(DC_Busy);
int US_GET_DS_Random();



extern void (*DC_state)();


#define SLEEP_STATE		0
#define DRIVING_SPEED	30



#endif /* DC_H_ */
