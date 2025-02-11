#include "MDIO.h"
#include "MPORT.h"
#include "BIT_MATH.h"
#include "HKEYPAD.h"
#include "HKEYPAD_cfg.h"
#define F_CPU 8000000UL

extern HKEYPAD_strCfg_t HKEYPAD_cfgArr[NUMBER_OF_KEYPAD];

HKEYPAD_enuErrorStatus_t HKEYPAD_enuInit(void)
{
    HKEYPAD_enuErrorStatus_t Loc_enuErrorStatus = HKEYPAD_OK;
    for(u8 iterator = 0; iterator < NUMBER_OF_KEYPAD ; iterator++)
    {
        for(u8 PinsIterator = 0 ; PinsIterator < 4 ; PinsIterator++ )
        {
            Loc_enuErrorStatus = MPORT_enuSetPinDirection(HKEYPAD_cfgArr[iterator].HKEYPAD_RowPins[PinsIterator],MPORT_INPUT);
            Loc_enuErrorStatus = MPORT_enuSetPinMode(HKEYPAD_cfgArr[iterator].HKEYPAD_RowPins[PinsIterator],MPORT_PIN_MODE_INPUT_PULLUP);
            Loc_enuErrorStatus = MPORT_enuSetPinDirection(HKEYPAD_cfgArr[iterator].HKEYPAD_ColumnPins[PinsIterator],MPORT_OUTPUT);
            Loc_enuErrorStatus = MDIO_enuSetPinValue((HKEYPAD_cfgArr[iterator].HKEYPAD_ColumnPins[PinsIterator]>>4),(HKEYPAD_cfgArr[iterator].HKEYPAD_ColumnPins[PinsIterator]&0x0F),MDIO_PIN_HIGH);
        }
    }
    return Loc_enuErrorStatus;
}

HKEYPAD_enuErrorStatus_t HKEYPAD_enuGetPressedKey(u8 * Add_u8PressedKey,u8 Copy_u8KeypadNum)
{
    HKEYPAD_enuErrorStatus_t Loc_enuErrorStatus = HKEYPAD_OK;
    if(NULL_PTR == Add_u8PressedKey)
    {
        Loc_enuErrorStatus = HKEYPAD_NULL_POINTER;
    }
    else
    {
        * Add_u8PressedKey = 0xFF;
        u8 Flag = 0;
        for(u8 ColumnIterator = 0 ; ColumnIterator < 4 ; ColumnIterator++)
        {
            Loc_enuErrorStatus = MDIO_enuSetPinValue((HKEYPAD_cfgArr[Copy_u8KeypadNum].HKEYPAD_ColumnPins[ColumnIterator]>>4),(HKEYPAD_cfgArr[Copy_u8KeypadNum].HKEYPAD_ColumnPins[ColumnIterator]&0x0F),MDIO_PIN_LOW);
            for(u8 RowIterator = 0 ; RowIterator < 4 ; RowIterator++)
            {
                u8 Loc_u8RowPinValue;
                Loc_enuErrorStatus = MDIO_enuGetPinValue((HKEYPAD_cfgArr[Copy_u8KeypadNum].HKEYPAD_RowPins[RowIterator]>>4),(HKEYPAD_cfgArr[Copy_u8KeypadNum].HKEYPAD_RowPins[RowIterator]&0x0F),&Loc_u8RowPinValue);
                if(Loc_u8RowPinValue == MDIO_PIN_LOW)
                {
                    *Add_u8PressedKey = HKEYPAD_u8CharArr[RowIterator][ColumnIterator];
                    while(Loc_u8RowPinValue == MDIO_PIN_LOW)
                    {
                        Loc_enuErrorStatus = MDIO_enuGetPinValue((HKEYPAD_cfgArr[Copy_u8KeypadNum].HKEYPAD_RowPins[RowIterator]>>4),(HKEYPAD_cfgArr[Copy_u8KeypadNum].HKEYPAD_RowPins[RowIterator]&0x0F),&Loc_u8RowPinValue);
                    }
                    Flag = 1;
                    break;
                }
            }
            Loc_enuErrorStatus = MDIO_enuSetPinValue((HKEYPAD_cfgArr[Copy_u8KeypadNum].HKEYPAD_ColumnPins[ColumnIterator]>>4),(HKEYPAD_cfgArr[Copy_u8KeypadNum].HKEYPAD_ColumnPins[ColumnIterator]&0x0F),MDIO_PIN_HIGH);
            if(Flag == 1)
            {
                break;
            }
        }
    }
    return Loc_enuErrorStatus;
}