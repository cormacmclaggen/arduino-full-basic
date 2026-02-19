int potPin = A0;
int ledPin = 9;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int pot = analogRead(potPin);          // 0–1023
  int speed = map(pot, 0, 1023, 1, 20);  // fade speed

  for (int i = 0; i <= 255; i++) {
    analogWrite(ledPin, i);
    delay(speed);
  }
  for (int i = 255; i >= 0; i--) {
    analogWrite(ledPin, i);
    delay(speed);
  }
}
