// Happy Birthday with Volume Control (Arduino)
// Buzzer: pin 3
// Potentiometer: A0 (5V - A0 - GND)

int buzzer = 3;
int potPin = A0;

/* ===== NOTE FREQUENCIES ===== */
#define C4 262
#define D4 294
#define E4 330
#define F4 349
#define G4 392
#define A4 440
#define B4 494

#define C5 523
#define D5 587
#define E5 659
#define F5 698
#define G5 784
#define A5 880

/* ===== MELODY ===== */
int melody[] = {
  G4, G4, A4, G4, C5, B4,
  G4, G4, A4, G4, D5, C5,
  G4, G4, G5, E5, C5, B4, A4,
  F5, F5, E5, C5, D5, C5
};

/* ===== DURATION (ms) ===== */
int duration[] = {
  250, 250, 500, 500, 500, 1000,
  250, 250, 500, 500, 500, 1000,
  250, 250, 500, 500, 500, 500, 1000,
  250, 250, 500, 500, 500, 1000
};

int noteCount = 25;

void playNoteWithVolume(int freq, int timeMs) {
  unsigned long startTime = millis();

  while (millis() - startTime < timeMs) {
    int pot = analogRead(potPin);          // 0 - 1023
    int onTime = map(pot, 0, 1023, 1, 10);  // volume
    int offTime = 15;

    tone(buzzer, freq);
    delay(onTime);
    noTone(buzzer);
    delay(offTime);
  }
}

void setup() {
  for (int i = 0; i < noteCount; i++) {
    playNoteWithVolume(melody[i], duration[i]);
    delay(50); // nghỉ giữa nốt
  }
}

void loop() {
  // nothing
}
