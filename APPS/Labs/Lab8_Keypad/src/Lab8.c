// #include <util/delay.h>
#include "MDIO.h"
#include "MPORT.h"
#include "HKEYPAD.h"
#include "HKEYPAD_cfg.h"
#include "HLCD.h"
#include "HLCD_cfg.h"

/* This Application is testing the Keypad driver */
u8 Column=0,Row=0;
void Clear_LCD(void);
void Shift_Cursor_Right(void);
void Shift_Cursor_Left(void);
void Shift_Cursor_Up(void);
void Shift_Cursor_Down(void);
void WriteMyName(void);


//     {'7', '8', '9', '/'},   
//     {'4', '5', '6', '*'},   
//     {'1', '2', '3', '-'},   
//     {'C', '0', '=', '+'}    

int main(void)
{
	HLCD_enuInit();
    HKEYPAD_enuInit();
	u8 KeyValue= 0xFF;
	while(1) 
    {
		HKEYPAD_enuGetPressedKey(&KeyValue,KEYPAD_ONE);
		switch(KeyValue)
		{
			case 'C':
				Clear_LCD();
			break;
			case '+':
				Shift_Cursor_Right();
			break;
			case '-':
				Shift_Cursor_Left();
			break;
			case '*':
				Shift_Cursor_Up();
			break;
			case '/':
				 Shift_Cursor_Down();
			break;
			case '=':
				WriteMyName();
			break;
			default :
				/* Do Nothing */
			break;	
		}
	}
	return 0;
}

void Clear_LCD(void)
{
	HLCD_enuWriteCommand(CLEAR_DISPLAY,LCD_ONE);
}

void Shift_Cursor_Right(void)
{
	if(Column == 15)
	{
		Column = 0;
	}
	else
	{
		Column++;
	}
	HLCD_enuGoToRowColumn(Row,Column,LCD_ONE);
}

void Shift_Cursor_Left(void)
{
	if(Column == 0)
	{
		Column = 15;
	}
	else
	{
		Column--;
	}
	HLCD_enuGoToRowColumn(Row,Column,LCD_ONE);
}

void Shift_Cursor_Up(void)
{
	if(Row == 0)
	{
		Row = 1;
	}
	else
	{
		Row = 0;
	}
	HLCD_enuGoToRowColumn(Row,Column,LCD_ONE);
}

void Shift_Cursor_Down(void)
{
	if(Row == 0)
	{
		Row = 1;
	}
	else
	{
		Row = 0;
	}
	HLCD_enuGoToRowColumn(Row,Column,LCD_ONE);
}

void WriteMyName(void)
{
	HLCD_enuWriteString("Mariam",LCD_ONE);
}
