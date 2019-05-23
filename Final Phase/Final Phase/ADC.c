/*
 * ADC.c
 *
 * Created: 5/8/2017 1:29:58 AM
 *  Author: A.Aboelmakarem
 */ 


#include <avr/io.h>
#include "ADC.h"
#include "common.h"
#include "DIO.h"
void ADC_Init(void){
	ADMUX=ADC_ADMUX_INITVAL;  
	ADCSRA=ADC_ADCSR_INITVAL; 
	
}


void ADC_Convert(char channel_num,int *ptr){
	int high;
	ADMUX =ADMUX|channel_num;
    SET_BIT(ADCSRA,6);
	while (GET_BIT(ADCSRA,6) )
	{
	}
	
		*ptr = ADCL;
		high=(int)ADCH<<8;
		*ptr|=high;
  		
	
}


