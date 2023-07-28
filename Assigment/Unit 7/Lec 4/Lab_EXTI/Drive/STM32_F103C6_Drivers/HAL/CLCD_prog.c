/*******************************************************************************/
/*******************************************************************************/
/***************************	Author :Ahmed Maher **************************/
/***************************	Date : 15/10/2021	****************************/
/***************************	Layer: HAL			****************************/
/***************************	Version : 1.00		****************************/
/*******************************************************************************/
/*******************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include "BIT_MATH.h"
#include "ERR_TYPE.h"
#include "STK_interface.h"
#include "GPIO_interface.h"
#include "CLCD_interface.h"
#include "CLCD_private.h"
#include "CLCD_config.h"

//
//static void delay_ms(uint32_t delay)
//{
//	uint32_t i, j;
//	for (i = 0; i < delay; i++)
//	{
//		for (j = 0; j < 255; j++);
//	}
//}

static void SendEnablePulse()
{
	GPIO_u8SetPinValue(CLCD_u8_CTRL_PORT,CLCD_u8_E_PIN,GPIO_PINHIGH);
	STK_voidDelayMilleSec(3);
	GPIO_u8SetPinValue(CLCD_u8_CTRL_PORT,CLCD_u8_E_PIN,GPIO_PINLOW);
}


static void SetHalfDataPins(uint8_t Copy_u8Data)
{
	GPIO_u8SetPinValue(CLCD_u8_DATA_PORT,CLCD_u8_PIN4,GET_BIT(Copy_u8Data,0));
	GPIO_u8SetPinValue(CLCD_u8_DATA_PORT,CLCD_u8_PIN5,GET_BIT(Copy_u8Data,1));
	GPIO_u8SetPinValue(CLCD_u8_DATA_PORT,CLCD_u8_PIN6,GET_BIT(Copy_u8Data,2));
	GPIO_u8SetPinValue(CLCD_u8_DATA_PORT,CLCD_u8_PIN7,GET_BIT(Copy_u8Data,3));
	SendEnablePulse();

	/*
	 * 	uint8_t Local_u8DataBit[4]={CLCD_u8_PIN4,CLCD_u8_PIN5,CLCD_u8_PIN6,CLCD_u8_PIN7};
		uint8_t Local_u8Itretor;
		for(Local_u8Itretor=0 ; Local_u8Itretor<4 ; Local_u8Itretor++)
		{
			GPIO_u8SetPinValue(CLCD_u8_DATA_PORT,Local_u8DataBit[Local_u8Itretor],GET_BIT(Copy_u8Data,Local_u8Itretor));
		}
	 *
	 */
}




void CLCD_voidSendCommand(uint8_t Copy_u8Command)
{
	//Set RS pin to low to command
	GPIO_u8SetPinValue(CLCD_u8_CTRL_PORT,CLCD_u8_RS_PIN,GPIO_PINLOW);

	//Set RW pin to low to write
	GPIO_u8SetPinValue(CLCD_u8_CTRL_PORT,CLCD_u8_RW_PIN,GPIO_PINLOW);

#if CLCD_u8_MODE == EIGHT_BIT
	//Send Command
	DIO_u8SetPortValue(CLCD_u8_DATA_PORT,Copy_u8Command);

	// Send Enable Pulse
	SendEnablePulse(void);

#elif CLCD_u8_MODE ==FOUR_BIT

	//Four Most Pins
	SetHalfDataPins(Copy_u8Command>>4);

	//Four Least Pins
	SetHalfDataPins(Copy_u8Command);

#endif

}
void CLCD_voidSendData(uint8_t Copy_u8Data)
{
	//Set RS pin to high for data
	GPIO_u8SetPinValue(CLCD_u8_CTRL_PORT,CLCD_u8_RS_PIN,GPIO_PINHIGH);

	//Set RW pin to low for write
	GPIO_u8SetPinValue(CLCD_u8_CTRL_PORT,CLCD_u8_RW_PIN,GPIO_PINLOW);

#if CLCD_u8_MODE == EIGHT_BIT

	//Send Data as 8 bits
	DIO_u8SetPortValue(CLCD_u8_DATA_PORT,Copy_u8Data);

	// Send Enable Pulse
	SendEnablePulse();

#elif CLCD_u8_MODE ==FOUR_BIT

	//Four Most Pins
	SetHalfDataPins(Copy_u8Data>>4);

	//Four Least Pins
	SetHalfDataPins(Copy_u8Data);

#endif

}

