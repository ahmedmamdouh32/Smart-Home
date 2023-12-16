/*
 * INTERRUPT.c
 *
 * Created: 7/21/2023 9:43:55 PM
 *  Author: Ahmed Mamdouh
 */ 


#include "INTERRUPT.h"

//Initializing External Interrupt
void EXT_INTERRUPT_INIT(uint8 pin , uint8 sense_control){
	
switch (pin) {
	case INT0 :
		BIT_SET(EIMSK,INT0);  //enabling interrupt INT0
		switch (sense_control)  //setting trigger for interrupt
		{
			case LOW_LVL :
				BIT_CLEAR(EICRA,ISC00);
				BIT_CLEAR(EICRA,ISC01);
			break;
		
			case LOGIC_CHANGE :
				BIT_SET(EICRA,ISC00);
				BIT_CLEAR(EICRA,ISC01);
			break;
		
			case FALLING_EDGE :
				BIT_CLEAR(EICRA,ISC00);
				BIT_SET(EICRA,ISC10);
			break;
		
			case RISING_EDGE :
				BIT_SET(EICRA,ISC00);
				BIT_SET(EICRA,ISC01);
			break;
		}
	break;
	
	case INT1 :
		BIT_SET(EIMSK,INT1);
		switch (sense_control)
		{
			case LOW_LVL :
			BIT_CLEAR(EICRA,ISC10);
			BIT_CLEAR(EICRA,ISC11);
			break;
			
			case LOGIC_CHANGE :
			BIT_SET(EICRA,ISC10);
			BIT_CLEAR(EICRA,ISC11);
			break;
			
			case FALLING_EDGE :
			BIT_CLEAR(EICRA,ISC10);
			BIT_SET(EICRA,ISC11);
			break;
			
			case RISING_EDGE :
			BIT_SET(EICRA,ISC10);
			BIT_SET(EICRA,ISC11);
			break;
			
		}
	break;	
}
}

//This function enables Global Interrupt
void GLOBAL_INTERRUPT_ENABLE(){
	BIT_SET(SREG,I);
}	