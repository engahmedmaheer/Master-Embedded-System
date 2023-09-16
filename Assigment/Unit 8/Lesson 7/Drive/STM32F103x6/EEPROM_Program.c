/*
 * EEPROM_Program.c
 *
 *  Created on: Sep 15, 2023
 *      Author: AhmedMaher
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "ERR_TYPE.h"

#include "STM32F103x6.h"
#include "EEPROM_Private.h"
#include "EEPROM_Interface.h"

#include "I2C_Interface.h"
#include "GPIO_Interface.h"
#include "RCC_Interface.h"

/**
 *
 */
void EEPROM_voidInit(void)
{
	I2C_Config_S I2C1_CFG =
	{
			.I2C_DEFINETION =I2C_ONE,
			.I2C_General_Call =I2C_GC_ENABLE ,
			.I2C_ACK_Control =I2C_ACK_ENABLE,
			.I2C_ClockSpeed = I2C_SCLCK_SM_100K,
			.SMBus_MODE =I2C_MODE,
			.I2C_STATE =I2C_SLAVE,
			.I2C_CLCK_Stretching=I2C_CLCK_Stretching_Enable,
			.I2C_DMA_EN = I2C_DMA_DISABLE,
			.I2C_EN_STATUS=I2C_ENABLE,
			.I2C_Interrupt_State=I2C_Polling

	};

	I2C_Init(&I2C1_CFG);

	RCC_EnableAPB2CLCK(3);
	GPIO_SetI2CPins(I2C_GPIO_ONE_ID);



}
/**
 *
 * @param memory_address
 * @param byte
 * @param DataLenght
 * @return
 */
unsigned char EEPROM_Write_Byte(unsigned int memory_address , uint16_t* byte , uint8_t DataLenght)
{

	uint8_t Count ;

	uint8_t LocalErrorState = OK ;

	uint16_t LocalBuffer[256]; // data will send with Address

	LocalBuffer[0]=(uint8_t)(memory_address >> 8 ); //upper byte memory address
	LocalBuffer[1]=(uint8_t)memory_address ;		//lower byte  memory address

	for( Count =2 ; Count < (DataLenght + 2) ; Count++)
	{
		LocalBuffer[Count]=byte[Count-2];  //      DATA1 |  DATA0 |ADD1 |ADD0
	}

	I2C_Master_Tx(I2C1, EEPROM_SLAVE_ADDRESS, LocalBuffer , (DataLenght+2) , I2C_STOP_CONDITION_ENABLE, START);

	return LocalErrorState ;


}
/**
 *
 * @param address
 * @param DataOut
 * @param DataLenght
 * @return
 */
unsigned char EEPROM_Read_Byte(unsigned int address , uint16_t* DataOut , uint8_t DataLenght)
{
	uint16_t LocalBuffer[2] ;

	uint16_t LocalErrorState = OK ;

	/*Address which I Read*/
	LocalBuffer[0]= (uint8_t)(address>>8);
	LocalBuffer[1]= (uint8_t)(address);

	/*Read Concept*/
	/*1-Write Addresss*/
	I2C_Master_Tx(I2C1, EEPROM_SLAVE_ADDRESS, LocalBuffer, 2, I2C_STOP_CONDITION_DISABLE, START);

	/*2-Read Data*/
	I2C_Master_Tx(I2C1, EEPROM_SLAVE_ADDRESS, DataOut, DataLenght, I2C_STOP_CONDITION_ENABLE, REPEAT_START);


	return LocalErrorState ;
}

