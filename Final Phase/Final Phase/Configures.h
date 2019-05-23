/*
 * Configures.h
 *
 * Created: 21-Aug-18 6:22:30 AM
 *  Author: Haruchika
 */ 


#ifndef CONFIGURES_H_
#define CONFIGURES_H_

void SoundSystem();
void Inc_Segment();
void Dec_Segment();
char FireAlarm();
void LightSystem();
void Watch_DogConf();
char Curtain_System();

#define LED1 30
#define LED2 31
#define BUZZER 28
#define PUSHB1 26
#define PUSHB2 13
#define TEMP 0
#define Light 1
#define Motor_F 27
#define Motor_B 29

///////////////////////////////////////////
//Watch Dog Part
//////////////////////////////////////////
#define DDRD_WDT 0xff
#define WDTCR_WDT 0x0f

#endif /* CONFIGURES_H_ */