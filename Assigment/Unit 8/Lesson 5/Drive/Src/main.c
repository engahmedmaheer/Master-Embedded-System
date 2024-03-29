/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "BIT_MATH.h"

//#define MCU_ACT_MASTER

#define MCU_ACT_SLAVE


#include "STM32F103x6.h"
#include "RCC_Interface.h"
#include "GPIO_Interface.h"
#include "NVIC_Interface.h"
#include "EXTI_Interface.h"
#include "USART_Interface.h"
#include "SPI_Interface.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

void CLCK_Init();
void GPIO_Init();
void Ahmed_SPI1_Handler(struct IRQ_SRC_S IRQ_SRC);

unsigned char CH ;

int main(void)
{

	CLCK_Init();
	NVICEnable(USART1_IRQ);
	NVICEnable(SPI1_);


	USART_HandleTypeDef USART1CFG=
	{
			.BAUDRATE=USART_BaudRate_115200,
			.IRQ_USART_Enable=USART_IRQ_Enable_NONE,
			.PARITY=USART_NO_PARITY,
			.STOP_BITS=USART_ONE_STOP_BITS,
			.USART_DATA_PAYLOAD=USART_8DATA_BITS,
			.USART_MODE=UART_MODE_RX_TX,
			.USART_SELECTION=USART_ONE,
			.USART_STATUE=USART_ENABLE,
			.HwFlowCtl=USART_HwFlowCtl_NONE,

	};
	GPIO_USARTSetPins(USART_ONE_ID);
	USART_Init(&USART1CFG);




	/*Common Configuration for master or slave*/
	SPI_Config_S SPICONFIG1=
	{
			.ClckPhase=SPI_CLCK_Phase_SeconedCLCK,
			.ClckPolarity=SPI_CLCK_Polarity_High_Idel,
			.DataSize=SPI_Data_Size_8bit,
			.FrameFormat=SPI_Frame_Format_MSB,
			.SPI_PERIPHERAL=SPI_ONE,
			.BaudRatePrescaller=SPI_BAUDRATE_FCLCK_DIV_8,
			.CommunicationMode=SPI_Direction_2_Lines

	};

#ifdef MCU_ACT_MASTER
	SPICONFIG1.DeviceMode=SPI_Mode_Master;
	SPICONFIG1.InterruptEnablel=SPI_IE_NONE;
	SPICONFIG1.NSSConfig=SPI_NSS_SW_SSI_SET;


	//Configured SS PA4 By GPIO
	GPIO_PinConfig_S NSS=
	{
			.Mode=GPIO_Output_PUSHPULL,
			.Speed=GPIO_LOWSPEED,
			.PortNum=PORTA,
			.PinNumber=PIN4,

	};
	GPIO_u8PinInit(&NSS);
	/*ACT AS MASTER ----------*/
	GPIO_u8SetPinValue(PORTA, PIN4, GPIO_PINHIGH);
	GPIO_SPISetPins(SPI_ONE_ID, SPI_MASTER_ID, SPI_NSS_HW_MASTER_SS_OP_ENABLE);



#endif

#ifdef MCU_ACT_SLAVE

	SPICONFIG1.DeviceMode=SPI_Mode_Slave;
	SPICONFIG1.InterruptEnable=SPI_IE_RXNEIE;
	SPICONFIG1.SPI_PtrCallBack= Ahmed_SPI1_Handler;
	SPICONFIG1.NSSConfig=SPI_NSS_HW_Slave;
	GPIO_SPISetPins(SPI_ONE_ID, SPI_SLAVE_ID, SPI_NSS_HW_MASTER_SS_OP_DISABLE);
#endif


	SPI_Init(&SPICONFIG1);

	NVIC_SetPendingFlag(SPI1_);
	while(1)
	{



	}


	/* Loop forever */
	for(;;);

}

void CLCK_Init()
{

	RCC_GPIOA_CLCK_EN();
	RCC_GPIOB_CLCK_EN();

	AFIO_GPIOA_CLCK_EN();

	RCC_USART1_CLCK_EN();

	SPI1_CLCK_EN();



}


void USART1_IRQHandler()
{

#ifdef MCU_ACT_MASTER

	uint16_t CH ;
	USART_U16RecieveData(USART1, &CH, USART_POLLING_DISABLE);

	USART_U16SendData(USART1, &CH, USART_POLLING_ENABLE);


	GPIO_u8SetPinValue(PORTA, PIN4, GPIO_PINLOW);
	SPI_U16TXRX(SPI1, &CH, Polling_Enable);
	GPIO_u8SetPinValue(PORTA, PIN4, GPIO_PINHIGH);

#endif
}

void Ahmed_SPI1_Handler(struct IRQ_SRC_S IRQ_SRC)
{
#ifdef MCU_ACT_SLAVE

	if(IRQ_SRC.RXNE )
	{
		CH = 0xf ;
		SPI_U16TXRX(SPI1, &CH, Polling_Disable);
		USART_U16SendData(USART1, &CH, USART_POLLING_ENABLE);

	}

#endif
}
