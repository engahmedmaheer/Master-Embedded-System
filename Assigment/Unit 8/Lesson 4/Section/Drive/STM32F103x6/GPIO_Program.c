/*******************************************************************/
/*******************************************************************/
/*****************   @Author:  AhmedMaher		********************/
/*****************   @Layer:   MCAL				********************/
/*****************   @SWC:     GPIO				********************/
/*****************	 @Version: 1.00				********************/
/*******************************************************************/
/*******************************************************************/
#include <stdint.h>
#include "ERR_TYPE.h"
#include "BIT_MATH.h"


#include "STM32F103x6.h"
#include "GPIO_Private.h"
#include "GPIO_Interface.h"



/*For peripheral Only :*/

static GPIO_TypeDef_S* GPIOPORT[GPIO_PERIPHERAL_NUM] ={GPIOA,GPIOB,GPIOC,GPIOD,GPIOE};

static uint8_t GET_CRLH_Position(GPIO_PIN_E PINNUM)
{
	uint8_t Position =0;

	switch(PINNUM)
	{
	case PIN0  :Position=0   ; break;
	case PIN1  :Position=4   ; break;
	case PIN2  :Position=8   ; break;
	case PIN3  :Position=12  ; break;
	case PIN4  :Position=16  ; break;
	case PIN5  :Position=20  ; break;
	case PIN6  :Position=24  ; break;
	case PIN7  :Position=28  ; break;
	case PIN8  :Position=0   ; break;
	case PIN9  :Position=4   ; break;
	case PIN10 :Position=8   ; break;
	case PIN11 :Position=12  ; break;
	case PIN12 :Position=16  ; break;
	case PIN13 :Position=20  ; break;
	case PIN14 :Position=24  ; break;
	case PIN15 :Position=28  ; break;
	case Allpins:	;break;
	default : ;break;
	}

	return Position;

}


/******************************************************************************
 * @Fun :  GPIO_u8PinInit
 *
 * Description:	 initialize the required pin configuration  options according parameters in pin config
 *
 * Parameters:
 * @par[in]  : 1- PinConfig: const pointer to GPIO_PinConfig_S structure which holds the configurations
 *
 * Return:	ErrorState , Type:uint8_t
 *
 ******************************************************************************/
uint8_t GPIO_u8PinInit(const GPIO_PinConfig_S* PinConfig)
{
	uint8_t LocalErrorStatue=OK ;
	//Port configuration register low (GPIOx_CRL) config pins 0 -> 7
	//Port configuration register high (GPIOx_CRH)  config pins 8 -> 15
	volatile uint32_t* configReg = NULL ;
	volatile uint8_t PIN = 0;
	configReg = (PinConfig->PinNumber < PIN8) ? &GPIOPORT[PinConfig->PortNum] ->CRL  : &GPIOPORT[PinConfig->PortNum] ->CRH  ;

	// clear CNF[1:0] & MODE[1:0]
	(*configReg) &= ~(0xF << GET_CRLH_Position(PinConfig->PinNumber));

	//if pin is OUTPUT
	if (PinConfig->Mode == GPIO_Output_PUSHPULL || PinConfig->Mode == GPIO_Output_OPENDRAIN || PinConfig->Mode == GPIO_AF_PP || PinConfig->Mode == GPIO_AF_OD)
	{
		//Set CNF[1:0] & MODE[1:0]
		PIN = (((PinConfig->Mode - 4) << 2) | (PinConfig->Speed)) & 0x0F ;

	}
	//if pin is INPUT
	else //MODE = 00 input mode (reset state)
	{
		if ( (PinConfig->Mode == GPIO_INPUT_Floating) | (PinConfig->Mode == GPIO_ANALOG))
		{
			PIN = (((PinConfig->Mode ) << 2) | (UNUSED)) & 0x0F ;
		}
		else if (PinConfig->Mode == GPIO_INPUT_Floating)//considered as INPUT Floating
		{
			PIN = (((GPIO_INPUT_Floating) << 2) | (UNUSED)) & 0x0F ;
		}
		else // PU PD INPUT
		{
			PIN = (((GPIO_INPUT_PU) << 2) | (UNUSED)) & 0x0F ;
			if (PinConfig->Mode == GPIO_INPUT_PU)
			{
				//ODR = 1 INPUT Pull Up :Table 20. Port bit configuration table
				GPIOPORT[PinConfig->PortNum] ->ODR  |= PinConfig->PinNumber;
			}else
			{
				//ODR = 0 INPUT Pull Down :Table 20. Port bit configuration table
				GPIOPORT[PinConfig->PortNum] ->ODR  &= ~(PinConfig->PinNumber);
			}
		}

	}

	//Write on CRL or CRH
	(*configReg) |= ( (PIN) << GET_CRLH_Position(PinConfig->PinNumber)) ;

	return LocalErrorStatue ;

}
/******************************************************************************
 * @Fun :  GPIO_u8PDeInit
 *
 * Description:	the function Reset the required pin configuration
 *
 * Parameters:
 * @par[in]  : 1- PinConfig: constant pointer to GPIO_TypeDef_S (GPIOA,GPIOB,...)
 *
 * Return:	ErrorState , Type:uint8_t
 *
 ******************************************************************************/
