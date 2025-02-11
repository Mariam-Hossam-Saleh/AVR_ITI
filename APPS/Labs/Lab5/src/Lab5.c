/*
 * Lab5.c
 * Created: 01/03/2024 2:58:13 PM
 * Author : Mariam Hossam
 */ 

/* This Application is testing the LED driver */
#include "Lab5.h"

int main(void)
{
	MPORT_vInit();
	HLED_init();
	u8 Loc_u8SwitchState1 = MDIO_PIN_LOW;   
	u8 Loc_u8SwitchState2 = MDIO_PIN_LOW; 
	u8 Loc_u8SwitchState3 = MDIO_PIN_LOW; 
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
				HLED_enuSetLedState(LED_START,HLED_HIGH);
				_delay_ms(100);
			}
		}
		else if(Loc_u8SwitchState2 == MDIO_PIN_LOW)                                                // check if switch is pressed
		{
			HLED_enuSetLedState(LED_STOP,HLED_HIGH);
			_delay_ms(100);
		}
		else if(Loc_u8SwitchState3 == MDIO_PIN_LOW)                                                // check if switch is pressed
		{
			HLED_enuSetLedState(LED_ALERT,HLED_HIGH);
			_delay_ms(100);
		}
		else
		{
			HLED_enuSetLedState(LED_STOP,HLED_LOW);
			HLED_enuSetLedState(LED_START,HLED_LOW);
			HLED_enuSetLedState(LED_ALERT,HLED_LOW);
		}
	}
	return 0;
}
