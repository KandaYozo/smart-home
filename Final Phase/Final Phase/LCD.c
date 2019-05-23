/*
 * LCD.c
 *
 * Created: 10/20/2016 6:13:23 PM
 *  Author: m.mamdooh
 */ 

#include "LCD.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include "DIO.h"
#include "common.h"
#define DIO_u8HIGH 1 
#define DIO_u8LOW  0
void LCD_WriteString(char*str)
{
	while(*str)
	{
		LCD_WriteData(*str);
		str++;
	}
}
void LCD_WriteData(unsigned char data ){

	DIO_WritePinVal(LCD_RSPin, DIO_u8HIGH);
	DIO_WritePinVal(LCD_RWPin, DIO_u8LOW);

	DIO_WritePinVal(LCD_d7Pin,GET_BIT(data,7));
	DIO_WritePinVal(LCD_d6Pin,GET_BIT(data,6));
	DIO_WritePinVal(LCD_d5Pin,GET_BIT(data,5));
	DIO_WritePinVal(LCD_d4Pin,GET_BIT(data,4));
	
	DIO_WritePinVal(LCD_ENPin, DIO_u8HIGH);
	_delay_us(5);
	DIO_WritePinVal(LCD_ENPin, DIO_u8LOW);



	_delay_us(100);
	
	DIO_WritePinVal(LCD_d7Pin,GET_BIT(data,3));
	DIO_WritePinVal(LCD_d6Pin,GET_BIT(data,2));
	DIO_WritePinVal(LCD_d5Pin,GET_BIT(data,1));
	DIO_WritePinVal(LCD_d4Pin,GET_BIT(data,0));
	
	DIO_WritePinVal(LCD_ENPin, DIO_u8HIGH);
	_delay_us(5);
	DIO_WritePinVal(LCD_ENPin, DIO_u8LOW);
	_delay_us(100);
}
void LCD_WriteCommand(unsigned char command ){

	DIO_WritePinVal(LCD_RSPin, DIO_u8LOW);
	DIO_WritePinVal(LCD_RWPin, DIO_u8LOW);

	DIO_WritePinVal(LCD_d7Pin,GET_BIT(command,7));
	DIO_WritePinVal(LCD_d6Pin,GET_BIT(command,6));
	DIO_WritePinVal(LCD_d5Pin,GET_BIT(command,5));
	DIO_WritePinVal(LCD_d4Pin,GET_BIT(command,4));

	DIO_WritePinVal(LCD_ENPin, DIO_u8HIGH);
	_delay_us(5);
	DIO_WritePinVal(LCD_ENPin, DIO_u8LOW);

	//DIO_WritePinVal(LCD_d7Pin,GET_BIT(command,3));
	//DIO_WritePinVal(LCD_d6Pin,GET_BIT(command,2));
	//DIO_WritePinVal(LCD_d5Pin,GET_BIT(command,1));
	//DIO_WritePinVal(LCD_d4Pin,GET_BIT(command,0));

	DIO_WritePortVal(0,(command<<4));

	DIO_WritePinVal(LCD_ENPin, DIO_u8HIGH);
	_delay_us(5);
	DIO_WritePinVal(LCD_ENPin, DIO_u8LOW);
	_delay_us(100);
}
void LCD_GoToxy(unsigned char x,unsigned char y)
{
	if(y==0)
	{
		if(x<16)
		
			LCD_WriteCommand(0x80+x);
	}
	else if (y==1)
	{
		if(x<16)
		
		LCD_WriteCommand(0xC0+x);
	}
}

void LCD_ClrScr()
{
	LCD_WriteCommand(LCD_CLRDISP);
	_delay_ms(2);
}
void LCD_init(){

	_delay_ms(15);
	//LCD_WriteCommand(0x30);
	LCD_WriteCommand(0x32);
	LCD_WriteCommand(0x28);
	LCD_WriteCommand(0x0C);
	LCD_WriteCommand(0x01);
	_delay_us(2000);
	LCD_WriteCommand(0x06);
	_delay_ms(1000);
}
