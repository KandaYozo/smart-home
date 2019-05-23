/*
 * EXT_INT.c
 *
 * Created: 18/05/2017 8:57:21 PM
 *  Author: A.Aboelmakarem
 */
#define F_CPU 800000UL 
#include <util/delay.h>
#include <avr/interrupt.h>
#include "EXT_INT.h"
#include "DIO.h"


void(*PtrIsr0)();

void EXT_Init()
{
MCUCR|= MCUCR_INIT ;  
MCUCSR|=MCUCSR_INIT  ;
GICR|=GICR_INIT   ;
}
void EXT_SetINT0(void (*ptr0)(void))
{
	PtrIsr0=ptr0;
}
ISR(INT0_vect)
{
	PtrIsr0();
		/*DIO_WritePinVal(31,1);
		DIO_WritePinVal(30,1);
		DIO_WritePinVal(29,1);
		_delay_ms(1000);
		DIO_WritePinVal(31,0);
		DIO_WritePinVal(30,0);
		DIO_WritePinVal(29,0);
		_delay_ms(1000);
		LCD_WriteString("Don't Interrupt ");
		LCD_GoToxy(0,1);
		LCD_WriteString("me Again Please");
        _delay_ms(5000);
		LCD_ClrScr();*/
	
	
}