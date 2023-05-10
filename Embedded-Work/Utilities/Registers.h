/*
 * Registers.h
 *
 *  Created on: Oct 10, 2022
 *      Author: ak
 */

#ifndef REGISTERS_H_
#define REGISTERS_H_
#include "Macros.h"
#include <avr/delay.h>
/* PORT A Registers */
#define PORTA   *((vuint8_t*)0x3B)	
#define DDRA    *((vuint8_t*)0x3A)	
#define PINA    *((vuint8_t*)0x39)	

/* PORT B Registers */
#define PORTB   *((vuint8_t*)0x38)	
#define DDRB    *((vuint8_t*)0x37)	
#define PINB    *((vuint8_t*)0x36)	

/* PORT C Registers */
#define PORTC   *((vuint8_t*)0x35)	
#define DDRC    *((vuint8_t*)0x34)	
#define PINC    *((vuint8_t*)0x33)	

/* PORT D Registers */
#define PORTD   *((vuint8_t*)0x32)	
#define DDRD    *((vuint8_t*)0x31)	
#define PIND    *((vuint8_t*)0x30)	

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


// TIMER0 - Registers
#define TCCR0       0x53	
#define TCNT0       *((vuint8_t*)0x52)	
#define TIFR        0x58
#define TIFR_R      *((vuint8_t*)0x58)
#define OCR0        *((vuint8_t*)0x5C)

// TIMER1 - Registers
#define TCCR1A      0x4F
#define TCCR1A_Reg  *((vuint8_t*)0x4F)
#define TCCR1B      0x4E
#define TCCR1B_Reg  *((vuint8_t*)0x4E)
#define TCNT1H      *((vuint8_t*)0x4D)
#define TCNT1L      *((vuint8_t*)0x4C)
#define OCR1AH      *((vuint8_t*)0x4B)
#define OCR1AL      *((vuint8_t*)0x4A)
#define OCR1BH      *((vuint8_t*)0x49)
#define OCR1BL      *((vuint8_t*)0x48)
#define ICR1H       *((vuint8_t*)0x47)
#define ICR1L       *((vuint8_t*)0x46)
#define TCCR1A_R    *((vuint8_t*)0x4F)
#define TCCR1B_R    *((vuint8_t*)0x4E)

// TIMER2 - Registers
#define TCCR2       0x45
#define TCNT2       *((vuint8_t*)0x44)	
#define OCR2        *((vuint8_t*)0x43)

// SFIOR - Register
#define SFIOR   *((vuint8_t*)0x50)
#define PSR10   0
#define PSR2    1
#define PUD     2
#define ACME    3
#define ADTS0   5
#define ADTS1   6
#define ADTS2   7

// USART - Registers
#define UDR     *((vuint16_t*)0x2C)
#define UCSRA   0x2B
#define ucsra   *((vuint8_t*)0x2B)
#define UCSRB   0x2A
#define UCSRC   0x40
#define UBRRL   *((vuint8_t*)0x29)
#define UBRRH   *((vuint8_t*)0x40)

#endif /* REGISTERS_H_ */