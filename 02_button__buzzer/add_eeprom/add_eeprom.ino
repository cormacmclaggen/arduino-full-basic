#include <EEPROM.h>

/* -------- PIN SETUP -------- */
int buttonPin = 3;
int led13 = LED_BUILTIN;
int leds[3] = {2, 4, 6};

/* -------- MODE -------- */
int mode = 0;              // current mode (0–6)
int lastButtonState = HIGH;

/* -------- LED 13 BLINK -------- */
bool blinking = false;
bool led13State = LOW;
int blinkTarget = 0;
int blinkDone = 0;

/* -------- LED 246 -------- */
int stepIndex = 0;
int direction = 1;
bool ledState = LOW;

/* -------- TIME -------- */
unsigned long prevTime = 0;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(led13, OUTPUT);
  for (int i = 0; i < 3; i++) pinMode(leds[i], OUTPUT);

  /* ---- READ SAVED MODE FROM EEPROM ---- */
  mode = EEPROM.read(0);        // address 0
  if (mode < 0 || mode > 6) {
    mode = 0;                   // safety reset
    EEPROM.write(0, mode);
  }

  /* ---- BLINK LED 13 TO SHOW SAVED MODE ---- */
  blinkTarget = mode;
  blinking = true;
  blinkDone = 0;
  led13State = LOW;
  prevTime = millis();
}

void allOff246() {
  for (int i = 0; i < 3; i++) digitalWrite(leds[i], LOW);
}

void loop() {
  /* -------- BUTTON -------- */
  int buttonState = digitalRead(buttonPin);

  if (lastButtonState == HIGH && buttonState == LOW && !blinking) {
    mode++;
    if (mode > 6) mode = 0;

    /* ---- SAVE MODE TO EEPROM ---- */
    EEPROM.write(0, mode);

    /* ---- PREPARE BLINK ---- */
    blinkTarget = mode;
    blinkDone = 0;
    led13State = LOW;
    blinking = true;

    /* ---- RESET MODE STATE ---- */
    stepIndex = 0;
    direction = 1;
    ledState = LOW;

    prevTime = millis();
    delay(200); // debounce
  }
  lastButtonState = buttonState;

  unsigned long now = millis();

  /* -------- LED 13 BLINK -------- */
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
    return;
  }

  /* -------- RUN MODE -------- */

  // MODE 0: ALL OFF
  if (mode == 0) {
    allOff246();
  }

  // MODE 1: ALL ON
  else if (mode == 1) {
    for (int i = 0; i < 3; i++) digitalWrite(leds[i], HIGH);
  }

  // MODE 2: CHASE
  else if (mode == 2 && now - prevTime >= 500) {
    prevTime = now;
    allOff246();
    digitalWrite(leds[stepIndex], HIGH);
    stepIndex = (stepIndex + 1) % 3;
  }

  // MODE 3: BLINK ALL
  else if (mode == 3 && now - prevTime >= 1000) {
    prevTime = now;
    ledState = !ledState;
    for (int i = 0; i < 3; i++) digitalWrite(leds[i], ledState);
  }

  // MODE 4: ALTERNATE
  else if (mode == 4 && now - prevTime >= 700) {
    prevTime = now;
    ledState = !ledState;
    digitalWrite(leds[0], ledState);
    digitalWrite(leds[1], !ledState);
    digitalWrite(leds[2], ledState);
  }

  // MODE 5: TRAFFIC
  else if (mode == 5 && now - prevTime >= 1000) {
    prevTime = now;
    allOff246();
    digitalWrite(leds[stepIndex], HIGH);
    stepIndex = (stepIndex + 1) % 3;
  }

  // MODE 6: CONTINUOUS
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
