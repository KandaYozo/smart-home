/*
 * PWM.h
 *
 * Created: 6/15/2017 8:10:53 PM
 *  Author: A.Aboelmakarem
 */ 

#ifndef PWM_H_
#define PWM_H_

////////////////prototyping/////////////////
void PWM_SetDutyCycle(char val) ;
void PWM_Init() ;
///////////////// configuration////////////////
#define TCCR2_INIT 0b01101101
#define TIMSK_INIT 0b00000000




#endif /* PWM_H_ */