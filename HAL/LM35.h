/*
 * LM35.h
 *
 * Created: 7/19/2023 8:53:07 PM
 *  Author: Ahmed Mamdouh
 */ 


#ifndef LM35_H_
#define LM35_H_

//***************** Inculdes *****************
#include "../types.h"
#include "../MCAL/ADC.h"

//***************** Functions *****************
uint8 temp_read(uint8 channel);

#endif /* LM35_H_ */