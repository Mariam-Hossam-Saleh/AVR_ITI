/*
 * Lab6.c
 * Created: 06/01/2024
 * Author : Mariam Hossam
 */ 

/* This Application is testing the 7Seg driver */
#include "Lab6.h"

int main(void)
{
	HSEVENSEG_vInit();
	MPORT_enuSetPinDirection(MPORT_PIND_0,MPORT_INPUT);
	MPORT_enuSetPinMode(MPORT_PIND_0,MPORT_PIN_MODE_INPUT_PULLUP);
	u8 Loc_Switch = 0;
	//HSEVENSEG_enuSetValue(SEVENSEG_ONE,7);
	//HSEVENSEG_enuSetValue(SEVENSEG_TWO,5);
	//HSEVENSEG_enuSetMultiDigitValue(1234);
    while (1) 
    {
		int number = 0;
		MDIO_enuGetPinValue(MDIO_PORTD,MDIO_PIN0,&Loc_Switch);
		if(Loc_Switch == 0)
		{
			MDIO_enuGetPinValue(MDIO_PORTD,MDIO_PIN0,&Loc_Switch);
			if(Loc_Switch == 0)
			{
				for(number = 0 ; number < 100 ; number++)
				{
					HSEVENSEG_enuSetMultiDigitValue(number);
					_delay_ms(300);
				}
			}
		}
	}
	return 0;
}
