/*
 * Functions.h
 *
 * Created: 21-Aug-18 7:53:29 PM
 *  Author: Haruchika
 */ 


#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_


/*
 * ProtoType.c
 *
 * Created: 21-Aug-18 6:20:23 AM
 *  Author: Haruchika
 */ 

#include <avr/io.h>
#include "DIO.h"
#include "SEG.h"
#include "EXT_INT.h"
#include "Configures.h"
#include "LCD.h"
#include "ADC.h"
#include "PWM.h"
#include "UART.h"
#include <util/delay.h>
#include <stdlib.h>
#define F_CPU 8000000UL
///////////////////////////////////////
char counter=0;
char MStatues;
///////////////////////////////////////
void SoundSystem()
{
	__asm__("SEI");
	EXT_SetINT0(Inc_Segment);
	__asm__("CLI");
	if (DIO_ReadPin(PUSHB2)==1)
	{
		Dec_Segment();
		while(DIO_ReadPin(PUSHB2)==1)
		{
		}
	}
	SEG_Write(counter);
	return;
}
void Inc_Segment()
{
	if(counter==9)
	{
		DIO_WritePinVal(BUZZER,1);
		_delay_ms(50);
		DIO_WritePinVal(BUZZER,0);
	}
	else
	{
		counter++;
	}
}
void Dec_Segment()
{
	if(counter==0)
	{
		DIO_WritePinVal(BUZZER,1);
		_delay_ms(50);
		DIO_WritePinVal(BUZZER,0);
	}
	else
	{
		counter--;
	}
}
char FireAlarm()
{
	ADC_Init();
	char Temperature,value,str[5];
	//value=DIO_ReadPin(TEMP);
	ADC_Convert(TEMP,&value);
	Temperature = (5*value*100/255); 
	if(Temperature>=60)
	{
		DIO_WritePinVal(LED1,ENABLE);
		DIO_WritePinVal(LED2,DISABLE);
		DIO_WritePinVal(Motor_B,0);
		DIO_WritePinVal(Motor_F,0);
		MStatues=0;
		return 0;
	}
	else
	{
		
		LCD_GoToxy(0,0);
		LCD_WriteString("Temp= ");
		itoa(Temperature,str,10);
		LCD_WriteString(str);
		DIO_WritePinVal(LED1,DISABLE);
		return 1;
	}
}
void LightSystem()
{
	ADC_Init();
	char Intensity;
	//Intensity=DIO_ReadPin(Light);
	ADC_Convert(Light,&Intensity);
	PWM_SetDutyCycle(Intensity);
	DIO_WritePinVal(BUZZER,DISABLE);
	return;
}
char Curtain_System()
{
	char Symbol,Recieve;
	//Symbol=1;
	//UART_Transmit(Symbol);
	UART_Receive(&Recieve);
	if(Recieve==1)
	{
		MStatues=1;
		DIO_WritePinVal(Motor_F,1);
		DIO_WritePinVal(Motor_B,0);
		return MStatues;
	}
	else if(Recieve==2)
	{
		MStatues=2;
		DIO_WritePinVal(Motor_B,1);
		DIO_WritePinVal(Motor_F,0);
		return MStatues;
	}
	else if(Recieve==3)
	{
		MStatues=3;
		DIO_WritePinVal(Motor_B,0);
		DIO_WritePinVal(Motor_F,0);
		return MStatues;
	}
	else
	{
		return MStatues;
	}
}
//Watch Dog Configure
////////////////////////////////////
void Watch_DogConf()
{
	DDRD=DDRD_WDT;
	WDTCR=WDTCR_WDT;
}
/////////////////////////////////////


#endif /* FUNCTIONS_H_ */