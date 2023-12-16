/*
 * USART.c
 *
 * Created: 7/21/2023 2:14:34 PM
 *  Author: Ahmed Mamdouh
 */ 

#include "USART.h"


/*
Baud Rate : 9600
8-Bits Data
EVEN Parity
*/



//Initialization Function 
void UART_Init()
{
	
	UBRRL = 103;        //Baud Rate
	BIT_CLEAR(UCSRA,1); //Normal Speed
	
	//frame -> parity,stopbits, databits
	BIT_SET(UCSRC,5);   
	BIT_CLEAR(UCSRC,4); //Even Parity
	
	BIT_CLEAR(UCSRC,3); //1 stop bit
	
	BIT_SET(UCSRC,1);
	BIT_SET(UCSRC,2);
	BIT_CLEAR(UCSRB,2); //data bits
	
	//mode default Asynchronous
	
	BIT_SET(UCSRB,4); //enable RX
	BIT_SET(UCSRB,3); //enable TX
}

void UART_Transmit(uint8 data)
{
	//UCSRA>> UART Data Register Empty/
	while(!BIT_CHECK(UCSRA,5));	 //This bit is set (one) when a character written to UDR is transferred to the Transmit shift register
	UDR = data;
}


uint8 UART_Receive()
{
	while(! BIT_CHECK(UCSRA,7));	//This bit is set when a received character is transferred from the Receiver Shift register to UDR
	return UDR;
}

void UART_ReceiveStr(uint8* str)		//void UART_ReceiveStr(rec)	>> rec
{
	unsigned char data =  UART_Receive();
	unsigned char i = 0;
	str[i] = data;		//to store the 1st char
	i++;
	while(data != '\r') //continue receive until Enter  \r
	{
		data =  UART_Receive();
		str[i] = data;
		i++;
	}
	str[i] = '\0';
}

void UART_TransmitStr(uint8* str)
{
	unsigned char i = 0;
	while(str[i] != '\0')
	{
		while(! BIT_CHECK(UCSRA,5));
		UDR = str[i];
		i++;
	}
	
}