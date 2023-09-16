/*******************************************************************/
/*******************************************************************/
/*****************   @Author:  AhmedMaher		********************/
/*****************   @Layer:   MCAL				********************/
/*****************   @SWC:     USART			********************/
/*****************	 @Version: 1.00				********************/
/*******************************************************************/
/*******************************************************************/
#ifndef INC_MCAL_USART_INTERFACE_H_
#define INC_MCAL_USART_INTERFACE_H_



#define CR3_DMAT 	1U<<7
#define CR3_DMAR	1U<<6





/**
 * @brief : Enum For Local Error Statue UART
 * Four error detection flags:
 * – Overrun error
 * – Noise error
 * – Frame error
 * – Parity error
 */
typedef enum
{
	NO_EROR,      /**< NO_EROR */
	Overrun_error,/**< Overrun_error */
	Noise_error,  /**< Noise_error */
	Frame_error,  /**< Frame_error */
	Parity_error  /**< Parity_error */

}UART_ERR_Statue;

typedef enum
{
	USART_ONE, /**< USART1 */
	USART_TWO, /**< USART2 */
	USART_THREE/**< USART3 */

}USART_PERIPHERAL_E;


typedef enum
{
	/*Bit 2 RE: Receiver enable
This bit enables the receiver. It is set and cleared by software.
0: Receiver is disabled
1: Receiver is enabled and begins searching for a start bit*/
 UART_MODE_RX = (uint32_t)(1<<2),
 /*Bit 3 TE: Transmitter enable
This bit enables the transmitter. It is set and cleared by software.
0: Transmitter is disabled
1: Transmitter is enabled*/
 UART_MODE_TX = (uint32_t)(1<<3),
 /*SET BIT 2 | BIT 3*/
 UART_MODE_RX_TX =((uint32_t)((1<<2)|(1<<3)))	,


}USART_MODE_E;




typedef enum
{
	USART_BaudRate_2400     =     2400     ,
	USART_BaudRate_9600     =     9600     ,
	USART_BaudRate_19200    =     19200    ,
	USART_BaudRate_57600    =     57600    ,
	USART_BaudRate_115200   =     115200   ,
	USART_BaudRate_230400   =     230400   ,
	USART_BaudRate_460800   =     460800   ,
	USART_BaudRate_921600   =     921600   ,
	USART_BaudRate_2250000  =     2250000  ,
	USART_BaudRate_4500000  =     4500000  ,

}USART_BaudRate_E;


typedef enum
{
	/*
	 * Bit 9 PS: Parity selection
		This bit selects the odd or even parity when the parity generation/detection is enabled (PCE
		bit set). It is set and cleared by software. The parity will be selected after the current byte.
		0: Even parity
		1: Odd parity

	*******************************************************
	Bit 10 PCE: Parity control enable
	This bit selects the hardware parity control (generation and detection). When the parity
	control is enabled, the computed parity is inserted at the MSB position (9th bit if M=1; 8th bit
	if M=0) and parity is checked on the received data. This bit is set and cleared by software.
	Once it is set, PCE is active after the current byte (in reception and in transmission).
	0: Parity control disabled
	 * */
	USART_NO_PARITY		=(uint32_t)(0),
	USART_EVEN_PARITY   =(uint32_t)(1<<10),
	USART_ODD_PARITY	=((uint32_t)((1<<10)|(1<<9)))

}USART_PARITY_E;

typedef enum
{
	/**					STOP BITS
	 * CR2 Registers
	 * Bits 13:12 STOP: STOP bits
	These bits are used for programming the stop bits.
	00: 1 Stop bit
	01: 0.5 Stop bit
	10: 2 Stop bits
	11: 1.5 Stop bit
	The 0.5 Stop bit and 1.5 Stop bit are not available for UART4 & UART5
	 */
	USART_ONE_STOP_BITS=(uint32_t)(0),
	USART_HALF_STOP_BITS=(uint32_t)(1<<12),
	USART_TWO_STOP_BITS=(uint32_t)(2<<12),
	USART_ONEANDHALF_STOP_BITS=(uint32_t)(3<<12)

}USART_STOPBITS_E;


