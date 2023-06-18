// Ultrasonic sensor pins
const int trigPin = 6;  // Trigger pin
const int echoPin = 7;  // Echo pin
const int ledPin = 8;   // Led pin

// Variables for distance measurement
long duration;  // Time taken for the ultrasonic wave to travel
int distance;   // Calculated distance in centimeters

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Configure the sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the pulse duration
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance
  distance = duration * 0.034 / 2;  // Divide by 2 for round trip
  if (distance <= 10){
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }

  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Delay before the next measurement
  delay(1000);
}
