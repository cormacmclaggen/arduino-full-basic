#include <Servo.h>

Servo myServo;

void setup() {
  Serial.begin(9600);     // Serial communication
  myServo.attach(12);     // Control servo motor using digital pin 12
}

// Variable to store potentiometer output value
int val;
int angle;

void loop() {
  val = analogRead(A0);               // Read potentiometer value
  angle = map(val, 0, 1023, 0, 180);  // Map 0~1023 to 0~180 degrees

  myServo.write(angle);               // Move servo to mapped angle
  Serial.println(angle);              // Print angle on serial monitor
  delay(50);
}
