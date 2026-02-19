/*
1, pinMode(buttonPin, INPUT);
Sets the push button pin as an input.

2, digitalRead(buttonPin);
Reads the current state of the button (HIGH or LOW).

3️, if (buttonState == HIGH)
Checks whether the button is pressed.
When the button is pressed, the input pin becomes HIGH.

4️ digitalWrite(ledPin, HIGH / LOW);
Turns the LED ON or OFF depending on the button state.
 */
int buttonPin = 4;     // Push button pin
int ledPin = 13;       // LED pin
int buttonState = 0;   // Variable to store button state

void setup() {
  pinMode(ledPin, OUTPUT);      // Set LED pin as output
  pinMode(buttonPin, INPUT);    // Set button pin as input
}

void loop() {
  buttonState = digitalRead(buttonPin);  // Read button state

  if (buttonState == HIGH) {    // If button is pressed
    digitalWrite(ledPin, HIGH); // Turn LED ON
  } else {
    digitalWrite(ledPin, LOW);  // Turn LED OFF
  }
}
