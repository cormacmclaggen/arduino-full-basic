volatile byte state = LOW;

void setup() {
  pinMode(13, OUTPUT);          // LED
  pinMode(2, INPUT_PULLUP);     // interrupt pin
  attachInterrupt(digitalPinToInterrupt(2), blink, CHANGE);
}

void loop() {
  digitalWrite(13, state);
}

void blink() {
  state = !state;   // toggle LED state
}
