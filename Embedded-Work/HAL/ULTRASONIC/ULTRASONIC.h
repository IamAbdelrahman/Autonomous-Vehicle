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

#define TRIG_PIN    0
#define ECHO_PIN    1
#define US_ERROR		-1    
#define	US_NO_OBSTACLE	-2
/**********************Ultra_Trig_Init****************************
 * Description: This function is used to initialize all motors
 * thorough initializing all the bits connected to the motors
 * by calling MOTOR1_Init(), MOTOR2_Init(), MOTOR3_Init(), and
 * MOTOR4_Init() functions. It also initializes the TIMER0 and 
 * starts it because of the PWM we use it to control the speed
 * of the motors.
 * 
 * Input: It takes nothing like all the functions inside it
 * Return: It returns void
 **********************Ultra_Trig_Init****************************/
void Ultra_Trig_Init(uint8_t portName, uint8_t pinNumber);
void Ultra_Echo_Init(uint8_t portName, uint8_t pinNumber);
void Ultra_Init(void);
void Ultra_Trig_Start(uint8_t portName, uint8_t pinNumber);
void Ultra_Echo_Start(void);
float Distance(void);
uint16_t getPulseWidth(void);
/*
 * Description: This function is used to check if the ultrasonic is 
 * working correctly or not. It checks the echo pin for amount of time.
 * 
 */
#endif	/* ULTRASONIC_H */
