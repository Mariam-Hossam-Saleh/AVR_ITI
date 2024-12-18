/*
 * Task1.c
 * Created: 12/17/2024
 * Author : Mariam Hossam
 */ 

#include "MDIO.h"
#include "BIT_MATH.h"

#define PORTA (*((volatile u8*) 0x3B))
#define PORTB (*((volatile u8*) 0x38))
#define PORTC (*((volatile u8*) 0x35))
#define PORTD (*((volatile u8*) 0x32))

#define PINA (*((volatile u8*) 0x39))
#define PINB (*((volatile u8*) 0x36))
#define PINC (*((volatile u8*) 0x33))
#define PIND (*((volatile u8*) 0x30))

#define DDRA (*((volatile u8*) 0x3A))
#define DDRB (*((volatile u8*) 0x37))
#define DDRC (*((volatile u8*) 0x34))
#define DDRD (*((volatile u8*) 0x31))

MDIO_enuErrorStatus_t MDIO_enuSetPinConfigration(MDIO_enuPortNum_t Copy_enuPortNum,MDIO_enuPinNum_t Copy_enuPinNum,MDIO_enuPinCfg_t Copy_enuConfigration)
{
	MDIO_enuErrorStatus_t Ret_enuErrorStatus = MDIO_NOK;
	if(Copy_enuPortNum > MDIO_PORTD)
	{
		Ret_enuErrorStatus = MDIO_INVALID_PORT_NUM;
	}
	else if(Copy_enuPinNum > MDIO_PIN7)
	{
		Ret_enuErrorStatus = MDIO_INVALID_PIN_NUM;
	}
	else if(Copy_enuConfigration > EXTERNAL_PULLDOWN)
	{
		Ret_enuErrorStatus = MDIO_INVALID_PIN_CFG;
	}
	else
	{
		Ret_enuErrorStatus = MDIO_OK;
		switch(Copy_enuPortNum)
		{
			case MDIO_PORTA:
				if(Copy_enuConfigration == OUTPUT_LOW)
				{
					SET_BIT(DDRA,Copy_enuPinNum);
					CLR_BIT(PORTA,Copy_enuPinNum);
				}
				else if(Copy_enuConfigration == OUTPUT_HIGH)
				{
					SET_BIT(DDRA,Copy_enuPinNum);
					SET_BIT(PORTA,Copy_enuPinNum);					
				}
				else if(Copy_enuConfigration == INTERNAL_PULLUP)
				{
					CLR_BIT(DDRA,Copy_enuPinNum);
					SET_BIT(PORTA,Copy_enuPinNum);					
				}
				else if(Copy_enuConfigration == EXTERNAL_PULLDOWN)
				{
					CLR_BIT(DDRA,Copy_enuPinNum);
					CLR_BIT(PORTA,Copy_enuPinNum);
				}				
			break;
			case MDIO_PORTB:
				if(Copy_enuConfigration == OUTPUT_LOW)
				{
					SET_BIT(DDRB,Copy_enuPinNum);
					CLR_BIT(PORTB,Copy_enuPinNum);
				}
				else if(Copy_enuConfigration == OUTPUT_HIGH)
				{
					SET_BIT(DDRB,Copy_enuPinNum);
					SET_BIT(PORTB,Copy_enuPinNum);
				}
				else if(Copy_enuConfigration == INTERNAL_PULLUP)
				{
					CLR_BIT(DDRB,Copy_enuPinNum);
					SET_BIT(PORTB,Copy_enuPinNum);
				}
				else if(Copy_enuConfigration == EXTERNAL_PULLDOWN)
				{
					CLR_BIT(DDRB,Copy_enuPinNum);
					CLR_BIT(PORTB,Copy_enuPinNum);
				}
			break;
			case MDIO_PORTC:
				if(Copy_enuConfigration == OUTPUT_LOW)
				{
					SET_BIT(DDRC,Copy_enuPinNum);
					CLR_BIT(PORTC,Copy_enuPinNum);
				}
				else if(Copy_enuConfigration == OUTPUT_HIGH)
				{
					SET_BIT(DDRC,Copy_enuPinNum);
					SET_BIT(PORTC,Copy_enuPinNum);
				}
				else if(Copy_enuConfigration == INTERNAL_PULLUP)
				{
					CLR_BIT(DDRC,Copy_enuPinNum);
					SET_BIT(PORTC,Copy_enuPinNum);
				}
				else if(Copy_enuConfigration == EXTERNAL_PULLDOWN)
				{
					CLR_BIT(DDRC,Copy_enuPinNum);
					CLR_BIT(PORTC,Copy_enuPinNum);
				}
			break;
			case MDIO_PORTD:
				if(Copy_enuConfigration == OUTPUT_LOW)
				{
					SET_BIT(DDRD,Copy_enuPinNum);
					CLR_BIT(PORTD,Copy_enuPinNum);
				}
				else if(Copy_enuConfigration == OUTPUT_HIGH)
				{
					SET_BIT(DDRD,Copy_enuPinNum);
					SET_BIT(PORTD,Copy_enuPinNum);
				}
				else if(Copy_enuConfigration == INTERNAL_PULLUP)
				{
					CLR_BIT(DDRD,Copy_enuPinNum);
					SET_BIT(PORTD,Copy_enuPinNum);
				}
				else if(Copy_enuConfigration == EXTERNAL_PULLDOWN)
				{
					CLR_BIT(DDRD,Copy_enuPinNum);
					CLR_BIT(PORTD,Copy_enuPinNum);
				}
			break;
		}
	}
	return Ret_enuErrorStatus;	
}


