/*******************************************************************/
/*******************************************************************/
/*****************   @Author:  AhmedMaher		********************/
/*****************   @Layer:   AC				********************/
/*****************   @Date:    6-June2023       ********************/
/*****************	 @Version: 1.00				********************/
/*******************************************************************/
/*******************************************************************/


#ifndef STATE_H_
#define STATE_H_

#include <stdio.h>
#include <stdlib.h>


/*Automatic state Function Define*/

#define STATE_define(_state_fun)	void ST_##_state_fun()

#define STATE(_state_fun)   	ST_##_state_fun


/*State Connection*/

void US_Set_Distance(int d);

void DC_MOTOR(int S);




#endif /* STATE_H_ */
