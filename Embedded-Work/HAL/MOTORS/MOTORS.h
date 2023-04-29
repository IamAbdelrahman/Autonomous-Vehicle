/* 
 * File:   MOTOR.h
 * Author: ak
 *
 * Created on February 25, 2023, 11:37 PM
 */

#ifndef MOTOR_H
#define	MOTOR_H
#include "DIO.h"
#include "TIMER.h"
#include "ADC.h"
#include "ULTRASONIC.h"
#include "LINE_TRACKER.h"

/**********************MOTORS_Init****************************
 * Description: This function is used to initialize all motors
 * thorough initializing all the bits connected to the motors
 * by calling MOTOR1_Init(), MOTOR2_Init(), MOTOR3_Init(), and
 * MOTOR4_Init() functions. It also initializes the TIMER0 and 
 * starts it because of the PWM we use it to control the speed
 * of the motors.
 * 
 * Input: It takes nothing like all the functions inside it
 * Return: It returns void
 **********************MOTORS_Init****************************/
void motor1Init(void);
void motor2Init(void);
void motor3Init(void);
void motor4Init(void);
void leftmotorsInit(void);
void rightmotorsInit(void);
void motorsInit(void);
/*_____________________________________________________________*/

/**********************MOTORS_Clkwise**********************************
 * Description: This function is used to rotate all motors in clockwise
 * direction thorough setting the bits connected to the positive
 * terminal of the DC-Motors and clearing the bits connected to
 * the negative terminal of the DC-Motors and this occurs by
 * calling MOTOR1_Clkwise(), MOTOR2_Clkwise(), MOTOR3_Clkwise(), and
 * MOTOR4_Clkwise() functions.
 * 
 * Input: It takes nothing like all the functions inside it
 * Return: It returns void
 **********************MOTORS_Clkwise***********************************/
void motor1Forward(void);
void motor2Forward(void);
void motor3Forward(void);
void motor4Forward(void);
void leftmotorsForward(void);
void rightmotorsForward(void);
void motorsForward (void);
/*_______________________________________________________________________*/

/**********************MOTORS_Anticlkwise**********************************
 * Description: This function is used to rotate all motors in anti-clockwise
 * direction thorough clearing the bits connected to the positive
 * terminal of the DC-Motors and setting the bits connected to
 * the negative terminal of the DC-Motors and this occurs by
 * calling MOTOR1_Anticlkwise(), MOTOR2_Anticlkwise(), MOTOR3_Anticlkwise()
 * , and MOTOR4_Anticlkwise() functions.
 * 
 * Input: It takes nothing like all the functions inside it
 * Return: It returns void
 **********************MOTORS_Anticlkwise***********************************/
void motor1Backward (void);
void motor2Backward(void);
void motor3Backward(void);
void motor4Backward(void);
void leftmotorsBackward(void);
void rightmotorsBackward(void);
void motorsBackward(void);
/*_________________________________________________________________________*/

/**********************MOTORS_Stop**********************************
 * Description: This function is used to stop all motors through
 * clearing all the bits connected to them and this occurs by
 * calling MOTOR1_Stop(), MOTOR2_Stop(), MOTOR3_Stop()
 * , and MOTOR4_Stop() functions.
 * 
 * Input: It takes nothing like all the functions inside it
 * Return: It returns void
 **********************MOTORS_Stop***********************************/
void motor1Stop(void);
void motor2Stop(void);
void motor3Stop(void);
void motor4Stop(void);
void leftmotorsStop(void);
void rightmotorsStop(void);
void motorsStop(void);
void Stop(void);
/*_________________________________________________________________________*/

/**********************Move_Forward**********************************
 * Description: This function is used to move the car in the forward
 * direction through calling the MOTORS_Anticlkwise() function
 * #Assuming : This direction is fixed with respect to the path
 * 
 * Input: It takes nothing like all the functions inside it
 * Return: It returns void
 **********************Move_Forward***********************************/
void moveForward(void);
/*_________________________________________________________________________*/

/**********************Move_Backward**********************************
 * Description: This function is used to move the car in the backward
 * direction through calling the MOTORS_Clkwise() function
 * #Assuming : This direction is fixed with respect to the path
 * 
 * Input: It takes nothing like all the functions inside it
 * Return: It returns void
 **********************Move_Backward***********************************/
void moveBackward(void);
/*_________________________________________________________________________*/

/**********************Move_Right**********************************
 * Description: This function is used to turn the car right
 * through moving only the left motors anticlokwise and stopping
 * the right motors and this occurs by calling the MOTOR1_Stop() and
 * MOTOR2_Stop() in addition that calling the MOTOR3_Anticlkwise() and
 * MOTOR4_Anticlkwise().
 * #Assuming : This direction is fixed with respect to the path
 * 
 * Input: It takes nothing like all the functions inside it
 * Return: It returns void
 **********************Move_Right***********************************/
void moveForwardRight(void);
void moveBackwardRight(void);
/*_________________________________________________________________________*/

/**********************Move_Left**********************************
 * Description: This function is used to turn the car left
 * through moving only the right motors anticlokwise and stopping
 * the left motors and this occurs by calling the MOTOR3_Stop() and
 * MOTOR4_Stop() in addition that calling the MOTOR1_Anticlkwise() and
 * MOTOR2_Anticlkwise().
 * #Assuming : This direction is fixed with respect to the path
 * 
 * Input: It takes nothing like all the functions inside it
 * Return: It returns void
 **********************Move_Left***********************************/
void moveForwardLeft(void);
void moveBackwardLeft(void);
/*_________________________________________________________________________*/

/**********************MOTOR_Speed**********************************
 * Description: This function is used to control the speed of the 
 * motors by sending the value from 0:100 and this value is sent
 * to the pwm_start() function that takes the same range to calculate
 * the value of OCR0.
 * 
 * Input: It takes unsigned character speed.
 * Return: It returns void
 **********************MOTOR_Speed***********************************/
void MOTOR_Speed(uint8_t speed);
/*_________________________________________________________________________*/

#endif	/* MOTOR_H */
