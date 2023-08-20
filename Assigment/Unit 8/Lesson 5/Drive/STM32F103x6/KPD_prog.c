////////////////////////////////////////////
/////////////////// Author : Ahmed Maher///
///////////////////Date 22/10/2021////////
///////////////////Layer : HAL //////////
/////////////////////////Version :1.00///
/******************************************/


#include  <stdlib.h>
#include  <stdio.h>
#include  <stdint.h>
#include  "GPIO_interface.h"
#include  "KPD_config.h"
#include  "KPD_private.h"

uint8_t KPD_voidGetPressedKey(void)
{
	//ACTIVE VAR
	uint8_t Local_u8RowIdx, Local_u8ColIdx, Local_u8PinState ,Local_u8PressedKey=KPD_u8_NO_PRESSED_KEY  ;

	// ACTIVE ARRAY
	static uint8_t Local_u8KPDArr[ROW_NUM][COL_NUM] = KPD_KEY_ARR;
	//ACTIVE ALL COL
	static uint8_t Local_u8_ColArr[COL_NUM]={KPD_u8_C0_PIN,KPD_u8_C1_PIN,KPD_u8_C2_PIN,KPD_u8_C3_PIN};
	static uint8_t Local_u8_RowArr[ROW_NUM]={KPD_u8_R0_PIN,KPD_u8_R1_PIN,KPD_u8_R2_PIN,KPD_u8_R3_PIN};

	///ACTIVE CO
	for(Local_u8ColIdx=0 ; Local_u8ColIdx<4 ; Local_u8ColIdx++)
	{
		GPIO_u8SetPinValue(KPD_u8_COL_PORT,Local_u8_ColArr[Local_u8ColIdx],GPIO_PINLOW);

		//READ THE ROUS
		for(Local_u8RowIdx=0 ; Local_u8RowIdx<ROW_NUM; Local_u8RowIdx++ )
		{
			GPIO_u8ReadPinValue(KPD_u8_ROW_PORT , Local_u8_RowArr[Local_u8RowIdx], &Local_u8PinState );

			if(GPIO_PINLOW == Local_u8PinState)
			{
				Local_u8PressedKey = Local_u8KPDArr[Local_u8RowIdx][Local_u8ColIdx];

				//WAITING UNTIL THEKEY IS REALSED
				while(GPIO_PINLOW == Local_u8PinState)
				{
					GPIO_u8ReadPinValue(KPD_u8_ROW_PORT , Local_u8_RowArr[Local_u8RowIdx], &Local_u8PinState );

				}
				return Local_u8PressedKey;
			}

		}
		//DEACTIVE THE CURRENT COLUM
		GPIO_u8SetPinValue(KPD_u8_COL_PORT, Local_u8_ColArr[Local_u8ColIdx],GPIO_PINHIGH);
	}
	return Local_u8PressedKey;

}






