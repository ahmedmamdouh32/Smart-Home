/*
 * DC_MOTOR.h
 *
 * Created: 7/19/2023 2:21:55 AM
 *  Author: Ahmed Mamdouh
 */ 


#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

//***************** Inculdes *****************
#include "../types.h"
#include "../MCAL/DIO.h"

/******************Defines***************/
#define clockwise      0
#define anti_clockwise 1



//***************** Functions *****************
void motor_init(uint8 pina , uint8 pinb);
void motor_stop(uint8 pina , uint8 pinb);
void motor_rotate(uint8 pina , uint8 pinb , uint8 direction);


#endif /* DC_MOTOR_H_ */