/* 
 * File:   BUTTON.h
 * Author: ak
 *
 * Created on March 15, 2023, 10:43 PM
 */

#ifndef BUTTON_H
#define	BUTTON_H
#include "Platform_Types.h"
#include "Registers.h"
#include "DIO.h"

/***************************BUTTON_Init**********************************
 * This function is used to initialize the status of the button connected to
 * any pin in any port register in the microcontroller. It must be an input
 * device by calling the function DIO_init() and passing a low value (0)
 * to it
 *
 * Inputs: (buttonPort): This is a character. It must be one of 
 * these characters 'A', 'B', 'C', and 'D' as they represent the
 * name of the ports of the microcontroller.
 *(buttonPin): It represents the pin number of each port
 * and takes a number from 0 : 7.
 * 
 * Return: Void
***************************BUTTON_Init**********************************/
void BUTTON_Init (uint8_t buttonPort, uint8_t buttonPin);
/*_____________________________________________________________________
 ______________________________________________________________________*/

/***************************BUTTON_Read**********************************
 * This function is used to read the status of the button connected to
 * any pin in any port register in the microcontroller. It must be an input
 * device by calling the function DIO_Read_Pin() and passing an address
 * of a variable to it to store the value of the status in
 *
 * Inputs: (buttonPort): This is a character. It must be one of 
 * these characters 'A', 'B', 'C', and 'D' as they represent the
 * name of the ports of the microcontroller.
 *(buttonPin): It represents the pin number of each port
 * and takes a number from 0 : 7.
 * (value): It is a pointer to a variable to write(store) the read value in
 * 
 * Return: Void
***************************BUTTON_Read**********************************/
void BUTTON_Read (uint8_t buttonPort, uint8_t buttonPin, uint8_t* value);
/*_____________________________________________________________________
 ______________________________________________________________________*/


#endif	/* BUTTON_H */
