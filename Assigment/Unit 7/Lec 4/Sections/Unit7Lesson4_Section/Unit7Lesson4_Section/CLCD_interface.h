#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

void CLCD_voidSendCommand(uint8 Copy_u8Command);
void CLCD_voidSendData(uint8 Copy_u8Data);
void CLCD_voidSendString(const char* str);
void CLCD_voidSendNumber(sint16 Copy_s8number);
void CLCD_voidGoToXY(uint8 Copy_u8XPos, uint8 Copy_u8YPos);
void CLCD_voidInit(void);
uint8 CLCD_u8SendSpecialCharacter( uint8* Copy_u8Pattern , uint8 Copy_u8PatternNum, uint8 Copy_u8XPos, uint8 Copy_u8YPos);
///////////////////////////////////////////////
uint8 CLCD_SendString(const char* Copy_u8str );
#endif
