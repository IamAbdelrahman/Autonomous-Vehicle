/* 
 * File:   IR.h
 * Author: manar essam - fatma monsef
 *
 * Created on March 11, 2023, 10:16 PM
 */

#ifndef IR_H
#define	IR_H

#include "DIO.h"
#include "MOTORS.h"
#include "ADC.h"
#include "TIMER.h"

/**********************lineTracker_Init****************************
 * Description: This function is used to initialize the IR-pin
 * by calling the DIO_Init_Pin() to make it an input pin
 * 
 * Input: It takes portName and pinNumber
 * Return: It returns void
 **********************lineTracker_Init****************************/
void lineTrackerInit(uint8_t portName, uint8_t pinNumber);
/*__________________________________________________________*/

/**********************lineTracker_Read****************************
 * Description: This function is used to read the output of 
 * the Line-Tracker sensor by storing the value of the output in a 
 * variable(e.g. lineTracker_State) that will be pointed by the pointer (State) 
 * through calling the function DIO_Read_Pin(), and this function will
 * take portName, pinNumber, and the address of the (lineTracker_State) to
 * store the value of reading in it.  
 * 
 * Input: It takes portName and pinNumber and pointer 'state'
 * Return: It returns nothing
 **********************lineTracker_Read****************************/
void lineTrackerRead(uint8_t portName, uint8_t pinNumber, uint8_t* State);
/*__________________________________________________________*/

#endif	/* IR_H */
