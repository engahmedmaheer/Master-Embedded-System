/*******************************************************************/
/*******************************************************************/
/*****************   @Author:  AhmedMaher		********************/
/*****************   @Layer:   MCAL				********************/
/*****************   @SWC:     I2C				********************/
/*****************	 @Version: 1.00				********************/
/*******************************************************************/
/*******************************************************************/

#include <stdint.h>
#include <stdio.h>
#include "ERR_TYPE.h"

#include "STM32F103x6.h"
#include "I2C_Private.h"
#include "I2C_Interface.h"

/*********************************************************************************/
/********************************Global Macros***********************************/
/********************************************************************************/
I2C_TypeDef_S* Global_I2C_PERIPHERAL_Def[I2C_NUM] ={I2C1,I2C2};

I2C_Config_S Global_I2C_CONFIG_Def[I2C_NUM] ={0};



/************************Private Macros******************************************/
#define MHZ			1000000U





/***************************************APIS**************************************/
uint8_t I2C_Init(I2C_Config_S* HI2C)
{
	/**
	-> to configure CLCK
		1-Program the peripheral input clock in I2C_CR2->FREQ Register in order to generate correct
		timings.
		2-Configure the clock control registers
		Sm mode or SMBus:
		Thigh = CCR * TPCLK1
		Tlow  = CCR * TPCLK1
		3-Configure the rise time register
		4-Program the I2C_CR1 register to enable the peripheral
	 **/
	uint8_t 	LocalErrorStatue = OK;

	uint16_t	TempReg1 =0 , Freqrange =0;

	uint16_t 	result   =0;	/*CCR Result*/

	if(HI2C != NULL)
	{
		/*Enable RCC FOR Test& Reset Value Of Registers*/
		switch(HI2C->I2C_DEFINETION)
		{
		case I2C_ONE:	/*Reset Registers Value*/
			I2C1_CLCK_EN();
			break;
		case I2C_TWO:
			/*Reset Registers Value*/
			I2C1_CLCK_EN();
			break;
		default :	break;
		}

		Global_I2C_CONFIG_Def[HI2C->I2C_DEFINETION]=*(HI2C);
		/*Switch mode*/
		if(HI2C->SMBus_MODE ==I2C_MODE )
		{
			/**<I2C Supported In Soc>**/

			/**1- Init time | Peripheral clock frequency **/

			/*CLEAR FREQ BITS*/
			Global_I2C_PERIPHERAL_Def[HI2C->I2C_DEFINETION]->CR2 &=~(I2C_CR2_FREQ_Msk);

			Freqrange=(uint16_t)((PCLCK1_FREQ) / (MHZ) );

			Global_I2C_PERIPHERAL_Def[HI2C->I2C_DEFINETION]->CR2 |=Freqrange ;


			//2-Configure the clock control registers while peripheral is disabled

			if( (HI2C->I2C_ClockSpeed ==I2C_SCLCK_SM_50K) || (HI2C->I2C_ClockSpeed ==I2C_SCLCK_SM_100K) )
			{
				/*in Standard Mode SM*/

				/**					CCR = FPCLCK1 / (FI2C_CLCK*2)			**/

				result = (uint16_t)((PCLCK1_FREQ)/((HI2C->I2C_ClockSpeed)<<1));

				/*put result in CCR  Reg */
				Global_I2C_PERIPHERAL_Def[HI2C->I2C_DEFINETION]->CCR |=result ;

				/*3-Configure the rise time register
				 * 		For instance: in Sm mode, the maximum allowed SCL rise time is 1000 ns.
				If, in the I2C_CR2 register, the value of FREQ[5:0] bits is equal to 0x08 and TPCLK1 = 125 ns
				therefore the TRISE[5:0] bits must be programmed with 09h.
				(1000 ns / 125 ns = 8 + 1)
				The filter value can also be added to TRISE[5:0].
				If the result is not an integer, TRISE[5:0] must be programmed with the integer part, in order
				to respect the tHIGH parameter.
				Note: TRISE[5:0] must be configured only when the I2C is disabled (PE = 0)
				 *
				 */

				Global_I2C_PERIPHERAL_Def[HI2C->I2C_DEFINETION]->TRISE |=Freqrange + 1;



			}
			else
			{
				/*	in FastMode not supported	*/
			}


			/****************************DMA Enable**********************************/

			Global_I2C_PERIPHERAL_Def[HI2C->I2C_DEFINETION]->CR2 |= HI2C->I2C_DMA_EN ;


			/*  I2C CR1 Configuration */

			TempReg1 = Global_I2C_PERIPHERAL_Def[HI2C->I2C_DEFINETION]->CR1 ;

			TempReg1 |= (uint16_t)((HI2C->I2C_ACK_Control )|(HI2C->I2C_General_Call) | (HI2C->I2C_CLCK_Stretching));

			Global_I2C_PERIPHERAL_Def[HI2C->I2C_DEFINETION]->CR1 =TempReg1 ;


			/*OAR1 & OAR2 Reg */

			TempReg1 = 0 ;

			if(HI2C->I2C_ADDRESS_MODE.DUAL_ADDRESS_Enable == 1)
			{
				/*DUAL ADDRESS MODE & Put I2C_OAR2_ENDUAL bit = 1 in TempReg1 */
				TempReg1 =  I2C_OAR2_ENDUAL ;

				TempReg1 |= HI2C->I2C_ADDRESS_MODE.Secondery_Address << I2C_OAR2_ADD2_Pos  ;

				Global_I2C_PERIPHERAL_Def[HI2C->I2C_DEFINETION]->OAR2 = TempReg1 ;

			}

			/*SINGLE ADDRESS MODE & 7 bit mode */
			/* 10 bit mode not supported  */
			TempReg1 =0 ;

			TempReg1 |= HI2C->I2C_ADDRESS_MODE.Primary_ADDRESS << I2C_OAR1_ADD0_Pos ;

			TempReg1 |=  HI2C->I2C_ADDRESS_MODE.I2C_Address_Slave_Mode ;

			Global_I2C_PERIPHERAL_Def[HI2C->I2C_DEFINETION]->OAR1 = TempReg1 ;

		}
		else
		{

			/*Soc Not Support SMBUS*/
			LocalErrorStatue=NOK;

		}

		if(HI2C->I2C_Interrupt_State == I2C_Interrupt)
		{
			/*Work With Interrupt  Enable Slave Interrupt IRQ*/

			Global_I2C_PERIPHERAL_Def[HI2C->I2C_DEFINETION]->CR2 |= I2C_CR2_ITERREN	;
			Global_I2C_PERIPHERAL_Def[HI2C->I2C_DEFINETION]->CR2 |= I2C_CR2_ITEVTEN	;
			Global_I2C_PERIPHERAL_Def[HI2C->I2C_DEFINETION]->CR2 |= I2C_CR2_ITBUFEN	;


		}

		Global_I2C_PERIPHERAL_Def[HI2C->I2C_DEFINETION]->CR1 |= HI2C->I2C_EN_STATUS ;

		Global_I2C_PERIPHERAL_Def[HI2C->I2C_DEFINETION]->SR1 &=~(REG_MASH);

		Global_I2C_PERIPHERAL_Def[HI2C->I2C_DEFINETION]->SR2 &=~(REG_MASH);



	}
	else
	{

		LocalErrorStatue = NULL_POINTER;
	}


	return LocalErrorStatue ;

}
/**
 *
 * @param ID
 * @param EN_STATE
 */
