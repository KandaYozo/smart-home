/*
 * EXT_INT.h
 *
 * Created: 18/05/2017 8:57:21 PM
 *  Author: A.Aboelmakarem
 */ 


#ifndef EXT_INT_H_
#define EXT_INT_H_

////////////////prototyping/////////////////

void EXT_SetINT0(void (*ptr0)(void));
void EXT_SetINT1(void (*ptr1)(void));
void EXT_SetINT2(void (*ptr2)(void));
void EXT_Init();
////////////////prototyping/////////////////
#define MCUCR_INIT  0b00001010
#define MCUCSR_INIT 0b01000000
#define GICR_INIT   0b01000000




#endif /* EXT_INT_H_ */