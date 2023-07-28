/*******************************************************************/
/*******************************************************************/
/*****************   @Author:  AhmedMaher		********************/
/*****************   @Layer:   MCAL				********************/
/*****************   @SWC:     NVIC				********************/
/*****************	 @Version: 1.00				********************/
/*******************************************************************/
/*******************************************************************/


#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

/**
 * @brief : IRQ NUM  Vector Table
 */
typedef enum
{   WWDG          ,/**< WWDG */
	PVD           ,   /**< PVD */
	TAMP_STAMP    ,   /**< TAMP_STAMP */
	RTC_WKUP      ,   /**< RTC_WKUP */
	FLASH         ,   /**< FLASH */
	RCC_IRQ       ,   /**< RCC_IRQ */
	EXTI0_IRQ     ,   /**< EXTI0_IRQ */
	EXTI1_IRQ     ,   /**< EXTI1_IRQ */
	EXTI2_IRQ     ,   /**< EXTI2_IRQ */
	EXTI3_IRQ     ,   /**< EXTI3_IRQ */
	EXTI4_IRQ     ,   /**< EXTI4_IRQ */
	DMA1_Stream0  ,   /**< DMA1_Stream0 */
	DMA1_Stream1  ,   /**< DMA1_Stream1 */
	DMA1_Stream2  ,   /**< DMA1_Stream2 */
	DMA1_Stream3  ,   /**< DMA1_Stream3 */
	DMA1_Stream4  ,   /**< DMA1_Stream4 */
	DMA1_Stream5  ,   /**< DMA1_Stream5 */
	DMA1_Stream6  ,   /**< DMA1_Stream6 */
	ADC           ,   /**< ADC */
	CAN1_TX       ,   /**< CAN1_TX */
	CAN1_RX0      ,   /**< CAN1_RX0 */
	CAN1_RX1      ,   /**< CAN1_RX1 */
	CAN1_SCE      ,   /**< CAN1_SCE */
	EXTI9_5       ,   /**< EXTI9_5 */
	TIM1_BRK_TIM9    ,/**< TIM1_BRK_TIM9 */
	TIM1_UP_TIM10    ,/**< TIM1_UP_TIM10 */
	TIM1_TRG_COM_TIM1,/**< TIM1_TRG_COM_TIM1 */
	TIM1_CC          ,/**< TIM1_CC */
	TIM2             ,/**< TIM2 */
	TIM3             ,/**< TIM3 */
	TIM4             ,/**< TIM4 */
	I2C1_EV          ,/**< I2C1_EV */
	I2C1_ER          ,/**< I2C1_ER */
	I2C2_EV          ,/**< I2C2_EV */
	I2C2_ER          ,/**< I2C2_ER */
	SPI1             ,/**< SPI1 */
	SPI2             ,/**< SPI2 */
	USART1           ,/**< USART1 */
	USART2           ,/**< USART2 */
	USART3           ,/**< USART3 */
	EXTI15_10        ,/**< EXTI15_10 */
	RTC_Alarm        ,/**< RTC_Alarm */
	OTG_FS_WKUP      ,/**< OTG_FS_WKUP */
	TIM8_BRK_TIM12   ,/**< TIM8_BRK_TIM12 */
	TIM8_UP_TIM13    ,/**< TIM8_UP_TIM13 */
	TIM8_TRG_COM_TIM1,/**< TIM8_TRG_COM_TIM1 */
	TIM8_CC          ,/**< TIM8_CC */
	DMA1_Stream7     ,/**< DMA1_Stream7 */
	FMC              ,/**< FMC */
	SDIO             ,/**< SDIO */
	TIM5             ,/**< TIM5 */
	SPI3             ,/**< SPI3 */
	UART4            ,/**< UART4 */
	TIM6_DAC      ,   /**< TIM6_DAC */
	TIM7          ,   /**< TIM7 */
	DMA2_Stream0  ,   /**< DMA2_Stream0 */
	DMA2_Stream1  ,   /**< DMA2_Stream1 */
	DMA2_Stream2  ,   /**< DMA2_Stream2 */
	DMA2_Stream3  ,   /**< DMA2_Stream3 */
	DMA2_Stream4  ,   /**< DMA2_Stream4 */
	Reseved_IRQ0   ,  /**< Reseved_IRQ0 */
	Reseved_IRQ1  ,   /**< Reseved_IRQ1 */
	CAN2_TX       ,   /**< CAN2_TX */
	CAN2_RX0      ,   /**< CAN2_RX0 */
	CAN2_RX1      ,   /**< CAN2_RX1 */
	CAN2_SCE      ,   /**< CAN2_SCE */
	OTG_FS        ,   /**< OTG_FS */
	DMA2_Stream5  ,   /**< DMA2_Stream5 */
	DMA2_Stream6  ,   /**< DMA2_Stream6 */
	DMA2_Stream7  ,   /**< DMA2_Stream7 */
	USART6        ,   /**< USART6 */
	I2C3_EV       ,   /**< I2C3_EV */
	I2C3_ER       ,   /**< I2C3_ER */
	OTG_HS_EP1_OUT,   /**< OTG_HS_EP1_OUT */
	OTG_HS_EP1_IN ,   /**< OTG_HS_EP1_IN */
	OTG_HS_WKUP   ,   /**< OTG_HS_WKUP */
	OTG_HS        ,   /**< OTG_HS */
	DCMI          ,   /**< DCMI */
	Reseved_IRQ2  ,   /**< Reseved_IRQ2 */
	Reseved_IRQ3  ,   /**< Reseved_IRQ3 */
	FPU           ,   /**< FPU */
	Reseved_IRQ4   ,   /**< Reseved_IRQ4 */
	Reseved_IRQ5   ,  /**< Reseved_IRQ5 */
	SPI4,              /**< SPI4 */
	Reseved_IRQ6,     /**< Reseved_IRQ6 */
	Reseved_IRQ7,     /**< Reseved_IRQ7 */
	SAI1,             /**< SAI1 */
	Reseved_IRQ8,     /**< Reseved_IRQ8 */
	Reseved_IRQ9,      /**< Reseved_IRQ9 */
	Reseved_IRQ10,     /**< Reseved_IRQ10 */
	SAI2,              /**< SAI2 */
	QuadSPI,           /**< QuadSPI */
	HDMI_CEC,          /**< HDMI_CEC */
	SPDIF_Rx,          /**< SPDIF_Rx */
	FMPI2C1,           /**< FMPI2C1 */
	FMPI2C1_error      /**< FMPI2C1_error */
}IRQNUM_E;




