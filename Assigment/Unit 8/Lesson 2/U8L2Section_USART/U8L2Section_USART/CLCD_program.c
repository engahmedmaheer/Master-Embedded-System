/********************		Author: Amgad Samir		**************/
/********************		Layer: HAL				**************/
/********************		SWC: CLCD				**************/
/********************		Version: 1.00			**************/
/********************		Date: 25-8-2020			**************/
/*****************************************************************/
/*****************************************************************/

#include "STD_TYPES.h"
#include <util/delay.h>

#include "DIO_interface.h"

#include "CLCD_config.h"
#include "CLCD_interface.h"
#include "CLCD_private.h"

void CLCD_voidSendCommand(uint8 Copy_u8Command)
{
	/*1- Set RS pin to low for command*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8_PIN_LOW);

	/*2- Set RW pin to low for write*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8_PIN_LOW);

	/*3- Send the command to the LCD*/
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Command);

	/*4- Send the enable pulse to the LCD*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8_PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8_PIN_LOW);
}

void CLCD_voidSendData(uint8 Copy_u8Data)
{
	/*1- Set RS pin to high for Data*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8_PIN_HIGH);

	/*2- Set RW pin to low for write*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8_PIN_LOW);

	/*3- Send the Data to the LCD*/
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Data);

	/*4- Send the enable pulse to the LCD*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8_PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8_PIN_LOW);
}

void CLCD_voidInit(void)
{
	/*1- wait for more than 30 ms*/
	_delay_ms(40);

	/*2- Function set command: 2 lines, Font= 5x7*/
	CLCD_voidSendCommand(0b00111000);

	/*3- Display on off control: Display on, cursor off, blink cursor off*/
	CLCD_voidSendCommand(0b00001100);

	/*4- Display clear*/
	CLCD_voidSendCommand(1);
}

void CLCD_voidSendString(const char* Copy_pchString)
{
	uint8 Local_u8Counter=0;
	while(Copy_pchString[Local_u8Counter]!='\0')
	{
		CLCD_voidSendData(Copy_pchString[Local_u8Counter]);
		Local_u8Counter++;
	}
}

void CLCD_voidGotoXY(uint8 Copy_u8XPos, uint8 Copy_u8YPos)
{
	uint8 Local_u8DDRAMAddress;
	if(Copy_u8YPos ==0)
	{
		/*Check if in first line*/
		Local_u8DDRAMAddress=Copy_u8XPos;
	}
	else if(Copy_u8YPos==1)
	{
		/*Check if in second line*/
		Local_u8DDRAMAddress=0x40+Copy_u8XPos;
	}

	/*Setbit number 7 for SetDDRAM Address command then send the command*/
	CLCD_voidSendCommand(Local_u8DDRAMAddress+128);
}

void CLCD_voidWriteSpecialCharacter(uint8* Copy_pu8Pattern,uint8 Copy_u8PatternNumber,uint8 Copy_u8XPos,uint8 Copy_u8YPos)
{
	uint8 Local_u8CGRamAddress,Local_u8Counter;

	/*1- calculate CGRAM address knowing that every pattern consumes 8 bytes*/
	Local_u8CGRamAddress= Copy_u8PatternNumber*8;

	/*2-Send SET CGRAM address command to LCD with setting bit6 ,clearing bit7*/
	CLCD_voidSendCommand(Local_u8CGRamAddress+64);

	/*3- write the pattern into CGRAM*/
	for(Local_u8Counter=0;Local_u8Counter<8;Local_u8Counter++)
	{
		CLCD_voidSendData(Copy_pu8Pattern[Local_u8Counter]);
	}
	/*4- Back to the DDRAM to display the special pattern*/
	CLCD_voidGotoXY(Copy_u8XPos,Copy_u8YPos);

	/*5- Display the special pattern*/
	CLCD_voidSendData(Copy_u8PatternNumber);
}
