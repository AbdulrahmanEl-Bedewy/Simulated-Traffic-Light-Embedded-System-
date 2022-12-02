/*
 * registers.h
 *
 * Created: 11/3/2022 8:05:35 PM
 *  Author: Abdurlahman Ayman
 */ 



#ifndef REGISTERS_H_
#define REGISTERS_H_
#include "types.h"
//Port A registers
#define PORTA *((volatile uint8_t*) 0x3B)
#define DDRA  *((volatile uint8_t*) 0x3A)
#define PINA  *((volatile uint8_t*) 0x39)
			  
//Port B registers
#define PORTB *((volatile uint8_t*) 0x38)
#define DDRB  *((volatile uint8_t*) 0x37)
#define PINB  *((volatile uint8_t*) 0x36)
			   
//Port C registers
#define PORTC *((volatile uint8_t*) 0x35)
#define DDRC  *((volatile uint8_t*) 0x34)
#define PINC  *((volatile uint8_t*) 0x33)
			    
//Port D registers
#define PORTD *((volatile uint8_t*) 0x32)
#define DDRD  *((volatile uint8_t*) 0x31)
#define PIND  *((volatile uint8_t*) 0x30)

//Timer0 registers
#define TCCR0 *((volatile uint8_t*) 0x53)
#define TCNT0 *((volatile uint8_t*) 0x52)
#define TIMSK *((volatile uint8_t*) 0x59)
#define TIFR  *((volatile  uint8_t*) 0x58)

//Timer1 registers
#define TCCR1A *((volatile uint8_t*) 0x4F)
#define TCCR1B *((volatile uint8_t*) 0x4E)
#define TCNT1H *((volatile uint8_t*) 0x4D)
#define TCNT1L *((volatile uint8_t*) 0x4C)


//External interrupt registers
#define MCUCR  *((volatile uint8_t*) 0x55)
#define MCUCSR *((volatile uint8_t*) 0x54)
#define GICR   *((volatile uint8_t*) 0x5B)
#define GIFR   *((volatile uint8_t*) 0x5A)



#endif /* REGISTERS_H_ */