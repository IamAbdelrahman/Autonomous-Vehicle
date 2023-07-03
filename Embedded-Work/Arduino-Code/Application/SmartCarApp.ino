#include <SoftwareSerial.h>

const int RX_PIN = 12;
const int TX_PIN = 13;
SoftwareSerial BTSerial(RX_PIN, TX_PIN); // RX | TX

const int motorPin1 = 2;    // Motor 1 control pin
const int motorPin2 = 3;    // Motor 2 control pin
const int motorPin3 = 4;    // Motor 3 control pin
const int motorPin4 = 5;    // Motor 4 control pin
const int pwmPinA = 9;      // PWM pin A (controls motors 1 and 2 >> right motors (OUT1-OUT2)
const int pwmPinB = 10;     // PWM pin B (controls motors 3 and 4 >> left motors) (OUT3-OUT4)

// Ultrasonic sensor pins
const int trigPin = 6;
const int echoPin = 7;
long duration;
int distance;

// LineTracker sensor pin
int lineTrackerPin = 8;

// Global variables
char receivedChar ;
char mode = 'f'; // f > free control - r > room mode
int positionOfCar = 0;

void setup() {
  BTSerial.begin(9600);
  DCMotor_init();
  Ultrasonic_init();
  LineTracker_init();
}

void loop() {
    if (mode == 'f') {
      freeControlMode(data);
    }
    else if (mode == 'r') {
      roomMode(data);
    }
    else if (mode == 'v') {
      voiceRecognitionMode();
    }
    else {
      ocrMode();
    }
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
}

void LineTracker_init()
{
  pinMode (lineTrackerPin, INPUT) ;
}

bool LineTracker_read() {

  bool val = digitalRead(lineTrackerPin);
  return val;
}

void Display_lineStatus() {
  if (LineTracker_read() == HIGH)
    Serial.println("LineTracker is on the line");
  else
    Serial.println("Linetracker is not on the line");
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
  DCMotor_setSpeed(85);
}

void DCMotor_backward() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  DCMotor_setSpeed(135);
}

void DCMotor_left() {
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  DCMotor_setSpeed(135);
}

void DCMotor_right() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  DCMotor_setSpeed(135);
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
  //DCMotor_turnRight();
  //DCMotor_forward();
  //stopAtDistance(10);
}

void from1to3() {
  from1to2();
  from2to3();
}

void from2to1() {
  //DCMotor_turnAround();
  DCMotor_turnLeft();
  DCMotor_forward();
  stopAtDistance(5);
  DCMotor_turnRight();
  DCMotor_forward();
  stopAtDistance(5);
  //DCMotor_turnRight();
  //DCMotor_forward();
  //stopAtDistance(10);
}

void from2to3() {
  DCMotor_turnAround();
  DCMotor_forward();
  stopAtDistance(5);
  //DCMotor_turnLeft();
  //DCMotor_forward();
  //stopAtDistance(10);
}

