/*
 * Lab4.c
 * Created: 03/01/2024 2:58:13 PM
 * Author : Mariam Hossam
 */ 

#include "Lab4.h"

int main(void)
{
	MPORT_vInit();
	u8 Loc_u8SwitchState1 = MDIO_PIN_LOW;   
	u8 Loc_u8SwitchState2 = MDIO_PIN_LOW; 
	u8 Loc_u8SwitchState3 = MDIO_PIN_LOW; 
	MPORT_enuSetPinDirection(MPORT_PINA_0,MPORT_OUTPUT);
    while (1) 
    {
		 MDIO_enuGetPinValue(MDIO_PORTD,MDIO_PIN3,&Loc_u8SwitchState1); 
		 MDIO_enuGetPinValue(MDIO_PORTD,MDIO_PIN4,&Loc_u8SwitchState2);
		 MDIO_enuGetPinValue(MDIO_PORTD,MDIO_PIN5,&Loc_u8SwitchState3);
		if(Loc_u8SwitchState1 == MDIO_PIN_LOW)                                                // check if switch is pressed
		{
			_delay_ms(100);
			MDIO_enuGetPinValue(MDIO_PORTD,MDIO_PIN3,&Loc_u8SwitchState1); 
			if(Loc_u8SwitchState1 == MDIO_PIN_LOW)
			{
				MDIO_enuSetPinValue(MDIO_PORTA,MDIO_PIN0,MDIO_PIN_HIGH);
				_delay_ms(100);
			}
		}
		else if(Loc_u8SwitchState2 == MDIO_PIN_LOW)                                                // check if switch is pressed
		{
			MDIO_enuSetPinValue(MDIO_PORTB,MDIO_PIN0,MDIO_PIN_HIGH);
			_delay_ms(100);
		}
		else if(Loc_u8SwitchState3 == MDIO_PIN_LOW)                                                // check if switch is pressed
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
