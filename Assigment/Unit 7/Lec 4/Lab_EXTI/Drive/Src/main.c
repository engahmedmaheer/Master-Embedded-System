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
#include "ERR_TYPE.h"

#include "STM32F103x6.h"
#include "GPIO_Interface.h"
#include "STK_interface.h"
#include "CLCD_interface.h"
#include "NVIC_Interface.h"
#include "EXTI_Interface.h"
#include "AFIO_Interface.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#define PINS_NUM	8


void ClockEnable();
void GPIOInit();
void EXTIConfig();
void HandlerPA0();

int main(void)
{
	ClockEnable();
	GPIOInit();
	EXTIConfig();

	CLCD_voidInit();

	uint8_t VALUE = 0 ;
	CLCD_voidGoToXY(2,0);
	CLCD_voidSendCommand(COMMAND_CLEAR_DISPALY);
	CLCD_voidSendString("Thread Mode");



while (1);
}
void ClockEnable()
{
	RCC_GPIOA_CLCK_EN();

	RCC_GPIOB_CLCK_EN();

	AFIO_GPIOA_CLCK_EN();


}
void GPIOInit()
{
	GPIO_PinConfig_S PINS[PINS_NUM] =
	{
			{	/*BUTTON*/
					.PortNum=PORTA,
					.PinNumber=PIN0,
					.Mode=GPIO_INPUT_Floating,



			},

			{	/*PB1 Output PushPull*/
					.PortNum=PORTA,
					.PinNumber=PIN1,
					.Mode=GPIO_Output_PUSHPULL,
					.Speed=GPIO_LOWSPEED,


			},
			{	/*PB1 Output PushPull*/
					.PortNum=PORTA,
					.PinNumber=PIN2,
					.Mode=GPIO_Output_PUSHPULL,
					.Speed=GPIO_LOWSPEED,


			},
			{	/*PB1 Output PushPull*/
					.PortNum=PORTA,
					.PinNumber=PIN3,
					.Mode=GPIO_Output_PUSHPULL,
					.Speed=GPIO_LOWSPEED,


			},
			{	/*PB1 Output PushPull*/
					.PortNum=PORTA,
					.PinNumber=PIN4,
					.Mode=GPIO_Output_PUSHPULL,
					.Speed=GPIO_LOWSPEED,


			},
			{	/*PB1 Output PushPull*/
					.PortNum=PORTA,
					.PinNumber=PIN5,
					.Mode=GPIO_Output_PUSHPULL,
					.Speed=GPIO_LOWSPEED,


			},
			{	/*PB1 Output PushPull*/
					.PortNum=PORTA,
					.PinNumber=PIN6,
					.Mode=GPIO_Output_PUSHPULL,
					.Speed=GPIO_LOWSPEED,


			},
			{	/*PB1 Output PushPull*/
					.PortNum=PORTA,
					.PinNumber=PIN7,
					.Mode=GPIO_Output_PUSHPULL,
					.Speed=GPIO_LOWSPEED,


			},
			{
					.PortNum=PORTA,
					.PinNumber=PIN8,
					.Mode=GPIO_Output_PUSHPULL,
					.Speed=GPIO_LOWSPEED,


			},




	};

	for(int counter1 = 0 ; counter1 <PINS_NUM ; counter1++)
		GPIO_u8PinInit(&PINS[counter1]);


}
void EXTIConfig()
{
	NVICEnable(EXTI0_IRQ);

	AFIO_voidSelectEXTIPort(AFIO_LINE0, AFIO_PORTA);

	EXTI_CONFIG_S PA0 =
	{
			.EXTI_LINE_NUM=EXTI_IRQ0,
			.TriggerType=FAILING_EDGE,
			.EnableState=ENABLE
	};

	EXTI_Init(&PA0);
	EXTI_u8SetCallBack(EXTI_IRQ0, &HandlerPA0);


}
void HandlerPA0()
{
	CLCD_voidSendCommand(COMMAND_CLEAR_DISPALY);
	CLCD_voidSendString("Handler Mode");
	CLCD_voidGoToXY(1, 2);
}


