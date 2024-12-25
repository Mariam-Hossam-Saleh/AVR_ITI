/*
 * Task1.c
 * Created: 12/17/2024
 * Author : Mariam Hossam
 */ 

#include "../Inc/MDIO.h"
#include "../../../LIB/BIT_MATH.h"


MDIO_enuPinCfg_t MDIO_enuPinCfgArray[MDIO_NUM_OF_PORTS * MDIO_NUM_OF_PINS];

typedef struct  
{
	u8 PIN;
	u8 DDR;
	u8 PORT;
}MDIO_strPortReg_t;

#define MDIO_PORT_REG_BASE_ADD ((volatile MDIO_strPortReg_t*)(0x39))

#define MDIO_GET_PORT_ADD(PORT_NUM) (MDIO_strPortReg_t *)(MDIO_PORT_REG_BASE_ADD) - (PORT_NUM)

MDIO_enuErrorStatus_t MDIO_enuSetPinConfigration(MDIO_enuPortNum_t Copy_enuPortNum,MDIO_enuPinNum_t Copy_enuPinNum,MDIO_enuPinCfg_t Copy_enuConfigration)
{
	MDIO_strPortReg_t * Loc_strPortAdd = MDIO_GET_PORT_ADD(Copy_enuPortNum);
	MDIO_enuErrorStatus_t Ret_enuErrorStatus = MDIO_NOK;
	if(Copy_enuPortNum > MDIO_PORTD)
	{
		Ret_enuErrorStatus = MDIO_INVALID_PORT_NUM;
	}
	else if(Copy_enuPinNum > MDIO_PIN7)
	{
		Ret_enuErrorStatus = MDIO_INVALID_PIN_NUM;
	}
	else if(Copy_enuConfigration > MDIO_EXTERNAL_PULLDOWN)
	{
		Ret_enuErrorStatus = MDIO_INVALID_PIN_CFG;
	}
	else
	{
		Ret_enuErrorStatus = MDIO_OK;
		if(Copy_enuConfigration == MDIO_OUTPUT_LOW)
		{
			SET_BIT(Loc_strPortAdd->DDR,Copy_enuPinNum);
			CLR_BIT(Loc_strPortAdd->PORT,Copy_enuPinNum);
		}
		else if(Copy_enuConfigration == MDIO_OUTPUT_HIGH)
		{
			SET_BIT(Loc_strPortAdd->DDR,Copy_enuPinNum);
			SET_BIT(Loc_strPortAdd->PORT,Copy_enuPinNum);
		}
		else if(Copy_enuConfigration == MDIO_INTERNAL_PULLUP)
		{
			CLR_BIT(Loc_strPortAdd->DDR,Copy_enuPinNum);
			SET_BIT(Loc_strPortAdd->PORT,Copy_enuPinNum);
		}
		else if(Copy_enuConfigration == MDIO_EXTERNAL_PULLDOWN)
		{
			CLR_BIT(Loc_strPortAdd->DDR,Copy_enuPinNum);
			CLR_BIT(Loc_strPortAdd->PORT,Copy_enuPinNum);
		}
	}
	return Ret_enuErrorStatus;	
}

MDIO_enuErrorStatus_t MDIO_enuSetPortConfigration(MDIO_enuPortNum_t Copy_enuPortNum,MDIO_enuPortCfg_t Copy_enuConfigration)
{
	MDIO_strPortReg_t * Loc_strPortAdd = MDIO_GET_PORT_ADD(Copy_enuPortNum);
	MDIO_enuErrorStatus_t Ret_enuErrorStatus = MDIO_NOK;
	if(Copy_enuPortNum > MDIO_PORTD)
	{
		Ret_enuErrorStatus = MDIO_INVALID_PORT_NUM;
	}
	else if(Copy_enuConfigration > MDIO_EXTERNAL_PORT_PULLDOWN)
	{
		Ret_enuErrorStatus = MDIO_INVALID_PORT_CFG;
	}
	else
	{
		Ret_enuErrorStatus = MDIO_OK;
		if(Copy_enuConfigration == MDIO_OUTPUT_PORT_LOW)
		{
			Loc_strPortAdd->DDR = MDIO_PORT_HIGH;
			Loc_strPortAdd->PORT = MDIO_PORT_LOW;
		}
		else if(Copy_enuConfigration == MDIO_OUTPUT_PORT_HIGH)
		{
			Loc_strPortAdd->DDR = MDIO_PORT_HIGH;
			Loc_strPortAdd->PORT = MDIO_PORT_HIGH;
		}
		else if(Copy_enuConfigration == MDIO_INTERNAL_PORT_PULLUP)
		{
			Loc_strPortAdd->DDR = MDIO_PORT_LOW;
			Loc_strPortAdd->PORT = MDIO_PORT_HIGH;
		}
		else if(Copy_enuConfigration == MDIO_EXTERNAL_PORT_PULLDOWN)
		{
			Loc_strPortAdd->DDR = MDIO_PORT_LOW;
			Loc_strPortAdd->PORT = MDIO_PORT_LOW;
		}
	}
	return Ret_enuErrorStatus;		
}

