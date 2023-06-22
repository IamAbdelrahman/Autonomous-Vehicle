#include <SoftwareSerial.h>

SoftwareSerial BTSerial(12, 13); // RX | TX
char receivedChar;
const int ledPin = 11;
const int RX_PIN = 12;
const int motorPin1 = 2;    // Motor 1 control pin
const int motorPin2 = 3;    // Motor 2 control pin
const int motorPin3 = 4;    // Motor 3 control pin
const int motorPin4 = 5;    // Motor 4 control pin
const int pwmPinA = 9;      // PWM pin A (controls motors 1 and 2 >> right motors)
const int pwmPinB = 10;     // PWM pin B (controls motors 3 and 4 >> left motors)

int sensorPin = 12;         // LineTracker sensor pin

// Ultrasonic sensor pins
const int trigPin = 6;  // Trigger pin
const int echoPin = 7;  // Echo pin
// Variables for distance measurement
long duration;  // Time taken for the ultrasonic wave to travel
int distance;   // Calculated distance in centimeters

// Global variables
volatile bool moving = false;
volatile char order = '0';
volatile char temp;

void UART_ReceiveISR() {
  if (BTSerial.available()) {
    if (moving)
      temp = BTSerial.read();
    else {
      order = BTSerial.read();
      moving = true;
    }
  }
}

char mode; // f > free control - r > room mode

void setup() {
  BTSerial.begin(9600);
  DCMotor_init();
  Ultrasonic_init();
  LineTracker_init();
  attachInterrupt(digitalPinToInterrupt(RX_PIN), UART_ReceiveISR, FALLING);
  // BTSerial.write("Welcome to our project\n");
  //BTSerial.write("Please select a mode 'f' for free control and 'r' for room mode\n");
}

void loop() {
  mode = BTSerial.read();
  if (mode == 'f')
    freeControlMode();
  else if (mode == 'r')
    roomMode();
  else
    BTSerial.write("Error, try again\n");  
}

  void Ultrasonic_init() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

int Ultrasonic_read() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; 
  return distance;
}

void Display_distance() {
  Serial.print("Distance: ");
  Serial.print(Ultrasonic_read());
  Serial.println(" cm");
  delay(1000);
}

void LineTracker_init()
{
  pinMode (sensorPin, INPUT) ;
}

bool LineTracker_read() {
  bool val = digitalRead(sensorPin);
  return val;
}

void Display_lineStatus() {
  if (LineTracker_read() == HIGH)
    Serial.println("LineTracker is on the line");
  else
    Serial.println("Linetracker is not on the line");
  delay(500);
}

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
 // DCMotor_turnAround();
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

void freeControlMode () {
  if (BTSerial.available()) {
    receivedChar = BTSerial.read();
    if (receivedChar == 'w') {
      DCMotor_forward();
      BTSerial.write("Moving Forward\n");
    } else if (receivedChar == 's') {
      DCMotor_backward();
      BTSerial.write("Moving Backward\n");
    } else if (receivedChar == 'x') {
      DCMotor_stop();
      BTSerial.write("Stop\n");
    } else if (receivedChar == 'd') {
      DCMotor_turnRight();
      BTSerial.write("Moving Right\n");
    } else if (receivedChar == 'a') {
      DCMotor_turnLeft();
      BTSerial.write("Moving Left\n");
    }
  }
}

void roomMode () {
  BTSerial.write("Welcome to the room mode\n");
  while (moving == false);

  switch (order) {
    case '1':
      goToRoom1();
      returnFrom1();
      break;
    case '2':
      goToRoom2();
      returnFrom2();
      break;
    case '3':
      goToRoom3();
      returnFrom3();
      break;
    case '4':
      goToRoom1_2();
      break;
    case '5':
      goToRoom2_3();
      break;
    case '6':
      goToRoom1_2_3();
        break;
     case '7':
        returnFrom1();
        break;
      case '8':
        returnFrom2();
        break;
      case '9':
        returnFrom3();
        break;
      default:
        break;
    }

    moving = false;
    delay(1000);
  }

 /*  if (BTSerial.available()) {
    order = BTSerial.read();
    switch (order) {
      case '1':
        goToRoom1();
        break;
      case '2':
        goToRoom2();
        break;
      case '3':
        goToRoom3();
        break;
      case '4':
        goToRoom1_2();
        break;
      case '5':
        goToRoom2_3();
        break;
      case '6':
        goToRoom1_2_3();
          break;
        case '7':
          returnFrom1();
          break;
        case '8':
          returnFrom2();
          break;
        case '9':
          returnFrom3();
          break;
          case '0':
          DCMotor_stop();
          break;
        default:
          break;
      }
*/
