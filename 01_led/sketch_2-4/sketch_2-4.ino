int leds[] = {2, 4, 6};

void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(leds[i], HIGH);
  }
  delay(1000);

  for (int i = 0; i < 3; i++) {
    digitalWrite(leds[i], LOW);
  }
  delay(500);
}
