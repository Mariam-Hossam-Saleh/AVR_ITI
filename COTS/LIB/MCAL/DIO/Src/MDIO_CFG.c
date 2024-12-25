/*
 * MDIO_CFG.c
 * Created: 12/24/2024
 *  Author: Mariam
 */ 
 
#include "../Inc/MDIO_Cfg.h"

MDIO_enuPinCfg_t MDIO_enuPinCfgArray[MDIO_NUM_OF_PORTS * MDIO_NUM_OF_PINS] =
{
	// PORTA Configuration
	MDIO_OUTPUT_LOW,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	// PORTB Configuration
	MDIO_OUTPUT_HIGH,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	// PORTC Configuration
	MDIO_OUTPUT_LOW,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	// PORTD Configuration
	0,
	0,
	0,
	MDIO_INTERNAL_PULLUP,
	MDIO_INTERNAL_PULLUP,
	MDIO_INTERNAL_PULLUP,
	0,
	0
};
 