uint8_t GPIO_u8PDeInit(GPIO_PORT_E PORT)
{
	uint8_t LocalErrorStatue = OK;

	if (PORT < INVALIED_PORT )
	{
		RCC->APB2RSTR |= (1<<(PORT+2));
		RCC->APB2RSTR &=~(1<<(PORT+2));

	}
	else
	{
		LocalErrorStatue=NOK;
	}



	//		Other Way
	//		/*SELECT GPIO MODE GPIO_INPUT,GPIO_OUTPUT,GPIO_AF,GPIO_ANALOG*/
	//					if (PinConfig->PinNumber <= LOW_PINS)
	//					{
	//							/*Reset Register To Reset Value*/
	//						(GPIOPORT[PinConfig->Mode]) ->CRL.Reg=Reset_Val;
	//
	//					}
	//					else if (PinConfig->PinNumber <= HIGH_PINS)
	//					{
	//						(GPIOPORT[PinConfig->Mode]) ->CRH.Reg=Reset_Val;
	//					}
	//					(GPIOPORT[PinConfig->Mode]) ->BRR.Reg=Reset_Val0;
	//					(GPIOPORT[PinConfig->Mode]) ->BSRR.Reg=Reset_Val0;
	//					(GPIOPORT[PinConfig->Mode]) ->LCKR.Reg=Reset_Val0;
	//					(GPIOPORT[PinConfig->Mode]) ->ODR.Reg=Reset_Val0;
	//
	//				}
	//				else
	//				{
	//					LocalErrorStatue =NOK;
	//				}
	//			}
	//		else
	//		{
	//			LocalErrorStatue=NULL_POINTER;
	//		}

	return LocalErrorStatue;
}

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
uint8_t GPIO_u8SetPinValue(GPIO_PORT_E PORT ,   GPIO_PIN_E  PIN  , PinVal_E VAL )
{
	uint8_t LocalErrorStatue = OK ;

	switch (VAL)
	{
	/*SET & RESER VAL BY BSRR BIT SET REST REGISTERS  */
	case GPIO_PINHIGH :  GPIOPORT[PORT]->BSRR =(uint32_t)PIN;   						break ;
	case GPIO_PINLOW  :  GPIOPORT[PORT]->BRR   =(uint32_t)PIN;							break ;
	default :LocalErrorStatue = NOK ;													    break ;
	}





	return LocalErrorStatue ;
}

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
uint8_t GPIO_u8TogglePinValue(GPIO_PORT_E PORT ,   GPIO_PIN_E  PIN )
{
	uint8_t LocalErrorStatue=OK ;
	//		SET_BIT((GPIOPORT[PORT]->BRR.Reg),PIN);
	GPIOPORT[PORT]->ODR  ^=(PIN);


	return LocalErrorStatue ;

}
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
uint8_t GPIO_u8TogglePortValue(GPIO_PORT_E PORT )
{
	uint8_t LocalErrorStatue=OK ;
	if (PORT <= INVALIED_PORT  )
	{

		GPIOPORT[PORT]->BRR =0xffff;

	}
	else
	{
		LocalErrorStatue = NOK ;
	}
	return LocalErrorStatue ;
}
/******************************************************************************
 * @func :  GPIO_u8ReadPinValue
 *
 * Description:	the function is Read Pin Value
 *
 * Parameters:
 * @par[in]  : 1- PORT: it's Enum For Switch PORTS (PORTA,PORTB,....)
 * 			   2- PIN : it's Enum For Switch PINS  (PIN0,PIN1,......)
 * 			   3- VAL : Pointer To Variable hold value (HIGH, LOW)
 * Return:		Value ErrorState , Type:uint8_t
 *
 *
 ******************************************************/
