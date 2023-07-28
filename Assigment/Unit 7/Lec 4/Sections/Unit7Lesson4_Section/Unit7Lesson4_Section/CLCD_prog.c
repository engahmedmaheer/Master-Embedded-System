#include "STD_TYPES.h"
#include <util/delay.h>

#include "DIO_interface.h"
#include "BIT_MATH.h"
#include "CLCD_interface.h"
#include "CLCD_private.h"
#include "CLCD_config.h"
#include "ERR_TYPE.h"

static void  SetHalfDataPort(uint8 Copy_u8Data)
{
	uint8 Local_u8DataBit[4]={CLCD_u8_PIN4,CLCD_u8_PIN5,CLCD_u8_PIN6,CLCD_u8_PIN7};
	uint8 Local_u8Itretor;
	for(Local_u8Itretor=0 ; Local_u8Itretor<4 ; Local_u8Itretor++)
	{
		DIO_u8SetPinValue(CLCD_u8_DATA_PORT,Local_u8DataBit[Local_u8Itretor],GET_BIT(Copy_u8Data,Local_u8Itretor));
	}



	/*/////////////////////<<<<<1WAY>>>>>//////////////////////////////////////////////
	uint8 Local_u8DataBit;
	Local_u8DataBit=GET_BIT(Copy_u8Data,0);
	DIO_u8SetPinValue(CLCD_u8_DATA_PORT,CLCD_u8_PIN4,Local_u8DataBit);

	Local_u8DataBit=GET_BIT(Copy_u8Data,1);
	DIO_u8SetPinValue(CLCD_u8_DATA_PORT,CLCD_u8_PIN5,Local_u8DataBit);

	Local_u8DataBit=GET_BIT(Copy_u8Data,2);
	DIO_u8SetPinValue(CLCD_u8_DATA_PORT,CLCD_u8_PIN6,Local_u8DataBit);

	Local_u8DataBit=GET_BIT(Copy_u8Data,3);
	DIO_u8SetPinValue(CLCD_u8_DATA_PORT,CLCD_u8_PIN7,Local_u8DataBit);
	////////////////////////////////<<<<2WAY>>>/////////////////////////////////////////////////////
	DIO_u8SetPinValue(CLCD_u8_DATA_PORT,CLCD_u8_PIN4,GET_BIT(Copy_u8Data,0));
	DIO_u8SetPinValue(CLCD_u8_DATA_PORT,CLCD_u8_PIN5,GET_BIT(Copy_u8Data,1));
	DIO_u8SetPinValue(CLCD_u8_DATA_PORT,CLCD_u8_PIN6,GET_BIT(Copy_u8Data,2));
	DIO_u8SetPinValue(CLCD_u8_DATA_PORT,CLCD_u8_PIN7,GET_BIT(Copy_u8Data,3));*/

}
/////////////////////////////////////////////////////////////////////////////
static void SendEnablePulse(void){
	//send enable pulse/
	DIO_u8SetPinValue(CLCD_u8_CTRL_PORT,CLCD_u8_E_PIN,DIO_u8_PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_u8_CTRL_PORT,CLCD_u8_E_PIN,DIO_u8_PIN_LOW);
}
/////////////////////////////////////////////////////////////////////////////
void CLCD_voidSendCommand(uint8 Copy_u8Command)
{
	/*Set RS pin to low*/
	DIO_u8SetPinValue(CLCD_u8_CTRL_PORT, CLCD_u8_RS_PIN, DIO_u8_PIN_LOW);

	/*Set RW pin to low*/
	DIO_u8SetPinValue(CLCD_u8_CTRL_PORT, CLCD_u8_RW_PIN, DIO_u8_PIN_LOW);
#if CLCD_u8_MODE==EIGHT_BIT
	/*Send command*/
	DIO_u8SetPortValue(CLCD_u8_DATA_PORT, Copy_u8Command);

	/*Send Enable pulse*/
	SendEnablePulse();

#elif CLCD_u8_MODE==FOUR_BIT
	//SET HIGH ORDER DATA PINS
	SetHalfDataPort(Copy_u8Command>>4);
	SendEnablePulse();
	SetHalfDataPort(Copy_u8Command);
	SendEnablePulse();
#endif

}

