/*
 * Lab2_APP2.c
 * Created: 12/17/2024
 * Author : Mariam Hossam
 */ 
 
#define F_CPU 8000000 
#include <util/delay.h>
#include "MDIO.h"


int main(void)
{
	MDIO_enuErrorStatus_t ErrorStatus = MDIO_NOK;
	ErrorStatus = MDIO_enuSetPortConfigration(MDIO_PORTB,MDIO_OUTPUT_PORT_LOW);               // APP2 set PORTB as OUTPUT with initial value LOW 
	if(ErrorStatus != MDIO_OK)
		return 1;
	ErrorStatus = MDIO_enuSetPinConfigration(MDIO_PORTD,MDIO_PIN0,MDIO_INTERNAL_PULLUP);	  // APP2 set PORTD PIN0 as INPUT with internal pullup
	if(ErrorStatus != MDIO_OK)
		return 1;
	MDIO_enuPinState_t Loc_enuSwitchState = MDIO_PIN_HIGH;                                    // local variable to get switch state initialized by HIGH (because of pullup)
    while (1) 
    {
		ErrorStatus = MDIO_enuGetPinValue(MDIO_PORTD,MDIO_PIN0,&Loc_enuSwitchState);          // read switch state (PORTD PIN0)
		if(ErrorStatus != MDIO_OK)
			return 1;
		if(Loc_enuSwitchState == MDIO_PIN_LOW)                                                // check if switch is pressed
		{
			_delay_ms(100);
			ErrorStatus = MDIO_enuGetPinValue(MDIO_PORTD,MDIO_PIN0,&Loc_enuSwitchState);      // another check for switch for debouncing effect
			if(ErrorStatus != MDIO_OK)
				return 1;
			if(Loc_enuSwitchState == MDIO_PIN_LOW)
			{
				for(u16 Loc_u8PortState = 0 ; Loc_u8PortState < 256 ; Loc_u8PortState++)
				{
					ErrorStatus = MDIO_enuSetPortValue(MDIO_PORTB,Loc_u8PortState);	         // this line displays the binary values of counter at LEDs 			
					if(ErrorStatus != MDIO_OK)
						return 1;
					_delay_ms(100);
				}
				ErrorStatus = MDIO_enuSetPortValue(MDIO_PORTB,MDIO_PORT_LOW);                // Turn off all LEDs after all counts are done
				if(ErrorStatus != MDIO_OK)
					return 1;
			}
		}
    }
	return 0 ;
}

