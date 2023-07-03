#ifndef Motor_h
#define Motor_h

#include "Arduino.h"
#include "Ultrasonic.h"
#include "LineTracker.h"

void DCMotor_init();
void DCMotor_setSpeed();
void DCMotor_forward();
void DCMotor_backward();
void DCMotor_right();
void DCMotor_left();
void DCMotor_turnRight();
void DCMotor_turnLeft();
void DCMotor_turnAround();
void DCMotor_stop();
void stopAtDistance(int distance_cm);
void detectLine();

// Room Functions
void from1to2();
void from1to3();
void from2to1();
void from2to3();
void from3to1();
void from3to2();
void fromStartto1();
void fromStartto2();
void fromStartto3();
void goToRoom1();
void goToRoom2();
void goToRoom3();
void goToStart();
void returnFrom1();
void returnFrom2();
void returnFrom3();

#endif
