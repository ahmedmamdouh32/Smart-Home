/*
 * Buzzer.h
 *
 * Created: 7/21/2023 4:58:25 PM
 *  Author: Ahmed Mamdouh
 */ 


#ifndef BUZZER_H_
#define BUZZER_H_

//***************** Inculdes *****************
#include "../types.h"
#include "../MCAL/DIO.h"

//***************** Functions *****************
void Buzzer_init(uint8 pin);
void Buzzer_ON(uint8 pin);
void Buzzer_OFF(uint8 pin);


#endif /* BUZZER_H_ */