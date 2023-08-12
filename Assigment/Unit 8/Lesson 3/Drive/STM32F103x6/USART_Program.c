/*******************************************************************/
/*******************************************************************/
/*****************   @Author:  AhmedMaher		********************/
/*****************   @Layer:   MCAL				********************/
/*****************   @SWC:     USART			********************/
/*****************	 @Version: 1.00				********************/
/*******************************************************************/
/*******************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "ERR_TYPE.h"
#include "BIT_MATH.h"

#include "STM32F103x6.h"


#include "USART_Private.h"
#include "USART_Interface.h"

#include "RCC_Interface.h"


/**
 * @brief: Static Private Array For peripheral Only
 *
 * */
static USART_TypeDef_S* USART[USART_NUM_DEFINE] ={USART1,USART2,USART3};

/**
 * @brief: USART Config Global Configuration
 */
USART_HandleTypeDef* Global_USART_CONFIG = NULL ;

/******************************************************************************
 * @func :  USART_Init
 *
 * Description:	the function initialize the required USART configuration  options
 *
 * Parameters:
 * @par[in]: 1- Huart: const pointer to USART_HandleTypeDef structure which holds the configurations
 *
 * Return:	UART_ERR_Statue , Type:enum
 *
 ******************************************************************************/
UART_ERR_Statue USART_Init( USART_HandleTypeDef* Huart)
{
	uint8_t LocalErrorStatue = NO_EROR;

	uint32_t LocalU32_PCLCKValue , LocalU32_BRRValue ;

	/*For Other Configuration*/
	Global_USART_CONFIG=Huart;


	/*Enable RCC For USART*/
	switch (Huart->USART_SELECTION)
	{
	case USART_ONE   : RCC_USART1_CLCK_EN() ; break;
	case USART_TWO   : RCC_USART2_CLCK_EN() ; break;
	case USART_THREE : RCC_USART3_CLCK_EN() ; break;
	default :  LocalErrorStatue = NOK ; break;
	}
	/*Enable USART  UE Bit
	Bit 13 UE: USART enable
	When this bit is cleared the USART prescalers and outputs are stopped and the end of the
	current
	byte transfer in order to reduce power consumption. This bit is set and cleared by software.
	0: USART prescaler and outputs disabled
	1: USART enabled*/
	USART[Huart->USART_SELECTION]->CR1 |= (Huart->USART_STATUE);

	/* Bit 3 TE: Transmitter enable
		This bit enables the transmitter. It is set and cleared by software.
		0: Transmitter is disabled
		1: Transmitter is enabled
		Note: 1: During transmission, a “0” pulse on the TE bit (“0” followed by “1”) sends a preamble
		(idle line) after the current word, except in Smartcard mode.
		2: When TE is set there is a 1 bit-time delay before the transmission starts.
		Bit 2 RE: Receiver enable
		This bit enables the receiver. It is set and cleared by software.
		0: Receiver is disabled
		1: Receiver is enabled and begins searching for a start bit
	 */

	USART[Huart->USART_SELECTION]->CR1 |= (Huart->USART_MODE);

	/*Switch Word Length
	This bit determines the word length. It is set or cleared by software.
	0: 1 Start bit, 8 Data bits, n Stop bit
	1: 1 Start bit, 9 Data bits, n Stop bit
	Note: The M bit must not be modified during a data transfer (both transmission and reception)*/

	USART[Huart->USART_SELECTION]->CR1 |= (Huart->USART_DATA_PAYLOAD) ;

	/*Parity control enable=
	PCE: Parity control enable
	This bit selects the hardware parity control (generation and detection). When the parity
	control is enabled, the computed parity is inserted at the MSB position (9th bit if M=1; 8th bit
	if M=0) and parity is checked on the received data. This bit is set and cleared by software.
	Once it is set, PCE is active after the current byte (in reception and in transmission).
	0: Parity control disabled
	1: Parity control enabled
	Parity control Selection
	This bit selects the odd or even parity when the parity generation/detection is enabled (PCE
	bit set). It is set and cleared by software. The parity will be selected after the current byte.
	0: Even parity
	1: Odd parity   */

	USART[Huart->USART_SELECTION]->CR1 |= (Huart->PARITY) ;

	/*Bits 13:12 STOP: STOP bits
	These bits are used for programming the stop bits.
	00: 1 Stop bit
	01: 0.5 Stop bit
	10: 2 Stop bits
	11: 1.5 Stop bit
	The 0.5 Stop bit and 1.5 Stop bit are not available for UART4 & UART5.*/

	USART[Huart->USART_SELECTION]->CR2 |= (Huart->STOP_BITS) ;

	/*Bit 9 CTSE: CTS enable
	0: CTS hardware flow control disabled
	1: CTS mode enabled, data is only transmitted when the CTS input is asserted (tied to 0). If
	the CTS input is deasserted while a data is being transmitted, then the transmission is
	completed before stopping. If a data is written into the data register while CTS is deasserted,
	the transmission is postponed until CTS is asserted.
	This bit is not available for UART4 & UART5.
	Bit 8 RTSE: RTS enable
	0: RTS hardware flow control disabled
	1: RTS interrupt enabled, data is only requested when there is space in the receive buffer.
	The transmission of data is expected to cease after the current character has been
	transmitted. The RTS output is asserted (tied to 0) when a data can be received.
	This bit is not available for UART4 & UART5.*/

	USART[Huart->USART_SELECTION]->CR3 |= (Huart->HwFlowCtl) ;


	/*****************	BAUD RATE **********************************/

	/*Switch USART TO Switch PCLCK*/
	/**
	 * USART1 		   --> PCLCK2
	 * USART2 | USART3 --> PCLCK1
	 */
	switch (Huart->USART_SELECTION)
	{
	case USART_ONE   :     RCC_USART1_CLCK_EN();
	LocalU32_PCLCKValue = RCC_GetPCLCK2()    ;break;
	case USART_TWO   :     RCC_USART2_CLCK_EN();
	LocalU32_PCLCKValue = RCC_GetPCLCK1();   ;break;
	case USART_THREE :     RCC_USART3_CLCK_EN();
	LocalU32_PCLCKValue = RCC_GetPCLCK1();   ;break;
	default :  LocalErrorStatue = NOK ; break;
	}


	LocalU32_BRRValue = UART_BRR_Register(LocalU32_PCLCKValue ,Huart->BAUDRATE );

	USART[Huart->USART_SELECTION]->BRR = LocalU32_BRRValue ;


	/************************ Interrupt **************************/

	if(Huart->IRQ_USART_Enable !=USART_IRQ_Enable_NONE )
	{

		USART[Huart->USART_SELECTION]->CR1 |= (Huart->IRQ_USART_Enable );

	}
	else
	{
		/*unable Interrupt*/
	}


	return LocalErrorStatue ;

}

