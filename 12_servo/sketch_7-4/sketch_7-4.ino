#include <Servo.h>        // Servo motor library

Servo myServo;            // Create servo object

int motor = 12;           // Servo motor pin
int angle = 90;           // Initial angle of servo

void setup() {
  myServo.attach(motor);  // Connect servo to pin 12

  Serial.begin(9600);
  Serial.println("Initial angle : 90 degrees");
  Serial.println("Enter U(u) or D(d)");
  Serial.println("U : Increase the angle by 10 degrees");
  Serial.println("D : Decrease the angle by 10 degrees");
}

void loop() {
  if (Serial.available()) {
    char input = Serial.read();

    if (input == 'U' || input == 'u') {
      for (int i = 0; i < 10; i++) {
        angle += 1;
        if (angle >= 180) angle = 180;
        myServo.write(angle);
        delay(10);
      }
      Serial.println(angle);
    }

    else if (input == 'D' || input == 'd') {
      for (int i = 0; i < 10; i++) {
        angle -= 1;
        if (angle <= 0) angle = 0;
        myServo.write(angle);
        delay(10);
      }
      Serial.println(angle);
    }

    else if (input == '\n') {
      // Do nothing
    }

    else {
      Serial.println("wrong character!!");
    }
  }
}
