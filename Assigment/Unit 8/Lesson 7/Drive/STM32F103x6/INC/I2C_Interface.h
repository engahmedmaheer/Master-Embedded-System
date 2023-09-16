/*******************************************************************/
/*******************************************************************/
/*****************   @Author:  AhmedMaher		********************/
/*****************   @Layer:   MCAL				********************/
/*****************   @SWC:     I2C				********************/
/*****************	 @Version: 1.00				********************/
/*******************************************************************/
/*******************************************************************/

#ifndef INC_I2C_INTERFACE_H_
#define INC_I2C_INTERFACE_H_

#include "I2C_Private.h"

#define I2C_NUM								2
#define PCLCK1_FREQ						8000000U







typedef enum
{
	I2C_ONE,
	I2C_TWO

}I2C_PERIPHERAL_E;


typedef enum
{
	/**–
 	 Standard Speed (up to 100 kHz)
	– Fast Speed (up to 400 kHz)*/

	I2C_SCLCK_SM_50K=50000U,
	I2C_SCLCK_SM_100K=100000U,


}I2C_ClockSpeed_E;


typedef enum
{
	I2C_DMA_DISABLE=(uint16_t)(0),
	I2C_DMA_ENABLE=(uint16_t)(I2C_CR2_DMAEN)

}I2C_DMA_EN_E;

typedef enum
{
	/**
	 * Bit 7 NOSTRETCH: Clock stretching disable (Slave mode)
	This bit is used to disable clock stretching in slave mode when ADDR or BTF flag is set, until
	it is reset by software.
	0: Clock stretching enabled
	1: Clock stretching disabled
	 */
	I2C_CLCK_Stretching_Disable =(uint16_t)(I2C_CR1_NOSTRETCH),
	I2C_CLCK_Stretching_Enable 	=(uint16_t)(0),


}I2C_CLCK_Stretching_E;


typedef enum
{
	/**
	 * Bit 1 SMBUS: SMBus mode
	0: I2C mode
	1: SMBus mode
	 */

	I2C_MODE=(uint16_t)(0),
	SMBUS_MODE=(uint16_t)(I2C_CR1_SMBUS)

}I2C_SMBus_mode_E;

typedef enum
{
	/**
	 * Bit 15 ADDMODE Addressing mode (slave mode)
	0: 7-bit slave address (10-bit address not acknowledged)
	1: 10-bit slave address (7-bit address not acknowledged)
	 */
	I2C_7_BIT_Address=(uint16_t)(0),
	I2C_10_BIT_Address=(uint16_t)(I2C_OAR1_ADDMODE_Msk),

}I2C_Address_Slave_Mode_E;

struct S_I2C_Device_Slave_Address
{
	uint16_t						DUAL_ADDRESS_Enable;			/*Bit 15 ADDMODE Addressing mode (slave mode)*/
	uint16_t						Primary_ADDRESS;
	uint16_t						Secondery_Address;
	I2C_Address_Slave_Mode_E		I2C_Address_Slave_Mode;			/*I2C_7_BIT_Address | I2C_10_BIT_Address */

};


typedef enum
{
	/**
	 * Bit 10 ACK: Acknowledge enable
	This bit is set and cleared by software and cleared by hardware when PE=0.
	0: No acknowledge returned
	1: Acknowledge returned after a byte is received (matched address or data)
	 *
	 */

	I2C_ACK_DISABLE,
	I2C_ACK_ENABLE = (uint16_t)(I2C_CR1_ACK)


}I2C_ACK_Control_E;

typedef enum
{
	/**
	Bit 6 ENGC: General call enable
	0: General call disabled. Address 00h is NACKed.
	1: General call enabled. Address 00h is ACKed.
	 */

	I2C_GC_DISABLE,
	I2C_GC_ENABLE = (uint16_t)(I2C_CR1_ENGC)

}I2C_GCE_E;

typedef enum
{
	/************************NOT Supported For User*************************/
	I2C_EV_STOP,
	I2C_ERROR_AF,
	I2C_EV_ADDR_MATCH,

	/************************Supported For User*****************************/
	I2C_EV_DATA_REQ,							/* APP Layer Should Send Data */
	I2C_EV_DATA_REC,							/* APP Layer Should Receive Data */

}Slave_Statue_E;


typedef enum
{
	I2C_UNENABLE = (uint16_t)(0),
	I2C_ENABLE= (uint16_t)(I2C_CR1_PE)

}I2C_EN_E;

typedef enum
{
	I2C_MASTER,			/*Support polling if used  I2C_MASTER*/
	I2C_SLAVE			/*Support Interrupt if used polling I2C_SLAVE*/
}I2C_STATES_E;


typedef enum
{
	I2C_STOP_CONDITION_DISABLE,		/*Without Stop*/
	I2C_STOP_CONDITION_ENABLE		/*With Stop*/

}Stop_Condition_E;


typedef enum
{
	START,
	REPEAT_START

}RepetedStart_E;

