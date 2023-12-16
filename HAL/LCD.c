/*
 * LCD.c
 *
 * Created: 7/19/2023 5:00:32 PM
 *  Author: Ahmed Mamdouh
 */ 


#include "LCD.h"


//LCD 4-BIT MODE


//Static function that is used to send Commands to LCD
static void LCD_SendCommand(uint8 command){
	
	DigitalWrite(D4,BIT_CHECK(command,PIN4));
	DigitalWrite(D5,BIT_CHECK(command,PIN5));
	DigitalWrite(D6,BIT_CHECK(command,PIN6));
	DigitalWrite(D7,BIT_CHECK(command,PIN7));
	DigitalWrite(RS,LOW); //to send command RS is LOW
	DigitalWrite(E,HIGH);
	_delay_us(1);
	DigitalWrite(E,LOW);
	_delay_us(100);

	DigitalWrite(D4,BIT_CHECK(command,PIN0));
	DigitalWrite(D5,BIT_CHECK(command,PIN1));
	DigitalWrite(D6,BIT_CHECK(command,PIN2));
	DigitalWrite(D7,BIT_CHECK(command,PIN3));
	DigitalWrite(E,HIGH);
	_delay_us(1);
	DigitalWrite(E,LOW);
	_delay_us(100);
}


//Static function that is used to send Data to LCD
static void LCD_SendData(uint8 data){
	
	DigitalWrite(D4,BIT_CHECK(data,PIN4));
	DigitalWrite(D5,BIT_CHECK(data,PIN5));
	DigitalWrite(D6,BIT_CHECK(data,PIN6));
	DigitalWrite(D7,BIT_CHECK(data,PIN7));
	DigitalWrite(RS,HIGH); //to send data RS is HIGH
	DigitalWrite(E,HIGH);
	_delay_us(1);
	DigitalWrite(E,LOW);
	_delay_us(100);
	
	DigitalWrite(D4,BIT_CHECK(data,PIN0));
	DigitalWrite(D5,BIT_CHECK(data,PIN1));
	DigitalWrite(D6,BIT_CHECK(data,PIN2));
	DigitalWrite(D7,BIT_CHECK(data,PIN3));
	DigitalWrite(E,HIGH);
	_delay_us(1);
	DigitalWrite(E,LOW);
	_delay_us(100);
}


//Initializing LCD in 4-Bit Mode 
void LCD_init(){
	PinMode(D4,OUTPUT);
	PinMode(D5,OUTPUT);
	PinMode(D6,OUTPUT);
	PinMode(D7,OUTPUT);
	PinMode(RS,OUTPUT);
	PinMode(E,OUTPUT);
	_delay_ms(20);
	LCD_SendCommand(0x02);
	LCD_SendCommand(0x28);
	LCD_SendCommand(0x0c);
	LCD_SendCommand(0x06);
	LCD_SendCommand(0x01);
	_delay_ms(20);
}


//This function displays characters on LCD 
void LCD_WriteChar(uint8 digit){
	LCD_SendData(digit);
}


//This function sets the cursor position on LCD screen
void LCD_SetCursor(uint8 row , uint8 column){
	uint8 address=0;
	address = row * 0x40 + column;
	BIT_SET(address,PIN7); //setting bit 7 to HIGH 
	LCD_SendCommand(address);
}


//This function is used to Print more than one character at a time 
void LCD_WriteString(char * str){
	for(int i=0;str[i]!='\0';i++){
		LCD_SendData(str[i]);
	}
}


//Clears the LCD screen
void LCD_Clear(){
	LCD_SendCommand(0x01);
	_delay_ms(20);
}


//To display number on LCD screen
void LCD_WriteNumber(uint32 number)
{
	uint32 temp=number;
	uint8 counter=0;
	while(temp!=0)
	{
		temp/=10;
		counter++;
	}
	uint8 arr[counter];
	for (int i=0;i<counter;i++)
	{
		temp=number%10;
		arr[i]=temp;
		number/=10;
	}
	for (int j=counter-1;j>=0;j--)
	{
		LCD_SendData(arr[j]+48);
	}
}