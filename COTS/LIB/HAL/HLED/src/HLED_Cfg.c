/*
 * HLED_Cfg.c
 *
 * Created: 05/01/2025
 *  Author: Mariam Hossam
 */ 

#include "HLED_Cfg.h"

HLED_Cfg_t ledCfgArr[NUM_OF_LEDS]=
{
    [LED_ALERT] = {
        .LedPinNumber = MPORT_PINA_0,
        .LedConnection = HLED_FORWARD
    },
    [LED_STOP] = {
        .LedPinNumber = MPORT_PINB_0,
        .LedConnection = HLED_FORWARD
    },
    [LED_START] ={
        .LedPinNumber = MPORT_PINC_0,
        .LedConnection = HLED_REVERSE
    }
};