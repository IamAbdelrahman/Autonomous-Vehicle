#include <SoftwareSerial.h>

SoftwareSerial BTSerial(12, 13); // RX | TX
char receivedChar;

const int motorPin1 = 2;    // Motor 1 control pin
const int motorPin2 = 3;    // Motor 2 control pin
const int motorPin3 = 4;    // Motor 3 control pin
const int motorPin4 = 5;    // Motor 4 control pin

const int pwmPinA = 9;      // PWM pin A (controls motors 1 and 2)
const int pwmPinB = 10;     // PWM pin B (controls motors 3 and 4)

void setup() {
  BTSerial.begin(9600);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  
  pinMode(pwmPinA, OUTPUT);
  pinMode(pwmPinB, OUTPUT);

}

void loop() {
  
    if (BTSerial.available()) {
    receivedChar = BTSerial.read();
    if (receivedChar == 'w') {
      motorsForward();
      BTSerial.write("Moving Forward\n");
    } else if (receivedChar == 's') {
      motorsBackward();
      BTSerial.write("Moving Backward\n");
    } else if (receivedChar == 'x') {
      motorsStop();
      BTSerial.write("Stop\n");
    }
  }
}
  
void motorsForward() {
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  
  motorSpeed();
}

void motorsBackward() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  
  motorSpeed();
}

void motorsStop() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  
  analogWrite(pwmPinA, 0);
  analogWrite(pwmPinB, 0);
}

void motorSpeed(){
  analogWrite(pwmPinA, 255);
  analogWrite(pwmPinB, 255);
}
