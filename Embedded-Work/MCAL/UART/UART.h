/* 
 * File:   USART.h
 * Author: ak
 *
 * Created on March 16, 2023, 9:03 PM
 */

#ifndef UART_H
#define	UART_H
#include "Registers.h"
#include "DIO.h"

#define USART_BAUDRATE 103
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)	

void USART_Init( uint32_t baud );
void USART_Transmit( uint8_t data );
uint8_t USART_Receive( void );
void USART_SendString(char *str);

#endif	/* UART_H */