//////////////////////////////////////////CLCD_voidSendData///////////////////////////////////////////
void CLCD_voidSendData(uint8 Copy_u8Data)
{
	/*Set RS pin to low*/
	DIO_u8SetPinValue(CLCD_u8_CTRL_PORT, CLCD_u8_RS_PIN, DIO_u8_PIN_HIGH);

	/*Set RW pin to low*/
	DIO_u8SetPinValue(CLCD_u8_CTRL_PORT, CLCD_u8_RW_PIN, DIO_u8_PIN_LOW);

	/*Send command*/
#if CLCD_u8_MODE==EIGHT_BIT
	/*Send command*/
	DIO_u8SetPortValue(CLCD_u8_DATA_PORT, Copy_u8Command);

	/*Send Enable pulse*/
	SendEnablePulse();

#elif CLCD_u8_MODE==FOUR_BIT
	SetHalfDataPort(Copy_u8Data>>4);
	SendEnablePulse();
	SetHalfDataPort(Copy_u8Data);
	SendEnablePulse();
#endif

}
////////////////////////////////CLCD_voidInit//////////////////////////////////
void CLCD_voidInit(void)
{
	/*delay for more than 30ms*/
	_delay_ms(40);
#if CLCD_u8_MODE==EIGHT_BIT
	/*Set command:N = 0 2 line,F = 0 font size: 5*7 */
	CLCD_voidSendCommand(0b00111000);
#elif CLCD_u8_MODE==FOUR_BIT
	SetHalfDataPort(0b0010);
	SendEnablePulse();
	SetHalfDataPort(0b0010);
	SendEnablePulse();
	SetHalfDataPort(0b1000);
	SendEnablePulse();
#endif
	/*Set command:D = 1 display enabled, C = 0 cursor off, B = 0 blink cursor off*/
	CLCD_voidSendCommand(0b00001100);
	/*Clear LCD*/
	CLCD_voidSendCommand(1);
}

////////////////////////////////////////////////////////////////////////////////
void CLCD_voidSendString(const char* str)
{

	for(uint8 i = 0; str[i] != '\0'; i++)
	{
		CLCD_voidSendData(str[i]);
	}
}
///////////////////////////////////////////////////////////////////////////////
void CLCD_voidSendNumber(sint16 number)
{
	sint16 holder = 0;
	if(number < 0)
	{
		number *=-1;
		CLCD_voidSendData('-');
	}
	while(number != 0)
	{
		holder += number%10;
		number /= 10;
		if(number != 0)
			holder *= 10;
	}
	while(holder != 0)
	{
		CLCD_voidSendData(holder%10 + '0');
		holder /= 10;
	}
}
/////////////////////////////////////////////////////////////////////////////
void CLCD_voidGoToXY(uint8 Copy_u8XPos, uint8 Copy_u8YPos)
{
	uint8 Local_u8Add;
	if(Copy_u8XPos <= 15 && Copy_u8XPos >= 0 && Copy_u8YPos <= 1 && Copy_u8YPos >= 0)
		Local_u8Add = Copy_u8YPos * 0x40 + Copy_u8XPos;
	else
		return;

	/*Set bit number 7*/
	SET_BIT(Local_u8Add, 7);

	/*Set DDRAM address command*/
	CLCD_voidSendCommand(Local_u8Add);
}
/////////////////////////////////////////////////////////////////////////
uint8 CLCD_u8SendSpecialCharacter( uint8* Copy_u8Pattern , uint8 Copy_u8PatternNum, uint8 Copy_u8XPos, uint8 Copy_u8YPos)
{

	/*
	uint8 Local_8Iterator;

	uint8 Local_u8CGRAMAdd =Copy_u8PatternNum *8;

	SET_BIT(Local_u8CGRAMAdd,6);


	CLCD_voidSendCommand(Local_u8CGRAMAdd);

	for(Local_8Iterator=0 ; Local_8Iterator<8 ;Local_8Iterator++)
	{
		CLCD_voidSendData(Copy_u8Pattern[Local_8Iterator]);
	}

	CLCD_voidGoToXY(Copy_u8XPos,Copy_u8YPos);

*/








	uint8 Local_u8ErrorState = OK;
	if ( Copy_u8Pattern != 0 )
	{
		uint8 Local_u8Add = Copy_u8PatternNum*8;
		uint8 Local_u8Counter;

		SET_BIT(Local_u8Add,6); //SET BIT NUMBER 6 FOR SET CGRAM ADDRESS COMMAND

		CLCD_voidSendCommand(Local_u8Add);  //SET CGRAM ADDRESS COMMAND

		//DRAW THE PATTERN INSIDE CGRAM
		for(Local_u8Counter=0; Local_u8Counter<8 ; Local_u8Counter++)
		{
			CLCD_voidSendData(Copy_u8Pattern[Local_u8Counter]);
		}

		CLCD_voidGoToXY(Copy_u8XPos,Copy_u8YPos);

		CLCD_voidSendData(Copy_u8PatternNum);
	}
	else
	{
		Local_u8ErrorState= NOK;
	}
	return Local_u8ErrorState;

}
/*****************************************************************/

uint8 CLCD_SendString(const char* Copy_u8str )
{
	uint8 Local_u8ErrorState = OK;
	uint8 Local_u8Counter=0;

	if (Copy_u8str !=NULL)
	{
		while(Copy_u8str[Local_u8Counter] !='\0')
		{
			CLCD_voidSendData(Copy_u8str[Local_u8Counter]);
			Local_u8Counter++;
		}
	}
	else
	{
		Local_u8ErrorState=NULL_POINTER;
	}
	return Local_u8ErrorState;
}

