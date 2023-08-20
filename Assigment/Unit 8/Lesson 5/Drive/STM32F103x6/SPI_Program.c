/*******************************************************************/
/*******************************************************************/
/*****************   @Author:  AhmedMaher		********************/
/*****************   @Layer:   MCAL				********************/
/*****************   @SWC:     SPI				********************/
/*****************	 @Version: 1.00				********************/
/*******************************************************************/
/*******************************************************************/


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


#include "ERR_TYPE.h"
#include "STM32F103x6.h"

#include "SPI_Interface.h"
#include "SPI_Private.h"



/*For Peripheral Only*/
static SPI_TypeDef_S* SPI_PeripheralArray[SPI_DEFINE_NUM]={SPI1,SPI2};

/*For Save Configuration For Other Function*/
SPI_Config_S* Global_SPI_Config[SPI_DEFINE_NUM]={0};

/**
 * @brief 			: Function Init SPI
 * @param SPIConfig : Constant Pointer To SPI Struct Configuration
 * @return 			: Local Error Statue
 */
uint8_t SPI_Init(const SPI_Config_S* SPIConfig)
{

	uint8_t LocalErrorStatue = OK ;

	/*Init SPI Reg Value For Safety*/

	uint16_t TempReg_CR1=0;

	uint16_t TempReg_CR2=0;

	/*For Save Configuration*/
	Global_SPI_Config[SPIConfig->SPI_PERIPHERAL]=SPIConfig;

	/*Clck Enable*/
	switch (SPIConfig->SPI_PERIPHERAL)
	{
	case SPI_ONE:	SPI1_CLCK_EN();	break;
	case SPI_TWO:	SPI2_CLCK_EN();	break;
	default     : 	/*error*/		;break;
	}

	/*Enable SPI*/
	TempReg_CR1 =CR1_SPE;

	/*Switch Master Or Slave*/
	TempReg_CR1 |= SPIConfig->DeviceMode ;

	TempReg_CR1 |= SPIConfig->CommunicationMode;

	TempReg_CR1 |= SPIConfig->FrameFormat;

	TempReg_CR1 |= SPIConfig->DataSize;

	TempReg_CR1 |= SPIConfig->ClckPolarity;

	TempReg_CR1 |= SPIConfig->ClckPhase;

	/*NSS*/

	if(SPIConfig->NSSConfig ==SPI_NSS_HW_Master_SS_OutputEnable )
	{

		TempReg_CR2 |=SPIConfig->NSSConfig ;

	}
	else if(SPIConfig->NSSConfig ==SPI_NSS_HW_Master_SS_OutputDisable)
	{

		TempReg_CR2 &=SPIConfig->NSSConfig ;

	}
	else
	{
		TempReg_CR1 |=SPIConfig->NSSConfig ;
	}

	/*BaudRatePrescaller*/
	TempReg_CR1 |= SPIConfig->BaudRatePrescaller ;

	if(SPIConfig->InterruptEnable != SPI_IE_NONE)
	{
		TempReg_CR2 |=SPIConfig->InterruptEnable;
	}

	SPI_PeripheralArray[SPIConfig->SPI_PERIPHERAL]->CR1 =TempReg_CR1;

	SPI_PeripheralArray[SPIConfig->SPI_PERIPHERAL]->CR2 =TempReg_CR2;


	return LocalErrorStatue ;

}
/**
 * @brief 			: Function Reset SPI
 * @param SPIx		: Pointer To Specific SPI
 * @return 			: Local Error Statue
 */
uint8_t SPI_DeInit(SPI_TypeDef_S* SPIx)
{
	uint8_t LocalErrorStatue = OK ;

	if(SPIx == SPI1)
	{
		SPI1_CLCK_RESET();
	}
	else if(SPIx == SPI2)
	{
		SPI2_CLCK_RESET();
	}

	return LocalErrorStatue ;


}

/**
 * @brief    			: Function To Send Data From SPI
 * @param SPIx 			: Pointer To SPI Peripheral Which Use
 * @param PxBuffer 		: Pointer To Buffer Which Send
 * @param PollingStatue : Polling Statue
 * @return 				: Local Error Statue
 */
uint8_t SPI_U16SendData(SPI_TypeDef_S* SPIx , uint16_t* PxBuffer ,Polling_Mechanism_E PollingStatue)
{
	uint8_t LocalErrorStatue = OK ;

	/*Bit 1 TXE: Transmit buffer empty
	0: Tx buffer not empty
	1: Tx buffer empty*/

	if(PollingStatue == Polling_Enable)
	{
		/*With Polling*/
		while (!(SPIx->SR & SR_TXE));
	}

	SPIx->DR=*(PxBuffer);

	return LocalErrorStatue ;

}
/**
 * @brief    			: Function To Recieve Data From SPI
 * @param SPIx 			: Pointer To SPI Peripheral Which Use
 * @param PxBuffer 		: Pointer To Buffer Which Send
 * @param PollingStatue : Polling Statue
 * @return			    : Local Error Statue
 */
uint8_t SPI_U16RecieveData(SPI_TypeDef_S* SPIx , uint16_t* PxBuffer ,Polling_Mechanism_E PollingStatue)
{

	uint8_t LocalErrorStatue = OK ;

	/*RXNE: Receive buffer not empty
	0: Rx buffer empty
	1: Rx buffer not empty*/
	if(PollingStatue == Polling_Enable)
	{
		/*With Polling*/
		while (!(SPIx->SR & SR_RXNE));
	}

	*(PxBuffer)=SPIx->DR;

	return LocalErrorStatue ;
}
/**
 * @brief    			: Function To Send and Recive Data From SPI and Change Data In Buffer
 * @param SPIx 			: Pointer To SPI Peripheral Which Use
 * @param PxBuffer 		: Pointer To Buffer Which Send
 * @param PollingStatue : Polling Statue
 * @return 				: Local Error Statue
 */
uint8_t SPI_U16TXRX(SPI_TypeDef_S* SPIx , uint16_t* PxBuffer ,Polling_Mechanism_E PollingStatue)
{

	uint8_t LocalErrorStatue = OK ;



	if(PollingStatue == Polling_Enable)
	{
		while(!((SPIx->SR)&SR_TXE));
	}
	SPIx->DR = *PxBuffer;

	if(PollingStatue == Polling_Enable)
		while(!((SPIx->SR)&SR_RXNE));
	*PxBuffer = SPIx->DR;


	return LocalErrorStatue ;
}

void SPI1_IRQHandler()
{
	struct IRQ_SRC_S IRQ_SRC;

	IRQ_SRC.TXE= ((SPI1->SR & (1<<1) )>>1);
	IRQ_SRC.RXNE= ((SPI1->SR & (1<<0) )>>0);
	IRQ_SRC.ERRI= ((SPI1->SR & (1<<4) )>>4);

	Global_SPI_Config[0]->SPI_PtrCallBack(IRQ_SRC);

}
void SPI2_IRQHandler()
{
	struct IRQ_SRC_S IRQ_SRC;

	IRQ_SRC.TXE= ((SPI2->SR & (1<<1) )>>1);
	IRQ_SRC.RXNE= ((SPI2->SR & (1<<0) )>>0);
	IRQ_SRC.ERRI= ((SPI2->SR & (1<<4) )>>4);


	Global_SPI_Config[1]->SPI_PtrCallBack(IRQ_SRC);

}
