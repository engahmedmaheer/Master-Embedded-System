#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_

#define CLCD_u8_DATA_PORT	PORTA
#define CLCD_u8_CTRL_PORT	PORTA
#define CLCD_u8_RS_PIN		PIN1
#define CLCD_u8_RW_PIN		PIN2
#define CLCD_u8_E_PIN		PIN3
      //SELECT THE MODE
//   1) 4BITS
//   2) 8 BITS
#define CLCD_u8_MODE        FOUR_BIT

#if CLCD_u8_MODE == FOUR_BIT

#define CLCD_u8_PIN4     PIN4
#define CLCD_u8_PIN5     PIN5
#define CLCD_u8_PIN6     PIN6
#define CLCD_u8_PIN7     PIN7

#endif
#endif
