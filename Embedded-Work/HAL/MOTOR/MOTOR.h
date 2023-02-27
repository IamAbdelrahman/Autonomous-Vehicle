/* 
 * File:   MOTOR.h
 * Author: ak
 *
 * Created on February 25, 2023, 11:37 PM
 */

#ifndef MOTOR_H
#define	MOTOR_H
#include "../MCAL/DIO.h"
#include "../MCAL/TIMER.h"

void MOTOR_Init (void);
void MOTOR_Clkwise (void);
void MOTOR_Anticlkwise (void);
void MOTOR_Stop (void);

#endif	/* MOTOR_H */

