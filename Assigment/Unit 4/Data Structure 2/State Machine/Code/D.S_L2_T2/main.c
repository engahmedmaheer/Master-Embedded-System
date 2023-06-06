/*
 * main.c
 *
 *  Created on: Jun 6, 2023
 *      Author: AhmedMaher
 */


#include "CA.h"
#include "DC.h"
#include "US.h"



void setup()
{
	/*init all drives*/
	/*init IRQ..     */
	/*init HAL Driver*/
	/*init BLOCK	*/
	US_Init();
	DC_init();
	/*Set State pointer for Blocks*/
	CA_state = STATE(CA_waiting);
	US_state = STATE(US_busy);
	DC_state = STATE(DC_ideal);
}


void main()
{
	volatile int d ;
	setup();

	while(1)
	{

		/*Call State For Each Block */

		US_state();
		CA_state();
		DC_state();
		/*Delay*/
		for(d=0 ; d<1000 ; d++);
	}


}
