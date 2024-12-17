/*
 * Task1.c
 * Created: 12/17/2024
 * Author : Mariam Hossam
 */ 

#include "BIT_MATH.h"
#include "MDIO.h"

int main(void)
{
	MDIO_enuSetPortConfigration(MDIO_PORTD,OUTPUT_PORT_LOW);
    while (1) 
    {
		MDIO_enuSetPortValue(MDIO_PORTD,PORT_HIGH);
    }
}

