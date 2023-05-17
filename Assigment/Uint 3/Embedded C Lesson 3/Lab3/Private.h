#ifndef PRIVATE_H_
#define PRIVATE_H_


typedef volatile unsigned int vint32_t;


#define RCC_BASE_ADDRESS		0x40021000
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