/*
 * Lab1_Task2
 * Created: 12/11/2024
 * Author : Mariam
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "../../../../COTS/STD_LIB/BIT_MATH.h"


int main(void)
{
			SET_BIT(DDRA,PORTA0);        // Set PORTA pin0 as output for RED LED
			CLR_BIT(PORTA,PORTA0);       // Set PORTA pin0 as LOW
			SET_BIT(DDRA,PORTA1);        // Set PORTA pin1 as output for YELLOW LED
			CLR_BIT(PORTA,PORTA1);       // Set PORTA pin1 as LOW
			SET_BIT(DDRA,PORTA2);        // Set PORTA pin2 as output for GREEN LED
			CLR_BIT(PORTA,PORTA2);       // Set PORTA pin2 as LOW
			CLR_BIT(DDRC,PORTC0);        // Set PORTC pin0 as input for Switch
			SET_BIT(PORTC,PORTC0);       // Set PORTC pin0 as input pull up
    while (1) 
    {
		if(GET_BIT(PINC,PINC0)==0)       // check if the switch is pressed
		{
			_delay_ms(100);
			if(GET_BIT(PINC,PINC0)==0)   // double check for debouncing effect
			{
				_delay_ms(100);
				for(int counter = 0 ; counter < 3 ; counter++)
				{
					if(counter == 0)
					{
						SET_BIT(PORTA,PORTA0);   // RED LED is ON
						CLR_BIT(PORTA,PORTA1);   // YELLOW LED is OFF
						CLR_BIT(PORTA,PORTA2);   // GREEN LED is OFF
					}
					else if(counter == 1)
					{
						CLR_BIT(PORTA,PORTA0);   // RED LED is OFF
						SET_BIT(PORTA,PORTA1);   // YELLOW LED is ON
						CLR_BIT(PORTA,PORTA2);   // GREEN LED is OFF
					}
					else if(counter == 2)
					{
						CLR_BIT(PORTA,PORTA0);   // RED LED is OFF
						CLR_BIT(PORTA,PORTA1);   // YELLOW LED is OFF
						SET_BIT(PORTA,PORTA2);   // GREEN LED is ON
					}
					_delay_ms(1000);
				}
				CLR_BIT(PORTA,PORTA2);   // GREEN LED is OFF
			}
		}
    }
}