void I2C_EnablePeripheral(I2C_PERIPHERAL_E ID , I2C_EN_E EN_STATE)
{
	Global_I2C_PERIPHERAL_Def[ID]->CR1 |=EN_STATE;

}
/**
 *
 * @param I2C_Peripheral
 */
void I2C_ResetPeripheral(I2C_PERIPHERAL_E I2C_Peripheral)
{
	switch (I2C_Peripheral)
	{

	case I2C_ONE :
		I2C1_CLCK_RESET();
	case I2C_TWO:
		I2C2_CLCK_RESET();

	}

}
/**
 *
 * @param I2Cx
 * @param DeviceAddress
 * @param NewStartStatue : Start Enable | Start Disable
 * @param Start			 : Start | Repeat Start
 */
void I2C_GenerateStartBit(I2C_TypeDef_S* I2Cx  , Start_Condition_E NewStartStatue , RepetedStart_E Start)
{
	if(Start != REPEAT_START)
	{
		/*Check Bus ideal*/
		/*Polling Until bus flag return ideal*/
		while(I2C_GetFlagStatue(I2Cx,I2C_BUSY_FLAG));

	}

	/************************* Bit 8 START: Start generation****************************************
		This bit is set and cleared by software and cleared by hardware when start is sent or PE=0.
		In Master Mode:
		0: No Start generation
		1: Repeated start generation
		In Slave mode:
		0: No Start generation
		1: Start generation when the bus is free
	 */
	switch(NewStartStatue)
	{
	case I2C_START_DISABLE :
		I2Cx->CR1 &=~(I2C_CR1_START);
		break;
	case I2C_START_ENABLE :
		I2Cx->CR1 |= I2C_CR1_START ;
		break;


	}



}

