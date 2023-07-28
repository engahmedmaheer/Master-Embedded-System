/*******************************************************************************/
/*******************************************************************************/
/***************************	Author : Ahmed Maher **************************/
/***************************	Date : 15/10/2021	****************************/
/***************************	Layer: HAL			****************************/
/***************************	Version : 1.00		****************************/
/*******************************************************************************/
/*******************************************************************************/
#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

/**
 * @brief
 *
 * @param Copy_u8Command
 */
void CLCD_voidSendCommand(uint8_t Copy_u8Command);
/**
 * @brief
 *
 * @param Copy_u8Data
 */
void CLCD_voidSendData(uint8_t Copy_u8Data);
/**
 * @brief
 *
 */
void CLCD_voidInit(void);
/**
 * @brief
 *
 * @param Copy_u8DataString
 */
void CLCD_voidSendString(char Copy_u8DataString[]);
uint8_t CLCD_voidSendNumebr(uint32_t Copy_u8Number);
void CLCD_voidGoToXY(uint8_t Copy_u8XPos,uint8_t Copy_u8YPos);
void CLCD_voidSendSpecialCharacter(uint8_t Copy_u8Pattern[],uint8_t Copy_u8PatternNum,uint8_t Copy_u8XPos,uint8_t Copy_u8YPos);
void CLCD_voidDisplaySpecialCharacter(uint8_t Copy_u8PatternNum,uint8_t Copy_u8XPos,uint8_t Copy_u8YPos);
void CLCD_voidStoreSpecialCharacter(uint8_t Copy_u8Pattern[],uint8_t Copy_u8PatternNum);



/*********************COMMAND****************/
#define COMMAND_DISPLAY_OFF_CURSOR_OFF		                     0x08	/*Clear Display without Clear DDRAM */
#define COMMAND_DISPLAY_ON_CURSOR_ON		                     0x0E
#define COMMAND_DISPLAY_ON_CURSOR_OFF		                     0x0C
#define COMMAND_DISPLAY_ON_CURSOR_BLINLING                       0x0F
#define COMMAND_SHIFT_ENIRE_DISPLAY_LEFT	                     0x18
#define COMMAND_SHIFT_ENIRE_DISPLAY_RIGHT                        0x1C
#define COMMAND_MOVE_CURSOR_LEFT			                     0x10
#define COMMAND_MOVE_CURSOR_RIGHT			                     0x18
#define COMMAND_CLEAR_DISPALY				                     0x01	/*Clear DDRAM*/

#define   COMMAND_C_beginning_LINE1 			               	0x80

#define   COMMAND_C_beginning_LINE2								 0xC0

#define   COMMAND_Use_two_lines_and_5x7_matrix 	             	0x38

#define  COMMAND_C_LINE1_POSITION_3       	  					 0x83
#define  COMMAND_ACTIVE_SCEONED_LINE      					     0x3C
//#define  COMMAND_JUMP_SECONED_LINE_POSITION_3    0xC3
#define  COMMAND_JUMP_SECONED_LINE_POSITION(POSITION)            0xC##POSITION




#endif