void CLCD_voidInit(void)
{
	// delay for more than 30ms
	STK_voidDelayMilleSec(40);

#if CLCD_u8_MODE == EIGHT_BIT
	//Function Set Command : 2 lines , font size : 5x7
	CLCD_voidSendCommand(0b00111000);

#elif CLCD_u8_MODE ==FOUR_BIT
	SetHalfDataPins(0b0010);
	SetHalfDataPins(0b0010);
	SetHalfDataPins(0b1000);

#endif

	// Function Set command : enable Display , Cursor off , Blink Cursor off
	CLCD_voidSendCommand(0b00001100);

	//Clear LCD
	CLCD_voidSendCommand(1);
}

void CLCD_voidSendString(char Copy_u8DataString[])
{
	uint8_t string_u8count = 0;
	while (Copy_u8DataString[string_u8count] != '\0')
	{
		CLCD_voidSendData(Copy_u8DataString[string_u8count]);
		string_u8count++;
		/*INCREAMENT 2nd LINE*/
		if(string_u8count ==16)
		{
			CLCD_voidGoToXY(0, 1);
		}
//		if(string_u8count ==32)
//		{
//			CLCD_voidSendCommand(COMMAND_CLEAR_DISPALY);
//
//		}
	}
}


uint8_t CLCD_voidSendNumebr(uint32_t Copy_u8Number)
{

	uint8_t Local_u8ErrorState = OK;
	if(Copy_u8Number == 0)
	{
		CLCD_voidSendData('0');
	}
	else
	{
		uint32_t Local_u8Inverter = 0;

		//this is iterator to solve problem of 12500 (zero)
		uint8_t Local_u8Iterator = 0;

		while(Copy_u8Number != 0)
		{
			Local_u8Inverter *= 10;
			Local_u8Inverter += (Copy_u8Number % 10);
			Copy_u8Number /= 10;
			Local_u8Iterator++;
		}
		for(;Local_u8Iterator > 0 ; Local_u8Iterator--)
		{
			CLCD_voidSendData((Local_u8Inverter % 10) + '0');
			Local_u8Inverter /= 10;
		}
	}


	return Local_u8ErrorState;
}



void CLCD_voidGoToXY(uint8_t Copy_u8XPos,uint8_t Copy_u8YPos)
{
	uint8_t Local_u8Add;
	if (Copy_u8XPos<16 && Copy_u8YPos<2)
	{
		Local_u8Add = Copy_u8YPos*0x40 + Copy_u8XPos;
	}
	// Set Bit number 7 for DDRAM address Command
	SET_BIT(Local_u8Add,7);

	//Set DDRAM Address Command
	CLCD_voidSendCommand(Local_u8Add);
}

void CLCD_voidSendSpecialCharacter(uint8_t Copy_u8Pattern[],uint8_t Copy_u8PatternNum,uint8_t Copy_u8XPos,uint8_t Copy_u8YPos)
{
	uint8_t Local_u8ErrorState = OK;

	if(Copy_u8Pattern!= NULL)
	{	// command for Storing something in CGRAM
		uint8_t Local_u8StartingAddress = Copy_u8PatternNum*8;
		SET_BIT(Local_u8StartingAddress,6);
		CLR_BIT(Local_u8StartingAddress,7);
		CLCD_voidSendCommand(Local_u8StartingAddress);

		for(uint8_t Local_u8counter = 0 ; Local_u8counter<8 ; Local_u8counter++)
		{
			CLCD_voidSendData(Copy_u8Pattern[Local_u8counter]);
		}

		CLCD_voidDisplaySpecialCharacter(Copy_u8PatternNum, Copy_u8XPos, Copy_u8YPos);
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}

}

void CLCD_voidDisplaySpecialCharacter(uint8_t Copy_u8PatternNum,uint8_t Copy_u8XPos,uint8_t Copy_u8YPos)
{

	CLCD_voidGoToXY(Copy_u8XPos,Copy_u8YPos);

	CLCD_voidSendData(Copy_u8PatternNum);
}




void CLCD_voidStoreSpecialCharacter(uint8_t Copy_u8Pattern[],uint8_t Copy_u8PatternNum)
{
	uint8_t Local_u8ErrorState = OK;

	if(Copy_u8Pattern!= NULL)
	{	// command for Storing something in CGRAM
		uint8_t Local_u8StartingAddress = Copy_u8PatternNum*8;
		SET_BIT(Local_u8StartingAddress,6);
		CLR_BIT(Local_u8StartingAddress,7);
		CLCD_voidSendCommand(Local_u8StartingAddress);

		for(uint8_t Local_u8counter = 0 ; Local_u8counter<8 ; Local_u8counter++)
		{
			CLCD_voidSendData(Copy_u8Pattern[Local_u8counter]);
		}

	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}

}

