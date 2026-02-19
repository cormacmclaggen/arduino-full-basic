int led1 = 6;   // PWM pin
int led2 = 9;   // PWM pin

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}
void loop() {
  analogWrite(led1, 50);   // 0~255
  analogWrite(led2, 255);  // 0~255
}
