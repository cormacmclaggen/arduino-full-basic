/*ERROR
 * 
 /// Numbers for 7-segment (a b c d e f g dp)
// Common Cathode
byte Numbers[10] = {
  0b11111100, // 0
  0b01100000, // 1
  0b11011010, // 2
  0b11110010, // 3
  0b01100110, // 4
  0b10110110, // 5
  0b10111110, // 6
  0b11100100, // 7
  0b11111110, // 8
  0b11110110  // 9
};

// Segment pins: a b c d e f g
int segPins[7] = {2, 3, 4, 5, 6, 7, 8};

// Number of digits
int digNum = 2;

// Digit control pins (left, right)
int digPin[] = {12, 13};

void displayDigit(int x, int d) {
  int value = Numbers[x];
  boolean segSet = LOW;

  // Turn off all digits first
  digitalWrite(digPin[0], LOW);
  digitalWrite(digPin[1], LOW);

  // Set segments a–g
  for (int led = 0; led < 7; led++) {
    if (value & 0x02)
      segSet = HIGH;
    else
      segSet = LOW;

    digitalWrite(10 - segPins[led], segSet);
    value >>= 1;
  }

  // Turn on selected digit
  digitalWrite(digPin[d], HIGH);
}

void displayNumber(int n) {
  if (n == 0) {
    displayDigit(0, 0);
  } else {
    for (int i = 0; i < digNum; i++) {
      if (n > 0) {
        displayDigit(n % 10, i);
        n = n / 10;
      }
    }
    delay(10); // multiplexing delay
  }
}

void setup() {
  // Segment pins
  for (int i = 0; i < 8; i++) {
    pinMode(segPins[i], OUTPUT);
  }

  // Digit pins
  for (int j = 0; j < digNum; j++) {
    pinMode(digPin[j], OUTPUT);
  }
}

void loop() {
  // Display 00 ~ 99
  for (int i = 0; i < 1000; i++) {
    displayNumber(i / 10);
  }
}*/
// Numbers for 7-segment (a b c d e f g dp)
// Common Cathode
byte Numbers[10] = {
  0b11111100, // 0
  0b01100000, // 1
  0b11011010, // 2
  0b11110010, // 3
  0b01100110, // 4
  0b10110110, // 5
  0b10111110, // 6
  0b11100100, // 7
  0b11111110, // 8
  0b11110110  // 9
};

// Segment pins: a b c d e f g
int segPins[7] = {2, 3, 4, 5, 6, 7, 8};

// Number of digits
int digNum = 2;

// Digit control pins (left, right)
int digPin[] = {12, 13};

void displayDigit(int x, int d) {
  int value = Numbers[x];

  // 🔴 SỬA 1: tắt cả 2 digit đúng logic CC (OFF = HIGH)
  digitalWrite(digPin[0], HIGH);
  digitalWrite(digPin[1], HIGH);

  // Set segments a–g (GIỮ NGUYÊN CÁCH SÁCH)
  for (int led = 0; led < 7; led++) {
    if (value & 0x02)
      digitalWrite(10 - segPins[led], HIGH);
    else
      digitalWrite(10 - segPins[led], LOW);

    value >>= 1;
  }

  // 🔴 SỬA 2: bật digit đúng logic CC (ON = LOW)
  digitalWrite(digPin[d], LOW);
}

void displayNumber(int n) {

  // đơn vị
  displayDigit(n % 10, 1);
  delay(2);     // 🔴 SỬA 3: delay nhỏ (quét nhanh)

  // chục
  displayDigit(n / 10, 0);
  delay(2);
}

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(segPins[i], OUTPUT);
  }
  for (int j = 0; j < digNum; j++) {
    pinMode(digPin[j], OUTPUT);
  }
}

void loop() {
  static int num = 0;
  static unsigned long lastTime = 0;

  // tăng số chậm, dễ nhìn
  if (millis() - lastTime >= 300) {
    num++;
    if (num > 99) num = 0;
    lastTime = millis();
  }

  // luôn luôn quét hiển thị
  displayNumber(num);
}
