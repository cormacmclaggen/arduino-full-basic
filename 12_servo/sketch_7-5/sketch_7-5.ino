#include <Stepper.h>

// To rotate one full revolution (360 degrees),
// 2048 steps are required
const int stepsPerRevolution = 2048;

// Create Stepper object
// Arduino digital pins: 8, 10, 9, 11
// (IN1, IN3, IN2, IN4 sequence)
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  // Set stepper motor speed to 14 RPM
  myStepper.setSpeed(14);
}

void loop() {
  // Rotate one revolution counterclockwise
  myStepper.step(stepsPerRevolution);
  delay(500);

  // Rotate one revolution clockwise
  myStepper.step(-stepsPerRevolution);
  delay(500);
}
