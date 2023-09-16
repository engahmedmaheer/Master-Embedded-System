/*
 * MAX7221_Interface.h
 *
 *  Created on: Aug 21, 2023
 *      Author: AhmedMaher
 */

#ifndef INC_MAX7221_INTERFACE_H_
#define INC_MAX7221_INTERFACE_H_

#define MAX7221_D0							0x01
#define MAX7221_D1							0x02
#define MAX7221_D2							0x03
#define MAX7221_D3							0x04
#define MAX7221_D4							0x05
#define MAX7221_D5							0x06
#define MAX7221_D6							0x07
#define MAX7221_D7							0x08


#define MAX7221_A							0b1110111
#define MAX7221_H							0b0110110
#define MAX7221_M1							0b1000111
#define MAX7221_M2							0b1110001
#define MAX7221_E							0b1001111
#define MAX7221_D							0b1111110
#define MAX7221_R							0b1110111







#define MAX2721_DECODE_MODE					0x09
#define MAX2721_INTENSITY					0x0A
#define MAX2721_SCAN_LIMT					0x0B
#define MAX7221_SHUTDOWN					0x0C
#define MAX2721_DISPLAY_TEST				0x0F

#define MAX2721_INTENSITY_MAX				0x0F
#define MAX7221_DIGIT0_DIGIT7				0xff
#define MAX2721_DIGIT_DISPLAY_0_7			0x07	/*Scan Limit  Display digits 0 1 2 3 4 5 6 7 */
#define MAX2721_NORMAL_OPERATION			0x01


void MAX7211_VoidInit(void);

void MAX7211_SendData(uint8_t Command , uint8_t Data );





#endif /* INC_MAX7221_INTERFACE_H_ */
