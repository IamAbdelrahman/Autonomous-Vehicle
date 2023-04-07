/* 
 * File:   BLUETOOTH.h
 * Author: ak
 *
 * Created on March 16, 2023, 8:54 PM
 */

#ifndef BLUETOOTH_H
#define	BLUETOOTH_H
#include "DIO.h" 
#include "UART.h"
#include "MOTORS.h"

/******************************BLUETOOTH_Init()**********************************
 * Description: This function is used initialize the usart communication
 * protocol with baudrate = 103 as we work on 16MHZ.
 * 
 * Input : It takes nothing.
 * Return: It returns nothing.
 ******************************BLUETOOTH_Init()************************************/
void BLUETOOTH_Init(void);
/*_________________________________________________________________*/

/******************************BLUETOOTH_Read()**********************************
 * Description: This function is used to read characters from the user
 * and each character indicates an action.
 * 
 * Input : It takes unsigned character variable to store the value
 * of USART_Recieve() function.
 * Return: It returns nothing.
 ******************************BLUETOOTH_Read()************************************/
void BLUETOOTH_Read(uint8_t Data_In);
/*_________________________________________________________________*/

#endif	/* BLUETOOTH_H */
