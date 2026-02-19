/*
  BUTTON + MODE SYSTEM (WITH MODE 0)

  Button (pin 3):
  - Each press cycles mode: 0 -> 1 -> ... -> 6 -> 0

  LED 13:
  - Blinks N times to indicate current mode

  LEDs 2,4,6:
  - Run MODE N continuously
*/

int buttonPin = 3;
int led13 = LED_BUILTIN;
int leds[3] = {2, 4, 6};

// Button
int lastButtonState = HIGH;

// Mode
int mode = 0;

// Indicator blink (LED 13)
bool blinking = false;
bool led13State = LOW;
int blinkTarget = 0;
int blinkDone = 0;

// LED 246 control
int stepIndex = 0;
int direction = 1;
bool ledState = LOW;

// Timing
unsigned long prevTime = 0;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(led13, OUTPUT);
  for (int i = 0; i < 3; i++) pinMode(leds[i], OUTPUT);
}

void allOff246() {
  for (int i = 0; i < 3; i++) digitalWrite(leds[i], LOW);
}

void loop() {
  /* -------- BUTTON TO CHANGE MODE -------- */
  int buttonState = digitalRead(buttonPin);

  if (lastButtonState == HIGH && buttonState == LOW && !blinking) {
    mode++;
    if (mode > 6) mode = 0;

    // Prepare LED 13 blink
    blinkTarget = mode;
    blinkDone = 0;
    led13State = LOW;
    blinking = true;

    // Reset mode states
    stepIndex = 0;
    direction = 1;
    ledState = LOW;

    prevTime = millis();
    delay(200); // debounce
  }
  lastButtonState = buttonState;

  unsigned long now = millis();

  /* -------- LED 13 BLINK (MODE INDICATOR) -------- */
  if (blinking) {
    if (now - prevTime >= 300) {
      prevTime = now;
      led13State = !led13State;
      digitalWrite(led13, led13State);

      if (led13State == LOW) {
        blinkDone++;
        if (blinkDone >= blinkTarget) {
          digitalWrite(led13, LOW);
          blinking = false;
          prevTime = now;
        }
      }
    }
    return; // wait until blinking finished
  }

  /* -------- RUN MODE 246 CONTINUOUSLY -------- */

  // MODE 0: All OFF
  if (mode == 0) {
    allOff246();
  }

  // MODE 1: All ON
  else if (mode == 1) {
    for (int i = 0; i < 3; i++) digitalWrite(leds[i], HIGH);
  }

  // MODE 2: Chase
  else if (mode == 2 && now - prevTime >= 500) {
    prevTime = now;
    allOff246();
    digitalWrite(leds[stepIndex], HIGH);
    stepIndex = (stepIndex + 1) % 3;
  }

  // MODE 3: Blink all
  else if (mode == 3 && now - prevTime >= 700) {
    prevTime = now;
    ledState = !ledState;
    for (int i = 0; i < 3; i++) digitalWrite(leds[i], ledState);
  }

  // MODE 4: Alternate
  else if (mode == 4 && now - prevTime >= 500) {
    prevTime = now;
    ledState = !ledState;
    digitalWrite(leds[0], ledState);   // pin 2
    digitalWrite(leds[1], !ledState);  // pin 4
    digitalWrite(leds[2], ledState);   // pin 6
  }

  // MODE 5: Traffic
  else if (mode == 5 && now - prevTime >= 300) {
    prevTime = now;
    allOff246();
    digitalWrite(leds[stepIndex], HIGH);
    stepIndex = (stepIndex + 1) % 3;
  }

  // MODE 6: Continuous running
  else if (mode == 6 && now - prevTime >= 300) {
    prevTime = now;
    allOff246();
    digitalWrite(leds[stepIndex], HIGH);
    stepIndex += direction;

    if (stepIndex == 2 || stepIndex == 0) {
      direction = -direction;
    }
  }
}
