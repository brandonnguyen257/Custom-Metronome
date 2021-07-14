/*
 * keypad.h
 *
 * Created: 5/2/2020 10:45:52 PM
 *  Author: brand
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "avr.h"
#include "lcd.h"

int isPressed(int r, int c);
//returns keyPressed
int getKey();
char getInput();


#endif /* KEYPAD_H_ */