/**
 *
 * @param I2Cx
 * @param Stop
 */
void I2C_GenerateStopBit(I2C_TypeDef_S* I2Cx ,Stop_Condition_E Stop)
{

	/*
	 * Bit 9 STOP: Stop generation
		The bit is set and cleared by software, cleared by hardware when a Stop condition is
		detected, set by hardware when a timeout error is detected.
		In Master Mode:
		0: No Stop generation.
		1: Stop generation after the current byte transfer or after the current Start condition is sent.
		In Slave mode:
		0: No Stop generation.
		1: Release the SCL and SDA lines after the current byte transfer.
	 */
	switch (Stop)
	{
	case I2C_STOP_CONDITION_DISABLE :
		I2Cx->CR1 &=(~I2C_CR1_STOP)  ;
		break;
	case I2C_STOP_CONDITION_ENABLE :
		I2Cx->CR1 |=I2C_CR1_STOP ;
		break;
	}

}
/**
 *
 * @param I2Cx
 * @param DeviceAddress
 * @param BufferDataOutput
 * @param DataLenght
 * @param Stop
 */
void I2C_Master_Tx(I2C_TypeDef_S* I2Cx , uint16_t DeviceAddress , uint16_t* BufferDataOutput , uint16_t DataLenght , Stop_Condition_E Stop , RepetedStart_E Start)
{
	uint8_t counter ;

	/*Send Start Bit & configure timeout by timer */

	I2C_GenerateStartBit(I2Cx ,I2C_START_ENABLE ,Start);

	/*Wait For EV5: SB=1, cleared by reading SR1 register followed by writing DR register with Address.*/

	while(!I2C_GetFlagStatue(I2Cx,EV5));

	/*writing DR register with Address*/

	I2C_SendAddress(I2Cx , DeviceAddress , I2C_Direction_Transmitter); //TX

	/*Wait For  EV6: ADDR=1, cleared by reading SR1 register followed by reading SR2*/

	while(!I2C_GetFlagStatue(I2Cx,EV6));

	/*check flags TRA(Tx|Rx) ,BUSY , MSL (M|S) , TXE */

	while(!I2C_GetFlagStatue(I2Cx,I2C_MASTER_BYTE_TRANSMITING));


	for(counter = 0 ; counter < DataLenght ; counter++)
	{
		/*write on DR */
		I2Cx->DR = BufferDataOutput[counter];

		/*Wait EV8(ACK) : TxE=1, shift register not empty, data register empty, cleared by writing DR register*/
		while(!I2C_GetFlagStatue(I2Cx,EV8));


	}

	/*EV8_2: TxE=1, BTF = 1, Program Stop request. TxE and BTF are cleared by hardware by the Stop condition*/

	while(!I2C_GetFlagStatue(I2Cx,EV8_2));

	/*Send Stop Condition*/

	if(Stop ==I2C_STOP_CONDITION_ENABLE)
	{
		I2C_GenerateStopBit(I2Cx,I2C_STOP_CONDITION_ENABLE);
	}




}
/**
 *
 * @param I2Cx
 * @param DeviceAddress
 * @param BufferDataOutput
 * @param DataLenght
 * @param Stop
 * @param Start
 */
