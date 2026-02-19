/*
  Toggle button example
  Button on pin 3
  Each press toggles state: 0 <-> 1
*/

int buttonPin = 3;
int ledPin = LED_BUILTIN;

int lastButtonState = HIGH;  // previous button state
int toggleState = 0;         // 0 or 1

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);
  Serial.println("Toggle button ready");
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  // Detect button press (HIGH -> LOW)
  if (lastButtonState == HIGH && buttonState == LOW) {
    toggleState = !toggleState;   // toggle 0 <-> 1

    Serial.print("State = ");
    Serial.println(toggleState);

    delay(200); // debounce
  }

  lastButtonState = buttonState;

  // Use toggleState
  if (toggleState == 1) {
    digitalWrite(ledPin, HIGH);   // LED ON
  } else {
    digitalWrite(ledPin, LOW);    // LED OFF
  }
}
