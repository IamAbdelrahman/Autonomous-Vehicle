#include "UART.h"

void USART_Init( uint32_t baud )
{
/* Set baud rate */
UBRRH = (uint8_t)(baud>>8);
UBRRL = (uint8_t)baud;
// UBRRL = BAUD_PRESCALE;
/* Enable receiver and transmitter */
UCSRB = (1<<4)|(1<<3);
/* Set frame format: 8data, 2stop bit */
UCSRC = (1<<7)|(1<<3)|(3<<1);
}

void USART_Transmit( uint8_t data )
{
/* Wait for empty transmit buffer */
while ( !( UCSRA & (1<<5)) );
/* Put data into buffer, sends the data */
UDR = data;
}

uint8_t USART_Receive( void )
{
/* Wait for data to be received */
while ( !(UCSRA & (1<<7)) )
;
/* Get and return received data from buffer */
return UDR;
}

void USART_SendString(char *str)
{
	unsigned char j=0;
	
	while (str[j]!=0)		/* Send string till null */
	{
		USART_Transmit(str[j]);	
		j++;
	}
}