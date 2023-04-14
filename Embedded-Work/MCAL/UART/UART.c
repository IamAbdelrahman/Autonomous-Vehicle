#include "UART.h"

ST_UART_config_t S_UART = {BAUD_PRESCALE, TX_RX_ENABLE, DATA_BITS_8,
    PARITY_MODE_DISABLED, STOP_BITS_2, NORMAL_SPEED};

volatile UUCSRA_t * const pUCSRA = ADDRESS_UCSRA;
volatile UUCSRB_t * const pUCSRB = ADDRESS_UCSRB;
volatile UUCSRC_t * const pUCSRC = ADDRESS_UCSRC;

void UART_TX_RX_Enable(ST_UART_config_t *pUART) {
    if (pUART-> enableTXorRX == TX_ENABLE) {
        pUCSRB->Ucsrb.TXEN = 1;
    } else if (pUART-> enableTXorRX == RX_ENABLE) {
        pUCSRB->Ucsrb.RXEN = 1;
    } else if (pUART->enableTXorRX == TX_RX_ENABLE) {
        pUCSRB->Ucsrb.RXEN = 1;
        pUCSRB->Ucsrb.TXEN = 1;
    }
}

void UART_Data_Size(ST_UART_config_t *pUART) {
    pUCSRC->Ucsrc.URSEL = 1; // Enalbe accessing the USCRC Register.
    
    if (pUART->characterSize == DATA_BITS_5) {
        
    } else if (pUART->characterSize == DATA_BITS_6) {

    } else if (pUART->characterSize == DATA_BITS_6) {

    } else if (pUART->characterSize == DATA_BITS_6) {

    }
}

void UART_Initialize(uint64_t Baud_Rate) {
    /* Set baud rate */
    UBRRL = BAUD_PRESCALE;
    UBRRH = (BAUD_PRESCALE >> 8);
}

/* Set frame format: 8data, 2stop bit */
UCSRC = (1 << 7) | (1 << 3) | (3 << 1);
}

void USART_Transmit(uint8_t data) {
    /* Wait for empty transmit buffer */
    while (!(UCSRA & (1 << 5)));
    /* Put data into buffer, sends the data */
    UDR = data;
}

uint8_t USART_Receive(void) {
    /* Wait for data to be received */
    while (!(UCSRA & (1 << 7)))
        ;
    /* Get and return received data from buffer */
    return UDR;
}

void USART_SendString(char *str) {
    unsigned char j = 0;

    while (str[j] != 0) /* Send string till null */ {
        USART_Transmit(str[j]);
        j++;
    }
}