#include "UART.h"

ST_UART_config_t S_UART = {BAUD_PRESCALE, TX_RX_ENABLE, DATA_BITS_8,
    PARITY_MODE_DISABLED, STOP_BITS_1, NORMAL_SPEED};

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
    pUCSRC->Ucsrc.URSEL = 1; // Enable accessing the USCRC Register.

    if (pUART->characterSize == DATA_BITS_5) {
        pUCSRC->Ucsrc.UCSZ0 = 0;
        pUCSRC->Ucsrc.UCSZ1 = 0;
        pUCSRB->Ucsrb.UCSZ2 = 0;
    } else if (pUART->characterSize == DATA_BITS_6) {
        pUCSRC->Ucsrc.UCSZ0 = 1;
        pUCSRC->Ucsrc.UCSZ1 = 0;
        pUCSRB->Ucsrb.UCSZ2 = 0;
    } else if (pUART->characterSize == DATA_BITS_7) {
        pUCSRC->Ucsrc.UCSZ0 = 0;
        pUCSRC->Ucsrc.UCSZ1 = 1;
        pUCSRB->Ucsrb.UCSZ2 = 0;
    } else if (pUART->characterSize == DATA_BITS_8) {
        pUCSRC->Ucsrc.UCSZ0 = 1;
        pUCSRC->Ucsrc.UCSZ1 = 1;
        pUCSRB->Ucsrb.UCSZ2 = 0;
    } else if (pUART->characterSize == DATA_BITS_9) {
        pUCSRC->Ucsrc.UCSZ0 = 1;
        pUCSRC->Ucsrc.UCSZ1 = 1;
        pUCSRB->Ucsrb.UCSZ2 = 1;
    }
}

void UART_Parity(ST_UART_config_t *pUART) {
    pUCSRC->Ucsrc.URSEL = 1; // Enable accessing the USCRC Register.
    if (pUART->parity == PARITY_MODE_DISABLED) {
        pUCSRC->Ucsrc.UPM0 = 0;
        pUCSRC->Ucsrc.UPM1 = 0;
    } else if (pUART->parity == PARITY_MODE_ENABLED_EVEN) {
        pUCSRC->Ucsrc.UPM0 = 0;
        pUCSRC->Ucsrc.UPM1 = 1;
    } else if (pUART->parity == PARITY_MODE_ENABLED_ODD) {
        pUCSRC->Ucsrc.UPM0 = 1;
        pUCSRC->Ucsrc.UPM1 = 1;
    }
}

void UART_Stop_Bit(ST_UART_config_t *pUART) {
    pUCSRC->Ucsrc.URSEL = 1; // Enable accessing the USCRC Register.
    if (pUART->stopbitsNumber == STOP_BITS_1) {
        pUCSRC->Ucsrc.USBS = 0;
    } else if (pUART->stopbitsNumber == STOP_BITS_2) {
        pUCSRC->Ucsrc.USBS = 1;
    }
}

void UART_Speed(ST_UART_config_t *pUART) {
    if (pUART->speed == NORMAL_SPEED) {
        pUCSRA->Ucsra.U2X = 0;
    } else if (pUART->speed == DOUBLE_SPEED) {
        pUCSRA->Ucsra.U2X = 1;
    }
}

void UART_Init(uint16_t Baud_Rate) {
    /* Set baud rate */
    UBRRL = (uint8_t) Baud_Rate;
    UBRRH = (uint8_t) (Baud_Rate >> 8);
    UART_TX_RX_Enable(&S_UART);
    UART_Data_Size(&S_UART);
    UART_Parity(&S_UART);
    UART_Stop_Bit(&S_UART);
    UART_Speed(&S_UART);
}

void UART_TransmitChar(uint8_t data) {
    /* Wait for empty transmit buffer */
    while (pUCSRA->Ucsra.UDRE == 0);
    /* Put data into buffer, sends the data */
    UDR = data;
}

uint8_t UART_ReceiveChar(void) {
    /* Wait for data to be received */
    while (pUCSRA->Ucsra.RXC == 0);
    /* Get and return received data from buffer */
    return UDR;
}

void UART_TransmitString(uint8_t *str) {
    uint8_t Char = 0;

    while (str[Char] != 0) /* Send string till null */ {
        UART_TransmitChar(str[Char]);
        Char++;
    }
}

void UART_ReceiveString(uint8_t* str) {
    uint8_t Char = 0;
    uint8_t i = 0;
    str[i] = UART_ReceiveChar();
    while (str[i] != '#'){
        i++;
        str[i] = UART_ReceiveChar();        
    }
    str[i] = '\0';
}

uint64_t stringCompare (uint8_t* arr1, uint8_t* arr2) {
    uint64_t flag = 0;
    uint8_t i = 0;
    while (arr2[i] != '#') {
        if (arr1[i] == arr2[i])
            flag = 1;
        else 
            flag = 0;
        i++;          
    }
    return flag; 
}

void enableUartRxInterrupt(){
    pUCSRB->Ucsrb.RXCIE = 1;
}
void disableUartRxInterrupt(){
    pUCSRB->Ucsrb.RXCIE = 0;
}
void enableUartTxInterrupt(){
    pUCSRB->Ucsrb.TXCIE = 1;
}
void disableUartTxInterrupt(){
    pUCSRB->Ucsrb.TXCIE = 0;
}