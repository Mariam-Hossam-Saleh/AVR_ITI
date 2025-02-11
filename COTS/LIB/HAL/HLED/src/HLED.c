/*
 * HLED.c
 *
 * Created: 05/01/2025
 *  Author: Mariam Hossam
 */ 

#include "HLED.h"

extern HLED_Cfg_t ledCfgArr[NUM_OF_LEDS];

void HLED_init(void)
{
    for(u8 itration = 0 ; itration < NUM_OF_LEDS ; itration++)
    {
        MPORT_enuSetPinDirection(ledCfgArr[itration].LedPinNumber , MPORT_OUTPUT);
    }
}

HLED_enuErrorStatus_t HLED_enuSetLedState(u8 Copy_u8LedName, HLED_STATE_t Copy_u8State)
{
    MDIO_enuPortNum_t Loc_enuPortNum = GET_HIGH_NIB(ledCfgArr[Copy_u8LedName].LedPinNumber);
    MDIO_enuPinNum_t Loc_enuPinNum = GET_LOW_NIB(ledCfgArr[Copy_u8LedName].LedPinNumber);
	HLED_enuErrorStatus_t Loc_enuErrorStatus = HLED_NOK;
    
    if(Copy_u8LedName >= NUM_OF_LEDS)
    {
        Loc_enuErrorStatus = HLED_INVALID_LED_NAME;
    }
    else if(Copy_u8State > HLED_HIGH)
    {
        Loc_enuErrorStatus = HLED_INVALID_LED_STATE;
    }
    else
    {
        Loc_enuErrorStatus = HLED_OK;
        if(ledCfgArr[Copy_u8LedName].LedConnection == HLED_FORWARD)
        {
            MDIO_enuSetPinValue(Loc_enuPortNum, Loc_enuPinNum, Copy_u8State);
        }
        else if(ledCfgArr[Copy_u8LedName].LedConnection == HLED_REVERSE)
        {
            MDIO_enuSetPinValue(Loc_enuPortNum, Loc_enuPinNum, !Copy_u8State);
        }
        else
        {
            Loc_enuErrorStatus = HLED_INVALID_CONNECTION;
        }
    }
    return Loc_enuErrorStatus;
    
}