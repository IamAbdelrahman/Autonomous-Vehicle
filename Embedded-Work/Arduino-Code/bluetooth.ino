#include <SoftwareSerial.h>

SoftwareSerial BTSerial(12, 13); // RX | TX

int ledPin = 7;
char receivedChar;

void setup() {
  BTSerial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (BTSerial.available()) {
    receivedChar = BTSerial.read();
    if (receivedChar == '1') {
      digitalWrite(ledPin, HIGH);
      BTSerial.write("LED is on\n");
    } else if (receivedChar == '0') {
      digitalWrite(ledPin, LOW);
      BTSerial.write("LED is off\n");
    }
  }
}
