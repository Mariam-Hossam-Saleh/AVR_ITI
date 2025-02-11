/*
 * Lab1_Task3
 * Created: 12/11/2024
 * Author : Mariam
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "../../../../COTS/STD_LIB/BIT_MATH.h"

int main(void)
{
			SET_BIT(DDRA,PORTA0);        // Set PORTA pin0 as output for LED
			SET_BIT(PORTA,PORTA0);       // Set PORTA pin0 as High
			CLR_BIT(DDRC,PORTC0);        // Set PORTC pin0 as input for Switch
			SET_BIT(PORTC,PORTC0);       // Set PORTC pin0 as input pull up
    while (1) 
    {
		if(GET_BIT(PINC,PINC0)==0)       // check if the switch is pressed
		{
			SET_BIT(PORTA,PORTA0);       // LED is ON
		}
		else
		{
			CLR_BIT(PORTA,PORTA0);       // LED is OFF
		}
    }
}

