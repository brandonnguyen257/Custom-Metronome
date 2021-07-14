/*
 * metronome.c
 *
 * Created: 6/10/2020 9:38:37 PM
 *  Author: brand
 */ 
#include "metronome.h"

Metronome currentMetronome={75,4,0,(60000/ 75)-50,1,1,1};//default value
Metronome metronomePresets[10]={NULL};
void init_metronome(){
	lcd_init();
	SET_BIT(DDRA,0);	//Sets B0 to be an output LED
	SET_BIT(DDRA,1);	//Sets B0 to be an output LED
	SET_BIT(DDRA,2);	//Sets B0 to be an output LED
	SET_BIT(DDRA,3);	//Sets B0 to be an output LED
	SET_BIT(DDRB,3);	//set DDRB 3 to be output for speaker
	metronomePresets[0]=currentMetronome;
}

int getWaitTime(int currBPM){
	return 100;
}

void updateBPM(){
	lcd_clr();
	lcd_pos(0,0);
	char buffer[17];
	sprintf(buffer,"Curr BPM:%d",currentMetronome.bpm);
	lcd_puts(buffer);
	
	lcd_pos(1,0);
	sprintf(buffer,"A:+5 B:-5 D:Confirm");
	lcd_puts(buffer);
	
	char input;

	while(1){
		input=getInput();
		
		if(input=='A'){//increase BPM
			
			currentMetronome.bpm+=5;
			lcd_pos(0,0);
			sprintf(buffer,"Curr BPM:%d",currentMetronome.bpm);
			lcd_puts(buffer);
			avr_wait(200);
			//display new BPM
		}
		else if(input=='B'){//decrease BPM
			currentMetronome.bpm-=5;
			lcd_pos(0,0);
			sprintf(buffer,"Curr BPM:%d",currentMetronome.bpm);
			lcd_puts(buffer);
			avr_wait(200);
			//display new BPM
		}
		else if(input=='D'){//confirm BPM
			avr_wait(200);
			break;
		}
	}
	currentMetronome.waitTime=(60000/ currentMetronome.bpm)-50;
	lcd_clr();


}

void playBeat(){
	displayBeatLCD();
	if(currentMetronome.displayLED){
		SET_BIT(PORTA,currentMetronome.currBeat);
		playNote(A, QUARTER);
		CLR_BIT(PORTA,currentMetronome.currBeat);
	}
	else{
		playNote(A, QUARTER);
	}

	
	updateMetronome();
}

void displayBeatLCD(){
	if(currentMetronome.displayLCD){
		lcd_pos(0,currentMetronome.currBeat);
		lcd_put(0xB0);
	}
	else{
		lcd_pos(0,0);
		lcd_puts("");
	}

}

void updateMetronome(){
	currentMetronome.currBeat++;
	currentMetronome.currBeat=currentMetronome.currBeat%4;	
}

void checkInput(){
	char input=getInput();
	//update BPM
	if(input=='*'){
		updateBPM();
	}
	//setting to turn on/off certain aspects of metronome
	else if(input=='#'){
		updateSettings();
	}
	else if(input=='C'){
		updatePresets();
	}
}

void updatePresets(){
	
}

void updateSettings(){
	lcd_clr();
	lcd_pos(0,0);
	char buffer[17];
	sprintf(buffer,"LCD:%d LED:%d",currentMetronome.displayLCD,currentMetronome.displayLED);
	lcd_puts(buffer);
	
	lcd_pos(1,0);
	sprintf(buffer,"A:LCD B:LED");
	lcd_puts(buffer);
	
	char input;	
	while(1){
		input=getInput();
		if(input=='A'){
			currentMetronome.displayLCD=!currentMetronome.displayLCD;
			lcd_pos(0,0);
			sprintf(buffer,"LCD:%d LED:%d",currentMetronome.displayLCD,currentMetronome.displayLED);
			lcd_puts(buffer);
			
			avr_wait(200);
		}
		else if(input=='B'){
			currentMetronome.displayLED=!currentMetronome.displayLED;
			lcd_pos(0,0);
			sprintf(buffer,"LCD:%d LED:%d",currentMetronome.displayLCD,currentMetronome.displayLED);
			lcd_puts(buffer);
			avr_wait(200);			
		}
		else if(input=='D'){
			avr_wait(200);
			break;
		}
	}
}