typedef enum
{
	/**
	 * Bit 9 CTSE: CTS enable
	0: CTS hardware flow control disabled
	1: CTS mode enabled, data is only transmitted when the CTS input is asserted (tied to 0). If
	the CTS input is deasserted while a data is being transmitted, then the transmission is
	completed before stopping. If a data is written into the data register while CTS is deasserted,
	the transmission is postponed until CTS is asserted.
	This bit is not available for UART4 & UART5.
	*********************************************
		 Bit 8 RTSE: RTS enable
	0: RTS hardware flow control disabled
	1: RTS interrupt enabled, data is only requested when there is space in the receive buffer.
	The transmission of data is expected to cease after the current character has been
	transmitted. The RTS output is asserted (tied to 0) when a data can be received.
	This bit is not available for UART4 & UART5.

	 */
	USART_HwFlowCtl_NONE=(uint32_t)(0),
	USART_HwFlowCtl_RTS=(uint32_t)(1<<8),
	USART_HwFlowCtl_CTS=(uint32_t)(1<<9),
	USART_HwFlowCtl_RTS_CTS=((uint32_t)((1<<8)|(1<<9))),

}USART_HwFlowCtl_E;

typedef enum
{

	 USART_IRQ_Enable_NONE =(uint32_t)(0)     ,
	 USART_IRQ_Enable_TXE  =(uint32_t)(1<<7)  , //Transmit data register empty
	 USART_IRQ_Enable_TC   =(uint32_t)(1<<6)  , //Transmission complete
	 USART_IRQ_Enable_RXNEIE =(uint32_t)(1<<5), //Received data ready to be read & Overrun error detected
	 USART_IRQ_Enable_PE   =(uint32_t)(1<<8)  , // Parity Error Interrupt Enable
	 USART_IRQ_Enable_IDLEIE =(uint32_t)(1<<4)
}USART_IRQ_ENABLE_E;


typedef enum
{
	/*
	 * Bit 12 M: Word length
	This bit determines the word length. It is set or cleared by software.
	0: 1 Start bit, 8 Data bits, n Stop bit
	1: 1 Start bit, 9 Data bits, n Stop bit
	Note: The M bit must not be modified during a data transfer (both transmission and reception)
	 */
	USART_8DATA_BITS = (uint32_t)(0UL),
	USART_9DATA_BITS = (uint32_t)(1<<12)

}USART_WORD_LENGHT_E;

typedef enum
{
	USART_DISABLE=(uint32_t)(0),
	USART_ENABLE=(uint32_t)(1<<13)

}USART_ENABLE_STATUE_E;


typedef enum
{
	USART_DMA_DISABLE=(uint32_t)(0),
	USART_DMA_TX_ENABLE=(uint32_t)(CR3_DMAT),
	USART_DMA_RX_ENABLE=(uint32_t)(CR3_DMAR)

}USART_DMA_E;


/***************************** Specific For BaudRate*****************************/

//BaudRate Calculation
//USARTDIV = fclk / (16 * Baudrate)
//USARTDIV_MUL100 =
// uint32((100 *fclk ) / (16 * Baudrate) == (25 *fclk ) / (4* Baudrate) )
//DIV_Mantissa_MUL100 = Integer Part (USARTDIV  )  * 100
//DIV_Mantissa = Integer Part (USARTDIV  )
//DIV_Fraction = (( USARTDIV_MUL100  - DIV_Mantissa_MUL100  ) * 16 ) / 100

#define USARTDIV(_PCLK_, _BAUD_)							(uint32_t) (_PCLK_/(16 * _BAUD_ ))
#define USARTDIV_MUL100(_PCLK_, _BAUD_)						(uint32_t) ( (25 * _PCLK_ ) / (4  * _BAUD_ ))
#define Mantissa_MUL100(_PCLK_, _BAUD_)						(uint32_t) (USARTDIV(_PCLK_, _BAUD_) * 100)
#define Mantissa(_PCLK_, _BAUD_)							(uint32_t) (USARTDIV(_PCLK_, _BAUD_) )
#define DIV_Fraction(_PCLK_, _BAUD_)						(uint32_t) (((USARTDIV_MUL100(_PCLK_, _BAUD_) -  Mantissa_MUL100(_PCLK_, _BAUD_) ) * 16 ) / 100 )
#define UART_BRR_Register(_PCLK_, _BAUD_)					(( Mantissa (_PCLK_, _BAUD_) ) <<4 )|( (DIV_Fraction(_PCLK_, _BAUD_)) & 0xF )

