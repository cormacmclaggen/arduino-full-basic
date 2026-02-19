/*
 * The buzzer generates sound using different frequencies.
Each frequency corresponds to a musical note, and the notes are played
sequentially.
 */
void setup() {
  tone(3, 523, 1000); delay(1000); // Do
  tone(3, 587, 1000); delay(1000); // Re
  tone(3, 659, 1000); delay(1000); // Mi
  tone(3, 698, 1000); delay(1000); // Fa
}

void loop() {
}
