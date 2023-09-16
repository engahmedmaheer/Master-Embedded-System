/*
 * GPIO_Interface.h
 *
 *  Created on: May 5, 2023
 *      Author: AhmedMaher
 */

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_



/**
 * @brief :enum For Ports
 *
 */
typedef enum
{
	PORTA						,      /**< PORTA */
	PORTB 						,      /**< PORTB */
	PORTC 						,      /**< PORTC */
	PORTD 						,      /**< PORTD */
	PORTE 						,      /**< PORTE */
	PORTF 						,      /**< PORTF */
	PORTG 						,      /**< PORTG */
	PORTH 						,      /**< PORTH */
	INVALIED_PORT				,/**< INVALIED_PORT */
	AllPort=((uint16_t)0xFFFF)
}GPIO_PORT_E;
/**
 * @brief
 *
 */
typedef enum
{
	PIN0  =((uint16_t)0x0001),
	PIN1  =((uint16_t)0x0002),
	PIN2  =((uint16_t)0x0004),
	PIN3  =((uint16_t)0x0008),
	PIN4  =((uint16_t)0x0010),
	PIN5  =((uint16_t)0x0020),
	PIN6  =((uint16_t)0x0040),
	PIN7  =((uint16_t)0x0080),
	PIN8  =((uint16_t)0x0100),
	PIN9  =((uint16_t)0x0200),
	PIN10 =((uint16_t)0x0400),
	PIN11 =((uint16_t)0x0800),
	PIN12 =((uint16_t)0x1000),
	PIN13 =((uint16_t)0x2000),
	PIN14 =((uint16_t)0x4000),
	PIN15 =((uint16_t)0x8000),
	//	INVALIED_PIN=16,
	Allpins =((uint16_t)0xffff)
}GPIO_PIN_E;


typedef enum
{
	GPIO_ANALOG					=0x00000000u,
	GPIO_INPUT_Floating 		=0x00000001u,
	GPIO_INPUT_PU 				=0x00000002u,
	GPIO_INPUT_PD 				=0x00000003u,

	GPIO_Output_PUSHPULL 		=0x00000004u,
	GPIO_Output_OPENDRAIN		=0x00000005u,

	GPIO_AF_PP					=0x00000006u,
	GPIO_AF_OD					=0x00000007u,
	GPIO_AF_INPUT				=0x00000008u

}GPIO_MODE_E;

typedef enum
{
	GPIO_LOWSPEED 				=0x00000002u,		//-->2MHZ
	GPIO_MEDUIMSPEED			=0x00000001u,		//-->10MHZ
	GPIO_FASTSPEED				=0x00000003u,		//-->50MHZ
}GPIO_SPEED_E;



typedef enum
{
	GPIO_AF0  ,
	GPIO_AF1  ,
	GPIO_AF2 ,
	GPIO_AF3  ,
	GPIO_AF4  ,
	GPIO_AF5  ,
	GPIO_AF6  ,
	GPIO_AF7  ,
	GPIO_AF8  ,
	GPIO_AF9  ,
	GPIO_AF10  ,
	GPIO_AF11  ,
	GPIO_AF12  ,
	GPIO_AF13  ,
	GPIO_AF14  ,
	GPIO_AF15  ,
}GPIO_AF_E;

typedef enum
{
	GPIO_PINLOW,
	GPIO_PINHIGH
}PinVal_E;

typedef struct
{
	GPIO_PORT_E        PortNum ;

	GPIO_PIN_E         PinNumber;

	GPIO_MODE_E        Mode;

	GPIO_SPEED_E       Speed;

	GPIO_AF_E          AF;

}GPIO_PinConfig_S;

typedef enum
{
	USART_ONE_ID,
	USART_TWO_ID,
	USART_THREE_ID,
	/********************************/
	SPI_ONE_ID,
	SPI_TWO_ID


}GPIO_ID_PERIPHERAL_E;

typedef enum
{
SPI_MASTER_ID,
SPI_SLAVE_ID

}MASTER_SLAVE_STATUE_E;

typedef enum
{
	SPI_NSS_HW_MASTER_SS_OP_DISABLE,
	SPI_NSS_HW_MASTER_SS_OP_ENABLE,

}NSS_STATUE_E;


typedef enum
{
	I2C_GPIO_ONE_ID,
	I2C_GPIO_TWO_ID

}I2C_ID_PERIPHERAL_E;

typedef enum
{
	I2C_GPIO_MASTER_ID,
	I2C_GPIO_SLAVE_ID

}I2C_MODE_E;


/******************************************************************************
 * @func :  GPIO_u8PinInit
 * 		 : Function Privileged Can't Change in Struct Which You Pass it
 *
 * Description:	the function initialize the required pin configuration  options
 *
 * Parameters:
 * @par[in]  : 1- PinConfig: constant pointer to GPIO_PinConfig_S structure which holds the configurations
 *
 * Return:	ErrorState , Type:uint8_t
 *
 ******************************************************************************/
uint8_t GPIO_u8PinInit(const GPIO_PinConfig_S* PinConfig);

/******************************************************************************
 * @func :  GPIO_u8PDeInit
 **      : Function Privileged Can't Change in Struct Which You Pass it
 * Description:	the function Reset the required pin configuration
 *
 * Parameters:
 * @par[in]  : 1- PORT: PORT ENUM (GPIOA,GPIOB,...)
 *
 * Return:	ErrorState , Type:uint8_t
 *
 ******************************************************************************/
