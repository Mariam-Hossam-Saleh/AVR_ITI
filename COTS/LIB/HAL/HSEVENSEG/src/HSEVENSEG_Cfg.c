/*
 * HSEVENSEG_Cfg.c
 *
 * Created: 06/01/2025
 *  Author: Mariam Hossam
 */ 

#include "HSEVENSEG_Cfg.h"

#include "HSEVENSEG.h"

HSEVENSEG_strCfg_t sevenSegCfgArr[NUMBER_OF_SEVENSEG]=
{
    [SEVENSEG_ONE] = {
        .HSEVENSEG_strPinNumArr={
            [HSEVENSEG_PIN_A]  = MPORT_PINA_0,
            [HSEVENSEG_PIN_B]  = MPORT_PINA_1,
            [HSEVENSEG_PIN_C]  = MPORT_PINA_2,
            [HSEVENSEG_PIN_D]  = MPORT_PINA_3,
            [HSEVENSEG_PIN_E]  = MPORT_PINA_4,
            [HSEVENSEG_PIN_F]  = MPORT_PINA_5,
            [HSEVENSEG_PIN_G]  = MPORT_PINA_6,
            [HSEVENSEG_PIN_DP] = MPORT_PINA_7
        },
        .HSEVENSEG_Connection = HSEVENSEG_COMMON_ANODE
    },
    [SEVENSEG_TWO] = {
        .HSEVENSEG_strPinNumArr={
            [HSEVENSEG_PIN_A]  = MPORT_PINB_0,
            [HSEVENSEG_PIN_B]  = MPORT_PINB_1,
            [HSEVENSEG_PIN_C]  = MPORT_PINB_2,
            [HSEVENSEG_PIN_D]  = MPORT_PINB_3,
            [HSEVENSEG_PIN_E]  = MPORT_PINB_4,
            [HSEVENSEG_PIN_F]  = MPORT_PINB_5,
            [HSEVENSEG_PIN_G]  = MPORT_PINB_6,
            [HSEVENSEG_PIN_DP] = MPORT_PINB_7
        },
        .HSEVENSEG_Connection = HSEVENSEG_COMMON_ANODE
    }
    /*
    [SEVENSEG_THREE] = {
        .HSEVENSEG_strPinNumArr={
            [HSEVENSEG_PIN_A]  = MPORT_PINC_0,
            [HSEVENSEG_PIN_B]  = MPORT_PINC_1,
            [HSEVENSEG_PIN_C]  = MPORT_PINC_2,
            [HSEVENSEG_PIN_D]  = MPORT_PINC_3,
            [HSEVENSEG_PIN_E]  = MPORT_PINC_4,
            [HSEVENSEG_PIN_F]  = MPORT_PINC_5,
            [HSEVENSEG_PIN_G]  = MPORT_PINC_6,
            [HSEVENSEG_PIN_DP] = MPORT_PINC_7
        },
        .HSEVENSEG_Connection = HSEVENSEG_COMMON_ANODE
    },
    [SEVENSEG_FOUR] = {
        .HSEVENSEG_strPinNumArr={
            [HSEVENSEG_PIN_A]  = MPORT_PIND_0,
            [HSEVENSEG_PIN_B]  = MPORT_PIND_1,
            [HSEVENSEG_PIN_C]  = MPORT_PIND_2,
            [HSEVENSEG_PIN_D]  = MPORT_PIND_3,
            [HSEVENSEG_PIN_E]  = MPORT_PIND_4,
            [HSEVENSEG_PIN_F]  = MPORT_PIND_5,
            [HSEVENSEG_PIN_G]  = MPORT_PIND_6,
            [HSEVENSEG_PIN_DP] = MPORT_PIND_7
        },
        .HSEVENSEG_Connection = HSEVENSEG_COMMON_CATHODE
    }*/
};
