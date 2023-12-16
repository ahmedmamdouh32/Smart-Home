/*
 * LED.h
 *
 * Created: 7/19/2023 12:26:48 AM
 *  Author: Ahmed Mamdouh
 */ 


#ifndef LED_H_
#define LED_H_


//***************** Inculdes *****************
#include "../types.h"
#include "../MCAL/DIO.h"

//***************** Functions *****************
void led_init(uint8 pin);
void LED_OFF(uint8 pin);
void led_ON(uint8 pin);

#endif /* LED_H_ */