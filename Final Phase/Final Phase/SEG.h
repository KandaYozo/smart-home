/*
 * SEG.h
 *
 * Created: 4/25/2017 2:17:51 AM
 *  Author: A.Aboelmakarem
 */ 
#include <avr/io.h>
#include "DIO.h"
#include "common.h"

/*************Prototypes********************/
void SEG_Write(char val);
void SEG1_Display(char val);
void SEG2_Display(char val);
void SEG_Init(void);




/*************Configuration****************/
#define BCD_DECODER
#define SEG1_EN  18
#define SEG2_EN  19
#define  ENABLE  1
#define  DISABLE 0
#define ON 1
#define OFF 0

#ifndef BCD_DECODER

#define SEG_PORT 3
#define ZERO   0b00111111
#define ONE    0b00000110
#define TWO    0b01011011
#define THREE  0b01001111
#define FOUR   0b01100110
#define FIVE   0b01101101
#define SIX    0b01111101
#define SEVEN  0b00000111
#define EIGHT  0b01111111
#define NINE   0b01101111

#else 

#define PINSEG_A 20
#define PINSEG_B 21
#define PINSEG_C 22
#define PINSEG_D 23

#endif