/******************************************************************************
 * @Fun :  USART_Deinit
 *
 * Description:	the function Deinit the required USART configuration  options
 *
 * Parameters:
 * @par[in]: 1- Huart: const pointer to USART_TypeDef_S structure which hold USART Peripheral
 *
 * Return:	UART_ERR_Statue , Type:enum
 *
 ******************************************************************************/
UART_ERR_Statue USART_Deinit(const USART_TypeDef_S* Huart)
{

	uint8_t LocalErrorStatue = NO_EROR;

	/*Enable RCC For RESET USART*/
	switch (Global_USART_CONFIG->USART_SELECTION)
	{
	case USART_ONE   : RCC_USART1_RESET() ; break;
	case USART_TWO   : RCC_USART2_RESET() ; break;
	case USART_THREE : RCC_USART3_RESET() ; break;
	default :  LocalErrorStatue = NOK ; break;
	}

	return LocalErrorStatue ;

}

/******************************************************************************
 * @Fun :  USART_U16SendData
 *
 * Description:	the function send Data From Buffer To Buss
 *
 * Parameters:
 * @par[in]: 1- Huart	 : const pointer to USART_TypeDef_Sstructure which hold USART Peripheral
 *			:2- PTxBuffre: const pointer to Buffer Which Want To Send
 *			:3-Polling_Status: Status Of Polling Enable Or Disable
 *
 * Return:	UART_ERR_Statue , Type:enum
 *
 ******************************************************************************/
UART_ERR_Statue USART_U16SendData( USART_TypeDef_S* Huart, uint16_t *PTxBuffre ,USART_Polling_Mechanism_E Polling_Status)
{
	uint8_t LocalErrorStatue = NO_EROR;

	/*wait until make sure TXE =1 --> Empty (with pooling mechanism)*/
	/* Write the data to send in the USART_DR register (this clears the TXE bit). Repeat this
	 * for each data to be transmitted in case of single buffer */
	if(Polling_Status == USART_POLLING_ENABLE)
	{
		/*Polling in TXE Bit*/
		while(! (Huart->SR & 1<<TXE_BIT));
	}
	/*Without Polling
	When transmitting with the parity enabled (PCE bit set to 1 in the USART_CR1 register),
	the value written in the MSB (bit 7 or bit 8 depending on the data length) has no effect
	because it is replaced by the parity.
	When receiving with the parity enabled, the value read in the MSB bit is the received parity
	bit.*/
	if(Global_USART_CONFIG->USART_DATA_PAYLOAD == USART_9DATA_BITS)
	{
		/*ignore the nine bit of Date Configured as parity*/
		Huart->DR =(*PTxBuffre & (uint16_t)0x01FF);

	}
	else if (Global_USART_CONFIG->USART_DATA_PAYLOAD == USART_8DATA_BITS)
	{
		/*ignore the eight bit of Date Configured as parity*/
		Huart->DR =(*PTxBuffre & (uint8_t)0xFF);

	}


	return LocalErrorStatue ;
}

