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

void DCMotor_setSpeed(int speed) {
  analogWrite(pwmPinA, speed);
  analogWrite(pwmPinB, speed);
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
  DCMotor_setSpeed(125);
}

void DCMotor_backward() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  DCMotor_setSpeed(125);
}

void DCMotor_left() {
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  DCMotor_setSpeed(125);
}

void DCMotor_right() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  DCMotor_setSpeed(125);
}

void DCMotor_turnRight() {
  DCMotor_right();
  delay(750);
  DCMotor_stop();
}

void DCMotor_turnLeft() {
  DCMotor_left();
  delay(750);
  DCMotor_stop();
}

void DCMotor_turnAround() {
  DCMotor_right();
  delay(1500);
  DCMotor_stop();
}

void stopAtDistance(int distance_cm) {
  int d = Ultrasonic_read();
  if (d <= distance_cm) {
    DCMotor_stop();
    delay(2000);
  }
}

void detectLine() {
  if (LineTracker_read())
    DCMotor_turnRight();
}

void goToRoom1() {
  DCMotor_forward();
  stopAtDistance(10);
}

void goToRoom2() {
  DCMotor_forward();
  detectLine();
  DCMotor_forward();
  stopAtDistance(20);
  DCMotor_turnLeft();
  DCMotor_forward();
  stopAtDistance(20);
  DCMotor_turnRight();
  DCMotor_forward();
  stopAtDistance(10);
}

void goToRoom3() {
  DCMotor_turnRight();
  DCMotor_forward();
  stopAtDistance(5);
}

void goToRoom1_2() {
  DCMotor_turnRight();
  DCMotor_forward();
  stopAtDistance(20);
  DCMotor_turnLeft();
  DCMotor_forward();
  stopAtDistance(20);
  DCMotor_turnRight();
  DCMotor_forward();
  stopAtDistance(10);
}

void goToRoom2_3() {
  DCMotor_turnRight();
  DCMotor_forward();
  stopAtDistance(20);
  DCMotor_turnLeft();
  DCMotor_forward();
  stopAtDistance(10);
}

void goToRoom1_2_3() {
  goToRoom1_2();
  goToRoom2_3();
}

void returnFrom1() {
  DCMotor_turnAround();
  DCMotor_stop();
  delay(1000);
  DCMotor_forward();
  stopAtDistance(5);
  DCMotor_turnAround();
}
void returnFrom2() {
  DCMotor_turnRight();
  DCMotor_forward();
  detectLine();
  DCMotor_forward();
  stopAtDistance(10);
  DCMotor_turnLeft();
  DCMotor_forward();
  stopAtDistance(10);
  DCMotor_turnAround();
}

void returnFrom3() {
  DCMotor_turnAround();
  DCMotor_forward();
  stopAtDistance(10);
  DCMotor_turnRight();
}
