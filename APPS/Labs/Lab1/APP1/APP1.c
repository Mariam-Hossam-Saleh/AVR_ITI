/*
 * Lab1_Task1
 * Created: 12/11/2024
 * Author : Mariam
 */ 
 
#define F_CPU 8000000UL 
#include <avr/io.h>
#include <util/delay.h>
#include "../../../../COTS_ITI/STD_LIB/BIT_MATH.h"

int main(void)
{
	SET_BIT(DDRA,PORTA0);       // Set PORTA pin0 as output for LED
	CLR_BIT(PORTA,PORTA0);      // Set PORTA pin0 as LOW
    while (1) 
    {
		_delay_ms(1000);
		TOG_BIT(PORTA,PORTA0);
			
    }
}
