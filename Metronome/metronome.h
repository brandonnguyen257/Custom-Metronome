/*
 * metronome.h
 *
 * Created: 6/10/2020 9:38:23 PM
 *  Author: brand
 */ 

#include <avr/io.h>
#include "avr.h"
#include "keypad.h"
#include "lcd.h"
#include "note.h"

#ifndef METRONOME_H_
#define METRONOME_H_


typedef struct Metronome{
	int bpm;			//beats per minute
	int timeSignatureTop;	//timeSignature/4
	int currBeat;		//currentBeat
	int waitTime;		//wait time between each beat
	int displayLED;
	int displayLCD;
	int displaySpeaker;
}Metronome;

extern Metronome currentMetronome;
extern Metronome metronomePresets[];

void init_metronome();

int getWaitTime();

void updateBPM();

void playBeat();

void displayBeatLCD();
void updateMetronome();
void checkInput();

void updateSettings();
void updatePresets();
#endif /* METRONOME_H_ */