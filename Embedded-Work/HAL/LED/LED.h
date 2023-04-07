#ifndef LED_H
#define	LED_H

#include "DIO.h"	

/***************************LED_Init**********************************
 * This function is used to initialize the status of the led connected to
 * any pin in any port register in the microcontroller. It must be an output
 * device by calling the function DIO_init() and passing a high value (1)
 * to it
 *
 * Inputs: (ledport): This is a character. It must be one of 
 * these characters 'A', 'B', 'C', and 'D' as they represent the
 * name of the ports of the microcontroller.
 *(ledpin): It represents the pin number of each port
 * and takes a number from 0 : 7.
 * 
 * Return: Void
***************************LED_Init**********************************/
void LED_Init (uint8_t ledport, uint8_t ledpin); 
/*_____________________________________________________________________
 ______________________________________________________________________*/

/***************************LED_On**********************************
 * This function is used to turn on the the led connected to
 * any pin in any port register in the microcontroller through calling the
 * function DIO_write() and passing high value (1) to it.
 *
 * Inputs: (ledport): This is a character. It must be one of 
 * these characters 'A', 'B', 'C', and 'D' as they represent the
 * name of the ports of the microcontroller.
 *(ledpin): It represents the pin number of each port
 * and takes a number from 0 : 7.
 * 
 * Return: Void
***************************LED_On**********************************/
void LED_On (uint8_t ledport, uint8_t ledpin);
/*_____________________________________________________________________
 ______________________________________________________________________*/

/***************************LED_Off**********************************
 * This function is used to turn off the the led connected to
 * any pin in any port register in the microcontroller through calling the
 * function DIO_write() and passing low value (0) to it.
 *
 * Inputs: (ledport): This is a character. It must be one of 
 * these characters 'A', 'B', 'C', and 'D' as they represent the
 * name of the ports of the microcontroller.
 *(ledpin): It represents the pin number of each port
 * and takes a number from 0 : 7.
 * 
 * Return: Void
***************************LED_Off**********************************/
void LED_Off (uint8_t ledport, uint8_t ledpin);
/*_____________________________________________________________________
 ______________________________________________________________________*/

/***************************LED_Toggle**********************************
 * This function is used to toggle the the led connected to
 * any pin in any port register in the microcontroller through calling the
 * function DIO_toggle().
 *
 * Inputs: (ledport): This is a character. It must be one of 
 * these characters 'A', 'B', 'C', and 'D' as they represent the
 * name of the ports of the microcontroller.
 *(ledpin): It represents the pin number of each port
 * and takes a number from 0 : 7.
 * 
 * Return: Void
***************************LED_Toggle**********************************/
void LED_Toggle (uint8_t ledport, uint8_t ledpin);
/*_____________________________________________________________________
 ______________________________________________________________________*/

#endif	/* LED_H */