MDIO_enuErrorStatus_t MDIO_enuSetPinValue(MDIO_enuPortNum_t Copy_enuPortNum,MDIO_enuPinNum_t Copy_enuPinNum,MDIO_enuPinState_t Copy_enuState)
{
	MDIO_strPortReg_t * Loc_strPortAdd = MDIO_GET_PORT_ADD(Copy_enuPortNum);
	MDIO_enuErrorStatus_t Ret_enuErrorStatus = MDIO_NOK;
	if(Copy_enuPortNum > MDIO_PORTD)
	{
		Ret_enuErrorStatus = MDIO_INVALID_PORT_NUM;
	}
	else if(Copy_enuPinNum > MDIO_PIN7)
	{
		Ret_enuErrorStatus = MDIO_INVALID_PIN_NUM;
	}
	else if(Copy_enuState > MDIO_PIN_HIGH)
	{
		Ret_enuErrorStatus = MDIO_INVALID_PIN_STATE;
	}
	else
	{
		Ret_enuErrorStatus = MDIO_OK;
		if(Copy_enuState == MDIO_PIN_LOW)
		{
			CLR_BIT(Loc_strPortAdd->PORT,Copy_enuPinNum);
		}
		else if(Copy_enuState == MDIO_PIN_HIGH)
		{
			SET_BIT(Loc_strPortAdd->PORT,Copy_enuPinNum);
		}
	}
	return Ret_enuErrorStatus;
}

MDIO_enuErrorStatus_t MDIO_enuSetPortValue(MDIO_enuPortNum_t Copy_enuPortNum , u8 Copy_enuPortState)
{
	MDIO_strPortReg_t * Loc_strPortAdd = MDIO_GET_PORT_ADD(Copy_enuPortNum);
	MDIO_enuErrorStatus_t Ret_enuErrorStatus = MDIO_NOK;
	if(Copy_enuPortNum > MDIO_PORTD)
	{
		Ret_enuErrorStatus = MDIO_INVALID_PORT_NUM;
	}
	else if(Copy_enuPortState > MDIO_PORT_HIGH)
	{
		Ret_enuErrorStatus = MDIO_INVALID_PORT_STATE;
	}
	else
	{
		Ret_enuErrorStatus = MDIO_OK;
		Loc_strPortAdd->PORT = (Copy_enuPortState & Loc_strPortAdd->DDR);
	}		
	return Ret_enuErrorStatus;
}

MDIO_enuErrorStatus_t MDIO_enuGetPortValue(MDIO_enuPortNum_t Copy_enuPortNum,u8* Add_pu8PinValue) 
{
	MDIO_strPortReg_t * Loc_strPortAdd = MDIO_GET_PORT_ADD(Copy_enuPortNum);
	MDIO_enuErrorStatus_t Ret_enuErrorStatus = MDIO_NOK;
	if(Copy_enuPortNum > MDIO_PORTD)
	{
		Ret_enuErrorStatus = MDIO_INVALID_PORT_NUM;
	}
	else if(Add_pu8PinValue == NULL_PTR)
	{
		Ret_enuErrorStatus = MDIO_NULL_POINTER;
	}
	else
	{	
		Ret_enuErrorStatus = MDIO_OK;
		* Add_pu8PinValue = Loc_strPortAdd->PIN;
	}
	return Ret_enuErrorStatus;
}

MDIO_enuErrorStatus_t MDIO_enuGetPinValue(MDIO_enuPortNum_t Copy_enuPortNum,MDIO_enuPinNum_t Copy_enuPinNum,u8* Add_pu8PinValue)
{
	MDIO_strPortReg_t * Loc_strPortAdd = MDIO_GET_PORT_ADD(Copy_enuPortNum);
	MDIO_enuErrorStatus_t Ret_enuErrorStatus = MDIO_NOK;
	if(Copy_enuPortNum > MDIO_PORTD)
	{
		Ret_enuErrorStatus = MDIO_INVALID_PORT_NUM;
	}
	else if(Copy_enuPinNum > MDIO_PIN7)
	{
		Ret_enuErrorStatus = MDIO_INVALID_PIN_NUM;
	}
	else if(Add_pu8PinValue == NULL_PTR)
	{
		Ret_enuErrorStatus = MDIO_NULL_POINTER;
	}
	else
	{
		Ret_enuErrorStatus = MDIO_OK;
		* Add_pu8PinValue = GET_BIT(Loc_strPortAdd->PIN,Copy_enuPinNum);
	}
	return Ret_enuErrorStatus;
}


void MDIO_vInit(void)
{
	MDIO_enuPortNum_t Loc_enuCurrentPort = MDIO_PORTA;           // int value ????
	MDIO_enuPinNum_t Loc_enuCurrentPin = MDIO_PIN0;              // int value ????
	for(u8 itration = 0 ; itration < (MDIO_NUM_OF_PORTS * MDIO_NUM_OF_PINS) ; itration++)
	{
		Loc_enuCurrentPort = itration / MDIO_NUM_OF_PINS;
		Loc_enuCurrentPin = itration % MDIO_NUM_OF_PINS;
		MDIO_enuSetPinConfigration(Loc_enuCurrentPort,Loc_enuCurrentPin,MDIO_enuPinCfgArray[itration]);
	}
	
}