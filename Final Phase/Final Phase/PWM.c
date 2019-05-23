/*
 * PWM.c
 *
 * Created: 6/15/2017 8:10:53 PM
 *  Author: A.Aboelmakarem
 */ 
#include <avr/io.h>
#include "PWM.h"


void PWM_Init()
{
	TCCR2=TCCR2_INIT ;
}

void PWM_SetDutyCycle(char val) 
{
	
	OCR2 = (val*255)/100 ; ;
}