/*
 * PUSHBUTTON.h
 *
 * Created: 7/19/2023 1:59:17 AM
 *  Author: Ahmed Mamdouh
 */ 


#ifndef PUSHBUTTON_H_
#define PUSHBUTTON_H_


//***************** Inculdes *****************
#include "../types.h"
#include "../MCAL/DIO.h"

//***************** Functions *****************
void PUSH_BUTTON_INIT(uint8 pin);
uint8 PUSH_BUTTON_READ(uint8 pin);


#endif /* PUSHBUTTON_H_ */