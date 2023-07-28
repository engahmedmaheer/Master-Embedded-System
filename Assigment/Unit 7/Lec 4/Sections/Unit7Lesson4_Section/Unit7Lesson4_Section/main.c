#include "STD_TYPES.h"

#define F_CPU	1000000UL


#include <util/delay.h>
#include "DIO_interface.h"
#include "PORT_interface.h"

#include "CLCD_interface.h"

void main(void)
{

	PORT_voidInit();

	CLCD_voidInit();

	CLCD_voidGoToXY(2,0);
CLCD_SendString("AhmedMaher");
CLCD_voidGoToXY(0,1);
CLCD_SendString("Learn in Depth");
	while(1);
}

