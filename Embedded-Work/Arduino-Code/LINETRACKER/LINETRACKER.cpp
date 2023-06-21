#include "LINETRACKER.h"
int sensorPin = 12;

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
