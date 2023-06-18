const int motorPin1 = 2;    // Motor 1 control pin
const int motorPin2 = 3;    // Motor 2 control pin
const int motorPin3 = 4;    // Motor 3 control pin
const int motorPin4 = 5;    // Motor 4 control pin

const int pwmPinA = 9;      // PWM pin A (controls motors 1 and 2)
const int pwmPinB = 10;     // PWM pin B (controls motors 3 and 4)

void setup() {
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  
  pinMode(pwmPinA, OUTPUT);
  pinMode(pwmPinB, OUTPUT);
  
}

void loop() {
  // Move motors connected to PWM pin A forward at maximum speed
  motorsForward();
  delay(2000); // Wait for 2 seconds
  
  // Stop the motors connected to PWM pin A
  motorsStop();
  delay(1000); // Wait for 1 second
  
  // Move motors connected to PWM pin B backward at half speed
  motorsBackward();
  delay(2000); // Wait for 2 seconds
  
  // Stop the motors connected to PWM pin B
  motorsStop();
  delay(1000); // Wait for 1 second
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
  analogWrite(pwmPinA, 200);
  analogWrite(pwmPinB, 200);
}
