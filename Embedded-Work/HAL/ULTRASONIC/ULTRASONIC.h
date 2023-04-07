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

void Ultra_Trig_Init(uint8_t portName, uint8_t pinNumber);
void Ultra_Echo_Init(uint8_t portName, uint8_t pinNumber);
void Ultra_Init(void);
void Ultra_Trig_Start(uint8_t portName, uint8_t pinNumber);
void Ultra_Echo_Start(void);
float Distance(void);

#endif	/* ULTRASONIC_H */
