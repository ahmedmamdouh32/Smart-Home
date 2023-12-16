/*
 * DIO.c
 *
 * Created: 7/18/2023 11:15:32 PM
 *  Author: Ahmed Mamdouh
 */ 


#include "DIO.h"

//This function Set the direction of PIN
void PinMode(unsigned char pin , unsigned char direction){
	
	if(direction==OUTPUT)
	{
		switch(pin) {
			case DIO_PB0 :
			BIT_SET(DDRB,PIN0);
			break;
			case DIO_PB1 :
			BIT_SET(DDRB,PIN1);
			break;
			case DIO_PB2 :
			BIT_SET(DDRB,PIN2);
			break;
			case DIO_PB3 :
			BIT_SET(DDRB,PIN3);
			break;
			case DIO_PB4 :
			BIT_SET(DDRB,PIN4);
			break;
			case DIO_PB5 :
			BIT_SET(DDRB,PIN5);
			break;
			case DIO_PB6 :
			BIT_SET(DDRB,PIN6);
			break;
			case DIO_PB7 :
			BIT_SET(DDRB,PIN7);
			break;
			case DIO_PC0 :
			BIT_SET(DDRC,PIN0);
			break;
			case DIO_PC1 :
			BIT_SET(DDRC,PIN1);
			break;
			case DIO_PC2 :
			BIT_SET(DDRC,PIN2);
			break;
			case DIO_PC3 :
			BIT_SET(DDRC,PIN3);
			break;
			case DIO_PC4 :
			BIT_SET(DDRC,PIN4);
			break;
			case DIO_PC5 :
			BIT_SET(DDRC,PIN5);
			break;
			case DIO_PC6 :
			BIT_SET(DDRC,PIN6);
			break;
			case DIO_PD0 :
			BIT_SET(DDRD,PIN0);
			break;
			case DIO_PD1 :
			BIT_SET(DDRD,PIN1);
			break;
			case DIO_PD2 :
			BIT_SET(DDRD,PIN2);
			break;
			case DIO_PD3 :
			BIT_SET(DDRD,PIN3);
			break;
			case DIO_PD4 :
			BIT_SET(DDRD,PIN4);
			break;
			case DIO_PD5 :
			BIT_SET(DDRD,PIN5);
			break;
			case DIO_PD6 :
			BIT_SET(DDRD,PIN6);
			break;
			case DIO_PD7 :
			BIT_SET(DDRD,PIN7);
			break;
		}
		
	}
	else if(direction==INPUT)
	{
		switch(pin)
		{
			case DIO_PB0 :
			BIT_CLEAR(DDRB,PIN0);
			break;
			case DIO_PB1 :
			BIT_CLEAR(DDRB,PIN1);
			break;
			case DIO_PB2 :
			BIT_CLEAR(DDRB,PIN2);
			break;
			case DIO_PB3 :
			BIT_CLEAR(DDRB,PIN3);
			break;
			case DIO_PB4 :
			BIT_CLEAR(DDRB,PIN4);
			break;
			case DIO_PB5 :
			BIT_CLEAR(DDRB,PIN5);
			break;
			case DIO_PB6 :
			BIT_CLEAR(DDRB,PIN6);
			break;
			case DIO_PB7 :
			BIT_CLEAR(DDRB,PIN7);
			break;
			case DIO_PC0 :
			BIT_CLEAR(DDRC,PIN0);
			break;
			case DIO_PC1 :
			BIT_CLEAR(DDRC,PIN1);
			break;
			case DIO_PC2 :
			BIT_CLEAR(DDRC,PIN2);
			break;
			case DIO_PC3 :
			BIT_CLEAR(DDRC,PIN3);
			break;
			case DIO_PC4 :
			BIT_CLEAR(DDRC,PIN4);
			break;
			case DIO_PC5 :
			BIT_CLEAR(DDRC,PIN5);
			break;
			case DIO_PC6 :
			BIT_CLEAR(DDRC,PIN6);
			break;
			case DIO_PD0 :
			BIT_CLEAR(DDRD,PIN0);
			break;
			case DIO_PD1 :
			BIT_CLEAR(DDRD,PIN1);
			break;
			case DIO_PD2 :
			BIT_CLEAR(DDRD,PIN2);
			break;
			case DIO_PD3 :
			BIT_CLEAR(DDRD,PIN3);
			break;
			case DIO_PD4 :
			BIT_CLEAR(DDRD,PIN4);
			break;
			case DIO_PD5 :
			BIT_CLEAR(DDRD,PIN5);
			break;
			case DIO_PD6 :
			BIT_CLEAR(DDRD,PIN6);
			break;
			case DIO_PD7 :
			BIT_CLEAR(DDRD,PIN7);
			break;
		}
	}
}


