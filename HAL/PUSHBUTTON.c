/*
 * PUSHBUTTON.c
 *
 * Created: 7/19/2023 1:59:36 AM
 *  Author: Ahmed Mamdouh
 */ 


#include "PUSHBUTTON.h"

//Initializing Push Button
void PUSH_BUTTON_INIT(uint8 pin){
	PinMode(pin,INPUT);
}

//Taking readings form Push Button
uint8 PUSH_BUTTON_READ(uint8 pin){
	return DigitalRead(pin);
}


