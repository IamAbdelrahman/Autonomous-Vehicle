/* 
 * File:   ULTRASONIC.h
 * Author: manar essam - fatma monsef
 *
 * Created on March 3, 2023, 9:28 PM
 */

#ifndef ULTRASONIC_H
#define	ULTRASONIC_H
#include "DIO.h"
#include "TIMER.h"

void TRIG_Init(uint8_t portName, uint8_t pinNumber);
void ECHO_Init(uint8_t portName, uint8_t pinNumber);




#endif	/* ULTRASONIC_H */

