/*
 * Task1.c
 * Created: 12/17/2024
 * Author : Mariam Hossam
 */ 
#define F_CPU 8000000 
#include <util/delay.h>
#include "../MDIO/Inc/MDIO.h"


int main(void)
{
	MDIO_enuErrorStatus_t ErrorStatus = MDIO_NOK;
	ErrorStatus = MDIO_enuSetPortConfigration(MDIO_PORTA,MDIO_OUTPUT_PORT_LOW);                  // APP1 set PORTA as OUTPUT with initial value LOW
	if(ErrorStatus != MDIO_OK)
		return 1;
	ErrorStatus = MDIO_enuSetPinConfigration(MDIO_PORTC,MDIO_PIN0,MDIO_INTERNAL_PORT_PULLUP);    // APP1 set PORTC PIN0 as INPUT with internal PULL_UP
	if(ErrorStatus != MDIO_OK)
		return 1;
	MDIO_enuPinState_t Loc_enuSwitchState = MDIO_PIN_HIGH;                                       // local variable to get switch state initialized by HIGH (because of PULL_UP)
    while (1) 
    {
		_delay_ms(100);
		MDIO_enuPinState_t Loc_enuPinValue;
		ErrorStatus = MDIO_enuGetPinValue(MDIO_PORTC,MDIO_PIN0,&Loc_enuPinValue);               // read switch state (PORTD PIN0)
		if(ErrorStatus != MDIO_OK)
			return 1;
		if(Loc_enuPinValue == MDIO_PIN_LOW)                                                     // check if switch is pressed
		{
			_delay_ms(100);
			ErrorStatus = MDIO_enuGetPinValue(MDIO_PORTC,MDIO_PIN0,&Loc_enuPinValue);           // another check for switch for debouncing effect
			if(ErrorStatus != MDIO_OK)
				return 1;
			if(Loc_enuPinValue == MDIO_PIN_LOW)
			{
				ErrorStatus = MDIO_enuSetPinValue(MDIO_PORTA,MDIO_PIN0,MDIO_PIN_HIGH);
				if(ErrorStatus != MDIO_OK)
					return 1;
			}

		}
		else
		{
			ErrorStatus = MDIO_enuSetPinValue(MDIO_PORTA,MDIO_PIN0,MDIO_PIN_LOW);
			if(ErrorStatus != MDIO_OK)
				return 1;
		}
    }
	return 0;
}

