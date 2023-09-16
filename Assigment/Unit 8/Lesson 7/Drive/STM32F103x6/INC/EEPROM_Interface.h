/*
 * EEPROM_Interface.h
 *
 *  Created on: Sep 15, 2023
 *      Author: AhmedMaher
 */

#ifndef INC_EEPROM_INTERFACE_H_
#define INC_EEPROM_INTERFACE_H_

#define EEPROM_SLAVE_ADDRESS	0x2A



/**
 *
 */
void EEPROM_voidInit(void);
/**
 *
 * @param memory_address
 * @param byte
 * @param DataLenght
 * @return
 */
unsigned char EEPROM_Write_Byte(unsigned int memory_address , uint16_t* byte , uint8_t DataLenght);
/**
 *
 * @param address
 * @param DataOut
 * @param DataLenght
 * @return
 */
unsigned char EEPROM_Read_Byte(unsigned int address , uint16_t* DataOut , uint8_t DataLenght);




#endif /* INC_EEPROM_INTERFACE_H_ */
