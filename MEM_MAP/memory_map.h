/*
 * memory_map.h
 *
 * Created: 7/18/2023 11:10:52 PM
 *  Author: Ahmed Mamdouh
 */ 


#ifndef MEMORY_MAP_H_
#define MEMORY_MAP_H_




// PORT B :
#define PINB  *((volatile unsigned char*)0x23)
#define DDRB  *((volatile unsigned char*)0x24)
#define PORTB *((volatile unsigned char*)0x25)

// PORT C :
#define PINC  *((volatile unsigned char*)0x26)
#define DDRC  *((volatile unsigned char*)0x27)
#define PORTC *((volatile unsigned char*)0x28)

// PORT D :
#define PIND  *((volatile unsigned char*)0x29)
#define DDRD  *((volatile unsigned char*)0x2A)
#define PORTD *((volatile unsigned char*)0x2B)



/****************** INTERRUPT REGISTERS **********************/
#define EICRA *((volatile unsigned char*)0x69)
#define SREG  *((volatile unsigned char*)0x5f)  //3f
#define EIMSK *((volatile unsigned char*)0x3d)






/******************** ADC REGISTERS ************************/

#define ADMUX  *((volatile unsigned char *)0x7c)
#define ADCSRA *((volatile unsigned char *)0x7a)
#define ADCH   *((volatile unsigned char *)0x79)
#define ADCL   *((volatile unsigned char *)0x78)




/******************** UART REGISTERS ************************/

#define UDR   *((volatile unsigned char *)0xc6)
#define UBRRH *((volatile unsigned char *)0xc5)
#define UBRRL *((volatile unsigned char *)0xc4)
#define UCSRC *((volatile unsigned char *)0xc2)
#define UCSRB *((volatile unsigned char *)0xc1)
#define UCSRA *((volatile unsigned char *)0xc0)







#endif /* MEMORY_MAP_H_ */