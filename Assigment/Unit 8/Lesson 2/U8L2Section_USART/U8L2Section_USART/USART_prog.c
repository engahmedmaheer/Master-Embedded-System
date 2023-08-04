#include <stdio.h>
#include <stdlib.h>

#include "STD_TYPES.h"

#include "BIT_MATH.h"

#include "USART_interface.h"
#include "USART_config.h"
#include "USART_private.h"
#include "USART_reg.h"

char StringData[50];
void USART_VoidInit(void)
{
	CLR_BIT(UCSRA,U2X);   // Normal Speed	
	// BaudRate 9600 F_cpu = 8MHZ
	UBRRH = 0;
	UBRRL = 51;
	
	//Asynchronous mode
	CLR_BIT(UCSRC,UMSEL);
	
	//B- 8-Bit data
	SET_BIT(UCSRC,UCSZ0);
	SET_BIT(UCSRC,UCSZ1);
	CLR_BIT(UCSRB,UCSZ2);
	
	//NO parity
	CLR_BIT(UCSRC,UPM0);
	CLR_BIT(UCSRC,UPM1);
	
	// One stop bit
	CLR_BIT(UCSRC,USBS);
	
	//enable UART  receiver.
	SET_BIT(UCSRB,RXEN);

	//enable UART  transmitter .
	SET_BIT(UCSRB,TXEN);
}

void USART_u8SendData(uint8_t data )
{	while(!(GET_BIT(UCSRA,UDRE)));
	UDR = data;
}

uint8_t USART_u8ReceiveData(void)
{
	while(!(GET_BIT(UCSRA,RXC)));
	return UDR;
}

void USART_SendU32Data(uint32_t Copy_u8Data)
{
	uint8_t *PtrNumber=(uint8_t*)&Copy_u8Data ;
	uint8_t LocalByteCounter;
	for(LocalByteCounter = 0 ; LocalByteCounter < 4 ; LocalByteCounter++)
	USART_u8SendData(PtrNumber[LocalByteCounter]);
}

uint32 USART_RecieveU32Data(void)
{
	uint32_t NUM ;
	uint8_t *PtrNumber=(uint8_t*)&NUM ;
	uint8_t LocalByteCounter;
		for(LocalByteCounter = 0 ; LocalByteCounter < 4 ; LocalByteCounter++)
		PtrNumber[LocalByteCounter]=USART_u8ReceiveData();
		
	return NUM;
}

void UART_Send_String(char* str)
{
	while (*str != '\0')
	{
		USART_u8SendData(*str);
		str++;
	}
}
char*  UART_Receive_String(void)
{
	uint8_t i = 0;
	
	uint8_t data =USART_u8ReceiveData();
	while(data !='#')
	{
		StringData[i]=data;
		data =USART_u8ReceiveData();
		i++;
	}
	StringData[i]='\0';
	return StringData;
}
