/*
 * ADC.h
 *
 * Created: 7/19/2023 8:39:51 PM
 *  Author: Ahmed Mamdouh
 */ 


#ifndef ADC_H_
#define ADC_H_


//***************** Inculdes *****************
#include "../types.h"
#include "../MEM_MAP/bit_masking.h"
#include "../MEM_MAP/memory_map.h"

//***************** Defines *****************
#define AREF 0
#define AVCC 1
#define internal_1v1 3

#define ADC_CHANNEL_0 0
#define ADC_CHANNEL_1 1
#define ADC_CHANNEL_2 2
#define ADC_CHANNEL_3 3
#define ADC_CHANNEL_4 4
#define ADC_CHANNEL_5 5
#define ADC_MUX0 0
#define ADC_MUX1 1
#define ADC_MUX2 2
#define ADC_MUX3 3
#define ADLAR 5
#define ADPS0 0
#define ADPS1 1
#define ADPS2 2
#define ADSC 6
#define ADEN 7
#define REFS0 6
#define REFS1 7
#define ADIF 4

#define ADC_PRESCALAR_2   1
#define ADC_PRESCALAR_4   2
#define ADC_PRESCALAR_8   3
#define ADC_PRESCALAR_16  4
#define ADC_PRESCALAR_32  5
#define ADC_PRESCALAR_64  6
#define ADC_PRESCALAR_128 7


//***************** Functions *****************
void ADC_init (unsigned char prescalar,unsigned char vref);
uint32 ADC_Read(unsigned char channel);
uint32 ADC_READVolt(unsigned char channel);




#endif /* ADC_H_ */