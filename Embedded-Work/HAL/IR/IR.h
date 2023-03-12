/* 
 * File:   IR.h
 * Author: manar essam - fatma monsef
 *
 * Created on March 11, 2023, 10:16 PM
 */

#ifndef IR_H
#define	IR_H

#include "DIO.h"
#include "MOTOR.h"
#include "ADC.h"
#include "TIMER.h"

/**********************IR_Config****************************
 * Description: This function is used to configure the IR sensor
 * which is connected to the ADC pins, so we configure the 
 * reference selection, adjustment of bits in ADCL and ADCH register
 * and we set the prescaler. All this occur by calling the ADC_Config()
 * function that we pass the IR_Struct to it.
 * 
 * Input: It takes nothing
 * Return: It returns void
 **********************IR_Config****************************/
void IR_Config(void);
/*__________________________________________________________*/

/**********************IR_Init****************************
 * Description: This function is used to initialize the IR
 * sensors by calling the ADC_Init() function to make the pin
 * connected to the IR as an input pin and to enable the ADC
 * 
 * Input: It takes portName and pinNumber
 * Return: It returns void
 **********************IR_Init****************************/
void IR_Init(uint8_t portName, uint8_t pinNumber);
/*__________________________________________________________*/

/**********************IR_Read****************************
 * Description: This function is used to read the output of
 * ADC pins by calling the ADC_Read() function and converting
 * the analog voltage into digital voltage
 * 
 * Input: It takes portName and pinNumber
 * Return: It returns unsigned character
 **********************IR_Read****************************/
uint8_t IR_Read(uint8_t portName, uint8_t pinNumber);
/*__________________________________________________________*/

#endif	/* IR_H */

