/*
 * Buzzer.c
 *
 * Created: 7/21/2023 4:58:40 PM
 *  Author: Ahmed Mamdouh
 */ 


#include "Buzzer.h"

//Initializing Buzzer Pin
void Buzzer_init(uint8 pin){
PinMode(pin,OUTPUT);	
}


//Turning Buzzer ON
void Buzzer_ON(uint8 pin){
	DigitalWrite(pin,HIGH);
}

//Turning Buzzer OFF
void Buzzer_OFF(uint8 pin){
	DigitalWrite(pin,LOW);
}