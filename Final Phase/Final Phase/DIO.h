/*
 * DIO.h
 *
 * Created: 4/22/2017 2:30:13 PM
 *  Author: A.Aboelmakarem
 */ 

#include <avr/io.h>
#include "common.h"

void DIO_WritePortVal(char Port_Num,char Val);
void DIO_WritePinVal(char Pin_Num, char Val);
void DIO_Init();
char DIO_ReadPort(char Port_Num);
char DIO_ReadPin(char Pin_Num);

/**********************Configuration****************/
#define DDRA_INIT    0b11110000	
#define DDRB_INIT    0b00001110
#define DDRC_INIT    0b11111100
#define DDRD_INIT    0b11111010

#define PORTA_INIT   0b00000000
#define PORTB_INIT   0b00000000
#define PORTC_INIT   0b00000000
#define PORTD_INIT   0b00000000



