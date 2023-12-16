/*
 * LED.C
 *
 * Created: 7/19/2023 12:26:35 AM
 *  Author: Ahmed Mamdouh
 */ 

#include "LED.h"

//Initializing LED 
void led_init(uint8 pin){
	PinMode(pin,OUTPUT);
}

void led_ON(uint8 pin){
	DigitalWrite(pin,HIGH);
}

void LED_OFF(uint8 pin){
	DigitalWrite(pin,LOW);
}
