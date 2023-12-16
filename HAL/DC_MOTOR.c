/*
 * DC_MOTOR.c
 *
 * Created: 7/19/2023 2:21:22 AM
 *  Author: Ahmed Mamdouh
 */ 

#include "DC_MOTOR.h"

//Initializing Motor
void motor_init(uint8 pina , uint8 pinb){
	PinMode(pina,OUTPUT);
	PinMode(pinb,OUTPUT);
}


//Stop the Motor
void motor_stop(uint8 pina , uint8 pinb){
	DigitalWrite(pina,LOW);
	DigitalWrite(pinb,LOW);
}


//this function takes the direction of rotation of motor to be rotated 
void motor_rotate(uint8 pina , uint8 pinb , uint8 direction){
	switch(direction) {
		case clockwise :
			DigitalWrite(pina,HIGH);
			DigitalWrite(pinb,LOW);
		break;
		case anti_clockwise :
			DigitalWrite(pina,LOW);
			DigitalWrite(pinb,HIGH);		
	}
}

