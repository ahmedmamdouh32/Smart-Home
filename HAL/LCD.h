/*
 * LCD.h
 *
 * Created: 7/19/2023 5:00:14 PM
 *  Author: Ahmed Mamdouh
 */ 


#ifndef LCD_H_
#define LCD_H_

#define F_CPU 16000000
//***************** Inculdes *****************
#include <util/delay.h>
#include "../types.h"
#include "../MCAL/DIO.h"
#include "../MEM_MAP/bit_masking.h"

//***************** Defines *****************
#define D4 DIO_PD4
#define D5 DIO_PD5
#define D6 DIO_PD6
#define D7 DIO_PD7
#define RS DIO_PC0
#define E  DIO_PC1


//***************** Functions *****************
void LCD_init();
void LCD_WriteChar(uint8 digit); 
void LCD_SetCursor(uint8 row , uint8 column); //values of row is in Range of [0:1], and for column is[0:15]
void LCD_WriteString(char *str);
void LCD_Clear();
void LCD_WriteNumber(uint32 number);

#endif /* LCD_H_ */