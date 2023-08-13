/*******************************************************************/
/*******************************************************************/
/*****************   @Author:  AhmedMaher       ********************/
/*****************   @Prohect:   Pressure Control Sensor***********/             
/*****************   @SWC:                       ********************/
/*****************   @Version: 1.00             ********************/
/*******************************************************************/
/*******************************************************************/

#include "main_Algorithm.h"
static int Main_Algorithm_Pressure_Value = 0;
static int Main_Algorithm_Pressure_Threshold = 20;
void (*Main_Algorithm_state)();

void Set_Pressure_Value(int Pressure_Val)
{
    Main_Algorithm_Pressure_Value = Pressure_Val;
    Main_Algorithm_state = STATE_calling(Main_Algorithm_High_Pressure_Detect);
}

// declare state function
STATE_Define(Main_Algorithm_High_Pressure_Detect)
{
    // state_name
    Main_Algorithm_state_id = Main_Algorithm_High_Pressure_Detect;


    if (Main_Algorithm_Pressure_Value <= Main_Algorithm_Pressure_Threshold)
    {
        Main_Algorithm_state = STATE_calling(Main_Algorithm_High_Pressure_Detect);
    }
    else
    {
        High_Pressure_Detected();
        Main_Algorithm_state = STATE_calling(Main_Algorithm_High_Pressure_Detect);
    }
}
