int led6 = 6;
int led9 = 9;

void setup() {
  pinMode(led6, OUTPUT);
  pinMode(led9, OUTPUT);
}

void loop() {
  for (int i = 0; i <= 255; i++) {
    analogWrite(led6, i);        // 
    analogWrite(led9, 255 - i);  // 
    delay(20);
  }
}