//This function Writes on PIN (HIGH , LOW)
void DigitalWrite(unsigned char pin , unsigned char val){
	
	if(val==HIGH)
	{
		
		switch (pin)
		{
			case DIO_PB0 :
			BIT_SET(PORTB,PIN0);
			break;
			case DIO_PB1 :
			BIT_SET(PORTB,PIN1);
			break;
			case DIO_PB2 :
			BIT_SET(PORTB,PIN2);
			break;
			case DIO_PB3 :
			BIT_SET(PORTB,PIN3);
			break;
			case DIO_PB4 :
			BIT_SET(PORTB,PIN4);
			break;
			case DIO_PB5 :
			BIT_SET(PORTB,PIN5);
			break;
			case DIO_PB6 :
			BIT_SET(PORTB,PIN6);
			break;
			case DIO_PB7 :
			BIT_SET(PORTB,PIN7);
			break;
			case DIO_PC0 :
			BIT_SET(PORTC,PIN0);
			break;
			case DIO_PC1 :
			BIT_SET(PORTC,PIN1);
			break;
			case DIO_PC2 :
			BIT_SET(PORTC,PIN2);
			break;
			case DIO_PC3 :
			BIT_SET(PORTC,PIN3);
			break;
			case DIO_PC4 :
			BIT_SET(PORTC,PIN4);
			break;
			case DIO_PC5 :
			BIT_SET(PORTC,PIN5);
			break;
			case DIO_PC6 :
			BIT_SET(PORTC,PIN6);
			break;
			case DIO_PD0 :
			BIT_SET(PORTD,PIN0);
			break;
			case DIO_PD1 :
			BIT_SET(PORTD,PIN1);
			break;
			case DIO_PD2 :
			BIT_SET(PORTD,PIN2);
			break;
			case DIO_PD3 :
			BIT_SET(PORTD,PIN3);
			break;
			case DIO_PD4 :
			BIT_SET(PORTD,PIN4);
			break;
			case DIO_PD5 :
			BIT_SET(PORTD,PIN5);
			break;
			case DIO_PD6 :
			BIT_SET(PORTD,PIN6);
			break;
			case DIO_PD7 :
			BIT_SET(PORTD,PIN7);
			break;
						
		}
					
	}
	
	else if(val==LOW)
	{
		
		switch(pin)
		{
			case DIO_PB0 :
			BIT_CLEAR(PORTB,PIN0);
			break;
			case DIO_PB1 :
			BIT_CLEAR(PORTB,PIN1);
			break;
			case DIO_PB2 :
			BIT_CLEAR(PORTB,PIN2);
			break;
			case DIO_PB3 :
			BIT_CLEAR(PORTB,PIN3);
			break;
			case DIO_PB4 :
			BIT_CLEAR(PORTB,PIN4);
			break;
			case DIO_PB5 :
			BIT_CLEAR(PORTB,PIN5);
			break;
			case DIO_PB6 :
			BIT_CLEAR(PORTB,PIN6);
			break;
			case DIO_PB7 :
			BIT_CLEAR(PORTB,PIN7);
			break;
			case DIO_PC0 :
			BIT_CLEAR(PORTC,PIN0);
			break;
			case DIO_PC1 :
			BIT_CLEAR(PORTC,PIN1);
			break;
			case DIO_PC2 :
			BIT_CLEAR(PORTC,PIN2);
			break;
			case DIO_PC3 :
			BIT_CLEAR(PORTC,PIN3);
			break;
			case DIO_PC4 :
			BIT_CLEAR(PORTC,PIN4);
			break;
			case DIO_PC5 :
			BIT_CLEAR(PORTC,PIN5);
			break;
			case DIO_PC6 :
			BIT_CLEAR(PORTC,PIN6);
			break;
			case DIO_PD0 :
			BIT_CLEAR(PORTD,PIN0);
			break;
			case DIO_PD1 :
			BIT_CLEAR(PORTD,PIN1);
			break;
			case DIO_PD2 :
			BIT_CLEAR(PORTD,PIN2);
			break;
			case DIO_PD3 :
			BIT_CLEAR(PORTD,PIN3);
			break;
			case DIO_PD4 :
			BIT_CLEAR(PORTD,PIN4);
			break;
			case DIO_PD5 :
			BIT_CLEAR(PORTD,PIN5);
			break;
			case DIO_PD6 :
			BIT_CLEAR(PORTD,PIN6);
			break;
			case DIO_PD7 :
			BIT_CLEAR(PORTD,PIN7);
			break;

		}	
	}			
} 


