int buzzer = 3;
int potPin = A0;

void setup() {
}

void loop() {
  int pot = analogRead(potPin);   // 0 - 1023

  // map giá trị biến trở -> thời gian bật
  int onTime  = map(pot, 0, 1023, 1, 12);  // to/nhỏ
  int offTime = 15;                        // cố định

  tone(buzzer, 523);   // DO (523 Hz)
  delay(onTime);       // bật ngắn / dài
  noTone(buzzer);
  delay(offTime);
}
