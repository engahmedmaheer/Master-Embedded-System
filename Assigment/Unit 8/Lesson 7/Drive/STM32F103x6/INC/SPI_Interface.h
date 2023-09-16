/*******************************************************************/
/*******************************************************************/
/*****************   @Author:  AhmedMaher		********************/
/*****************   @Layer:   MCAL				********************/
/*****************   @SWC:     SPI				********************/
/*****************	 @Version: 1.00				********************/
/*******************************************************************/
/*******************************************************************/

#ifndef INC_SPI_INTERFACE_H_
#define INC_SPI_INTERFACE_H_

/**********************************************
 **************Private Macros*******************
 ***********************************************/
#define	CR1_MSTR		1U<<2
#define	CR1_RXONLY		1U<<10
#define	CR1_BIDIMODE	1U<<15
#define	CR1_BIDIOE		1U<<14
#define CR1_DFF			1U<<11
#define CR1_LSBFIRST	1U<<7
#define CR1_CPOL		1U<<1
#define CR1_CPHA		1U<<0
#define CR1_SSI			1U<<8
#define CR1_SSM			1U<<9
#define CR2_SSOE		1U<<2
#define CR1_DR			(3)
#define CR1_SPE			1U<<6

#define CR2_TXEIE		1U<<7
#define CR2_RXNEIE      1U<<6
#define CR2_ERRIE       1U<<5

#define CR2_TXDMAEN		1U<<1
#define CR2_RXDMAEN		1U<<0


#define SR_TXE			1U<<1
#define SR_RXNE			1U<<0



#define SPI_DEFINE_NUM	2



/******************************************/
typedef enum
{

	SPI_ONE,
	SPI_TWO

}SPI_PERIPHERAL_E;

typedef enum
{

	SPI_Mode_Slave 	= (uint16_t)(0),
	SPI_Mode_Master	= (uint16_t)(CR1_MSTR),

}DeviceMode_E;

typedef enum
{
	SPI_Direction_2_Lines 			=(uint16_t)(0),
	SPI_Direction_2_Lines_RXONLY	=(uint16_t)(CR1_RXONLY) ,
	SPI_Direction_1_Line_Rx_Only	=(uint16_t)(CR1_BIDIMODE),
	SPI_Direction_1_Line_Tx_Only	=(uint16_t)(CR1_BIDIMODE | CR1_BIDIOE)

}CommunicationMode_E;

typedef enum
{
	SPI_Frame_Format_MSB=(uint16_t)(0),
	SPI_Frame_Format_LSB=(uint16_t)(CR1_LSBFIRST),

}FrameFormat_E;


typedef enum
{
	SPI_Data_Size_8bit  = (uint16_t)(0),
	SPI_Data_Size_16bit = (uint16_t)(CR1_DFF),

}DataSize_E;


typedef enum
{
	SPI_CLCK_Polarity_Low_Idel = (uint16_t)(0),
	SPI_CLCK_Polarity_High_Idel=(uint16_t)(CR1_CPOL)


}ClckPolarity_E;


typedef enum
{

	SPI_CLCK_Phase_FirstClck	= (uint16_t)(0),
	SPI_CLCK_Phase_SeconedCLCK  =(uint16_t)(CR1_CPHA)


}ClckPhase_E;



typedef enum
{

	/*************************************HW***********************************************/
	SPI_NSS_HW_Slave =	(uint16_t)(0) ,
	SPI_NSS_HW_Master_SS_OutputEnable =(uint16_t)(CR2_SSOE),
	SPI_NSS_HW_Master_SS_OutputDisable =(uint16_t)~(CR2_SSOE),			//in CR2 ~CR2_SSOE

	/************************************SW**********************************************/

	SPI_NSS_SW_SSI_RESET = (uint16_t)(CR1_SSM),
	SPI_NSS_SW_SSI_SET   = (uint16_t)((CR1_SSI)|(CR1_SSM))



}NSSConfig_E;

typedef enum
{
	SPI_BAUDRATE_FCLCK_DIV_2       =(uint16_t)(0),
	SPI_BAUDRATE_FCLCK_DIV_4       =(uint16_t)(1U<<CR1_DR),
	SPI_BAUDRATE_FCLCK_DIV_8       =(uint16_t)(2U<<CR1_DR),
	SPI_BAUDRATE_FCLCK_DIV_16      =(uint16_t)(3U<<CR1_DR),
	SPI_BAUDRATE_FCLCK_DIV_32      =(uint16_t)(4U<<CR1_DR),
	SPI_BAUDRATE_FCLCK_DIV_64      =(uint16_t)(5U<<CR1_DR),
	SPI_BAUDRATE_FCLCK_DIV_128     =(uint16_t)(6U<<CR1_DR),
	SPI_BAUDRATE_FCLCK_DIV_256     =(uint16_t)(7U<<CR1_DR),



}SPIPrescaller_E;