//This function reads PIN Value 
unsigned char DigitalRead(unsigned char pin){
	char value=0;
	
	switch(pin)
	{
		case DIO_PB0 :
		value=BIT_CHECK(PINB,PIN0);
		break;
		case DIO_PB1 :
		value=BIT_CHECK(PINB,PIN1);
		break;
		case DIO_PB2 :
		value=BIT_CHECK(PINB,PIN2);
		break;
		case DIO_PB3 :
		value=BIT_CHECK(PINB,PIN3);
		break;
		case DIO_PB4 :
		value=BIT_CHECK(PINB,PIN4);
		break;
		case DIO_PB5 :
		value=BIT_CHECK(PINB,PIN5);
		break;
		case DIO_PB6 :
		value=BIT_CHECK(PINB,PIN6);
		break;
		case DIO_PB7 :
		value=BIT_CHECK(PINB,PIN7);
		break;
		case DIO_PC0 :
		value=BIT_CHECK(PINC,PIN0);
		break;
		case DIO_PC1 :
		value=BIT_CHECK(PINC,PIN1);
		break;
		case DIO_PC2 :
		value=BIT_CHECK(PINC,PIN2);
		break;
		case DIO_PC3 :
		value=BIT_CHECK(PINC,PIN3);
		break;
		case DIO_PC4 :
		value=BIT_CHECK(PINC,PIN4);
		break;
		case DIO_PC5 :
		value=BIT_CHECK(PINC,PIN5);
		break;
		case DIO_PC6 :
		value=BIT_CHECK(PINC,PIN6);
		break;
		case DIO_PD0 :
		value=BIT_CHECK(PIND,PIN0);
		break;
		case DIO_PD1 :
		value=BIT_CHECK(PIND,PIN1);
		break;
		case DIO_PD2 :
		value=BIT_CHECK(PIND,PIN2);
		break;
		case DIO_PD3 :
		value=BIT_CHECK(PIND,PIN3);
		break;
		case DIO_PD4 :
		value=BIT_CHECK(PIND,PIN4);
		break;
		case DIO_PD5 :
		value=BIT_CHECK(PIND,PIN5);
		break;
		case DIO_PD6 :
		value=BIT_CHECK(PIND,PIN6);
		break;
		case DIO_PD7 :
		value=BIT_CHECK(PIND,PIN7);
		break;
	}
return value;
}
