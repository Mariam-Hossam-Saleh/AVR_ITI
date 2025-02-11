#ifndef HKEYPAD_H
#define HKEYPAD_H

#include "STD_TYPES.h"
#include "MPORT.h"
#include "MDIO.h"

// Define the keypad size
#define KEYPAD_ROWS 4
#define KEYPAD_COLS 4

static const u8 HKEYPAD_u8CharArr[KEYPAD_ROWS][KEYPAD_COLS] = 
{
    {'7', '8', '9', '/'},   
    {'4', '5', '6', '*'},   
    {'1', '2', '3', '-'},   
    {'C', '0', '=', '+'}    
};

typedef enum
{
	HKEYPAD_ROW_0 = 0,
	HKEYPAD_ROW_1,
	HKEYPAD_ROW_2,
	HKEYPAD_ROW_3,

} HKEYPAD_enuRowPin_t;

typedef enum
{
	HKEYPAD_Column_0 = 0,
	HKEYPAD_Column_1,
	HKEYPAD_Column_2,
	HKEYPAD_Column_3,

} HKEYPAD_enuColumnPin_t;

/**** Enum for Error Status ****/
typedef enum
{
	HKEYPAD_OK = 0,
	HKEYPAD_NOK,
	HKEYPAD_NULL_POINTER,
	HKEYPAD_INVALID_ROW,
	HKEYPAD_INVALID_COLUMN,
	
} HKEYPAD_enuErrorStatus_t ;

typedef struct
{
    MPORT_enuPORT_PIN_t HKEYPAD_RowPins[4];
	MPORT_enuPORT_PIN_t HKEYPAD_ColumnPins[4];

} HKEYPAD_strCfg_t;

extern HKEYPAD_enuErrorStatus_t HKEYPAD_enuInit(void);
extern HKEYPAD_enuErrorStatus_t HKEYPAD_enuGetPressedKey(u8 * Add_u8PressedKey,u8 Copy_u8KeypadNum);

#endif // HKEYPAD_H