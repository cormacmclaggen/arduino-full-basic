#include <Servo.h>

Servo myServo;          // Create a servo object
int motorPin = 12;      // Servo motor connected to pin 12
int pushPin = 7;        // Push button connected to pin 7
int angle = 90;         // Initial servo position (center)
int state = 0;          // Rotation direction state
                        // state = 0 → clockwise
                        // state = 1 → counterclockwise

void setup() {
  myServo.attach(motorPin);   // Attach servo to pin 12
  pinMode(pushPin, INPUT);    // Set push button pin as input

  Serial.begin(9600);         // Serial communication
  Serial.println("Enter the push button.");
}

void loop() {
  if (digitalRead(pushPin) == HIGH) {
    if (state == 0) {
      angle += 1;             // Increase angle
      if (angle >= 180) state = 1;
      myServo.write(angle);
      delay(10);
      Serial.println(angle);
    }
    else {
      angle -= 1;             // Decrease angle
      if (angle <= 0) state = 0;
      myServo.write(angle);
      delay(10);
      Serial.println(angle);
    }
  }
}
