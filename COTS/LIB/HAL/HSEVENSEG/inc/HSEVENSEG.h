/*
 * HSEVENSEG.h
 * 
 * Created: 06/01/2025
 * Author: Mariam Hossam
 */ 

#ifndef HSEVENSEG_H_
#define HSEVENSEG_H_

#define F_CPU 8000000UL

#include "MDIO.h"
#include "MPORT.h"
#include "HSEVENSEG_Cfg.h"
#include <util/delay.h>

#define HSEVENSEG_PIN_A   0
#define HSEVENSEG_PIN_B   1
#define HSEVENSEG_PIN_C   2
#define HSEVENSEG_PIN_D   3
#define HSEVENSEG_PIN_E   4
#define HSEVENSEG_PIN_F   5
#define HSEVENSEG_PIN_G   6
#define HSEVENSEG_PIN_DP  7


typedef enum
{
    HSEVENSEG_ZERO  = 0x3F,
    HSEVENSEG_ONE   = 0x06, 
    HSEVENSEG_TWO   = 0x5B,
    HSEVENSEG_THREE = 0x4F,
    HSEVENSEG_FOUR  = 0x66,
    HSEVENSEG_FIVE  = 0x6D,
    HSEVENSEG_SIX   = 0x7D,
    HSEVENSEG_SEVEN = 0x07,
    HSEVENSEG_EIGHT = 0x7F,
    HSEVENSEG_NINE  = 0x6F,
    HSEVENSEG_DP    = 0x80
    
} HSEVENSEG_enuSevenSegMapping_t;


typedef enum
{
    HSEVENSEG_OK,
    HSEVENSEG_NOK,
    HSEVENSEG_INVALID_CONNECTION,
    HSEVENSEG_INVALID_NUMBER_OF_SEVENSEG,
    HSEVENSEG_INVALID_NUMBER

} HSEVENSEG_enuErrorStatus_t;

typedef enum
{
    HSEVENSEG_COMMON_CATHODE = 0,
    HSEVENSEG_COMMON_ANODE

} HSEVENSEG_enuConnectionOpt_t;


typedef struct
{
    MPORT_enuPORT_PIN_t  HSEVENSEG_strPinNumArr[NUMBER_OF_SEVENSEG_PINS];  
    HSEVENSEG_enuConnectionOpt_t HSEVENSEG_Connection;

} HSEVENSEG_strCfg_t;

/*************************************************************************************
 * void HSEVENSEG_vInit(void);
 * Purpose:
 * The HSEVENSEG_vInit function is responsible for initializing and configuring the
 * pins of seven-segment displays based on the provided configuration.
 * Parameters:
 *             void
 * Return:
 *         void
 *************************************************************************************/
//void anything(void);
void HSEVENSEG_vInit(void);

/*************************************************************************************
 void HSEVENSEG_vSetValue(u8 Copy_enuSevenSegNum , u8 Copy_u8Value);

Purpose :
    HSEVENSEG_enuSetValue function is responsible for configuring a 7-segment display to show a specific value (0-9) 
on a particular segment module identified by Copy_enuSevenSegNum

Parmeters:

   Copy_enuSevenSegNum:
        Specifies which seven-segment display you want to control.

           Example:

           HSEVENSEG_SevenSegNum1 = 0 (First display)
           HSEVENSEG_SevenSegNum2 = 1 (Second display)
           .
           .

   Copy_u8Value:
 *  The value you want to display on the specified seven-segment display.
 *  Commonly, this parameter is expected to be a digit (0-9) because seven-segment displays typically represent single digits.
 * Return:
 *        void
 *************************************************************************************/

HSEVENSEG_enuErrorStatus_t HSEVENSEG_enuSetValue(u8 Copy_enuSevenSegNum , u8 Copy_u8Value);

/*************************************************************************************************************************************************
HSEVENSEG_enuErrorStatus_t HSEVENSEG_enuSetMultiDigitValue(u16 Copy_u16Value);

Purpose :
    The function HSEVENSEG_enuSetMultiDigitValue is used to display a multi-digit number (Copy_u16Value) across multiple seven-segment displays, 
depending on how many are configured (up to 4 in this case).

Parameters:

     Copy_u16Value :

        Description: This is the number to be displayed on the seven-segment displays.

        Expected Range:
            The range of valid input depends on the number of configured seven-segment displays:
                1 segment :  Valid values are  0-9.
                2 segments:  Valid values are  0-99.
                3 segments:  Valid values are  0-999.
                4 segments:  Valid values are  0-9999.


Return Type:
    HSEVENSEG_enuErrorStatus_t:
        An enumerated type that represents the status of the operation.
        Possible values:
            HSEVENSEG_enuSevenSegLimitError: Indicates that the input number exceeds the range supported by the number of configured seven-segment displays.
            .
            .
            .
Example : 
  HSEVENSEG_enuSetMultiDigitValue(4078);;
**************************************************************************************************************************************************************/
HSEVENSEG_enuErrorStatus_t HSEVENSEG_enuSetMultiDigitValue(u16 Copy_u16Value);

#endif /* HSEVENSEG_H_ */