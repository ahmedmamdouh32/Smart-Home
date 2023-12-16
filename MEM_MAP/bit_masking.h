/*
 * Bit_Masking.h
 *
 * Created: 3/20/2023 8:11:33 PM
 *  Author: Ahmed Mamdouh
 */ 


#ifndef BIT_MASKING_H_
#define BIT_MASKING_H_

//Macros :

#define BIT_SET(address,bit)     (address|=(1<<bit))
#define BIT_CLEAR(address,bit)   (address&=~(1<<bit))
#define BIT_TOOGLE(address,bit)  (address^=(1<<bit))
#define BIT_CHECK(address,bit)   ((address>>bit)&1)
#define BIT_WRITE(reg,bit,Value) (reg &= ~(1<<bit)|Value<<bit)

#define REG_SET(address)         (address=0xff)
#define REG_CLEAR(address)       (address=0x00)
#define Reg_Write(address,Value) (address=Value)
#define Reg_CHECK(address)       (address&(0xff))


#endif /* BIT_MASKING_H_ */