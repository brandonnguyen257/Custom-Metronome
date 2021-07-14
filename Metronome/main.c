/*
 * Project5.c
 *
 * Created: 6/10/2020 5:17:23 PM
 * Author : brand
 */ 


#include "metronome.h"
int main(void)
{
	
	init_metronome();
	
		lcd_pos(0,0);
		char buffer[17];
		sprintf(buffer,"bpm:%d",currentMetronome.bpm);
		lcd_puts("");
		avr_wait(1000);
    while (1) 
    {
		
		checkInput();
		playBeat();
		avr_wait(currentMetronome.waitTime);	
		lcd_clr();
	}

}

