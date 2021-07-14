/*
 * keypad.c
 *
 * Created: 5/2/2020 10:45:46 PM
 *  Author: brand
 */ 
#include "keypad.h"
int isPressed(int r, int c){
	//set all pins to N/C DDR:0 PORT:0
	int i;
	for(i=0;i<8;i++){
		CLR_BIT(DDRC,i);
		CLR_BIT(PORTC,i);
	}
	//set r to S0 DDR:1 PORT:0
	SET_BIT(DDRC,r);
	CLR_BIT(PORTC,r);
	//set c to W1 DDR:0 PORT:1
	SET_BIT(PORTC,c+4);
	//get value at c
	avr_wait(1);
	int pressed = GET_BIT(PINC,c+4);
	//if pressed
	if(pressed==0){
		return 1;
	}
	//not pressed
	return 0;
}

int getKey(){
	int r,c;
	for(r=0;r<4;r++){
		for(c=0;c<4;c++){
			if(isPressed(r,c)){
				return(r*4+c)+1;
			}
		}
	}
	return 0;
}
char getInput(){
	char keyArray[]={'X','1','2','3','A','4','5','6','B','7','8','9','C','*','0','#','D'};
	int key=getKey();
	return keyArray[key];
}
