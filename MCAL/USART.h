/*
 * USART.h
 *
 * Created: 7/21/2023 2:14:59 PM
 *  Author: Ahmed Mamdouh
 */ 


#ifndef USART_H_
#define USART_H_

//***************** Inculdes *****************
#include "../types.h"
#include "../MEM_MAP/bit_masking.h"
#include "../MEM_MAP/memory_map.h"

//***************** Functions *****************
void UART_Init();
void UART_Transmit(uint8 data);
uint8 UART_Receive();
void UART_ReceiveStr(uint8* str);
void UART_TransmitStr(uint8* str);






#endif /* USART_H_ */