/*
 * Lab2_APP2.c
 * Created: 12/17/2024
 * Author : Mariam Hossam
 */ 
 
#define F_CPU 8000000 
#include <util/delay.h>
#include "BIT_MATH.h"
#include "MDIO.h"


int main(void)
{
	MDIO_enuSetPortConfigration(MDIO_PORTB,OUTPUT_PORT_LOW);                // APP2 set PORTB as OUTPUT with initial value LOW 
	MDIO_enuSetPinConfigration(MDIO_PORTD,MDIO_PIN0,INTERNAL_PULLUP);	    // APP2 set PORTD PIN0 as INPUT with internal pullup
	MDIO_enuPinState_t Loc_enuSwitchState = PIN_HIGH;                       // local variable to get switch state initialized by HIGH (because of pullup)
    while (1) 
    {
		MDIO_enuGetPinValue(MDIO_PORTD,MDIO_PIN0,&Loc_enuSwitchState);      // read switch state (PORTD PIN0)
		if(Loc_enuSwitchState == PIN_LOW)                                   // check if switch is pressed
		{
			_delay_ms(100);
			MDIO_enuGetPinValue(MDIO_PORTD,MDIO_PIN0,&Loc_enuSwitchState);  // another check for switch for debouncing effect
			if(Loc_enuSwitchState == PIN_LOW)
			{
				for(u16 Loc_u8PortState = 0 ; Loc_u8PortState < 256 ; Loc_u8PortState++)
				{
					MDIO_enuSetPortValue(MDIO_PORTB,Loc_u8PortState);		// this line displays the binary values of counter at LEDs 			
					_delay_ms(200);
				}
				MDIO_enuSetPortValue(MDIO_PORTB,PORT_LOW);                  // Turn off all LEDs after all counts are done
				
			}
		}
    }
}