uint8_t GPIO_u8ReadPinValue(GPIO_PORT_E PORT ,   GPIO_PIN_E  PIN  , PinVal_E* VAL )
{
	uint8_t LocalErrorStatue=OK ;
	if ( VAL != NULL)
	{


		*VAL = GET_BIT(GPIOPORT[PORT]->IDR ,PIN);


	}
	else
	{
		LocalErrorStatue = NULL_POINTER ;

	}

	return LocalErrorStatue ;
}
/******************************************************************************
 * @func :  GPIO_voidSetPortValue
 *
 * Description:	the function is SET PORT Value
 *
 * Parameters:
 * @par[in]  : 1- GPIO_PORT_E: it's Enum For Switch PORTS (PORTA,PORTB,....)
 * 			   2- GPIO_PIN_E : it's Enum For Switch PINS  (PIN0,PIN1,......)
 * Return:		Value ErrorState , Type:uint8_t
 *
 *
 ******************************************************/
uint8_t GPIO_voidSetPortValue(GPIO_PORT_E PORT, uint16_t Val)
{
	uint8_t LocalErrorStatue=OK ;

	if(PORT < INVALIED_PORT)
	{
		GPIOPORT[PORT]->ODR =(uint32_t)Val;
	}
	else
	{
		LocalErrorStatue = NOK;
	}
	return LocalErrorStatue;
}
/******************************************************************************
 * @func :  GPIO_u8ReadPortValue
 *
 * Description:	the function is Read PORT Value
 *
 * Parameters:
 * @par[in]  : 1- PORT: it's Enum For Switch PORTS (PORTA,PORTB,....)
 * 			   3- VAL : Pointer To Variable  value Should be uint16
 * Return:		Value ErrorState , Type:uint8_t
 *
 *
 ******************************************************/
uint8_t GPIO_u8ReadPortValue(GPIO_PORT_E PORT   , uint16_t* VAL )
{
	uint8_t LocalErrorStatue=OK ;
	if ( VAL != NULL)
	{
		if (PORT < INVALIED_PORT )
		{

			*VAL = (uint16_t)GPIOPORT[PORT]->IDR ;

		}
		else
		{
			LocalErrorStatue = NOK ;
		}
	}
	else
	{
		LocalErrorStatue = NULL_POINTER ;

	}

	return LocalErrorStatue ;
}
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
uint8_t GPIO_u8LockPin(GPIO_PORT_E PORT , GPIO_PIN_E PIN)
{

	uint8_t LocalErrorStatue = OK;

	/*Set LCK(16)*/
	volatile uint32_t temp = 1<<16;

	/*set LCKY*/
	temp |= PIN ;

	/*Sequance*/
	/*Write 1*/
	GPIOPORT[PORT]->LCKR =temp;
	/*Write 0*/
	CLR_BIT(GPIOPORT[PORT]->LCKR ,16);
	/*Write 1*/
	GPIOPORT[PORT]->LCKR =temp;
	/*Read 0*/
	temp=GPIOPORT[PORT]->LCKR ;
	/*Read 1*/

	return LocalErrorStatue= (((uint32_t)GPIOPORT[PORT]->LCKR )& 1<<16) ? OK: NOK;

}
/**
 *
 * @param Local_USARTID
 * @return
 */
