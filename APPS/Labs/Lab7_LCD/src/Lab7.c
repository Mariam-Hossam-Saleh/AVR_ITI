// #include <util/delay.h>
#include "MDIO.h"
#include "MPORT.h"
#include "HLCD.h"
#include "HLCD_cfg.h"

/* This Application is testing the LCD driver */

int main(void)
{
    HLCD_enuInit();
    HLCD_enuWriteString("Mariam ",LCD_ONE);
	HLCD_enuGoToRowColumn(HLCD_FIRST_LINE,10,LCD_ONE);
    HLCD_enuWriteNumber(20680,LCD_ONE);

	u8 Battern[8] = {
  		0b00000,
  		0b11111,
  		0b10101,
  		0b11111,
  		0b11111,
  		0b01110,
  		0b01010,
  		0b11011
	};

	u8 Battern1[8] = {
		0b00000,
  		0b00111,
  		0b00101,
  		0b11111,
  		0b00000,
  		0b00000,
  		0b00000,
  		0b00000
	};

	u8 Battern2[8] = {
		0b00000,
  		0b00000,
  		0b00000,
  		0b00001,
  		0b00001,
  		0b00010,
  		0b10100,
  		0b01000
	};

	u8 Battern3[8] = {
  		0b00000,
  		0b00001,
  		0b00001,
  		0b11111,
  		0b00000,
  		0b01010,
  		0b00000,
  		0b00000
	};

	u8 Battern4[8] = {
  		0b00000,
  		0b00111,
  		0b00101,
  		0b11111,
  		0b10000,
  		0b10000,
  		0b10000,
  		0b00000
	};

	HLCD_enuStoreSpecialChar(Battern,0,LCD_ONE);
	HLCD_enuStoreSpecialChar(Battern1,1,LCD_ONE);
	HLCD_enuStoreSpecialChar(Battern2,2,LCD_ONE);
	HLCD_enuStoreSpecialChar(Battern3,3,LCD_ONE);
	HLCD_enuStoreSpecialChar(Battern4,4,LCD_ONE);
	HLCD_enuDisplaySpecialChar(0,HLCD_SECOND_LINE,3,LCD_ONE);
	HLCD_enuDisplaySpecialChar(1,HLCD_SECOND_LINE,10,LCD_ONE);
	HLCD_enuDisplaySpecialChar(2,HLCD_SECOND_LINE,9,LCD_ONE);
	HLCD_enuDisplaySpecialChar(3,HLCD_SECOND_LINE,8,LCD_ONE);
	HLCD_enuDisplaySpecialChar(4,HLCD_SECOND_LINE,7,LCD_ONE);
	

	while (1) 
    {
		
	}
	return 0;
}
