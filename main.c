/*
 * final_project.c
 *
 * Created: 7/18/2023 11:02:19 PM
 * Author : Ahmed Mamdouh
 */ 
//#include <avr/io.h>

#define F_CPU 16000000
#include <util/delay.h>
#include "HAL/LED.h"
#include "types.h"
#include "MCAL/DIO.h"
#include "HAL/PUSHBUTTON.h"
#include "HAL/LCD.h"
#include "HAL/DC_MOTOR.h"
#include "MCAL/ADC.h"
#include "hal/LM35.h"
#include "MCAL/USART.h"
#include "HAL/Buzzer.h"
#include <avr/interrupt.h>
#include "MCAL/INTERRUPT.h"


#define MAXIMUM_TEMPERATURE 100
#define ROOM_LAMP DIO_PB0
#define Motor_pin1 DIO_PB1
#define Motor_pin2 DIO_PB2
#define Open_Door_lamp DIO_PB3
#define Close_Door_Lamp DIO_PB4
#define LED_Buzzer DIO_PB5
#define int_button DIO_PD2
#define Temp_Sensor ADC_CHANNEL_2
#define Buzzer DIO_PC3


void welcome_message();
void Open_Room_Lamp();
void Close_Room_Lamp();
void Open_Door();
void Close_Door();
void Display_Temperature();

uint8 temp_flag=1;

int main(void)
{	
	PinMode(DIO_PC2,INPUT);
	PinMode(int_button,INPUT);
	EXT_INTERRUPT_INIT(INT0,FALLING_EDGE);

	GLOBAL_INTERRUPT_ENABLE();
	Buzzer_init(Buzzer);
	led_init(ROOM_LAMP);
	led_init(Open_Door_lamp);
	led_init(Close_Door_Lamp);
	led_init(LED_Buzzer);
	motor_init(Motor_pin1,Motor_pin2);
	LCD_init();
	UART_Init();
	ADC_init(ADC_PRESCALAR_128,AVCC);
	uint8 order[3];
	uint8 Lamp_flag=1;
	uint8 Door_flag=1;
	
	welcome_message();
	
	while(1)
	{
	LCD_Clear();	
	LCD_WriteString("What do you need?");
	UART_ReceiveStr(order);
	
	if(order[0]=='O' && order[1]=='L')
	{
		if(Lamp_flag)
		{
		Open_Room_Lamp();
		Lamp_flag=0;
		}
		else
		{
			LCD_Clear();
			LCD_WriteString("already on");
			_delay_ms(500);
			LCD_Clear();
		}
	}
	
	else if(order[0]=='C' && order[1]=='L')
	{
		if(!Lamp_flag)
		{
			Close_Room_Lamp();
			Lamp_flag=1;	
		}
		else
		{
			LCD_Clear();
			LCD_WriteString("already off");
			_delay_ms(500);
			LCD_Clear();
		}	
	}
	
	else if(order[0]=='O' && order[1]=='D')
	{
		if(Door_flag)
		{
			Open_Door();
			Door_flag=0;
		}
		else
		{
			LCD_Clear();
			LCD_WriteString("Already opened");
			_delay_ms(500);
			LCD_Clear();
		}
	}
	
	else if(order[0]=='C' && order[1]=='D')
	{
		if(!Door_flag)
		{
			Close_Door();
			Door_flag=1;
		}
		else
		{
			LCD_Clear();
			LCD_WriteString("Already closed");
			_delay_ms(500);
			LCD_Clear();
		}
	
	}
	
	else if(order[0]=='D' && order[1]=='T')
	{	
		temp_flag=1;
		LCD_Clear();
		
		while(temp_flag)
		{
			Display_Temperature();
			if(temp_read(Temp_Sensor)>=MAXIMUM_TEMPERATURE)
			{
				while(temp_flag)
				{
					Buzzer_ON(Buzzer);
					led_ON(LED_Buzzer);
					LCD_WriteString("Fire!");
				}
			}

		}
		
		
	}
	else 
	{
	LCD_Clear();
	LCD_WriteString("Invalid Order !!");
	_delay_ms(500);
	}
		
	}
			
			

return 0;
}






void welcome_message(){
	LCD_WriteString("Welcome to The");
	LCD_SetCursor(1,0);
	LCD_WriteString("IEEEian Helper !");
	_delay_ms(1500);
}

void Open_Room_Lamp(){
	led_ON(ROOM_LAMP);
	LCD_Clear();
	LCD_WriteString("opening lamp");
	_delay_ms(1000);
	LCD_Clear();
}

void Close_Room_Lamp(){
	LED_OFF(ROOM_LAMP);
	LCD_Clear();
	LCD_WriteString("Closing Lamp");
	_delay_ms(1000);
	LCD_Clear();
}

void Open_Door(){
	motor_rotate(Motor_pin1,Motor_pin2,clockwise);
	led_ON(Open_Door_lamp);
	LCD_Clear();
	LCD_WriteString("Opening Door");
	_delay_ms(2000);
	motor_stop(Motor_pin1,Motor_pin2);
	LED_OFF(Open_Door_lamp);
	LCD_Clear();
	LCD_WriteString("Door is opened");
	_delay_ms(500);
	LCD_Clear();
	
}

void Close_Door(){
	motor_rotate(Motor_pin1,Motor_pin2,anti_clockwise);
	led_ON(Close_Door_Lamp);
	LCD_Clear();
	LCD_WriteString("Closing Door");
	_delay_ms(2000);
	motor_stop(Motor_pin1,Motor_pin2);
	LED_OFF(Close_Door_Lamp);
	LCD_Clear();
	LCD_WriteString("Door is Closed");
	_delay_ms(500);
	LCD_Clear();	
}

void Display_Temperature(){
	LCD_SetCursor(0,0);
	LCD_WriteString("Temperature is :");
	LCD_SetCursor(1,6);
	LCD_WriteNumber(temp_read(Temp_Sensor));
	LCD_WriteString(" C ");
}





ISR(INT0_vect){
	temp_flag=0;
	LED_OFF(LED_Buzzer);
	Buzzer_OFF(Buzzer);
	LCD_Clear();
}

