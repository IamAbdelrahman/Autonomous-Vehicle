/*
 * Registers.h
 *
 *  Created on: Oct 10, 2022
 *      Author: ak
 */

#ifndef REGISTERS_H_
#define REGISTERS_H_
#include "Platform_Types.h"

#define FCPU    1000000
#define SET_BIT(X, BIT_NO)   (X |= (1 << BIT_NO))
#define CLR_BIT(X, BIT_NO)  (X &= ~(1 << BIT_NO))
#define TOGGLE_BIT(X, BIT_NO)   (X ^= (1 << BIT_NO))
#define READ_BIT(X, BIT_NO) ((X & (1 << BIT_NO) >> BIT_NO))

/* PORT A Registers */
#define PORTA *((vuint8_t*)0x3B)	
#define DDRA *((vuint8_t*)0x3A)	
#define PINA *((vuint8_t*)0x39)	

/* PORT B Registers */
#define PORTB *((vuint8_t*)0x38)	
#define DDRB *((vuint8_t*)0x37)	
#define PINB *((vuint8_t*)0x36)	

/* PORT C Registers */
#define PORTC *((vuint8_t*)0x35)	
#define DDRC *((vuint8_t*)0x34)	
#define PINC *((vuint8_t*)0x33)	

/* PORT D Registers */
#define PORTD *((vuint8_t*)0x32)	
#define DDRD *((vuint8_t*)0x31)	
#define PIND *((vuint8_t*)0x30)	

/*
 * Another approach (method) to access the registers by using
 * structures, unions , and bit-fields to save our memory and hence
 * our code will be efficient, redundant, and more readable
 */

// GPIO - Registers - Absolute Address
#define PORT_A   0x3B
#define DDR_A    0x3A
#define PIN_A    0x39
#define PORT_B   0x38
#define DDR_B    0x37
#define PIN_B    0x36
#define PORT_C   0x35
#define DDR_C    0x34
#define PIN_C    0x33
#define PORT_D   0x32
#define DDR_D    0x31
#define PIN_D    0x30

#define ADDRESS_DDRA    (UGPIO_t*)DDR_A
// TIMER - Registers
#define TCCR0    0x53	
#define TCNT0    0x52	
#define TIFR     0x58

#endif /* REGISTERS_H_ */