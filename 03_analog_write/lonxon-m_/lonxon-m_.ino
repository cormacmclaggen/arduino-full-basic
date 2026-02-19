/* ===== PIN CONFIG ===== */
int leds[4] = {3, 5, 6, 9};
int buttonPin = 12;     // 3.3V + pull-down
int potPin = A0;        // 5V potentiometer
int led13 = LED_BUILTIN;

/* ===== STATE ===== */
int mode = 0;
int lastButtonState = LOW;
bool blinking13 = false;

/* ===== LED13 BLINK ===== */
int blinkTarget = 0;
int blinkDone = 0;
bool led13State = LOW;

/* ===== ANALOG ===== */
int brightness = 0;
int speedDelay = 0;

/* ===== EFFECT ===== */
int stepIndex = 0;
int direction = 1;
int fadeValue = 0;
bool fadeUp = true;

unsigned long prevTime = 0;

void allOff() {
  for (int i = 0; i < 4; i++) analogWrite(leds[i], 0);
}

void setup() {
  for (int i = 0; i < 4; i++) pinMode(leds[i], OUTPUT);
  pinMode(led13, OUTPUT);
  pinMode(buttonPin, INPUT); // 3.3V + pull-down
}

/* ================= LOOP ================= */
void loop() {

  /* ---- BUTTON: CHANGE MODE ---- */
  int buttonState = digitalRead(buttonPin);
  if (lastButtonState == LOW && buttonState == HIGH && !blinking13) {
    mode++;
    if (mode > 7) mode = 0;

    blinkTarget = mode;
    blinkDone = 0;
    led13State = LOW;
    blinking13 = true;
    prevTime = millis();

    stepIndex = 0;
    direction = 1;
    fadeValue = 0;
    fadeUp = true;

    delay(200);
  }
  lastButtonState = buttonState;

  /* ---- ANALOG READ ---- */
  int potValue = analogRead(potPin);
  brightness = map(potValue, 0, 1023, 30, 255);
  speedDelay = map(potValue, 0, 1023, 30, 300);

  unsigned long now = millis();

  /* ---- LED13 BLINK ---- */
  if (blinking13) {
    if (now - prevTime >= 300) {
      prevTime = now;
      led13State = !led13State;
      digitalWrite(led13, led13State);

      if (led13State == LOW) {
        blinkDone++;
        if (blinkDone >= blinkTarget) {
          digitalWrite(led13, LOW);
          blinking13 = false;
          prevTime = now;
        }
      }
    }
    return;
  }

  /* ========== MODES ========== */

  // MODE 0: OFF
  if (mode == 0) {
    allOff();
  }

  // MODE 1: ALL ON
  else if (mode == 1) {
    for (int i = 0; i < 4; i++)
      analogWrite(leds[i], brightness);
  }

  // MODE 2: CHASE
  else if (mode == 2 && now - prevTime >= speedDelay) {
    prevTime = now;
    allOff();
    analogWrite(leds[stepIndex], brightness);
    stepIndex = (stepIndex + 1) % 4;
  }

  // MODE 3: FADE ALL
  else if (mode == 3 && now - prevTime >= 20) {
    prevTime = now;
    for (int i = 0; i < 4; i++)
      analogWrite(leds[i], fadeValue);

    fadeValue += fadeUp ? 5 : -5;
    if (fadeValue >= 255) fadeUp = false;
    if (fadeValue <= 0) fadeUp = true;
  }

  // MODE 4: BLINK ROUND → FADE
  else if (mode == 4) {
    if (stepIndex < 4 && now - prevTime >= 200) {
      prevTime = now;
      allOff();
      analogWrite(leds[stepIndex], 255);
      stepIndex++;
    } else {
      for (int i = 0; i < 4; i++)
        analogWrite(leds[i], fadeValue);

      fadeValue += fadeUp ? 4 : -4;
      if (fadeValue >= 255) fadeUp = false;
      if (fadeValue <= 0) fadeUp = true;
    }
  }

  // MODE 5: WAVE FADE
  else if (mode == 5 && now - prevTime >= 40) {
    prevTime = now;
    for (int i = 0; i < 4; i++) {
      int v = fadeValue - i * 60;
      if (v < 0) v = 0;
      analogWrite(leds[i], v);
    }
    fadeValue += fadeUp ? 10 : -10;
    if (fadeValue >= 255) fadeUp = false;
    if (fadeValue <= 0) fadeUp = true;
  }

  // MODE 6: PING-PONG CHASE
  else if (mode == 6 && now - prevTime >= speedDelay) {
    prevTime = now;
    allOff();
    analogWrite(leds[stepIndex], brightness);
    stepIndex += direction;

    if (stepIndex == 3 || stepIndex == 0)
      direction = -direction;
  }

  // MODE 7: RANDOM BLINK
  else if (mode == 7 && now - prevTime >= speedDelay) {
    prevTime = now;
    allOff();
    int r = random(0, 4);
    analogWrite(leds[r], brightness);
  }
}
