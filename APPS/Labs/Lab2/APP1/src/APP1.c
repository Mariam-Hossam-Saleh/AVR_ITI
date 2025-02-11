/*
 * Task1.c
 * Created: 12/17/2024
 * Author : Mariam Hossam
 */ 
//#define F_CPU 8000000 
#include <util/delay.h>
#include "MDIO.h"


int main(void)
{
	MDIO_enuSetPortConfigration(MDIO_PORTA,MDIO_OUTPUT_PORT_LOW);                  // APP1 set PORTA as OUTPUT with initial value LOW
	MDIO_enuSetPinValue(MDIO_PORTA,MDIO_PIN0,MDIO_PIN_HIGH);
	_delay_ms(1000);
    MDIO_enuSetPinConfigration(MDIO_PORTA,MDIO_PIN1,MDIO_INTERNAL_PORT_PULLUP);    // APP1 set PORTC PIN0 as INPUT with internal PULL_UP
                                      // local variable to get switch state initialized by HIGH (because of PULL_UP)
    while (1) 
    {
		_delay_ms(100);
		MDIO_enuPinState_t Loc_enuPinValue;
	                   // read switch state (PORTD PIN0)
		if((MDIO_enuGetPinValue(MDIO_PORTA,MDIO_PIN1,&Loc_enuPinValue)==0) && (Loc_enuPinValue == 0))                                                     // check if switch is pressed
		{
			//while((MDIO_enuGetPinValue(MDIO_PORTA,MDIO_PIN1,&Loc_enuPinValue)==0) && (Loc_enuPinValue == 0));
				MDIO_enuSetPinValue(MDIO_PORTA,MDIO_PIN0,MDIO_PIN_HIGH);
			_delay_ms(1000);
			MDIO_enuGetPinValue(MDIO_PORTA,MDIO_PIN1,&Loc_enuPinValue);           // another check for switch for debouncing effect
			if(Loc_enuPinValue == MDIO_PIN_LOW)
			{

				MDIO_enuSetPinValue(MDIO_PORTA,MDIO_PIN0,MDIO_PIN_HIGH);
			    _delay_ms(100);
			}

		}
		else
		{
			MDIO_enuSetPinValue(MDIO_PORTA,MDIO_PIN0,MDIO_PIN_LOW);
		}
    }
	return 0;
}

