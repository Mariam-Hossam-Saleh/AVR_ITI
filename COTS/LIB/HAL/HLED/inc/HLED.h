/*
 * HLED.h
 * 
 * Created: 05/01/2025
 *  Author: Mariam Hossam
 */ 

#ifndef HLED_H_
#define HLED_H_

#include "HLED_Cfg.h"
#include "MDIO.h"
#include "MPORT.h"

/**** Enum for Error Status ****/
typedef enum
{
	HLED_OK = 0,
	HLED_NOK,
	HLED_INVALID_LED_STATE,
	HLED_INVALID_LED_NAME,
    HLED_INVALID_CONNECTION
	
} HLED_enuErrorStatus_t ;

typedef enum
{
    HLED_FORWARD = 0,
    HLED_REVERSE

} HLED_ConnectionOption_t;

typedef struct
{
    MPORT_enuPORT_PIN_t LedPinNumber;
    HLED_ConnectionOption_t LedConnection;

} HLED_Cfg_t;

typedef enum
{
    HLED_LOW,
    HLED_HIGH

} HLED_STATE_t;

void HLED_init(void);

HLED_enuErrorStatus_t HLED_enuSetLedState(u8 Copy_u8LedName, HLED_STATE_t Copy_u8State);

#endif /* HLED_H_ */