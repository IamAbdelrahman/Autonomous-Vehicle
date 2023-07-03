#include "Arduino.h"
#include "MOTOR.h"

const int motorPin1 = 2;    // Motor 1 control pin
const int motorPin2 = 3;    // Motor 2 control pin
const int motorPin3 = 4;    // Motor 3 control pin
const int motorPin4 = 5;    // Motor 4 control pin
const int pwmPinA = 9;      // PWM pin A (controls motors 1 and 2 >> right motors)
const int pwmPinB = 10;     // PWM pin B (controls motors 3 and 4 >> left motors)

void DCMotor_init() {
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT); 
  pinMode(pwmPinA, OUTPUT);
  pinMode(pwmPinB, OUTPUT);
  
}

void DCMotor_setSpeed(){
  analogWrite(pwmPinA, 175);
  analogWrite(pwmPinB, 175);
}

void DCMotor_stop() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);  
  analogWrite(pwmPinA, 0);
  analogWrite(pwmPinB, 0);
}

void DCMotor_forward() {
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  
  DCMotor_setSpeed();
}

void DCMotor_backward() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  
  DCMotor_setSpeed();
}

void DCMotor_right() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, HIGH);
  
  DCMotor_setSpeed();
}
void DCMotor_left() {
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  
  DCMotor_setSpeed();
}
void DCMotor_turnRight() {
  DCMotor_right();
  delay(750);
}
void DCMotor_turnLeft() {
  DCMotor_left();
  delay(750);
}

void DCMotor_turnAround() {
  DCMotor_right();
  delay(1500);
}

void stopAtDistance(int distance_cm) {
  int d = 100;
  do {
    d = Ultrasonic_read();
  }
  while (d >= distance_cm);
  DCMotor_stop();
}

void detectLine() {
  while (!LineTracker_read());
}

void from1to2() {
  DCMotor_turnRight();
  DCMotor_forward();
  stopAtDistance(10);
  DCMotor_turnLeft();
  DCMotor_forward();
  stopAtDistance(5);
  DCMotor_turnRight();
  DCMotor_forward();
  stopAtDistance(10);
}

void from1to3() {
  from1to2();
  from2to3();
}

void from2to1() {
  DCMotor_turnAround();
  DCMotor_turnLeft();
  DCMotor_forward();
  stopAtDistance(5);
  DCMotor_turnRight();
  DCMotor_forward();
  stopAtDistance(5);
  DCMotor_turnRight();
  DCMotor_forward();
  stopAtDistance(10);
}

void from2to3() {
  DCMotor_turnAround();
  DCMotor_forward();
  stopAtDistance(5);
  DCMotor_turnLeft();
  DCMotor_forward();
  stopAtDistance(10);
}

void from3to2 () {
  DCMotor_turnAround();
  DCMotor_turnRight();
  DCMotor_forward();
  stopAtDistance(5);
  DCMotor_turnRight();
  DCMotor_forward();
  stopAtDistance(10);
}

void from3to1 () {
  from3to2();
  from2to1();
}

void fromStartto1() {
  DCMotor_forward();
  stopAtDistance(5);
}

void fromStartto2() {
  DCMotor_forward();
  detectLine();
  DCMotor_turnRight();
  DCMotor_forward();
  stopAtDistance(5);
  DCMotor_turnLeft();
  DCMotor_forward();
  stopAtDistance(5);
  DCMotor_turnRight();
  DCMotor_forward();
  stopAtDistance(5);
}

void fromStartto3() {
  DCMotor_turnRight();
  DCMotor_forward();
  stopAtDistance(5);
  DCMotor_turnRight();
  DCMotor_forward();
  stopAtDistance(5); 
}


void returnFrom1() {
  DCMotor_turnAround();
  DCMotor_turnRight();
  DCMotor_turnRight();
  DCMotor_forward();
  stopAtDistance(5);
  DCMotor_turnAround();
}

void returnFrom2() {
  from2to1();
  returnFrom1();
}

void returnFrom3() {
  DCMotor_turnRight();
  DCMotor_forward();
  stopAtDistance(10);
  DCMotor_turnLeft();
  stopAtDistance(10);
  DCMotor_turnAround();
}

void goToRoom1() {
  switch (positionOfCar) {
    case 0: // To go from start to room 1
      fromStartto1();
      positionOfCar = 1;
      break;
      
    case 2: // To go from room 2 to room 1
      from2to1();
      positionOfCar = 1;
      break;
      
    case 3: // To go from room 3 to room 1
      from3to1();
      positionOfCar = 1;
      break;
      
    default:
      break;
  }
}

void goToRoom2() {
  switch (positionOfCar) {
    case 0: // To go from start to room 2
      fromStartto2();
      positionOfCar = 2;
      break;
      
    case 1: // To go from room 1 to room 2
      from1to2();
      positionOfCar = 2;
      break;
      
    case 3: // To go from room 3 to room 2
      from3to2();
      positionOfCar = 2;
      break;
      
    default:
      break;
  }
}

void goToRoom3() {
  switch (positionOfCar) {
    case 0: // To go from start to room 3
      fromStartto3();
      positionOfCar = 3;     
      break;
      
    case 1: // To go from room 1 to room 3
      from1to3();
      positionOfCar = 3;
      break;
      
    case 2: // To go from room 2 to room 3
      from2to3();
      positionOfCar = 3;
      break;
  }
}

void goToStart () {
  switch (positionOfCar) {
    case 1:
      returnFrom1();
      break;
    case 2:
      returnFrom2();
      break;
    case 3:
      returnFrom3();
      break;
    default:
      break;
  }
  positionOfCar = 0;
}