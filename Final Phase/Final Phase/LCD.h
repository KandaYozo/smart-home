/*
 * LCD.h
 *
 * Created: 10/20/2016 6:14:18 PM
 *  Author: m.mamdooh
 */ 


#ifndef LCD_H_
#define LCD_H_

#define LCD_CLRDISP    0x01

////////////////////////////////////////////////////////
////////// prototypes /////////////////////////////////
//////////////////////////////////////////////////////
void LCD_WriteCommand(unsigned char command ) ;
void LCD_init() ;
void LCD_WriteString(char *str);
void LCD_WriteData(unsigned char data );
void LCD_GoToxy(unsigned char x,unsigned char y);
void LCD_ClrScr();
//////////////////////////////////////////////////////
//////////////// Configuration //////////////////////
////////////////////////////////////////////////////
#define LCD_RSPin 	9
#define LCD_RWPin   10
#define LCD_ENPin 	11

#define LCD_d7Pin  7
#define LCD_d6Pin  6
#define LCD_d5Pin  5
#define LCD_d4Pin  4



#endif /* LCD_H_ */