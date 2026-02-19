#include <FrequencyTimer2.h>

// heart & smile patterns
byte col = 0;
byte leds[8][8];

// pin[xx] on led matrix connected to nn on Arduino
// (-1 is dummy to make array start at pos 1)
int pins[17] = {-1, 5, 4, 3, 2, 14, 15, 16, 17, 13, 12, 11, 10, 9, 8, 7, 6};

// row[xx] of leds = pin yy on led matrix
int rows[8] = {pins[9], pins[14], pins[8], pins[12], pins[1], pins[7], pins[2], pins[5]};

// col[xx] of leds = pin yy on led matrix
int cols[8] = {pins[13], pins[3], pins[4], pins[10], pins[6], pins[11], pins[15], pins[16]};

int pattern = 0;

void setup() {
  for (int i = 1; i <= 16; i++) {
    pinMode(pins[i], OUTPUT);
  }

  for (int i = 1; i <= 8; i++) {
    digitalWrite(cols[i - 1], HIGH);
  }

  for (int i = 1; i <= 8; i++) {
    digitalWrite(rows[i - 1], LOW);
  }
}

void loop() {
  digitalWrite(rows[0], HIGH);
  digitalWrite(cols[1], LOW);
  digitalWrite(cols[6], LOW);
  delay(2);
  clear();

  digitalWrite(rows[1], HIGH);
  digitalWrite(cols[0], LOW);
  digitalWrite(cols[2], LOW);
  digitalWrite(cols[5], LOW);
  digitalWrite(cols[7], LOW);
  delay(2);
  clear();

  digitalWrite(rows[2], HIGH);
  digitalWrite(cols[0], LOW);
  digitalWrite(cols[3], LOW);
  digitalWrite(cols[4], LOW);
  digitalWrite(cols[7], LOW);
  delay(2);
  clear();

  digitalWrite(rows[3], HIGH);
  digitalWrite(cols[0], LOW);
  digitalWrite(cols[7], LOW);
  delay(2);
  clear();

  digitalWrite(rows[4], HIGH);
  digitalWrite(cols[0], LOW);
  digitalWrite(cols[7], LOW);
  delay(2);
  clear();

  digitalWrite(rows[5], HIGH);
  digitalWrite(cols[1], LOW);
  digitalWrite(cols[6], LOW);
  delay(2);
  clear();

  digitalWrite(rows[6], HIGH);
  digitalWrite(cols[2], LOW);
  digitalWrite(cols[5], LOW);
  delay(2);
  clear();

  digitalWrite(rows[7], HIGH);
  digitalWrite(cols[3], LOW);
  digitalWrite(cols[4], LOW);
  delay(2);
  clear();
}

void clear() {
  for (int i = 0; i < 8; i++) {
    digitalWrite(rows[i], LOW);
    digitalWrite(cols[i], HIGH);
  }
}
