/*
 * ADC.c
 *
 * Created: 7/19/2023 8:39:39 PM
 *  Author: Ahmed Mamdouh
 */ 

#include "ADC.h"
 

//Initializing ADC Peripheral
void ADC_init (uint8 prescalar,uint8 vref){
	switch(vref)
	{
		case AREF :
		BIT_CLEAR(ADMUX,REFS0);
		BIT_CLEAR(ADMUX,REFS1);
		break;
		
		case AVCC :
		BIT_SET(ADMUX,REFS0);
		BIT_CLEAR(ADMUX,REFS1);
		break;
		
		case internal_1v1 :
		BIT_SET(ADMUX,REFS0);
		BIT_SET(ADMUX,REFS1);
		break;
	}
	
	//Prescalar :
	ADCSRA&=0xf8;  //0xLLLLL000
	ADCSRA|=prescalar;
	
	BIT_CLEAR(ADMUX,ADLAR); /*for right presentation of conversion value on Registers (ADCH-ADCL)*/
}

//this Function returns readings of ADC channel
uint32 ADC_Read(uint8 channel){
	
	uint16 ADC_Measured_Value=0;
	ADMUX&=0xf0;
	ADMUX|=channel; //selecting ADC channel
	
	BIT_SET(ADCSRA,ADEN); //Enabling ADC
	
	BIT_SET(ADCSRA,ADSC); //to start conversion
	
	while((BIT_CHECK(ADCSRA,ADSC))); //waiting for ADC to finish conversion
	ADC_Measured_Value|=(uint8)ADCL;
	ADC_Measured_Value|=(uint16)(ADCH<<8); //this value is returned to the reference of variable address to be updated
	
	return ADC_Measured_Value;
}

//This function converts reading of ADC to Volts
uint32 ADC_READVolt(uint8 channel){
	return ADC_Read(channel)*5000/1024;
}