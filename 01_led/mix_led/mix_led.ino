/*
  MODE = NUMBER
  LED 13 blinks N times as mode indicator
  LEDs 2-4-6 run selected MODE continuously
*/

int led13 = LED_BUILTIN;
int leds[3] = {2, 4, 6};

int mode = 0;

// Phase control
int phase = 0;   // 0 = idle, 1 = blink LED13, 2 = run MODE
bool blinking = false;

// LED13 blink
bool led13State = LOW;
int blinkTarget = 0;
int blinkDone = 0;

// LED246
int stepIndex = 0;
int direction = 1;
bool ledState = LOW;

unsigned long prevTime = 0;

void setup() {
  pinMode(led13, OUTPUT);
  for (int i = 0; i < 3; i++) pinMode(leds[i], OUTPUT);

  Serial.begin(9600);
  Serial.println("Press 0~6 to select MODE");
}

void allOff() {
  digitalWrite(led13, LOW);
  for (int i = 0; i < 3; i++) digitalWrite(leds[i], LOW);
}

void loop() {
  /* -------- READ COMMAND -------- */
  if (Serial.available() > 0) {
    char c = Serial.read();

    if (c >= '0' && c <= '6') {
      mode = c - '0';

      // Prepare LED13 blink
      blinkTarget = mode;
      blinkDone = 0;
      led13State = LOW;
      phase = 1;
      blinking = true;

      // Reset LED246 state
      stepIndex = 0;
      direction = 1;
      ledState = LOW;

      prevTime = millis();

      Serial.print("MODE = ");
      Serial.println(mode);
    }
  }

  unsigned long now = millis();

  /* -------- PHASE 1: LED 13 BLINK (INDICATOR) -------- */
  if (phase == 1 && blinking) {
    if (now - prevTime >= 300) {
      prevTime = now;
      led13State = !led13State;
      digitalWrite(led13, led13State);

      if (led13State == LOW) {
        blinkDone++;
        if (blinkDone >= blinkTarget) {
          digitalWrite(led13, LOW);
          blinking = false;
          phase = 2;          // Move to MODE running
          prevTime = now;
        }
      }
    }
  }

  /* -------- PHASE 2: RUN MODE CONTINUOUSLY -------- */
  else if (phase == 2) {

    // MODE 0: All OFF
    if (mode == 0) {
      allOff();
    }

    // MODE 1: All ON
    else if (mode == 1) {
      for (int i = 0; i < 3; i++) digitalWrite(leds[i], HIGH);
    }

    // MODE 2: Chase
    else if (mode == 2 && now - prevTime >= 500) {
      prevTime = now;
      allOff();
      digitalWrite(leds[stepIndex], HIGH);
      stepIndex = (stepIndex + 1) % 3;
    }

    // MODE 3: Blink all
    else if (mode == 3 && now - prevTime >= 1000) {
      prevTime = now;
      ledState = !ledState;
      for (int i = 0; i < 3; i++) digitalWrite(leds[i], ledState);
    }

    // MODE 4: Alternate
    else if (mode == 4 && now - prevTime >= 700) {
      prevTime = now;
      ledState = !ledState;
      digitalWrite(leds[0], ledState);
      digitalWrite(leds[1], !ledState);
      digitalWrite(leds[2], ledState);
    }

    // MODE 5: Traffic
    else if (mode == 5 && now - prevTime >= 1000) {
      prevTime = now;
      allOff();
      digitalWrite(leds[stepIndex], HIGH);
      stepIndex = (stepIndex + 1) % 3;
    }

    // MODE 6: Continuous running
    else if (mode == 6 && now - prevTime >= 300) {
      prevTime = now;
      allOff();
      digitalWrite(leds[stepIndex], HIGH);
      stepIndex += direction;

      if (stepIndex == 2 || stepIndex == 0) {
        direction = -direction;
      }
    }
  }
}
1