uint8_t GPIO_USARTSetPins(GPIO_ID_PERIPHERAL_E Local_USARTID)
{
	uint8_t LocalErrorStatue = OK;

	switch(Local_USARTID)
	{
	case USART_ONE_ID :
		uint8_t counter1 ;
		GPIO_PinConfig_S GPIO_PIN1[2]=
		{


				//USART1
				{//PA9 TX
						.Mode=GPIO_AF_PP,
						.PinNumber=PIN9,
						.PortNum=PORTA,
						.Speed=GPIO_LOWSPEED
				},
				{//PA10 RX
						.Mode=GPIO_AF_INPUT,
						.PinNumber=PIN10,
						.PortNum=PORTA,

				}

		};

		for(counter1 = 0 ; counter1 < 2 ; counter1++)
		{
			GPIO_u8PinInit(&GPIO_PIN1[counter1]);
		}
		;break;



	case USART_TWO_ID :
		uint8_t counter2 ;
		GPIO_PinConfig_S GPIO_PIN2[2]=
		{


				//USART1
				{//PA9 TX
						.Mode=GPIO_AF_PP,
						.PinNumber=PIN2,
						.PortNum=PORTA,
						.Speed=GPIO_LOWSPEED
				},
				{//PA10 RX
						.Mode=GPIO_AF_INPUT,
						.PinNumber=PIN3,
						.PortNum=PORTA,

				}

		};

		for(counter2 = 0 ; counter2 < 2 ; counter2++)
		{
			GPIO_u8PinInit(&GPIO_PIN2[counter2]);
		}
		;break;

	case USART_THREE_ID :
		uint8_t counter3 ;
		GPIO_PinConfig_S GPIO_PIN3[2]=
		{


				//USART1
				{//PA9 TX
						.Mode=GPIO_AF_PP,
						.PinNumber=PIN10,
						.PortNum=PORTB,
						.Speed=GPIO_LOWSPEED
				},
				{//PA10 RX
						.Mode=GPIO_AF_INPUT,
						.PinNumber=PIN11,
						.PortNum=PORTB,

				}

		};

		for(counter3 = 0 ; counter3 < 2 ; counter3++)
		{
			GPIO_u8PinInit(&GPIO_PIN3[counter3]);
		}
		;break;



	default: //error ;
		break;
	}

	return LocalErrorStatue;

}
/******************************************************************************
 * @func :  GPIO_SPISetPins
 *
 * Description:	the function is Set SPI Pins
 *
 * Parameters:
 * @par[in]  : 1- GPIO_ID_PERIPHERAL_E: it's ID For USART ID Number
 * Return:		Value ErrorState , Type:uint8_t
 *
 *
 ******************************************************/
