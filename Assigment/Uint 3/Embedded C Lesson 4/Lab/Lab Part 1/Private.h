#ifndef PRIVATE_H_
#define PRIVATE_H_


typedef volatile unsigned int vint32_t;


#define SYSCTL_RCGC2_R			(*((volatile unsigned long *)0x400FE108))
#define GPIO_PORTF_DIR_R		(*((volatile unsigned long *)0x40025400))
#define GPIO_PORTF_DEN_R		(*((volatile unsigned long *)0x4002551C))
#define GPIO_PORTF_DATA_R		(*((volatile unsigned long *)0x400253FC))


#define GPIOA_BASE_ADDRESS		0x40010800

#define RCC_APB2ENR				*((volatile uint32_t*)RCC_BASE_ADDRESS+0x18)
#define GPIOA_CRH				*((volatile uint32_t*)GPIOA_BASE_ADDRESS+0x04)
#define GPIOA_ODR				*((volatile uint32_t*)GPIOA_BASE_ADDRESS+0x0C)

/*BIT FIELD*/

#define GPIOA_IOPAEN			(1<<2)
#define GPIOA13					(1UL<<13)

typedef union
{
	vint32_t allfield ;
	struct 
	{

		vint32_t Reseved : 13 ; 
		vint32_t P_13		:1;
	}pin;
		
}R_ODR_t;

volatile R_ODR_t* R_ODR = (volatile R_ODR_t*)(GPIOA_BASE_ADDRESS + 0X0C);




#define GPIOA


#endif