typedef enum
{
	I2C_START_DISABLE = (uint16_t)(0),
	I2C_START_ENABLE= (uint16_t)(I2C_CR1_START)



}Start_Condition_E;


typedef enum
{
	Reset,
	Set
}FlagState_E;

typedef enum
{
	I2C_BUSY_FLAG,
	EV5,			//SB=1, cleared by reading SR1 register followed by writing DR register with Address
	EV6,//EV6: ADDR=1, cleared by reading SR1 register followed by reading SR2
	EV8,
	EV8_1,
	EV8_2,
	EV7,
	I2C_MASTER_BYTE_TRANSMITING=(uint32_t)(0x00070080)	//Check on Flags TRA , BUSY , MSL , TX


}I2C_Flags_E;

typedef enum
{
	I2C_Direction_Transmitter,
	I2C_Direction_Reciever


}I2C_Direction_E;

typedef enum
{
	I2C_Interrupt,
	I2C_Polling

}I2C_INT_E;

typedef struct
{
	I2C_PERIPHERAL_E									I2C_DEFINETION;			/*WHICH I2C USED   -> I2C1  | I2C2 @ref I2C_PERIPHERAL_E*/

	I2C_ClockSpeed_E									I2C_ClockSpeed ;		/*Target Support SM Only (Standard Speed)*/

	I2C_DMA_EN_E										I2C_DMA_EN;				/*Support DMA Enable Tx Rx*/

	I2C_CLCK_Stretching_E								I2C_CLCK_Stretching;

	I2C_SMBus_mode_E									SMBus_MODE;

	struct S_I2C_Device_Slave_Address					I2C_ADDRESS_MODE;

	I2C_ACK_Control_E									I2C_ACK_Control;

	I2C_GCE_E											I2C_General_Call;

	I2C_EN_E											I2C_EN_STATUS ;

	I2C_STATES_E										I2C_STATE;

	I2C_INT_E											I2C_Interrupt_State;
	void(*P_Slave_Event_Callback)(Slave_Statue_E state);

}I2C_Config_S;






/**
 *
 * @param HI2C
 * @return : Local Error Statue
 */
uint8_t I2C_Init(I2C_Config_S* HI2C);

/**
 *
 * @param ID
 * @param EN_STATE
 */
void I2C_EnablePeripheral(I2C_PERIPHERAL_E ID , I2C_EN_E EN_STATE);
/**
 *
 * @param I2C_Peripheral
 */
void I2C_ResetPeripheral(I2C_PERIPHERAL_E I2C_Peripheral);

/**
 *
 * @param I2Cx
 * @param DeviceAddress
 * @param BufferDataOutput
 * @param DataLenght
 * @param Stop
 */
void I2C_Master_Tx(I2C_TypeDef_S* I2Cx , uint16_t DeviceAddress , uint16_t* BufferDataOutput , uint16_t DataLenght , Stop_Condition_E Stop , RepetedStart_E Start);
/**
 *
 * @param I2Cx
 * @param DeviceAddress
 * @param BufferDataOutput
 * @param DataLenght
 * @param Stop
 * @param Start
 */
void I2C_Master_Rx(I2C_TypeDef_S* I2Cx , uint16_t DeviceAddress , uint16_t* BufferDataOutput , uint16_t DataLenght , Stop_Condition_E Stop , RepetedStart_E Start);

/**
 *
 * @param I2Cx
 * @param DeviceAddress
 * @param NewStartStatue : Start Enable | Start Disable
 * @param Start			 : Start | Repeat Start
 */
void I2C_GenerateStartBit(I2C_TypeDef_S* I2Cx  , Start_Condition_E NewStartStatue , RepetedStart_E Start);
/**
 *
 * @param I2Cx
 * @param Stop
 */
void I2C_GenerateStopBit(I2C_TypeDef_S* I2Cx ,Stop_Condition_E Stop);
/**
 *
 * @param I2Cx
 * @param flag : which Flag Want Check
 * @return
 */
FlagState_E I2C_GetFlagStatue (I2C_TypeDef_S* I2Cx  , I2C_Flags_E flag );


/**
 *
 * @param I2Cx
 * @param address
 * @param I2C_Direction : Read Or Write
 */
void I2C_SendAddress(I2C_TypeDef_S* I2Cx ,uint16_t address , I2C_Direction_E I2C_Direction);

/**
 *
 * @param I2Cx
 * @param ACK
 */
void I2C_SendACKState(I2C_TypeDef_S* I2Cx , I2C_ACK_Control_E ACK );

/***************************************************SLave APIS ********************************/


/**
 *
 * @param I2Cx
 * @param data
 */
void I2C_Slave_TX(I2C_TypeDef_S* I2Cx , uint16_t 	data);
/**
 *
 * @param I2Cx
 * @param BufferData
 * @return
 */
void I2C_Slave_Rx(I2C_TypeDef_S* I2Cx , uint16_t* BufferData );





#endif /* INC_I2C_INTERFACE_H_ */
