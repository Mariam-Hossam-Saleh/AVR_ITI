/*
 * Project1.c
 *
 * Created: 12/11/2024 1:47:02 PM
 * Author : Mariam
 */ 
#define F_CPU 8000000UL 
#include <avr/io.h>
#include <util/delay.h>
#include "BIT_MATH.h"

int main(void)
{
    /* Replace with your application code */
	SET_BIT(DDRA,PORTA0);
	CLR_BIT(PORTA,PORTA0);
    while (1) 
    {
		_delay_ms(1000);
		TOG_BIT(PORTA,PORTA0);
			
    }
}

