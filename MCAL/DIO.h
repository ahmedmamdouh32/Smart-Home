/*
 * DIO.h
 *
 * Created: 7/18/2023 11:15:19 PM
 *  Author: Ahmed Mamdouh
 */ 


#ifndef DIO_H_
#define DIO_H_


//***************** Inculdes *****************
#include "../MEM_MAP/bit_masking.h"
#include "../MEM_MAP/memory_map.h"

//***************** Defines *****************
#define HIGH 1
#define LOW 0
#define INPUT 0
#define OUTPUT 1
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#define DIO_PB0 0
#define DIO_PB1 1
#define DIO_PB2 2
#define DIO_PB3 3
#define DIO_PB4 4
#define DIO_PB5 5
#define DIO_PB6 6
#define DIO_PB7 7
#define DIO_PC0 8
#define DIO_PC1 9
#define DIO_PC2 10
#define DIO_PC3 11
#define DIO_PC4 12
#define DIO_PC5 13
#define DIO_PC6 14
#define DIO_PD0 15
#define DIO_PD1 16
#define DIO_PD2 17
#define DIO_PD3 18
#define DIO_PD4 19
#define DIO_PD5 20
#define DIO_PD6 21
#define DIO_PD7 22

//***************** Functions *****************
void DigitalWrite(unsigned char pin , unsigned char val);
void PinMode(unsigned char pin , unsigned char direction);
unsigned char DigitalRead(unsigned char pin);


#endif /* DIO_H_ */