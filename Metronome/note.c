/*
 * CFile1.c
 *
 * Created: 5/16/2020 10:01:27 PM
 *  Author: brand
 */ 
#include "note.h"


int tempo=2;
int pitch=2;
void playNote(int freq, double duration){
	lcd_pos(1,0);	
	int i;
	int cycles=getCycles(freq,duration);
	for(i=0;i<cycles;++i){
		SET_BIT(PORTB,3);
		note_wait(freq);
		CLR_BIT(PORTB,3);
		note_wait(freq);
	}	
}

char playSong(const struct Note song[],int N){
	int i;
	char action;
	for(i=0;i<N;++i){
		action=getInput();
		if(action=='D'){
			pauseSong();
		} 
		else if(action=='A'|| action=='B'||action=='C'){
			return action;
		}
		else if(action=='*'){		
			tempo=tempo%4;
			tempo=tempo+1;
			avr_wait(200);
		}	
		else if(action=='#'){
			pitch=pitch%3;
			pitch=pitch+1;
			avr_wait(200);
		}
		playNote(song[i].freq*pitch,song[i].duration*(tempo*4));
	
	}
	return 'O';
}



int getCycles(int freq, double duration){
	double Thigh=freq*WAIT_RES;	//convert #defined frequency to real frequency
	double period=Thigh*2;		//p=Thigh+Thigh
	int cycles=duration/period;//k=duration/p
	return cycles;
}

void pauseSong(){
	avr_wait(200);
	while(1){
		if(getInput()=='D'){
			avr_wait(200);
			break;
		}
	}

}
