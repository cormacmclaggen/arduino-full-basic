// Button connected to pin 3 (to GND)
int buttonPin = 3;

int ledPin = LED_BUILTIN;

// Button state tracking
int lastButtonState = HIGH;

// Blink control
int blinkCount = 0;      // current blink number (1 -> 6)
int blinkDone = 0;
bool ledState = LOW;
bool blinking = false;

// Timing
unsigned long prevTime = 0;
const int interval = 300; // ms ON/OFF

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  // Detect button press (HIGH -> LOW)
  if (lastButtonState == HIGH && buttonState == LOW && !blinking) {

    // Increase blink count
    blinkCount++;
    if (blinkCount > 6) blinkCount = 1;

    // Prepare blinking
    blinkDone = 0;
    ledState = LOW;
    blinking = true;
    prevTime = millis();

    delay(200); // debounce
  }

  lastButtonState = buttonState;

  // Handle blinking process
  if (blinking) {
    unsigned long now = millis();

    if (now - prevTime >= interval) {
      prevTime = now;
      ledState = !ledState;
      digitalWrite(ledPin, ledState);

      // Count one blink when LED turns OFF
      if (ledState == LOW) {
        blinkDone++;
        if (blinkDone >= blinkCount) {
          blinking = false;
          digitalWrite(ledPin, LOW); // ensure LED OFF
        }
      }
    }
  }
}