/********************************************************************************/

typedef struct
{
	USART_PERIPHERAL_E USART_SELECTION	;	// This For Choose Which USART USED
											// This parameter must be set based on @ref USART_PERIPHERAL_E

	USART_ENABLE_STATUE_E USART_STATUE ;       // This For Choose Which USART USED
										      	// This parameter must be set based on @ref USART_ENABLE_STATUE_E


	USART_MODE_E 		USART_MODE ;	      // Specifies the TX/RX Mode.
										     // This parameter must be set based on @ref USART_MODE_E enum


	USART_WORD_LENGHT_E	USART_DATA_PAYLOAD ; // Specifies the number of data bits transmitted or received in a frame.
											// This parameter must be set based on @ref USART_WORD_LENGHT_E


	USART_BaudRate_E 	BAUDRATE ; 		     // This member configures the UART communication baud rate
										     // This parameter must be set based on @ref USART_BaudRate_E


	USART_PARITY_E		PARITY ;		     //Specifies the parity mode.
										     //@ref USART_PARITY_E


	USART_STOPBITS_E	STOP_BITS;		     //Specifies the number of stop bits transmitted
										     //@ref USART_STOPBITS_E


	USART_HwFlowCtl_E	HwFlowCtl;		     //Specifies whether the hardware flow control mode is enabled or disabled
										     //@ref USART_HwFlowCtl_E


	USART_IRQ_ENABLE_E	IRQ_USART_Enable;	//enable or disable UART IRQ TX/RX
											//@ref USART_IRQ_ENABLE_E , you can select two or three parameters EX.UART_IRQ_Enable_TXE |UART_IRQ_Enable_TC


	USART_DMA_E 		USART_DMA_ENABLE ;

//	void(*PtrCallBackFunc)(void);			//Set the C Function() which will be called once the IRQ  Happen



}USART_HandleTypeDef;


typedef enum
{
	USART_POLLING_DISABLE,
	USART_POLLING_ENABLE

}USART_Polling_Mechanism_E;

#define USART_NUM_DEFINE	3



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
UART_ERR_Statue USART_Init( USART_HandleTypeDef* Huart);

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
UART_ERR_Statue USART_Deinit(const USART_TypeDef_S* Huart);

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

UART_ERR_Statue USART_U16SendData( USART_TypeDef_S* Huart, uint16_t* PTxBuffre ,USART_Polling_Mechanism_E Polling_Status);

/******************************************************************************
 * @Fun :  USART_U16RecieveData
 *
 * Description:	the function send Data From Buffer To Buss
 *
 * Parameters:
 * @par[in]: 1- Huart	 :  pointer to USART_TypeDef_Sstructure which hold USART Peripheral
 *			:2- PRxBuffre: const pointer to Buffer Which Want To Receive in.
 *			:3-Polling_Status: Status Of Polling Enable Or Disable
 *
 * Return:	UART_ERR_Statue , Type:enum
 *
 ******************************************************************************/
UART_ERR_Statue USART_U16RecieveData( USART_TypeDef_S* Huart, uint16_t* PRxBuffre ,USART_Polling_Mechanism_E Polling_Status);

/******************************************************************************
 * @Fun :  USART_U16WAIT_TC
 *
 * Description:	Function Wait Until Transmit Complete
 *
 * Parameters:
 * @par[in]: 1- Huart	 : const pointer to USART_TypeDef_Sstructure which hold USART Peripheral
 *
 * Return:	UART_ERR_Statue , Type:enum
 *
 ******************************************************************************/
UART_ERR_Statue USART_U16WAIT_TC(const USART_TypeDef_S* Huart);
/******************************************************************************
 * @Fun :  USART_SetGPIOPins
 *
 * Description:	the function send Data For GPIO Pins
 *
 * Parameters:
 * @par[in]: 1- Huart	 :  pointer to USART_TypeDef_Sstructure which hold USART Peripheral
 *
 * Return:	UART_ERR_Statue , Type:enum
 *
 ******************************************************************************/
UART_ERR_Statue USART_SetGPIOPins( USART_TypeDef_S* Huart);




#endif /* INC_MCAL_USART_INTERFACE_H_ */