uint8_t GPIO_SPISetPins(GPIO_ID_PERIPHERAL_E LocalSPIID , MASTER_SLAVE_STATUE_E MS_Statue_ID , NSS_STATUE_E NSS_STATUE)
{
	uint8_t LocalErrorStatue = OK;

	switch(LocalSPIID)
	{
	case SPI_ONE_ID:
		/*
		 * NSS-> PA4
		 * SCK-> PA5
		 * MISO->PA6
		 * MOSI->PA7
		 */
		if(MS_Statue_ID == SPI_MASTER_ID)
		{
			//NSS-> PA4
			if(NSS_STATUE == SPI_NSS_HW_MASTER_SS_OP_DISABLE)
			{	/*Have other Master*/

				GPIO_PinConfig_S SPI1_NSS_PIN=
				{
						/*INPUT FLOATING*/
						.Mode=GPIO_INPUT_Floating,
						.PortNum=PORTA,
						.PinNumber=PIN4,
				};
				GPIO_u8PinInit(&SPI1_NSS_PIN);
			}
			else //SPI_NSS_HW_MASTER_SS_OP_ENABLE
			{
				GPIO_PinConfig_S SPI1_NSS_PIN=
				{
						/*INPUT FLOATING*/
						.Mode=GPIO_AF_PP,
						.PortNum=PORTA,
						.PinNumber=PIN4,
						.Speed=GPIO_LOWSPEED,
				};
				GPIO_u8PinInit(&SPI1_NSS_PIN);

			}

			/*********PA5 SCK*************/

			GPIO_PinConfig_S SPI1_SCK_PIN=
			{
					/*AF PP*/
					.Mode=GPIO_AF_PP,
					.PortNum=PORTA,
					.PinNumber=PIN5,
					.Speed=GPIO_LOWSPEED,
			};
			GPIO_u8PinInit(&SPI1_SCK_PIN);


			/******PA6 MISO*************/
			GPIO_PinConfig_S SPI1_MISO_PIN=
			{
					/*INPUT FLOATING*/
					.Mode=GPIO_INPUT_Floating,
					.PortNum=PORTA,
					.PinNumber=PIN6,
			};
			GPIO_u8PinInit(&SPI1_MISO_PIN);


			/*******PA7 MOSI**************/
			GPIO_PinConfig_S SPI1_MOSI_PIN=
			{
					/*AF PP*/
					.Mode=GPIO_AF_PP,
					.PortNum=PORTA,
					.PinNumber=PIN7,
					.Speed=GPIO_LOWSPEED,
			};
			GPIO_u8PinInit(&SPI1_MOSI_PIN);
		}
		else
		{

			//NSS-> PA4
			if(NSS_STATUE == SPI_NSS_HW_MASTER_SS_OP_DISABLE)
			{
				/*Have other Master*/

				GPIO_PinConfig_S SPI1_NSS_PIN=
				{
						/*INPUT FLOATING*/
						.Mode=GPIO_INPUT_Floating,
						.PortNum=PORTA,
						.PinNumber=PIN4,
				};
				GPIO_u8PinInit(&SPI1_NSS_PIN);
			}
			else //SPI_NSS_HW_MASTER_SS_OP_ENABLE
			{
				GPIO_PinConfig_S SPI1_NSS_PIN=
				{
						/*INPUT FLOATING*/
						.Mode=GPIO_AF_PP,
						.PortNum=PORTA,
						.PinNumber=PIN4,
						.Speed=GPIO_LOWSPEED,
				};
				GPIO_u8PinInit(&SPI1_NSS_PIN);

			}

			/*********PA5 SCK*************/

			GPIO_PinConfig_S SPI1_SCK_PIN=
			{
					/*AF PP*/
					.Mode=GPIO_INPUT_Floating,
					.PortNum=PORTA,
					.PinNumber=PIN5,

			};
			GPIO_u8PinInit(&SPI1_SCK_PIN);


			/******PA6 MISO*************/
			GPIO_PinConfig_S SPI1_MISO_PIN=
			{
					/*INPUT FLOATING*/
					.Mode=GPIO_AF_PP,
					.PortNum=PORTA,
					.Speed=GPIO_LOWSPEED,
					.PinNumber=PIN6,
			};
			GPIO_u8PinInit(&SPI1_MISO_PIN);


			/*******PA7 MOSI**************/
			GPIO_PinConfig_S SPI1_MOSI_PIN=
			{
					/*AF PP*/
					.Mode=GPIO_INPUT_Floating,
					.PortNum=PORTA,
					.PinNumber=PIN7,

			};
			GPIO_u8PinInit(&SPI1_MOSI_PIN);

		}


	case SPI_TWO_ID:


		/**
		 * NSS-> PB12
		 * SCK-> PB13
		 * MISO-> PB14
		 * MOSI-> PB15
		 */

		if(MS_Statue_ID == SPI_MASTER_ID)
			{
				//NSS-> PA4
				if(NSS_STATUE == SPI_NSS_HW_MASTER_SS_OP_DISABLE)
				{	/*Have other Master*/

					GPIO_PinConfig_S SPI1_NSS_PIN=
					{
							/*INPUT FLOATING*/
							.Mode=GPIO_INPUT_Floating,
							.PortNum=PORTB,
							.PinNumber=PIN12,
					};
					GPIO_u8PinInit(&SPI1_NSS_PIN);
				}
				else //SPI_NSS_HW_MASTER_SS_OP_ENABLE
				{
					GPIO_PinConfig_S SPI1_NSS_PIN=
					{
							/*INPUT FLOATING*/
							.Mode=GPIO_AF_PP,
							.PortNum=PORTB,
							.PinNumber=PIN12,
							.Speed=GPIO_LOWSPEED,
					};
					GPIO_u8PinInit(&SPI1_NSS_PIN);

				}

				/*********PA5 SCK*************/

				GPIO_PinConfig_S SPI1_SCK_PIN=
				{
						/*AF PP*/
						.Mode=GPIO_AF_PP,
						.PortNum=PORTB,
						.PinNumber=PIN13,
						.Speed=GPIO_LOWSPEED,
				};
				GPIO_u8PinInit(&SPI1_SCK_PIN);


				/******PA6 MISO*************/
				GPIO_PinConfig_S SPI1_MISO_PIN=
				{
						/*INPUT FLOATING*/
						.Mode=GPIO_INPUT_Floating,
						.PortNum=PORTB,
						.PinNumber=PIN14,
				};
				GPIO_u8PinInit(&SPI1_MISO_PIN);


				/*******PA7 MOSI**************/
				GPIO_PinConfig_S SPI1_MOSI_PIN=
				{
						/*AF PP*/
						.Mode=GPIO_AF_PP,
						.PortNum=PORTB,
						.PinNumber=PIN15,
						.Speed=GPIO_LOWSPEED,
				};
				GPIO_u8PinInit(&SPI1_MOSI_PIN);
			}
			else
			{

				//NSS-> PA4
				if(NSS_STATUE == SPI_NSS_HW_MASTER_SS_OP_DISABLE)
				{
					/*Have other Master*/

					GPIO_PinConfig_S SPI1_NSS_PIN=
					{
							/*INPUT FLOATING*/
							.Mode=GPIO_INPUT_Floating,
							.PortNum=PORTB,
							.PinNumber=PIN12,
					};
					GPIO_u8PinInit(&SPI1_NSS_PIN);
				}
				else //SPI_NSS_HW_MASTER_SS_OP_ENABLE
				{
					GPIO_PinConfig_S SPI1_NSS_PIN=
					{
							/*INPUT FLOATING*/
							.Mode=GPIO_AF_PP,
							.PortNum=PORTB,
							.PinNumber=PIN12,
							.Speed=GPIO_LOWSPEED,
					};
					GPIO_u8PinInit(&SPI1_NSS_PIN);

				}

				/*********PA5 SCK*************/

				GPIO_PinConfig_S SPI1_SCK_PIN=
				{
						/*AF PP*/
						.Mode=GPIO_INPUT_Floating,
						.PortNum=PORTB,
						.PinNumber=PIN13,

				};
				GPIO_u8PinInit(&SPI1_SCK_PIN);


				/******PA6 MISO*************/
				GPIO_PinConfig_S SPI1_MISO_PIN=
				{
						/*INPUT FLOATING*/
						.Mode=GPIO_AF_PP,
						.PortNum=PORTB,
						.Speed=GPIO_LOWSPEED,
						.PinNumber=PIN14,
				};
				GPIO_u8PinInit(&SPI1_MISO_PIN);


				/*******PA7 MOSI**************/
				GPIO_PinConfig_S SPI1_MOSI_PIN=
				{
						/*AF PP*/
						.Mode=GPIO_INPUT_Floating,
						.PortNum=PORTB,
						.PinNumber=PIN15,

				};
				GPIO_u8PinInit(&SPI1_MOSI_PIN);

			}

	default:
		//error
		break;
	}




	return LocalErrorStatue;
}


