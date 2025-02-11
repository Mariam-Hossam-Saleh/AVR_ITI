/*
 * HSEVENSEG.c
 *
 * Created: 06/01/2025
 *  Author: Mariam Hossam
 */ 

#include "HSEVENSEG.h"

extern HSEVENSEG_strCfg_t sevenSegCfgArr[NUMBER_OF_SEVENSEG];

HSEVENSEG_enuSevenSegMapping_t sevenSegValuesArr[11]=
{
    HSEVENSEG_ZERO,
    HSEVENSEG_ONE,
    HSEVENSEG_TWO,
    HSEVENSEG_THREE,
    HSEVENSEG_FOUR,
    HSEVENSEG_FIVE,
    HSEVENSEG_SIX,
    HSEVENSEG_SEVEN,
    HSEVENSEG_EIGHT,
    HSEVENSEG_NINE,
    HSEVENSEG_DP
};


void HSEVENSEG_vInit(void)
{
    MPORT_enuSetPinDirection(MPORT_PINA_0,MPORT_OUTPUT);
    MPORT_enuSetPinDirection(0,MPORT_OUTPUT);
    MDIO_enuPortNum_t Loc_enuPort = MDIO_PORTA;
    MDIO_enuPinNum_t  Loc_enuPin  = MDIO_PIN0;
    for(u8 SevenSeg_iterator = 0 ; SevenSeg_iterator < NUMBER_OF_SEVENSEG ; SevenSeg_iterator++)
    {
        for(u8 Pins_iterator = 0 ; Pins_iterator < NUMBER_OF_SEVENSEG_PINS ; Pins_iterator++)
        {      
            MPORT_enuSetPinDirection((sevenSegCfgArr[SevenSeg_iterator].HSEVENSEG_strPinNumArr[Pins_iterator]),MPORT_OUTPUT);
            Loc_enuPort = GET_HIGH_NIB(sevenSegCfgArr[SevenSeg_iterator].HSEVENSEG_strPinNumArr[Pins_iterator]);
            Loc_enuPin  = GET_LOW_NIB(sevenSegCfgArr[SevenSeg_iterator].HSEVENSEG_strPinNumArr[Pins_iterator]);
            if(sevenSegCfgArr[SevenSeg_iterator].HSEVENSEG_Connection == HSEVENSEG_COMMON_CATHODE)
            {
                MDIO_enuSetPinValue(Loc_enuPort,Loc_enuPin,MDIO_PIN_LOW); 
            }
            else if(sevenSegCfgArr[SevenSeg_iterator].HSEVENSEG_Connection == HSEVENSEG_COMMON_ANODE)
            {
                MDIO_enuSetPinValue(Loc_enuPort,Loc_enuPin,MDIO_PIN_HIGH); 
            }
            else
            {
                /* Do Nothing */
            }
        }
    }
}

HSEVENSEG_enuErrorStatus_t HSEVENSEG_enuSetValue(u8 Copy_u8SevenSegNum , u8 Copy_u8Value)
{
    HSEVENSEG_enuErrorStatus_t Loc_enuErrorStatus = HSEVENSEG_NOK;
    if(Copy_u8SevenSegNum >= NUMBER_OF_SEVENSEG)
    {
        Loc_enuErrorStatus = HSEVENSEG_INVALID_NUMBER_OF_SEVENSEG;
    }
    else if((Copy_u8Value > 9) || (Copy_u8Value < 0))
    {
        Loc_enuErrorStatus = HSEVENSEG_INVALID_NUMBER;
    }
    else
    {
        Loc_enuErrorStatus = HSEVENSEG_OK;
        MPORT_enuPortNum_t Loc_enuSevenSegPort = MPORT_PORTA;
        MPORT_enuPinNum_t  Loc_enuSevenSegPin  = MPORT_PIN0;
        u8 Loc_u8SevenSegConnectedPin = 0;
        for(u8 PinIterator = HSEVENSEG_PIN_A ; PinIterator <= HSEVENSEG_PIN_DP ; PinIterator++)
        {
            Loc_enuSevenSegPort = GET_HIGH_NIB(sevenSegCfgArr[Copy_u8SevenSegNum].HSEVENSEG_strPinNumArr[PinIterator]);
            Loc_enuSevenSegPin  = GET_LOW_NIB(sevenSegCfgArr[Copy_u8SevenSegNum].HSEVENSEG_strPinNumArr[PinIterator]);
            Loc_u8SevenSegConnectedPin = GET_BIT(sevenSegValuesArr[Copy_u8Value],PinIterator);
            if(sevenSegCfgArr[Copy_u8SevenSegNum].HSEVENSEG_Connection == HSEVENSEG_COMMON_ANODE)
            {
                Loc_u8SevenSegConnectedPin = !Loc_u8SevenSegConnectedPin;
            }
            else
            {
                /* Do Nothing */
            }
            MDIO_enuSetPinValue(Loc_enuSevenSegPort,Loc_enuSevenSegPin,Loc_u8SevenSegConnectedPin);
        }
    } 
}

HSEVENSEG_enuErrorStatus_t HSEVENSEG_enuSetMultiDigitValue(u16 Copy_u16Value)
{
    u8 Loc_u8SevenSegValue = 0;
    do
    {
        HSEVENSEG_enuSetValue(Loc_u8SevenSegValue++,Copy_u16Value%10);
    } while ((Copy_u16Value/=10)!=0);

}

// void HSEVENSEG_vInit(void)
// {
//     MDIO_enuPortNum_t Loc_enuPort = MDIO_PORTA;
//     MDIO_enuPinNum_t  Loc_enuPin  = MDIO_PIN0;
//     for(u8 SevenSeg_iterator = 0 ; SevenSeg_iterator < NUMBER_OF_SEVENSEG ; SevenSeg_iterator++)
//     {
//         for(u8 Pins_iterator = 0 ; Pins_iterator < NUMBER_OF_SEVENSEG_PINS ; Pins_iterator++)
//         {      
//             MPORT_enuSetPinDirection((sevenSegCfgArr[SevenSeg_iterator].HSEVENSEG_strPinNumArr[Pins_iterator]),MPORT_OUTPUT);
//             Loc_enuPort = GET_HIGH_NIB(sevenSegCfgArr[SevenSeg_iterator].HSEVENSEG_strPinNumArr[Pins_iterator]);
//             Loc_enuPin  = GET_LOW_NIB(sevenSegCfgArr[SevenSeg_iterator].HSEVENSEG_strPinNumArr[Pins_iterator]);
//             if(sevenSegCfgArr[SevenSeg_iterator].HSEVENSEG_Connection == HSEVENSEG_COMMON_CATHODE)
//             {
//                 MDIO_enuSetPinValue(Loc_enuPort,Loc_enuPin,MDIO_PIN_LOW); 
//             }
//             else if(sevenSegCfgArr[SevenSeg_iterator].HSEVENSEG_Connection == HSEVENSEG_COMMON_ANODE)
//             {
//                 MDIO_enuSetPinValue(Loc_enuPort,Loc_enuPin,MDIO_PIN_HIGH); 
//             }
//             else
//             {
//                 /* Do Nothing */
//             }
//         }
//     }
// }
