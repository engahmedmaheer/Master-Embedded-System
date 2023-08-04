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


void CLCD_voidSendCommand(uint8 Copy_u8Command);
void CLCD_voidSendData(uint8 Copy_u8Data);
void CLCD_voidInit(void);
void CLCD_voidSendString(char Copy_u8DataString[]);
uint8 CLCD_voidSendNumebr(uint32 Copy_u8Number);
void CLCD_voidGoToXY(uint8 Copy_u8XPos,uint8 Copy_u8YPos);
void CLCD_voidSendSpecialCharacter(uint8 Copy_u8Pattern[],uint8 Copy_u8PatternNum,uint8 Copy_u8XPos,uint8 Copy_u8YPos);
void CLCD_voidDisplaySpecialCharacter(uint8 Copy_u8PatternNum,uint8 Copy_u8XPos,uint8 Copy_u8YPos);
void CLCD_voidStoreSpecialCharacter(uint8 Copy_u8Pattern[],uint8 Copy_u8PatternNum);
#endif