void I2C_Master_Rx(I2C_TypeDef_S* I2Cx , uint16_t DeviceAddress , uint16_t* BufferDataOutput , uint16_t DataLenght , Stop_Condition_E Stop , RepetedStart_E Start)
{

	uint8_t counter , index ;

	/*Send Start Bit & configure timeout by timer */

	I2C_GenerateStartBit(I2Cx ,I2C_START_ENABLE ,START);

	/*Wait For EV5: SB=1, cleared by reading SR1 register followed by writing DR register with Address.*/

	while(!I2C_GetFlagStatue(I2Cx,EV5));

	/*writing DR register with Address*/

	I2C_SendAddress(I2Cx , DeviceAddress , I2C_Direction_Reciever); //Rx

	/*Wait For  EV6: ADDR=1, cleared by reading SR1 register followed by reading SR2*/

	while(!I2C_GetFlagStatue(I2Cx,EV6));

	/*Enable ACK*/
	I2C_SendACKState(I2Cx,I2C_ACK_ENABLE);

	for(counter = DataLenght ; counter > 1 ; counter--)
	{
		/*Bit 6 RxNE: Data register not empty (receivers)
		0: Data register empty
		1: Data register not empty
		– Set when data register is not empty in receiver mode. RxNE is not set during address phase.
		– Cleared by software reading or writing the DR register or by hardware when PE=0.
		RxNE is not set in case of ARLO event.
		Note: RxNE is not cleared by reading data when BTF is set, as the data register is still full.
		 *
		 */
		while(!I2C_GetFlagStatue(I2Cx,EV7));

		/*write on DR */
		*BufferDataOutput =I2Cx->DR ;

		BufferDataOutput++;

	}

	/*DISABLE ACK*/
	I2C_SendACKState(I2Cx,I2C_ACK_DISABLE);


	if(Stop ==I2C_STOP_CONDITION_ENABLE)
	{
		I2C_GenerateStopBit(I2Cx,I2C_STOP_CONDITION_ENABLE);
	}


	/*Return state ACK*/

	if(I2Cx == I2C1)
		index=0;
	else
		index=1;


	if(Global_I2C_CONFIG_Def[index].I2C_ACK_Control == I2C_ACK_ENABLE)
	{
		I2C_SendACKState(I2Cx,I2C_ACK_ENABLE);

	}



}
/**
 *
 * @param I2Cx
 * @param flag : which Flag Want Check
 * @return
 */
FlagState_E I2C_GetFlagStatue (I2C_TypeDef_S* I2Cx  , I2C_Flags_E flag )
{

	FlagState_E BitStatus = Reset ;

	volatile uint32_t DummyRead ;

	uint32_t flag1=0 , flag2=0;

	uint32_t LastValue= 0;

	switch (flag)
	{

	case I2C_BUSY_FLAG :

		/************************************* BUSY: Bus busy**********************************
	0: No communication on the bus
	1: Communication ongoing on the bus
	– Set by hardware on detection of SDA or SCL low
	– cleared by hardware on detection of a Stop condition.
	It indicates a communication in progress on the bus. This information is still updated when
	the interface is disabled (PE=0)*/

		if((I2Cx->SR2) & I2C_SR2_BUSY)
		{
			BitStatus=Set;	/*Bus Not Ideal*/
		}
		else{
			BitStatus=Reset;
		}
		break;


	case EV5:
		/*Bit 0 SB: Start bit (Master mode)
			0: No Start condition
			1: Start condition generated.
			– Set when a Start condition generated.
			– Cleared by software by reading the SR1 register followed by writing the DR register, or by
			hardware when PE=0*/

		if((I2Cx->SR1) & I2C_SR1_SB)
		{
			BitStatus=Set;
		}
		else{
			BitStatus=Reset;
		}
		break;


	case EV6 :
		/*		EV6: ADDR=1, cleared by reading SR1 register followed by reading SR2
		Bit 1 ADDR: Address sent (master mode)/matched (slave mode)
		This bit is cleared by software reading SR1 register followed reading SR2, or by hardware
		when PE=0.
		Address matched (Slave)
		0: Address mismatched or not received.
		1: Received address matched.
		– Set by hardware as soon as the received slave address matched with the OAR registers
		content or a general call or a SMBus Device Default Address or SMBus Host or SMBus Alert
		is recognized. (when enabled depending on configuration).
		Note: In slave mode, it is recommended to perform the complete clearing sequence (READ
		SR1 then READ SR2) after ADDR is set. Refer to Figure 272.
		Address sent (Master)
		0: No end of address transmission
		1: End of address transmission
		– For 10-bit addressing, the bit is set after the ACK of the 2nd byte.
		– For 7-bit addressing, the bit is set after the ACK of the byte.
		Note: ADDR is not set after a NACK reception*/
		if((I2Cx->SR1) & I2C_SR1_ADDR)
		{
			BitStatus=Set;
		}
		else{
			BitStatus=Reset;
		}
		DummyRead =I2Cx->SR1 ;
		DummyRead =I2Cx->SR2 ;
		//Reading I2C_SR2 after reading I2C_SR1 clears the ADDR flag, even if the ADDR flag was set after reading I2C_SR1. Consequently,
		//I2C_SR2 must be read only when ADDR is found set in I2C_SR1 or when the STOPF bit is cleared.

		break;

	case I2C_MASTER_BYTE_TRANSMITING :

		flag1 = I2Cx->SR1 ;
		flag2 = I2Cx->SR2 ;
		flag2 =flag2<<16;

		LastValue = ((uint32_t)(flag1 | flag2)) &(uint32_t)(0x00ffffff);

		if((LastValue & flag)==flag)
		{
			BitStatus=Set;
		}
		else{
			BitStatus=Reset;
		}
		break;

	case EV8:
	case EV8_1:
		/*Bit 7 TxE: Data register empty (transmitters)
				0: Data register not empty
				1: Data register empty
				– Set when DR is empty in transmission. TxE is not set during address phase.
				– Cleared by software writing to the DR register or by hardware after a start or a stop condition
				or when PE=0.
				TxE is not set if either a NACK is received, or if next byte to be transmitted is PEC (PEC=1)
				Note: TxE is not cleared by writing the first data being transmitted, or by writing data when
				BTF is set, as in both cases the data register is still empty.*/
		if((I2Cx->SR1) &(I2C_SR1_TXE) )
		{
			BitStatus=Set;
		}
		else{
			BitStatus=Reset;
		}
		break;

	case EV8_2:
		/**
		 * Bit 7 TxE: Data register empty (transmitters)
0: Data register not empty
1: Data register empty
– Set when DR is empty in transmission. TxE is not set during address phase.
– Cleared by software writing to the DR register or by hardware after a start or a stop condition
or when PE=0.
TxE is not set if either a NACK is received, or if next byte to be transmitted is PEC (PEC=1)
Note: TxE is not cleared by writing the first data being transmitted, or by writing data when
BTF is set, as in both cases the data register is still empty
		 */
		if((I2Cx->SR1)&(I2C_SR1_TXE) &&  (I2Cx->SR1)&(I2C_SR1_BTF))
		{
			BitStatus=Set;
		}
		else{
			BitStatus=Reset;
		}
		break;

	case EV7:

		if((I2Cx->SR1) &(I2C_SR1_RXNE) )
		{
			BitStatus=Set;
		}
		else{
			BitStatus=Reset;
		}
		break;


	}


	return BitStatus ;


}

