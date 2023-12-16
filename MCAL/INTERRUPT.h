/*
 * INTERRUPT.h
 *
 * Created: 7/21/2023 9:44:15 PM
 *  Author: Ahmed Mamdouh
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_


//***************** Inculdes *****************
#include "../types.h"
#include "../MEM_MAP/bit_masking.h"
#include "../MEM_MAP/memory_map.h"

//***************** Defines *****************
#define LOW_LVL 0
#define LOGIC_CHANGE 1
#define FALLING_EDGE 2
#define RISING_EDGE 3
#define INT0 0
#define INT1 1
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3
#define I 7

//***************** Functions *****************
void EXT_INTERRUPT_INIT(uint8 pin , uint8 sense_contrl);
void GLOBAL_INTERRUPT_ENABLE();


#endif /* INTERRUPT_H_ */