#include "Arduino.h"
#include "Application.h"

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
    freeControlMode();
  }
  else if (mode == 'r') {
    roomMode();
  }
  else if (mode == 'v') {
    voiceRecognitionMode();
  }
  else if (mode == 'o') {
    ocrMode();
  }
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
