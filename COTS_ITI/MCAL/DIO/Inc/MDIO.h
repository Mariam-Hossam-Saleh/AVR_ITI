/*
 * MDIO.h
 * Created: 12/17/2024
 * Author : Mariam Hossam
 */ 
#ifndef MDIO_H_
#define MDIO_H_

typedef unsigned char u8;
typedef unsigned short int u16;

typedef enum
{
	MDIO_OK,
	MDIO_NOK,
	MDIO_INVALID_PORT_NUM,
	MDIO_INVALID_PIN_NUM,
	MDIO_INVALID_PORT_CFG,
	MDIO_INVALID_PIN_CFG,
	MDIO_INVALID_PORT_STATE,
	MDIO_INVALID_PIN_STATE
	
}MDIO_enuErrorStatus_t ;

typedef enum
{
	MDIO_PORTA,
	MDIO_PORTB,
	MDIO_PORTC,
	MDIO_PORTD
	
}MDIO_enuPortNum_t ;

typedef enum
{
	MDIO_PIN0,
	MDIO_PIN1,
	MDIO_PIN2,
	MDIO_PIN3,
	MDIO_PIN4,
	MDIO_PIN5,
	MDIO_PIN6,
	MDIO_PIN7
	
}MDIO_enuPinNum_t ;

typedef enum
{
	OUTPUT_LOW,
	OUTPUT_HIGH,
	INTERNAL_PULLUP,
	EXTERNAL_PULLDOWN
	
}MDIO_enuPinCfg_t ;

typedef enum
{
	OUTPUT_PORT_LOW,
	OUTPUT_PORT_HIGH,
	INTERNAL_PORT_PULLUP,
	EXTERNAL_PORT_PULLDOWN
	
}MDIO_enuPortCfg_t ;

typedef enum
{
	PIN_LOW = 0,
	PIN_HIGH = 1
	
}MDIO_enuPinState_t ;

typedef enum
{
	PORT_LOW = 0x00,
	PORT_HIGH = 0xff
	
}MDIO_enuPortState_t ;

MDIO_enuErrorStatus_t MDIO_enuSetPinConfigration(MDIO_enuPortNum_t Copy_enuPortNum,MDIO_enuPinNum_t Copy_enuPinNum,MDIO_enuPinCfg_t Copy_enuConfigration);

MDIO_enuErrorStatus_t MDIO_enuSetPortConfigration(MDIO_enuPortNum_t Copy_enuPortNum,MDIO_enuPortCfg_t Copy_enuConfigration);

MDIO_enuErrorStatus_t MDIO_enuSetPinValue(MDIO_enuPortNum_t Copy_enuPortNum,MDIO_enuPinNum_t Copy_enuPinNum,MDIO_enuPinState_t Copy_enuState);

MDIO_enuErrorStatus_t MDIO_enuSetPortValue(MDIO_enuPortNum_t Copy_enuPortNum,u8 Copy_enuPortState);

MDIO_enuErrorStatus_t MDIO_enuGetPortValue(MDIO_enuPortNum_t Copy_enuPortNum,u8* Add_pu8PinValue) ;

MDIO_enuErrorStatus_t MDIO_enuGetPinValue(MDIO_enuPortNum_t Copy_enuPortNum,MDIO_enuPinNum_t Copy_enuPinNum,u8* Add_pu8PinValue);



#endif //MDIO_H_

