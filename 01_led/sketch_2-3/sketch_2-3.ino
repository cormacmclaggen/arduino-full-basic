int led1 = 2;   // LED 1 connected to pin 2
int led2 = 4;   // LED 2 connected to pin 4
int led3 = 6;   // LED 3 connected to pin 6

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  // Turn all LEDs ON
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  delay(1000);

  // Turn all LEDs OFF
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  delay(500);
}
