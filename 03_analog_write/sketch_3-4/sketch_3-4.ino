// Play Spring Outing (봄나들이) melody with buzzer
// Buzzer pin: D3

int myNote[] = {784, 659, 784, 659, 784, 880, 784};   // Note frequencies (Hz)
int myDu[]   = {250, 250, 250, 250, 250, 250, 500};  // Note durations (ms)

void setup() {
  for (int i = 0; i < 7; i++) {
    tone(3, myNote[i], myDu[i]);     // Play note
    delay(myDu[i] * 1.3);            // Short pause between notes
    noTone(3);                       // Stop sound
  }
}

void loop() {
  // Empty: melody plays only once
}

/*
 * To play the sound repeatedly: move the for-loop from setup() to loop()
   To make the music slower:
    increase the delay value (e.g. 250, 500)
    or multiply the delay by a factor (e.g. delay * 1.3)
 */





 /*-----------------------------------------------------------------=----------------------------------------
  // Play Spring Outing (봄나들이) melody with button
// Buzzer: D3
// Button: D2 (INPUT_PULLUP)

int buzzerPin = 3;
int buttonPin = 2;

int myNote[] = {784, 659, 784, 659, 784, 880, 784};   // Note frequencies (Hz)
int myDu[]   = {250, 250, 250, 250, 250, 250, 500};  // Note durations (ms)

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  // Check button press (LOW when pressed)
  if (digitalRead(buttonPin) == LOW) {

    // Play melody once
    for (int i = 0; i < 7; i++) {
      tone(buzzerPin, myNote[i], myDu[i]);
      delay(myDu[i] * 1.3);
      noTone(buzzerPin);
    }

    // Wait until button is released (avoid repeat)
    while (digitalRead(buttonPin) == LOW);
    delay(200); // debounce
  }
}


  
  */
