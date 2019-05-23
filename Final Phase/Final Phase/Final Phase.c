/*
 * Final_Phase.c
 *
 * Created: 21-Aug-18 7:52:36 PM
 *  Author: Haruchika
 */ 

#include <avr/io.h>
#include <avr/wdt.h>
#include "Functions.h"
int main(void)
{
	DIO_Init();
	SEG_Init();
	EXT_Init();
	ADC_Init();
	LCD_init();
	PWM_Init();
	UART_Init();
	/////////////////////////////////////
	SEG1_Display(ENABLE);
	SEG2_Display(ENABLE);
	Watch_DogConf();
	/////////////////////////////////////
	char FResult;
	char CResult;
	/////////////////////////////////////
    while(1)
    {
		LCD_GoToxy(0,1);
		LCD_WriteString("ssad");
		LCD_ClrScr();
		FResult=FireAlarm();
		if(FResult==1)
		{
			CResult=Curtain_System();
			if(CResult==1)
			{
				LCD_GoToxy(0,1);
				LCD_WriteString("Motor F");
			}
			else if(CResult==2)
			{
				LCD_GoToxy(0,1);
				LCD_WriteString("Motor B");
			}
			else if(CResult==3)
			{
				LCD_GoToxy(0,1);
				LCD_WriteString("Motor S");
			}
			else
			{
				LCD_GoToxy(0,1);
				LCD_WriteString("Motor S");

			}			
			_delay_ms(100);
			LCD_ClrScr();
			SoundSystem();
			LightSystem();
		}	
		else
		{
			LCD_ClrScr();
			LCD_GoToxy(0,0);
			LCD_WriteString("The System Is");
			LCD_GoToxy(2,1);
			LCD_WriteString("Stopped");
			_delay_ms(100);
		}
		wdt_reset();				 
    }
}