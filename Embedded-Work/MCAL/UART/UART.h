/* 
 * File:   USART.h
 * Author: ak
 *
 * Created on March 16, 2023, 9:03 PM
 */

#ifndef UART_H
#define	UART_H
#include "Registers.h"

#define USART_BAUDRATE 9600
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)	

/* Initializing the UART */
#define TX_ENABLE   0
#define RX_ENABLE 1
#define TX_RX_ENABLE  2

#define DATA_BITS_5 3
#define DATA_BITS_6 4
#define DATA_BITS_7 5
#define DATA_BITS_8 6
#define DATA_BITS_9 7

#define PARITY_MODE_DISABLED    8
#define PARITY_MODE_ENABLED_EVEN   9
#define PARITY_MODE_ENABLED_ODD    10

#define STOP_BITS_1 11
#define STOP_BITS_2 12

#define NORMAL_SPEED    13
#define DOUBLE_SPEED    14

typedef struct {
    uint64_t baudRate;
    uint8_t enableTXorRX;
    uint8_t characterSize;
    uint8_t parity;
    uint8_t stopbitsNumber;
    uint8_t speed;

} ST_UART_config_t;

typedef struct {
    vuint8_t MPCM : 1;
    vuint8_t U2X : 1;
    vuint8_t PE : 1;
    vuint8_t DOR : 1;
    vuint8_t FE : 1;
    vuint8_t UDRE : 1;
    vuint8_t TXC : 1;
    vuint8_t RXC : 1;

} SUCSRA_t;

typedef union {
    vuint8_t All_Bits;
    SUCSRA_t Ucsra;

} UUCSRA_t;

typedef struct {
    vuint8_t TXB8 : 1;
    vuint8_t RXB8 : 1;
    vuint8_t UCSZ2 : 1;
    vuint8_t TXEN : 1;
    vuint8_t RXEN : 1;
    vuint8_t UDRIE : 1;
    vuint8_t TXCIE : 1;
    vuint8_t RXCIE : 1;

} SUCSRB_t;

typedef union {
    vuint8_t All_Bits;
    SUCSRB_t Ucsrb;

} UUCSRB_t;

typedef struct {
    vuint8_t UCPOL : 1;
    vuint8_t UCSZ0 : 1;
    vuint8_t UCSZ1 : 1;
    vuint8_t USBS : 1;
    vuint8_t UPM0 : 1;
    vuint8_t UPM1 : 1;
    vuint8_t UMSEL : 1;
    vuint8_t URSEL : 1;

} SUCSRC_t;

typedef union {
    vuint8_t All_Bits;
    SUCSRC_t Ucsrc;

} UUCSRC_t;

#define ADDRESS_UCSRA    (UUCSRA_t*)(UCSRA)
#define ADDRESS_UCSRB    (UUCSRB_t*)(UCSRB)
#define ADDRESS_UCSRC    (UUCSRC_t*)(UCSRC)

/******************************UART_TX_RX_Enable()**********************************
 * Description: This function is used to enable the transmitting or receiving
 * in the micro-controller or both of them
 * 
 * Input : It takes a pointer to structure that includes the configurations of 
 * the uart application.
 * Return: It returns nothing.
 ******************************UART_TX_RX_Enable()************************************/
void UART_TX_RX_Enable(ST_UART_config_t *pUART);
/*___________________________________________________________________________________*/

/******************************UART_Parity()**********************************
 * Description: This function is used to enable or disable the parity mode 
 * in micro-controller
 * 
 * Input : It takes a pointer to structure that includes the configurations of 
 * the uart application.
 * Return: It returns nothing.
 ******************************UART_Parity()************************************/
void UART_Parity(ST_UART_config_t *pUART);
/*___________________________________________________________________________________*/

/******************************UART_Data_Size()**********************************
 * Description: This function is used to determine the data sent size from
 * 5 - 9 bits
 * 
 * Input : It takes a pointer to structure that includes the configurations of 
 * the uart application.
 * Return: It returns nothing.
 ******************************UART_Data_Size()************************************/
void UART_Data_Size(ST_UART_config_t *pUART);
/*___________________________________________________________________________________*/

/******************************UART_Stop_Bit()**********************************
 * Description: This function is used to determine the number of stop bits
 * of the data sent (1 or 2) bits
 * 
 * Input : It takes a pointer to structure that includes the configurations of 
 * the uart application.
 * Return: It returns nothing.
 ******************************UART_Stop_Bit()************************************/
void UART_Stop_Bit(ST_UART_config_t *pUART);
/*___________________________________________________________________________________*/

/******************************UART_Speed()**********************************
 * Description: This function is used to determine the speed of transmitting
 * of data whether it should be normal or double
 * 
 * Input : It takes a pointer to structure that includes the configurations of 
 * the uart application.
 * Return: It returns nothing.
 ******************************UART_Speed()************************************/
void UART_Speed(ST_UART_config_t *pUART);
/*___________________________________________________________________________________*/

/******************************UART_Init()**********************************
 * Description: This function is used to initialize the uart through
 * calling all the function above
 * 
 * Input : It takes an unsigned short int to store the baudrate (e.g. 9600)
 * Return: It returns nothing.
 ******************************UART_Init()************************************/
void UART_Init(uint16_t Baud_Rate);
/*___________________________________________________________________________________*/

/******************************UART_TransmitChar()**********************************
 * Description: This function is used to transmit data by waiting for the UDRE
 * to be empty (the transmision buffering).
 * 
 * Input : It takes an unsigned character to store the data sent.
 * Return: It returns nothing.
 ******************************UART_TransmitChar()************************************/
void UART_TransmitChar(uint8_t data);
/*___________________________________________________________________________________*/

/******************************UART_ReceiveChar()**********************************
 * Description: This function is used to receive data from outside the world
 * 
 * Input : It takes an unsigned character to store the data sent.
 * Return: It returns nothing.
 ******************************UART_ReceiveChar()************************************/
uint16_t UART_ReceiveChar(void);
/*___________________________________________________________________________________*/

/******************************UART_TransmitString()**********************************
 * Description: This function is used to send string
 * 
 * Input : It takes a pointer to character
 * Return: It returns nothing.
 ******************************UART_TransmitString()************************************/
void UART_TransmitString(uint8_t *str);
/*___________________________________________________________________________________*/

/******************************UART_ReceiveString()**********************************
 * Description: This function is used to receive string
 * 
 * Input : It takes void
 * Return: It returns pointer to character.
 ******************************UART_ReceiveString()************************************/
uint8_t* UART_ReceiveString(void);
/*___________________________________________________________________________________*/

#endif	/* UART_H */