typedef enum
{
	SPI_IE_NONE=(uint16_t)(0),
	SPI_IE_TXEIE=(uint16_t)(CR2_TXEIE),
	SPI_IE_RXNEIE=(uint16_t)(CR2_RXNEIE),
	SPI_IE_ERRIE=(uint16_t)(CR2_ERRIE),

}SPI_IE_E;



typedef enum
{
	SPI_DMA_DISABLE=(uint16_t)(0),
	SPI_DMA_RX_ENABLE=(uint16_t)(CR2_RXDMAEN),
	SPI_DMA_TX_ENABLE=(uint16_t)(CR2_TXDMAEN),
	SPI_DMA_TX_RX_ENABLE=(uint16_t)((CR2_RXDMAEN)|(CR2_TXDMAEN))
}SPI_DMA_E;


struct	IRQ_SRC_S
{
	uint8_t	TXE:1; 		/*Tx Interrupt Empty Buffer*/
	uint8_t	RXNE:1;		/*Rx Interrupt Not Empty Enable*/
	uint8_t	ERRI:1;		/*Error Interrupt*/
	uint8_t	Reserved:5;
};



typedef struct
{
	SPI_PERIPHERAL_E		SPI_PERIPHERAL ;

	DeviceMode_E			DeviceMode;						/*SPI Master or SPI Slave*/

	CommunicationMode_E		CommunicationMode;


	FrameFormat_E			FrameFormat ;

	DataSize_E				DataSize;

	ClckPolarity_E			ClckPolarity;

	ClckPhase_E				ClckPhase;

	NSSConfig_E				NSSConfig;

	SPIPrescaller_E			BaudRatePrescaller;

	SPI_IE_E				InterruptEnable;

	SPI_DMA_E				SPI_DMA_ENABLE;

				/*For Interrupt*/
	void(*SPI_PtrCallBack)(struct IRQ_SRC_S IRQ_SRC);


}SPI_Config_S;


typedef enum
{
	Polling_Disable,
	Polling_Enable

}Polling_Mechanism_E;


/**************************************API*******************************************/

/**
 * @brief 			: Function Init SPI
 * @param SPIConfig : Const Pointer To SPI Struct Configuration
 * @return 			: Local Error Statue
 */
uint8_t SPI_Init(const SPI_Config_S* SPIConfig);
/**
 * @brief 			: Function Reset SPI
 * @param SPIx		: Pointer To Specific SPI
 * @return 			: Local Error Statue
 */
uint8_t SPI_DeInit(SPI_TypeDef_S* SPIx);
/**
 * @brief    			: Function To Send Data From SPI
 * @param SPIx 			: Pointer To SPI Peripheral Which Use
 * @param PxBuffer 		: Pointer To Buffer Which Send
 * @param PollingStatue : Polling Statue
 * @return 				: Local Error Statue
 */
uint8_t SPI_U16SendData(SPI_TypeDef_S* SPIx , uint16_t* PxBuffer ,Polling_Mechanism_E PollingStatue);
/**
 * @brief    			: Function To Recieve Data From SPI
 * @param SPIx 			: Pointer To SPI Peripheral Which Use
 * @param PxBuffer 		: Pointer To Buffer Which Send
 * @param PollingStatue : Polling Statue
 * @return			    : Local Error Statue
 */
uint8_t SPI_U16RecieveData(SPI_TypeDef_S* SPIx , uint16_t* PxBuffer ,Polling_Mechanism_E PollingStatue);
/**
 * @brief    			: Function To Send and Recive Data From SPI and Change Data In Buffer
 * @param SPIx 			: Pointer To SPI Peripheral Which Use
 * @param PxBuffer 		: Pointer To Buffer Which Send
 * @param PollingStatue : Polling Statue
 * @return 				: Local Error Statue
 */
uint8_t SPI_U16TXRX(SPI_TypeDef_S* SPIx , uint16_t* PxBuffer ,Polling_Mechanism_E PollingStatue);

#endif /* INC_SPI_INTERFACE_H_ */