MDIO_enuErrorStatus_t MDIO_enuSetPortConfigration(MDIO_enuPortNum_t Copy_enuPortNum,MDIO_enuPortCfg_t Copy_enuConfigration)
{
	MDIO_enuErrorStatus_t Ret_enuErrorStatus = MDIO_NOK;
	if(Copy_enuPortNum > MDIO_PORTD)
	{
		Ret_enuErrorStatus = MDIO_INVALID_PORT_NUM;
	}
	else if(Copy_enuConfigration > EXTERNAL_PORT_PULLDOWN)
	{
		Ret_enuErrorStatus = MDIO_INVALID_PORT_CFG;
	}
	else
	{
		Ret_enuErrorStatus = MDIO_OK;
		switch(Copy_enuPortNum)
		{
			case MDIO_PORTA:
			if(Copy_enuConfigration == OUTPUT_PORT_LOW)
			{
				DDRA = PORT_HIGH;
				PORTA = PORT_LOW;
			}
			else if(Copy_enuConfigration == OUTPUT_PORT_HIGH)
			{
				DDRA = PORT_HIGH;
				PORTA = PORT_HIGH;
			}
			else if(Copy_enuConfigration == INTERNAL_PULLUP)
			{
				DDRA = PORT_LOW;
				PORTA = PORT_HIGH;
			}
			else if(Copy_enuConfigration == EXTERNAL_PULLDOWN)
			{
				DDRA = PORT_LOW;
				PORTA = PORT_LOW;
			}
			break;
			case MDIO_PORTB:
			if(Copy_enuConfigration == OUTPUT_PORT_LOW)
			{
				DDRB = PORT_HIGH;
				PORTB = PORT_LOW;
			}
			else if(Copy_enuConfigration == OUTPUT_PORT_HIGH)
			{
				DDRB = PORT_HIGH;
				PORTB = PORT_HIGH;
			}
			else if(Copy_enuConfigration == INTERNAL_PULLUP)
			{
				DDRB = PORT_LOW;
				PORTB = PORT_HIGH;
			}
			else if(Copy_enuConfigration == EXTERNAL_PULLDOWN)
			{
				DDRB = PORT_LOW;
				PORTB = PORT_LOW;
			}
			break;
			case MDIO_PORTC:
			if(Copy_enuConfigration == OUTPUT_PORT_LOW)
			{
				DDRC = PORT_HIGH;
				PORTC = PORT_LOW;
			}
			else if(Copy_enuConfigration == OUTPUT_PORT_HIGH)
			{
				DDRC = PORT_HIGH;
				PORTC = PORT_HIGH;
			}
			else if(Copy_enuConfigration == INTERNAL_PULLUP)
			{
				DDRC = PORT_LOW;
				PORTC = PORT_HIGH;
			}
			else if(Copy_enuConfigration == EXTERNAL_PULLDOWN)
			{
				DDRC = PORT_LOW;
				PORTC = PORT_LOW;
			}
			break;
			case MDIO_PORTD:
			if(Copy_enuConfigration == OUTPUT_PORT_LOW)
			{
				DDRD = PORT_HIGH;
				PORTD = PORT_LOW;
			}
			else if(Copy_enuConfigration == OUTPUT_PORT_HIGH)
			{
				DDRD = PORT_HIGH;
				PORTD = PORT_HIGH;
			}
			else if(Copy_enuConfigration == INTERNAL_PULLUP)
			{
				DDRD = PORT_LOW;
				PORTD = PORT_HIGH;
			}
			else if(Copy_enuConfigration == EXTERNAL_PULLDOWN)
			{
				DDRD = PORT_LOW;
				PORTD = PORT_LOW;
			}
			break;
		}
	}
	return Ret_enuErrorStatus;	
	
}

