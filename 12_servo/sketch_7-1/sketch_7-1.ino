#include <Servo.h>

Servo myServo;        // Create a servo object to control the servo motor
// On most boards, up to 12 servo objects can be created

int angle = 90;       // Variable to store the servo position (angle)

void setup() {
  myServo.attach(12); // Attach the servo connected to pin 12
}

void loop() {
  // Move from 0 degree to 180 degree, 1 degree at a time
  for (angle = 0; angle <= 180; angle += 1) {
    myServo.write(angle);  // Move servo to the specified angle
    delay(5);             // Wait 15 ms for the servo to reach the position
  }

  // Move from 180 degree back to 0 degree, 1 degree at a time
  for (angle = 180; angle >= 0; angle -= 1) {
    myServo.write(angle);  // Move servo to the specified angle
    delay(5);             // Wait 15 ms for the servo to reach the position
  }
}
