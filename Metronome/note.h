/*
 * IncFile1.h
 *
 * Created: 5/16/2020 10:01:23 PM
 *  Author: brand
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_

#include "avr.h"
#include "lcd.h"
#include "keypad.h"
#include<stdio.h>
#include<stdlib.h>

//wait resolution to convert from
#define WAIT_RES 0.00005

//#define Notes

#define llGs 240

#define lA 227
#define lAs 215
#define lB 202
#define lC 191
#define lCs 180
#define lD 170
#define lDs 161
#define lE 152
#define lF 143
#define lFs 135
#define lG 128
#define lGs 120

#define A 114
#define As 107
#define B 101
#define C 96
#define Cs 90
#define D 85
#define Ds 80
#define E 76
#define F 72
#define Fs 68
#define G 64
#define Gs 60

#define hA 57
#define hAs 54
#define hB 51
#define hC 48
#define hCs 45
#define hD 43
#define hDs 40
#define hE 38
#define hF 36
#define hFs 34
#define hG 32
#define hGs 30

#define hhB 26

//#define Lengths
#define WHOLE 1
#define HALF .5
#define QUARTER .25
#define EIGHTH .125
#define SIXTEENTH .0625
#define WHOLE_QUARTER 1.25
#define SIXTEENTH_HALF .5626

struct Note{
	int freq;			//frequency at which note resonates at
	double duration;	//how long the note is played

};

extern int tempo;
extern int pitch;
//plays a Note given the frequency and duration
void playNote(int freq, double duration);
//plays a song by iterating through the Note array
char playSong(const struct Note SONG[],int N);
//calculates how many square waves a note should produce
int getCycles(int freq, double duration);
void pauseSong();
void checkAction();
#endif /* INCFILE1_H_ */