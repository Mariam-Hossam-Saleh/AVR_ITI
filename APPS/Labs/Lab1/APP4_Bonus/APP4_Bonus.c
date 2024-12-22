/*
 * Lab1_Task2
 * Created: 12/11/2024
 * Author : Mariam
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "../../../../COTS_ITI/STD_LIB/BIT_MATH.h"

int main(void)
{
			SET_BIT(DDRA,PORTA0);           // Set PORTA pin0 as output for GREEN LED
			CLR_BIT(PORTA,PORTA0);          // Set PORTA pin0 as LOW
			SET_BIT(DDRA,PORTA1);           // Set PORTA pin1 as output for RED LED
			CLR_BIT(PORTA,PORTA1);          // Set PORTA pin1 as LOW
			SET_BIT(DDRA,PORTA2);           // Set PORTA pin2 as output for BLUE  LED
			CLR_BIT(PORTA,PORTA2);          // Set PORTA pin2 as LOW
			SET_BIT(DDRA,PORTA3);           // Set PORTA pin2 as output for YELLOW LED
			CLR_BIT(PORTA,PORTA3);          // Set PORTA pin2 as LOW
			CLR_BIT(DDRC,PORTC0);           // Set PORTC pin0 as input for Switch
			SET_BIT(PORTC,PORTC0);          // Set PORTC pin0 as input pull up
			int counter = 1;
    while (1) 
    {
		_delay_ms(100);
		if(GET_BIT(PINC,PINC0) == 0)          // check if the switch is pressed
		{
			_delay_ms(100);
			while(GET_BIT(PINC,PINC0) == 0);  // double check for debouncing effect
			PORTA = counter;
			counter++;
			if(counter == 16)
			{
				counter = 0;
			}
		}
    }
}

