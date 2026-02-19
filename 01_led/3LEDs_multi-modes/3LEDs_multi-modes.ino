/*
  Serial Multi-Mode LED Control (3 LEDs)

  LED pins: 2, 4, 6

  Commands:
  0 = All OFF
  1 = All ON
  2 = Chase (2 -> 4 -> 6) every 500 ms
  3 = Blink all every 1000 ms
  4 = Alternate (2+6 ON <-> 4 ON)
  5 = Traffic style (2 -> 4 -> 6)
  6 = Continuous running (2 -> 4 -> 6 -> 4 -> 2 ...)
*/

int leds[3] = {2, 4, 6};      // LED pins
int mode = 0;                // Current mode
int stepIndex = 0;           // Step index for patterns
int direction = 1;           // Direction for continuous running
bool ledState = LOW;         // Used for blinking
unsigned long prevTime = 0;  // Time tracking

void setup() {
  // Set LED pins as OUTPUT
  for (int i = 0; i < 3; i++) {
    pinMode(leds[i], OUTPUT);
  }

  Serial.begin(9600);
  Serial.println("3-LED MULTI MODE CONTROL");
  Serial.println("0:OFF 1:ON 2:CHASE 3:BLINK 4:ALT 5:TRAFFIC 6:CONTINUOUS");
}

void allOff() {
  for (int i = 0; i < 3; i++) digitalWrite(leds[i], LOW);
}

void allOn() {
  for (int i = 0; i < 3; i++) digitalWrite(leds[i], HIGH);
}

void loop() {
  // Read command from Serial Monitor
  if (Serial.available() > 0) {
    char c = Serial.read();
    if (c >= '0' && c <= '6') {
      mode = c - '0';        // Convert char to number
      stepIndex = 0;
      direction = 1;
      ledState = LOW;
      prevTime = millis();
      Serial.print("Mode set to: ");
      Serial.println(mode);
    }
  }

  unsigned long now = millis();

  // MODE 0: All OFF
  if (mode == 0) {
    allOff();
  }

  // MODE 1: All ON
  else if (mode == 1) {
    allOn();
  }

  // MODE 2: Chase (2 -> 4 -> 6)
  else if (mode == 2) {
    if (now - prevTime >= 500) {
      prevTime = now;
      allOff();
      digitalWrite(leds[stepIndex], HIGH);
      stepIndex = (stepIndex + 1) % 3;
    }
  }

  // MODE 3: Blink all
  else if (mode == 3) {
    if (now - prevTime >= 1000) {
      prevTime = now;
      ledState = !ledState;
      for (int i = 0; i < 3; i++) digitalWrite(leds[i], ledState);
    }
  }

  // MODE 4: Alternate
  else if (mode == 4) {
    if (now - prevTime >= 700) {
      prevTime = now;
      if (ledState == LOW) {
        digitalWrite(leds[0], HIGH);
        digitalWrite(leds[1], LOW);
        digitalWrite(leds[2], HIGH);
        ledState = HIGH;
      } else {
        digitalWrite(leds[0], LOW);
        digitalWrite(leds[1], HIGH);
        digitalWrite(leds[2], LOW);
        ledState = LOW;
      }
    }
  }

  // MODE 5: Traffic style
  else if (mode == 5) {
    if (now - prevTime >= 500) {
      prevTime = now;
      allOff();
      digitalWrite(leds[stepIndex], HIGH);
      stepIndex = (stepIndex + 1) % 3;
    }
  }

  // MODE 6: Continuous running (forward & backward)
  else if (mode == 6) {
    if (now - prevTime >= 300) {
      prevTime = now;
      allOff();
      digitalWrite(leds[stepIndex], HIGH);

      stepIndex += direction;

      // Change direction at the ends
      if (stepIndex == 2 || stepIndex == 0) {
        direction = -direction;
      }
    }
  }
}
