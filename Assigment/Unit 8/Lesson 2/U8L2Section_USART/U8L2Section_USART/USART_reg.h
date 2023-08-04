/*******************************************************************************/
/*******************************************************************************/
/***************************	Author : Ahmed Maher **************************/
/***************************	Date : 27/11/2021	****************************/
/***************************	Layer: MCAL			****************************/
/***************************	Version : 1.00		****************************/
/*******************************************************************************/
/*******************************************************************************/


#ifndef USART_REG_H_
#define USART_REG_H_

/* USART Baud Rate  */
#define UBRRL   (*(volatile unsigned char*)0x29)
/* USART Control and Status Register B */
#define UCSRB   (*(volatile unsigned char*)0x2A)
#define RXCIE        7
#define TXCIE        6
#define UDRIE        5
#define RXEN         4
#define TXEN         3
#define UCSZ         2
#define UCSZ2        2
#define RXB8         1
#define TXB8         0
/*******************************************/
/* USART Control and Status Register A */
#define UCSRA   (*(volatile unsigned char*)0x2B)
#define RXC          7
#define TXC          6
#define UDRE         5
#define FE           4
#define DOR          3
#define UPE          2
#define U2X          1
#define MPCM         0
/*********************************************/
#define UDR     (*(volatile unsigned char*)0x2C)
/* USART Baud Rate Register High */
#define UBRRH   (*(volatile unsigned char*)0x40)
/* USART Control and Status Register C */
#define UCSRC   (*(volatile unsigned char*)0x40)
#define URSEL        7
#define UMSEL        6
#define UPM1         5
#define UPM0         4
#define USBS         3
#define UCSZ1        2
#define UCSZ0        1
#define UCPOL        0

#endif
