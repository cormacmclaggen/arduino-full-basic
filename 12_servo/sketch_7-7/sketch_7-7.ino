#include <Stepper.h>

const int STEPS = 2048;          // 2048 steps = 360 degrees rotation

// Create a Stepper object
// Stepper(STEPS, IN1, IN3, IN2, IN4)
Stepper stepper(STEPS, 8, 10, 9, 11);

void setup() {
  stepper.setSpeed(14);          // Set stepper motor speed to 14 RPM
  Serial.begin(9600);            // Start serial communication at 9600 baud
  Serial.println("Enter the rotation angle.");
}

void loop() {
  if (Serial.available()) {      
    int val = Serial.parseInt();             // Read an integer value from Serial Monitor
    val = map(val, -360, 360, -2048, 2048);  // Map angle (-360~360) to steps (-2048~2048)
    stepper.step(val);                       // Rotate the stepper motor by the mapped steps
    Serial.println(val);                     // Print the step value to Serial Monitor
    delay(10);                               // Small delay
  }
}