uint8_t GPIO_u8PDeInit(GPIO_PORT_E PORT);
/******************************************************************************
 * @func :  GPIO_u8SetPinValue
 *
 * Description:	the function is Set Pin Value
 *
 * Parameters:
 * @par[in]  : 1- GPIO_PORT_E: it's Enum For Switch PORTS (PORTA,PORTB,...)
 * 			   2- GPIO_PIN_E : it's Enum For Switch PINS (PIN0,PIN1,......)
 * 			   3- PinVal_E	 : it's Enum For Switch Value(GPIO_PINHIGH,GPIO_PINLOW)
 * Return:	ErrorState , Type:uint8_t
 *
 ******************************************************************************/
uint8_t GPIO_u8SetPinValue(GPIO_PORT_E PORT ,   GPIO_PIN_E  PIN  , PinVal_E VAL );
/******************************************************************************
 * @func :  GPIO_u8ReadPinValue
 *
 * Description:	the function is Read Pin Value
 *
 * Parameters:
 * @par[in]  : 1- GPIO_PORT_E: it's Enum For Switch PORTS (PORTA,PORTB,....)
 * 			   2- GPIO_PIN_E : it's Enum For Switch PINS  (PIN0,PIN1,......)
 * Return:		Value ErrorState , Type:uint8_t
 *
 *
 ******************************************************/
uint8_t GPIO_u8ReadPinValue(GPIO_PORT_E PORT ,   GPIO_PIN_E  PIN  , PinVal_E* VAL );
/******************************************************************************
 * @func :  GPIO_u8TogglePinValue
 *
 * Description:	the function is Toggle Pin Value
 *
 * Parameters:
 * @par[in]  : 1- GPIO_PORT_E: it's Enum For Switch PORTS (PORTA,PORTB,...)
 * 			   2- GPIO_PIN_E : it's Enum For Switch PINS  (PIN0,PIN1,......)
 * Return:	   ErrorState , Type:uint8_t
 *
 ******************************************************/
uint8_t GPIO_u8TogglePinValue(GPIO_PORT_E PORT ,   GPIO_PIN_E  PIN );
/******************************************************************************
 * @func :  GPIO_voidSetPortValue
 *
 * Description:	the function is SET PORT Value
 *
 * Parameters:
 * @par[in]  : 1- GPIO_PORT_E: it's Enum For Switch PORTS (PORTA,PORTB,....)
 * 			   2- Val : it's Enum For Status PINS  (GPIO_HIGI,GPIO_LOW)
 * Return:		Value ErrorState , Type:uint8_t
 *
 *
 ******************************************************/
uint8_t GPIO_voidSetPortValue(GPIO_PORT_E PORT, uint16_t Val);
/******************************************************************************
 * @func :  GPIO_u8TogglePortValue
 *
 * Description:	the function is Toggle PORT Value
 *
 * Parameters:
 * @par[in]  : 1- GPIO_PORT_E: it's Enum For Switch PORTS (PORTA,PORTB,...)
 * Return:	   ErrorState , Type:uint8_t
 *
 ******************************************************/
uint8_t GPIO_u8TogglePortValue(GPIO_PORT_E PORT );

/******************************************************************************
 * @func :  GPIO_u8ReadPortValue
 *
 * Description:	the function is Read PORT Value
 *
 * Parameters:
 * @par[in]  : 1- PORT: it's Enum For Switch PORTS (PORTA,PORTB,....)
 * 			   2- PIN : it's Enum For Switch PINS  (PIN0,PIN1,......)
 * 			   3- VAL : Pointer To Variable  value Should be uint32
 * Return:		Value ErrorState , Type:uint8_t
 *
 *
 ******************************************************/
uint8_t GPIO_u8ReadPortValue(GPIO_PORT_E PORT   , uint16_t* VAL );

/******************************************************************************
 * @func :  GPIO_u8LockPin
 *
 * Description:	the function is Lock Pin
 *
 * Parameters:
 * @par[in]  : 1- PORT: it's Enum For Switch PORTS (PORTA,PORTB,....)
 * 			   2- PIN : it's Enum For Switch PINS  (PIN0,PIN1,......)
 * Return:		Value ErrorState , Type:uint8_t
 *
 *
 ******************************************************/
uint8_t GPIO_u8LockPin(GPIO_PORT_E PORT ,   GPIO_PIN_E  PIN  );

/*****************************************For Peripherals**********************************/
/******************************************************************************
 * @func :  GPIO_USARTSetPins
 *
 * Description:	the function is Set USART Pins
 *
 * Parameters:
 * @par[in]  : 1- GPIO_ID_PERIPHERAL_E: it's ID For USART ID Number
 * Return:		Value ErrorState , Type:uint8_t
 *
 *
 ******************************************************/
uint8_t GPIO_USARTSetPins(GPIO_ID_PERIPHERAL_E Local_USARTID);
/******************************************************************************
 * @func :  GPIO_SPISetPins
 *
 * Description:	the function is Set SPI Pins
 *
 * Parameters:
 * @par[in]  : 1- GPIO_ID_PERIPHERAL_E: it's ID For USART ID Number
 * 			 : 2- Master Or Slave
 * Return:		Value ErrorState , Type:uint8_t
 *
 *
 ******************************************************/
uint8_t GPIO_SPISetPins(GPIO_ID_PERIPHERAL_E LocalSPIID , MASTER_SLAVE_STATUE_E MS_Statue_ID , NSS_STATUE_E NSS_STATUE);
/******************************************************************************
 * @func :  GPIO_I2CSetPins
 *
 * Description:	the function is Set SPI Pins
 *
 * Parameters:
 * @par[in]  : 1- I2C_ID_PERIPHERAL_E: it's ID For I2C ID Number
 * 			 :
 *
 *
 ******************************************************/
void GPIO_SetI2CPins(I2C_ID_PERIPHERAL_E I2C_ID );






#endif /* GPIO_INTERFACE_H_ */
