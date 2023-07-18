/*******************************************************************/
/*******************************************************************/
/*****************   @Author:  AhmedMaher		********************/
/*****************   @Layer:   MCAL				********************/
/*****************   @SWC:     GPIO				********************/
/*****************	 @Version: 1.00				********************/
/*******************************************************************/
/*******************************************************************/
#ifndef INC_STM32F103X6_H_
#define INC_STM32F103X6_H_

/**
 * @brief : INCLUDES
 *
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief :Base addresses for Memories
 *
 */
#define FLASH_MEMORY_BASE_ADDRESS		0x08000000UL

#define SYSTEM_MEMORY_BASE_ADDRESS		0x1FFFF000UL

#define SRAM_MEMORY_BASE_ADDRESS		0x20000000UL


#define PERIPHERAL_MEMORY_BASE_ADDRESS	0x40000000UL

#define CORTEXM3_MEMORY_BASE_ADDRESS	0xE0000000UL


/**
 * @brief :Base addresses for APB2 Peripheral : CortexM3 LQFP48
 */
/**************************GPIOA-->GPIOD*********************************/
#define GPIOA_BASE_ADDRESS					   		 0x40010800UL
#define GPIOB_BASE_ADDRESS							 0x40010C00UL
#define GPIOC_BASE_ADDRESS							 0x40011000UL
#define GPIOD_BASE_ADDRESS							 0x40011400UL
#define GPIOE_BASE_ADDRESS							 0x40011800UL
/**************************AFIO*****************************************/

#define AFIO_BASE_ADDRESS							 0x40010000UL

/**************************EXTI*****************************************/
#define EXTI_BASE_ADDRESS							 0x40010400UL

/**
 * @brief :Base addresses for AHB Peripheral : CortexM3 LQFP48
 */
/**************************RCC*****************************************/
#define RCC_BASE_ADDRESS 							 0x40021000UL



/*==================================================================*/

/**
 * brief:Peripheral register
 */
/**************GPIO************************/
typedef struct
{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;

}GPIO_TypeDef_S;


/**************RCC************************/
typedef struct {

	union
	{
		volatile	uint32_t Reg ;
		struct
		{
		uint8_t HSION :1;
		uint8_t HSIRDY :1;
		uint8_t Reserved0 :1;
		uint8_t HSITRIM :5;
		uint8_t HSICAL :8;
		uint8_t HSEON :1;
		uint8_t HSERDY :1;
		uint8_t HSEBYP :1;
		uint8_t CSSON :1;
		uint8_t Reserved1 :4;
		uint8_t PLL_ON :1 ;
		uint8_t PLL_RDY:1;
		uint8_t Reserved2 :6;

		}BIT;
	}CR;
	union {
		volatile	uint32_t Reg ;
		struct{
			uint8_t SW      : 2 ;
			uint8_t SWS     : 2 ;
			uint8_t HPRE    : 4 ;
			uint8_t PPRE1   : 3 ;
			uint8_t PPRE2   : 3 ;
			uint8_t ADCPRE  : 2 ;
			uint8_t PLLSRC  : 1 ;
			uint8_t PLLXTPRE: 1 ;
			uint8_t PLLMUL  : 4 ;
			uint8_t USBPRE: 1 ;
			uint8_t Reseved3: 1 ;
			uint8_t MCO     : 4 ;
		}Bit;

	}CFGR;

	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR ;
	volatile uint32_t APB1RSTR;

	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;

}RCC_TypeDef_S;

/**************AFIO************************/
typedef struct
{
	union
	{
		volatile uint32_t Reg;
		struct
		{
			uint32_t PIN :3 ;
			uint32_t PORT: 3;
			uint32_t EVOE:1 ;
			uint32_t Reserved0: 25;

		}BIT;
	}EVCR;
	union
	{
		volatile uint32_t Reg;
		struct
		{
			//BIT FIELD REG

		}BIT;
	}MAPR;
	union
	{
		volatile uint32_t Reg;
		struct
		{
			//BIT FIELD REG

		}BIT;
	}EXTICR1;
	union
	{
		volatile uint32_t Reg;
		struct
		{
			//BIT FIELD REG
		}BIT;
	}EXTICR2;
	union
	{
		volatile uint32_t Reg;
		struct
		{
			//BIT FIELD REG

		}BIT;
	}EXTICR3;
	union
	{
		volatile uint32_t Reg;
		struct
		{
			//BIT FIELD REG

		}BIT;
	}EXTICR4;
	union
	{
		volatile uint32_t Reg;
		struct
		{
			//BIT FIELD REG

		}BIT;
	}RESERVED0_REG;
	union
	{
		volatile uint32_t Reg;
		struct
		{
			//BIT FIELD REG

		}BIT;
	}MAPR2;

}AFIO_TypeDef_S;



/**************EXTI************************/

typedef struct
{
	volatile uint32_t	IMR;
	volatile uint32_t	EMR;
	volatile uint32_t	RSTR;
	volatile uint32_t	FTSR;
	volatile uint32_t	SWIER;
	volatile uint32_t	PR;

}EXTI_TypeDef_S;




//===============================================================//

/**
 * brief:Peripheral Instants
 */
/*********************GPIO****************************************/

#define GPIOA 				((GPIO_TypeDef_S*) GPIOA_BASE_ADDRESS)
#define GPIOB 				((GPIO_TypeDef_S*) GPIOB_BASE_ADDRESS)
#define GPIOC 				((GPIO_TypeDef_S*) GPIOC_BASE_ADDRESS)
#define GPIOD 				((GPIO_TypeDef_S*) GPIOD_BASE_ADDRESS)
#define GPIOE 				((GPIO_TypeDef_S*) GPIOE_BASE_ADDRESS)

/*********************RCC****************************************/

#define RCC ((RCC_TypeDef_S*)RCC_BASE_ADDRESS)



/*********************EXTI****************************************/

#define EXTI ((EXTI_TypeDef_S*)EXTI_BASE_ADDRESS)



/*********************AFIO****************************************/

#define AFIO ((AFIO_TypeDef_S*)AFIO_BASE_ADDRESS)




//clock enable Macros:
#define RCC_GPIOA_CLCK_EN()		(RCC->APB2ENR |=1<<2)
#define RCC_GPIOB_CLCK_EN()		(RCC->APB2ENR |=1<<3)
#define RCC_GPIOC_CLCK_EN()		(RCC->APB2ENR |=1<<4)
#define RCC_GPIOD_CLCK_EN()		(RCC->APB2ENR |=1<<5)
#define RCC_GPIOE_CLCK_EN()		(RCC->APB2ENR |=1<<6)

#define AFIO_GPIOA_CLCK_EN()		(RCC->APB2ENR|=1<<0)


//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*



#endif /* INC_STM32F103X6_H_ */