MDIO_enuErrorStatus_t MDIO_enuSetPinValue(MDIO_enuPortNum_t Copy_enuPortNum,MDIO_enuPinNum_t Copy_enuPinNum,MDIO_enuPinState_t Copy_enuState)
{
	MDIO_enuErrorStatus_t Ret_enuErrorStatus = MDIO_NOK;
	if(Copy_enuPortNum > MDIO_PORTD)
	{
		Ret_enuErrorStatus = MDIO_INVALID_PORT_NUM;
	}
	else if(Copy_enuPinNum > MDIO_PIN7)
	{
		Ret_enuErrorStatus = MDIO_INVALID_PIN_NUM;
	}
	else if(Copy_enuState > PIN_HIGH)
	{
		Ret_enuErrorStatus = MDIO_INVALID_PIN_STATE;
	}
	else
	{
		Ret_enuErrorStatus = MDIO_OK;
		switch(Copy_enuPortNum)
		{
			case MDIO_PORTA :
				if(Copy_enuState == PIN_LOW)
					CLR_BIT(PORTA,Copy_enuPinNum);
				else if(Copy_enuState == PIN_HIGH)
					SET_BIT(PORTA,Copy_enuPinNum);
			break;
			case MDIO_PORTB :
				if(Copy_enuState == PIN_LOW)
					CLR_BIT(PORTB,Copy_enuPinNum);
				else if(Copy_enuState == PIN_HIGH)
					SET_BIT(PORTB,Copy_enuPinNum);
			break;
			case MDIO_PORTC :
				if(Copy_enuState == PIN_LOW)
					CLR_BIT(PORTC,Copy_enuPinNum);
				else if(Copy_enuState == PIN_HIGH)
					SET_BIT(PORTC,Copy_enuPinNum);
			break;
			case MDIO_PORTD :
				if(Copy_enuState == PIN_LOW)
					CLR_BIT(PORTD,Copy_enuPinNum);
				else if(Copy_enuState == PIN_HIGH)
					SET_BIT(PORTD,Copy_enuPinNum);
			break;
		}
	}
	return Ret_enuErrorStatus;
}
MDIO_enuErrorStatus_t MDIO_enuSetPortValue(MDIO_enuPortNum_t Copy_enuPortNum , MDIO_enuPortState_t Copy_enuPortState)
{
	MDIO_enuErrorStatus_t Ret_enuErrorStatus = MDIO_NOK;
	if(Copy_enuPortNum > MDIO_PORTD)
	{
		Ret_enuErrorStatus = MDIO_INVALID_PORT_NUM;
	}
	else if(Copy_enuPortState > PORT_HIGH)
	{
		Ret_enuErrorStatus = MDIO_INVALID_PORT_STATE;
	}
	else
	{
		Ret_enuErrorStatus = MDIO_OK;
		switch(Copy_enuPortNum)
		{
			case MDIO_PORTA :
				PORTA = Copy_enuPortState;
			break;
			case MDIO_PORTB :
				PORTB = Copy_enuPortState;
			break;
			case MDIO_PORTC :
				PORTC = Copy_enuPortState;
			break;
			case MDIO_PORTD :
				PORTD = Copy_enuPortState;
			break;
		}
	}		
		return Ret_enuErrorStatus;
}

MDIO_enuErrorStatus_t MDIO_enuGetPinValue(MDIO_enuPortNum_t Copy_enuPortNum,MDIO_enuPinNum_t Copy_enuPinNum,u8* Add_pu8PinValue) 
{
	MDIO_enuErrorStatus_t Ret_enuErrorStatus = MDIO_NOK;
	if(Copy_enuPortNum > MDIO_PORTD)
	{
		Ret_enuErrorStatus = MDIO_INVALID_PORT_NUM;
	}
	else if(Copy_enuPinNum > MDIO_PIN7)
	{
		Ret_enuErrorStatus = MDIO_INVALID_PIN_NUM;
	}
	else
	{
		Ret_enuErrorStatus = MDIO_OK;
		switch(Copy_enuPortNum)
		{
			case MDIO_PORTA :
				* Add_pu8PinValue = PINA;
			break;
			case MDIO_PORTB :
				* Add_pu8PinValue = PINB;
			break;
			case MDIO_PORTC :
				* Add_pu8PinValue = PINC;
			break;
			case MDIO_PORTD :
				* Add_pu8PinValue = PIND;
			break;
		}
	}
	return Ret_enuErrorStatus;
}


