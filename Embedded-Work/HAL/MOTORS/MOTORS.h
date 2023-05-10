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

typedef enum {
    MOTOR1,
    MOTOR2,
    MOTOR3,
    MOTOR4,
    LEFT_MOTORS,
    RIGHT_MOTORS,
    MOTORS,
}EN_motor_t;

typedef enum {
    LEFT_MOTORS_FORWARD,
    RIGHT_MOTORS_FORWARD,
    MOTORS_FORWARD,
    LEFT_MOTORS_BACKWARD,
    RIGHT_MOTORS_BACKWARD,
    MOTORS_BACKWARD,
    LEFT_MOTORS_STOP,
    RIGHT_MOTORS_STOP,
    STOP,
}EN_motorsState_t;

typedef enum {
    MOVE_FORWARD,
    MOVE_BACKWARD,
    MOVE_FORWARD_RIGHT,
    MOVE_FORWARD_LEFT,
    MOVE_BACKWARD_RIGHT,
    MOVE_BACKWARD_LEFT,
    TURN_FORWARD_RIGHT,
    TURN_FORWARD_LEFT,
    TURN_BACKWARD_RIGHT,
    TURN_BACKWARD_LEFT,
    TURN_AROUND_FORWARD_RIGHT,
    TURN_AROUND_FORWARD_LEFT,
    TURN_AROUND_BACKWARD_RIGHT,
    TURN_AROUND_BACKWARD_LEFT,

} EN_directions_t;

#define TURN_90     _delay_ms(750)
#define TURN_180    _delay_ms(1500)
#define TURN_270    _delay_ms(2250)
#define TURN_360    _delay_ms(3000)
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
void motorsInit(EN_motor_t);
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
void motorsState(EN_motorsState_t);
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
void moveCar(EN_directions_t direction);
void rotateCar(EN_directions_t direction, uint64_t degreeValue);
void stopAtDistance(float distance_cm) ;
uint8_t detectBlackLine();
void goToRoom1();
void goToRoom2();
void goToRoom3();
void goToRoom1_2();
void goToRoom1_2_3();
void goToRoom1_2_3();
 void degree(uint64_t deg);
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
void motorSpeed(uint8_t speed);
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

/*_________________________________________________________________________*/


#endif	/* MOTOR_H */
