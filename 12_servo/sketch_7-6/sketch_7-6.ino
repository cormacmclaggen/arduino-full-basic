#include <Stepper.h>

// 2048 / 8 = 256 steps (256 steps = 45 degrees)
const int stepsPerRevolution = 2048 / 8;

// Connect ULN2003 IN1, IN2, IN3, IN4
// to Arduino D8, D9, D10, D11 (sequence 1-3-2-4)
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  // Set motor speed to 120 RPM
  myStepper.setSpeed(120);

  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {

    Serial.println("clockwise");
    // Move 8 times stepsPerRevolution (clockwise = 1 full rotation)
    for (int x = 1; x < 9; x++) {
      myStepper.step(stepsPerRevolution);
      Serial.println(x);   // Print current iteration count
    }

    delay(500);

    Serial.println("counterclockwise");
    // Move 8 times -stepsPerRevolution (counterclockwise = 1 full rotation)
    for (int x = 1; x < 9; x++) {
      myStepper.step(-stepsPerRevolution);
      Serial.println(x);   // Print current iteration count
    }

    delay(500);
  }
}