/**
 * @brief  : Function used For Enable IRQ Peripheral
 * @post
 * @param  : IQR Number
 * @return : LocalErrorStatus
 */
uint8_t NVICEnable (IRQNUM_E IRQ );
/**
 * @brief  : Function used For Disable IRQ Peripheral
 * @post
 * @param  : IRQ Number
 * @return : LocalErrorStatus
 */
uint8_t NVICDisable (IRQNUM_E IRQ );
/**
 * @brief  : Function used For Set Pending Flag For Peripheral
 * @post
 * @param  : IRQ Number
 * @return : LocalErrorStatus
 */
uint8_t NVIC_SetPendingFlag(IRQNUM_E IRQ);
/**
 * @brief  : Function used For Clear Pending Flag For Peripheral
 * @post
 * @param  : IRQ Number
 * @return : LocalErrorStatus
 */
uint8_t NVIC_ClearPendingFlag(IRQNUM_E IRQ);
/**
 * @brief  : Function used For Get Status Pending Flag For Peripheral
 * @post
 * @param  : IQR Number
 * @param  : Pointer to Active Flag Value
 * @return : LocalErrorStatus | Value Of Flag
 */
uint8_t NVIC_GetActiveFlag(IRQNUM_E IRQ , uint8_t* ActiveVal);

/**
 * @brief  : Function To Set Priority For IRQ I
 * @param  :   IQR Number , Priority Number
 * @post   :
 * @return : LocalErrorStatus
 */
uint8_t NVIC_U8SetIRQPriorty(IRQNUM_E IRQ , uint8_t CopyU8_Priorty);



#endif
