#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERR_TYPE.h"

#include "DIO_interface.h"
#include "DIO_reg.h"
#include "DIO_private.h"
#include "DIO_config.h"

uint8 DIO_u8SetPinValue(uint8 Copy_u8Port, uint8 Copy_u8PinNum,uint8 Copy_u8Val)
{
	uint8 Local_u8ErrorState = OK;

	if((Copy_u8PinNum<= DIO_u8_PIN7) && (Copy_u8Val<= DIO_u8_PIN_HIGH))
	{
		switch(Copy_u8Port)
		{
		case DIO_u8_PORTA: ASSIGN_BIT(PORTA,Copy_u8PinNum,Copy_u8Val); break;
		case DIO_u8_PORTB: ASSIGN_BIT(PORTB,Copy_u8PinNum,Copy_u8Val); break;
		case DIO_u8_PORTC: ASSIGN_BIT(PORTC,Copy_u8PinNum,Copy_u8Val); break;
		case DIO_u8_PORTD: ASSIGN_BIT(PORTD,Copy_u8PinNum,Copy_u8Val); break;
		default: Local_u8ErrorState= NOK; break;
		}
	}
	else
	{
		Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;
}
uint8 DIO_u8SetPortValue(uint8 Copy_u8Port, uint8 Copy_u8Val)
{
	uint8 Local_u8ErrorState = OK;

	switch (Copy_u8Port)
	{
	case DIO_u8_PORTA: PORTA= Copy_u8Val; break;
	case DIO_u8_PORTB: PORTB= Copy_u8Val; break;
	case DIO_u8_PORTC: PORTC= Copy_u8Val; break;
	case DIO_u8_PORTD: PORTD= Copy_u8Val; break;
	default: Local_u8ErrorState= NOK ; break;
	}
	return Local_u8ErrorState;

}

uint8 DIO_u8ReadPinValue(uint8 Copy_u8Port, uint8 Copy_u8PinNum,uint8* Copy_pu8Value)
{

	uint8 Local_u8ErrorState = OK;

	if(Copy_pu8Value != NULL)
	{
		if(Copy_u8PinNum <= DIO_u8_PIN7)
		{
			switch (Copy_u8Port)
			{
			case DIO_u8_PORTA: *Copy_pu8Value=GET_BIT(PINA,Copy_u8PinNum); break;
			case DIO_u8_PORTB: *Copy_pu8Value=GET_BIT(PINB,Copy_u8PinNum); break;
			case DIO_u8_PORTC: *Copy_pu8Value=GET_BIT(PINC,Copy_u8PinNum); break;
			case DIO_u8_PORTD: *Copy_pu8Value=GET_BIT(PIND,Copy_u8PinNum); break;
			default: Local_u8ErrorState= NOK ; break;
			}
		}
		else
		{
			Local_u8ErrorState= NOK;
		}
	}
	else
	{
		Local_u8ErrorState= NULL_POINTER;
	}
	return Local_u8ErrorState;
}

uint8 DIO_u8TogglePinValue(uint8 Copy_u8Port,uint8 Copy_u8PinNum)
{
	uint8 Local_u8ErrorState = OK;

	if(Copy_u8PinNum <= DIO_u8_PIN7)
	{
		switch (Copy_u8Port)
		{
		case DIO_u8_PORTA: TOG_BIT(PORTA,Copy_u8PinNum); break;
		case DIO_u8_PORTB: TOG_BIT(PORTB,Copy_u8PinNum); break;
		case DIO_u8_PORTC: TOG_BIT(PORTC,Copy_u8PinNum); break;
		case DIO_u8_PORTD: TOG_BIT(PORTD,Copy_u8PinNum); break;
		default: Local_u8ErrorState= NOK ; break;
		}
	}
	else
	{
		Local_u8ErrorState= NOK;
	}

	return Local_u8ErrorState;
}

uint8 DIO_u8SetPinDirection(uint8 Copy_u8Port, uint8 Copy_u8Pin, uint8 Copy_u8Direction)
{
	uint8 Local_u8ErrorState= OK;

	if(Copy_u8Pin > DIO_u8_PIN7)
	{
		Local_u8ErrorState= NOK;
	}
	else
	{
		if(Copy_u8Direction == DIO_u8_PIN_INPUT)
		{
			switch(Copy_u8Port)
			{
			case DIO_u8_PORTA: CLR_BIT(DDRA,Copy_u8Pin); break;
			case DIO_u8_PORTB: CLR_BIT(DDRB,Copy_u8Pin); break;
			case DIO_u8_PORTC: CLR_BIT(DDRC,Copy_u8Pin); break;
			case DIO_u8_PORTD: CLR_BIT(DDRD,Copy_u8Pin); break;
			default: Local_u8ErrorState=NOK;			 break;
			}
		}
		else if(Copy_u8Direction == DIO_u8_PIN_OUTPUT)
		{
			switch(Copy_u8Port)
			{
			case DIO_u8_PORTA: SET_BIT(DDRA,Copy_u8Pin); break;
			case DIO_u8_PORTB: SET_BIT(DDRB,Copy_u8Pin); break;
			case DIO_u8_PORTC: SET_BIT(DDRC,Copy_u8Pin); break;
			case DIO_u8_PORTD: SET_BIT(DDRD,Copy_u8Pin); break;
			default: Local_u8ErrorState=NOK;			 break;
			}
		}
		else
		{
			Local_u8ErrorState=NOK;
		}
	}

	return Local_u8ErrorState;
}