/**
 *
 * @param I2Cx
 * @param address
 * @param I2C_Direction : Read Or Write
 */
void I2C_SendAddress(I2C_TypeDef_S* I2Cx ,uint16_t address , I2C_Direction_E I2C_Direction)
{
	/*7 bit address & last bit R/W*/
	address = address<<1 ;

	if(I2C_Direction != I2C_Direction_Transmitter)
	{
		/*Set Last bit address bit0 for read*/
		address |=1<<0 ;

	}
	else
	{
		/*tog Last bit address bit0 for write*/
		address &=~(1<<0);
	}
	I2Cx->DR = address ;

}
/**
 *
 * @param I2Cx
 * @param ACK
 */
void I2C_SendACKState(I2C_TypeDef_S* I2Cx , I2C_ACK_Control_E ACK )
{

	switch(ACK)
	{
	case I2C_ACK_DISABLE :

		I2Cx->CR1 &=~(I2C_CR1_ACK);

		break;
	case I2C_ACK_ENABLE :

		I2Cx->CR1 |= I2C_CR1_ACK;

		break;
	}


}

/**
 *
 * @param I2Cx
 * @param data
 */
void I2C_Slave_TX(I2C_TypeDef_S* I2Cx , uint16_t data)
{

	I2Cx->DR =data ;

}
/**
 *
 * @param I2Cx
 * @param BufferData
 * @return
 */
void I2C_Slave_Rx(I2C_TypeDef_S* I2Cx , uint16_t* BufferData )
{

	*BufferData = (uint16_t)I2Cx->DR ;

}




/************************************************Interrupt Handler ***************************************/



void I2C1_EV_IRQHandler()  					/* I2C1 event interrupt                             */
{



}
void I2C1_ER_IRQHandler()        			/* I2C1 error interrupt                             */
{



}
void I2C2_EV_IRQHandler()        			/* I2C2 event interrupt                             */
{



}
void I2C2_ER_IRQHandler()
{


}



