/*
 * DIO.c
 *
 * Created: 4/22/2017 2:29:45 PM
 *  Author: A.Aboelmakarem
 */

#include "DIO.h"

void DIO_WritePortVal(char Port_Num,char Val)
{
	switch(Port_Num)
	{
		case 0:
		PORTA=Val;
		break;

		case 1:
		PORTB=Val;
		break;

		case 2:
		PORTC=Val;
		break;

		case 3:
		PORTD=Val;
		break;

		default:
		break;
	}
}

void DIO_WritePinVal(char Pin_Num, char Val)
{
	char Port_Num = Pin_Num/8;
	char Pin_Index = Pin_Num % 8;
	switch(Port_Num)
	{
		case 0:
		if(Val==0)
		CLR_BIT(PORTA,Pin_Index);
		else
		SET_BIT(PORTA,Pin_Index);
		break;

		case 1:
		if(Val==0)
		CLR_BIT(PORTB,Pin_Index);
		else
		SET_BIT(PORTB,Pin_Index);
		break;

		case 2:
		if(Val==0)
		CLR_BIT(PORTC,Pin_Index);
		else
		SET_BIT(PORTC,Pin_Index);
		break;

		case 3:
		if(Val==0)
		CLR_BIT(PORTD,Pin_Index);
		else
		SET_BIT(PORTD,Pin_Index);
		break;

		default:
		break;
	}
}
char DIO_ReadPort(char Port_Num)
{
	char Value=0;

	switch(Port_Num)
	{
		case 0:
		Value=PINA;
		break;

		case 1:
		Value=PINB;
		break;

		case 2:
		Value=PINC;
		break;

		case 3:
		Value=PIND;
		break;

		default:
		break;
	}

	return Value;
}
char DIO_ReadPin(char Pin_Num)
{
	char value=0;
	char PORT_NUM;
	char PIN_INDEX;

	PORT_NUM=Pin_Num/8;
	PIN_INDEX=Pin_Num%8;

	switch(PORT_NUM)
	{
		case 0:
		value=GET_BIT(PINA,PIN_INDEX);
		break;

		case 1:
		value=GET_BIT(PINB,PIN_INDEX);
		break;

		case 2:
		value=GET_BIT(PINC,PIN_INDEX);
		break;

		case 3:
		value=GET_BIT(PIND,PIN_INDEX);
		break;

		default:
		break;
	}

	return value;
}
void DIO_Init()
{
	DDRA=DDRA_INIT;
	DDRB=DDRB_INIT;
	DDRC=DDRC_INIT;
	DDRD=DDRD_INIT;


	PORTA=PORTA_INIT;
	PORTB=PORTB_INIT;
	PORTC=PORTC_INIT;
	PORTD=PORTD_INIT;

}
