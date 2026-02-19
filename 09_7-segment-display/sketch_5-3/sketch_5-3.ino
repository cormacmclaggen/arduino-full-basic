/*// Segment order: a b c d e f g dp
// 1 = ON, 0 = OFF (COMMON CATHODE)

byte numbers[10][8] = {
  {1,1,1,1,1,1,0,0}, // 0
  {0,1,1,0,0,0,0,0}, // 1
  {1,1,0,1,1,0,1,0}, // 2
  {1,1,1,1,0,0,1,0}, // 3
  {0,1,1,0,0,1,1,0}, // 4
  {1,0,1,1,0,1,1,0}, // 5
  {1,0,1,1,1,1,1,0}, // 6
  {1,1,1,0,0,0,0,0}, // 7
  {1,1,1,1,1,1,1,0}, // 8
  {1,1,1,1,0,1,1,0}  // 9
};

int pin = 2;
int num = 0;

void displayNumbers(int n) {
  // 7-segment LEDs are connected from digital pin 2
  // a -> 2, b -> 3, ..., dp -> 9
  for (int i = 0; i < 8; i++) {
    digitalWrite(pin + i, numbers[n][i]);
  }
}

void setup() {
  pinMode(12, INPUT);   // push button

  for (int i = 2; i <= 9; i++) {
    pinMode(i, OUTPUT);
  }

  digitalWrite(9, HIGH); // dp OFF
}

void loop() {
  if (digitalRead(12) == HIGH) {
    ++num;
    if (num > 9) {
      num = 0;
    }
  }

  displayNumbers(num);
  delay(300);
}
*/
// Segment order: a b c d e f g dp
// 1 = ON, 0 = OFF (COMMON CATHODE)

byte numbers[16][8] = {
  {1,1,1,1,1,1,0,0}, // 0
  {0,1,1,0,0,0,0,0}, // 1
  {1,1,0,1,1,0,1,0}, // 2
  {1,1,1,1,0,0,1,0}, // 3
  {0,1,1,0,0,1,1,0}, // 4
  {1,0,1,1,0,1,1,0}, // 5
  {1,0,1,1,1,1,1,0}, // 6
  {1,1,1,0,0,0,0,0}, // 7
  {1,1,1,1,1,1,1,0}, // 8
  {1,1,1,1,0,1,1,0}, // 9

  {1,1,1,0,1,1,1,0}, // A
  {0,0,1,1,1,1,1,0}, // b (B)
  {1,0,0,1,1,1,0,0}, // C
  {0,1,1,1,1,0,1,0}, // d (D)
  {1,0,0,1,1,1,1,0}, // E
  {1,0,0,0,1,1,1,0}  // F
};

int pin = 2;    // segment 'a' starts at D2
int num = 0;    // current index (0–15)

void displayNumbers(int n) {
  // a -> D2, b -> D3, ..., dp -> D9
  for (int i = 0; i < 8; i++) {
    digitalWrite(pin + i, numbers[n][i]);
  }
}

void setup() {
  pinMode(12, INPUT);   // button (book style)

  for (int i = 2; i <= 9; i++) {
    pinMode(i, OUTPUT);
  }

  digitalWrite(9, LOW); // dp OFF
}
/*
void loop() {
  if (digitalRead(12) == HIGH) {
    num++;
    if (num > 15) {
      num = 0;
    }
  }

  displayNumbers(num);
  delay(300);
}
*/

 // sketch 5-4 random (fixed)
void loop() {
  if (digitalRead(12) ==HIGH){
    num = random(16);
    num = num +1;
  }

  displayNumbers(num);
  delay(300);
}

///========================================================================================================
/* clear version
 *  // Segment order: a b c d e f g dp
// 1 = ON, 0 = OFF (COMMON CATHODE)

byte numbers[16][8] = {
  {1,1,1,1,1,1,0,0}, // 0
  {0,1,1,0,0,0,0,0}, // 1
  {1,1,0,1,1,0,1,0}, // 2
  {1,1,1,1,0,0,1,0}, // 3
  {0,1,1,0,0,1,1,0}, // 4
  {1,0,1,1,0,1,1,0}, // 5
  {1,0,1,1,1,1,1,0}, // 6
  {1,1,1,0,0,0,0,0}, // 7
  {1,1,1,1,1,1,1,0}, // 8
  {1,1,1,1,0,1,1,0}, // 9
  {1,1,1,0,1,1,1,0}, // A
  {0,0,1,1,1,1,1,0}, // b
  {1,0,0,1,1,1,0,0}, // C
  {0,1,1,1,1,0,1,0}, // d
  {1,0,0,1,1,1,1,0}, // E
  {1,0,0,0,1,1,1,0}  // F
};

int pin = 2;
int num = 0;

void displayNumbers(int n) {
  for (int i = 0; i < 8; i++) {
    digitalWrite(pin + i, numbers[n][i]);
  }
}

void setup() {
  for (int i = 2; i <= 9; i++) {
    pinMode(i, OUTPUT);
  }

  pinMode(12, INPUT_PULLUP); // button
  digitalWrite(9, LOW);      // dp OFF

  randomSeed(analogRead(0)); // for random mode; initialize the random number generator using analog noise, so random() produces different sequences after each reset
}
/*
void loop() {
  if (digitalRead(12) == LOW) {   // button pressed
    num++;
    if (num > 15) {
      num = 0;
    }
    delay(300); // debounce
  }

  displayNumbers(num);
}
*/
/*
void loop() {
  if (digitalRead(12) == LOW) {   // button pressed
    num = random(16);             // 0 ~ F
    delay(300);                   // debounce
  }

  displayNumbers(num);
}

 */
