/*
 * LM35.c
 *
 * Created: 7/19/2023 8:53:30 PM
 *  Author: Ahmed Mamdouh
 */ 


#include "LM35.h"

//This function Calculates the Temperature value
uint8 temp_read(uint8 channel){
	return ADC_READVolt(channel)/10;
}