/*
 * Lab3.c
 *
 * Created: 12/25/2024 2:58:13 PM
 * Author : DELL
 */ 

#define F_CPU 8000000
#include <util/delay.h>
#include "../MCAL/MDIO/inc/MDIO.h"

int main(void)
{
	MDIO_vInit();
	MDIO_enuPinState_t Loc_enuSwitchState1 = MDIO_PIN_LOW;   
	MDIO_enuPinState_t Loc_enuSwitchState2 = MDIO_PIN_LOW; 
	MDIO_enuPinState_t Loc_enuSwitchState3 = MDIO_PIN_LOW; 
    while (1) 
    {
		 MDIO_enuGetPinValue(MDIO_PORTD,MDIO_PIN3,&Loc_enuSwitchState1); 
		 MDIO_enuGetPinValue(MDIO_PORTD,MDIO_PIN4,&Loc_enuSwitchState2);
		 MDIO_enuGetPinValue(MDIO_PORTD,MDIO_PIN5,&Loc_enuSwitchState3);
		if(Loc_enuSwitchState1 == MDIO_PIN_LOW)                                                // check if switch is pressed
		{
			MDIO_enuSetPinValue(MDIO_PORTA,MDIO_PIN0,MDIO_PIN_HIGH);
			_delay_ms(100);
		}
		else if(Loc_enuSwitchState2 == MDIO_PIN_LOW)                                                // check if switch is pressed
		{
			MDIO_enuSetPinValue(MDIO_PORTB,MDIO_PIN0,MDIO_PIN_HIGH);
			_delay_ms(100);
		}
		else if(Loc_enuSwitchState3 == MDIO_PIN_LOW)                                                // check if switch is pressed
		{
			MDIO_enuSetPinValue(MDIO_PORTC,MDIO_PIN0,MDIO_PIN_HIGH);
			_delay_ms(100);
		}
		else
		{
			MDIO_enuSetPinValue(MDIO_PORTA,MDIO_PIN0,MDIO_PIN_LOW);
			MDIO_enuSetPinValue(MDIO_PORTB,MDIO_PIN0,MDIO_PIN_LOW);
			MDIO_enuSetPinValue(MDIO_PORTC,MDIO_PIN0,MDIO_PIN_LOW);
		}
	}
	return 0;
}