void from3to2 () {
  DCMotor_turnAround();
  //DCMotor_turnRight();
  DCMotor_forward();
  stopAtDistance(5);
  // DCMotor_turnRight();
  //DCMotor_forward();
  //stopAtDistance(10);
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

/*void fromStartto2() {
  fromStartto1();
  from1to2();
  }
*/
void fromStartto3() {
  DCMotor_turnRight();
  DCMotor_forward();
  stopAtDistance(5);
  //DCMotor_turnRight();
  //DCMotor_forward();
  //stopAtDistance(5);
}


void returnFrom1() {
  //DCMotor_turnAround();
  DCMotor_turnRight();
  DCMotor_turnRight();
  DCMotor_forward();
  stopAtDistance(5);
  DCMotor_turnAround();
}

void returnFrom2() {
  /* DCMotor_turnRight();
    DCMotor_forward();
    detectLine();
    DCMotor_turnRight();
    DCMotor_forward();
    stopAtDistance(10);
    DCMotor_turnLeft();
    DCMotor_forward();
    stopAtDistance(10);
    DCMotor_turnAround();
  */

  from2to1();
  returnFrom1();
}

void returnFrom3() {
  /* DCMotor_turnAround();
    DCMotor_forward();
    stopAtDistance(5);
    DCMotor_turnRight();
  */
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

void freeControlMode () {
  char receivedChar = BTSerial.read();
  switch (receivedChar) {
    case 'w':
      DCMotor_forward();
      break;

    case 's':
      DCMotor_backward();
      break;

    case 'd':
      DCMotor_turnRight();
      break;

    case 'a':
      DCMotor_turnLeft();
      break;

    case 'x':
      DCMotor_stop();
      break;

    case '0':
      positionOfCar = 0;
      break;

    case '1':
      positionOfCar = 1;
      break;

    case '2':
      positionOfCar = 2;
      break;

    case '3':
      positionOfCar = 3;
      break;

    case 'r':
      DCMotor_stop();
      mode = 'r';
      BTSerial.write("Welcome to Room-Mode\n");
      break;
      
    case 'o':
      DCMotor_stop();
      mode = 'o';
      BTSerial.write("Welcome to OCR-Mode\n");
      break;
      
      case 'v':
      DCMotor_stop();
      mode = 'v';
      BTSerial.write("Welcome to Voice-Mode\n");
      break;
      
    case 'S':
      exit(0);
      break;

    default:
      break;

  }
}

void roomMode () {
  char data = BTSerial.read();
  switch (data) {
    case '1':
      goToRoom1();
      break;

    case '2':
      goToRoom2();
      break;

    case '3':
      goToRoom3();
      break;

    case '0':
      goToStart();
      break;

    case 'f':
      DCMotor_stop();
      mode = 'f';
      BTSerial.write("Welcome to Free Control-Mode\n");

    case 'v':
      DCMotor_stop();
      mode = 'v';
      BTSerial.write("Welcome to Voice-Mode\n");
      break;

    case 'o':
      DCMotor_stop();
      mode = 'o';
      BTSerial.write("Welcome to OCR-Mode\n");
      break;

    case 'S':
      exit(0);
      break;

    default:
      break;
  }
  if (BTSerial.available()) {
    char temp = BTSerial.read();
  }
}

void voiceRecognitionMode(char* data) {
  char* data = BTSerial.read();
  if (strcmp(data, "Move Forward") == 0) {
    DCMotor_forward();
  } else if (strcmp(data, "Move Backward") == 0) {
    DCMotor_backward();
  } else if (strcmp(data, "Turn Left") == 0) {
    DCMotor_turnLeft();
  } else if (strcmp(data, "Turn Right") == 0) {
    DCMotor_turnRight();
  } else if (strcmp(data, "Stop") == 0) {
    DCMotor_stop();
  } else if (strcmp(data, "One") == 0) {
    positionOfCar = 1;
  } else if (strcmp(data, "Two") == 0) {
    positionOfCar = 2;
  } else if (strcmp(data, "Three") == 0) {
    positionOfCar = 3;
  } else if (strcmp(data, "Zero") == 0) {
    positionOfCar = 0;
  } else if (strcmp(data, "Free Control Mode") == 0) {
    DCMotor_stop();
    mode = 'f';
    BTSerial.write("Welcome to Free Control-Mode\n");
  } else if (strcmp(data, "Room Mode") == 0) {
    DCMotor_stop();
    mode = 'r';
    BTSerial.write("Welcome to Room-Mode\n");
  } else if (strcmp(data, "OCR Mode") == 0) {
    DCMotor_stop();
    mode = 'o';
    BTSerial.write("Welcome to OCR-Mode\n");
  } else if (strcmp(data, "Shut Down") == 0) {
    exit(0);
  } else {
    // Handle unrecognized command
    Serial.println("Unrecognized command");
  }
}

void ocrMode () {
  char data = BTSerial.read();
  switch (data) {
    case '1':
      goToRoom1();
      break;

    case '2':
      goToRoom2();
      break;

    case '3':
      goToRoom3();
      break;

    case '0':
      goToStart();
      break;

    case 'f':
      DCMotor_stop();
      mode = 'f';
      BTSerial.write("Welcome to Free Control-Mode\n");
      break;

    case 'r':
      DCMotor_stop();
      mode = 'r';
      BTSerial.write("Welcome to Room-Mode\n");
      break;

    case 'v':
      DCMotor_stop();
      mode = 'v';
      BTSerial.write("Welcome to Voice-Mode\n");
      break;

    case 'S':
      exit(0);
      break;

    default:
      break;
  }
  if (BTSerial.available()) {
    char temp = BTSerial.read();
  }
}