/******************************************************************************
 * @Fun :  USART_U16RecieveData
 *
 * Description:	the function send Data From Buffer To Buss
 *
 * Parameters:
 * @par[in]: 1- Huart	 : const pointer to USART_TypeDef_Sstructure which hold USART Peripheral
 *			:2- PRxBuffre: const pointer to Buffer Which Want To Receive in.
 *			:3-Polling_Status: Status Of Polling Enable Or Disable
 *
 * Return:	UART_ERR_Statue , Type:enum
 *
 ******************************************************************************/
UART_ERR_Statue USART_U16RecieveData( USART_TypeDef_S* Huart, uint16_t* PRxBuffre ,USART_Polling_Mechanism_E Polling_Status)
{
	uint8_t LocalErrorStatue = NO_EROR;

	/*When a character is received
	• The RXNE bit is set. It indicates that the content of the shift register is transferred to the
	RDR. In other words, data has been received and can be read (as well as its
	associated error flags).*/


	if(Polling_Status ==USART_POLLING_ENABLE)
	{
		/*Polling until RXNE Is Set
		    RXNE: Read data register not empty
			This bit is set by hardware when the content of the RDR shift register has been transferred to
			the USART_DR register. An interrupt is generated if RXNEIE=1 in the USART_CR1 register.
			It is cleared by a read to the USART_DR register. The RXNE flag can also be cleared by
			writing a zero to it. This clearing sequence is recommended only for multibuffer
			communication.
			0: Data is not received
			1: Received data is ready to be read.*/
	while( !(Huart->SR & 1<< RXNE_BIT ));


	}

	if(Global_USART_CONFIG->USART_DATA_PAYLOAD == USART_9DATA_BITS)
	{

		if(Global_USART_CONFIG->PARITY ==USART_NO_PARITY )
		{

			*((uint16_t*)PRxBuffre)=Huart->DR ;


		}
		else
		{
			*((uint16_t*)PRxBuffre)=( Huart->DR & (uint8_t)0xFF) ;

		}


	}
	else if (Global_USART_CONFIG->USART_DATA_PAYLOAD == USART_8DATA_BITS)
	{

		if(Global_USART_CONFIG->PARITY ==USART_NO_PARITY )
		{

			//no parity So all 8bit are considered data
			*((uint16_t*) PRxBuffre) = ( Huart->DR  & (uint8_t)0xFF ) ;
		}
		else
		{
			//Parity is used, so,7 bits will be of user data and 1 bit is parity
			*((uint16_t*) PRxBuffre) = ( Huart->DR  & (uint8_t)0X7F );


		}




	}




	return LocalErrorStatue ;
}

/******************************************************************************
 * @Fun :  USART_U16WAIT_TC
 *
 * Description:	the function send Data From Buffer To Buss
 *
 * Parameters:
 * @par[in]: 1- Huart	 : const pointer to USART_TypeDef_Sstructure which hold USART Peripheral
 *			:2- PRxBuffre: const pointer to Buffer Which Want To Receive in.
 *			:3-Polling_Status: Status Of Polling Enable Or Disable
 *
 * Return:	UART_ERR_Statue , Type:enum
 *
 ******************************************************************************/
UART_ERR_Statue USART_U16WAIT_TC(const USART_TypeDef_S* Huart)
{

	uint8_t LocalErrorStatue = NO_EROR;


	/*wait till TC flag is set in the SR
	Bit 6 TC: Transmission complete
	This bit is set by hardware if the transmission of a frame containing data is complete and if
	TXE is set. An interrupt is generated if TCIE=1 in the USART_CR1 register. It is cleared by a
	software sequence (a read from the USART_SR register followed by a write to the
	USART_DR register). The TC bit can also be cleared by writing a '0' to it. This clearing
	sequence is recommended only for multibuffer communication.
	0: Transmission is not complete
	1: Transmission is complete*/

	while( ! (Huart->SR & 1<<TC_BIT ));

	return LocalErrorStatue ;
}







