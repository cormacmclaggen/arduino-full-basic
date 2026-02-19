#include <FrequencyTimer2.h>

/* ===============================
   BITMAP DEFINITIONS (8x8)
   =============================== */

#define SPACE { \
{0,0,0,0,0,0,0,0}, \
{0,0,0,0,0,0,0,0}, \
{0,0,0,0,0,0,0,0}, \
{0,0,0,0,0,0,0,0}, \
{0,0,0,0,0,0,0,0}, \
{0,0,0,0,0,0,0,0}, \
{0,0,0,0,0,0,0,0}, \
{0,0,0,0,0,0,0,0}  \
}

#define H { \
{0,1,0,0,0,0,1,0}, \
{0,1,0,0,0,0,1,0}, \
{0,1,0,0,0,0,1,0}, \
{0,1,1,1,1,1,1,0}, \
{0,1,0,0,0,0,1,0}, \
{0,1,0,0,0,0,1,0}, \
{0,1,0,0,0,0,1,0}, \
{0,1,0,0,0,0,1,0}, \
}

#define I { \
{0,0,1,1,1,0,0,0}, \
{0,0,0,1,0,0,0,0}, \
{0,0,0,1,0,0,0,0}, \
{0,0,0,1,0,0,0,0}, \
{0,0,0,1,0,0,0,0}, \
{0,0,0,1,0,0,0,0}, \
{0,0,0,1,0,0,0,0}, \
{0,0,1,1,1,0,0,0}, \
}

#define Q { \
{0,0,0,0,0,0,1,0}, \
{0,0,0,0,1,1,1,0}, \
{0,0,0,0,1,1,1,0}, \
{0,0,0,1,1,1,0,0}, \
{0,0,0,1,1,0,0,0}, \
{0,0,0,0,0,0,0,0}, \
{0,1,1,0,0,0,0,0}, \
{0,1,1,0,0,0,0,0}  \
}

#define SMILE { \
{0,0,0,0,0,0,0,0}, \
{0,0,1,0,0,0,1,0}, \
{0,1,0,1,0,1,0,1}, \
{0,0,0,0,0,0,0,0}, \
{0,0,0,0,1,0,0,0}, \
{0,1,0,0,1,0,0,1}, \
{0,0,1,0,0,0,1,0}, \
{0,0,0,1,1,1,0,0}  \
}

/* ===============================
   GLOBAL VARIABLES
   =============================== */

byte col = 0;
byte leds[8][8];

int pins[17] = {-1,5,4,3,2,14,15,16,17,13,12,11,10,9,8,7,6};

int rows[8] = {
  pins[9], pins[14], pins[8], pins[12],
  pins[1], pins[7], pins[2], pins[5]
};

int cols[8] = {
  pins[13], pins[3], pins[4], pins[10],
  pins[6], pins[11], pins[15], pins[16]
};

const int numPatterns = 5;

byte patterns[numPatterns][8][8] = {
  H, I, Q, SMILE, SPACE
};

int pattern = 0;

/* ===============================
   SETUP
   =============================== */

void setup() {
  for (int i = 1; i <= 16; i++) {
    pinMode(pins[i], OUTPUT);
  }

  for (int i = 0; i < 8; i++) {
    digitalWrite(cols[i], HIGH);   // Common Anode: OFF
    digitalWrite(rows[i], HIGH);   // OFF
  }

  clearLeds();

  FrequencyTimer2::disable();
  FrequencyTimer2::setPeriod(2000);        // 2ms
  FrequencyTimer2::setOnOverflow(display); // interrupt
}

/* ===============================
   LOOP
   =============================== */

void loop() {
  pattern = (pattern + 1) % numPatterns;
  slidePattern(pattern, 300);
}

/* ===============================
   FUNCTIONS
   =============================== */

void clearLeds() {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      leds[i][j] = 0;
    }
  }
}

void setPattern(int p) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      leds[i][j] = patterns[p][i][j];
    }
  }
}

void slidePattern(int p, int del) {
  setPattern(p);

  for (int t = 0; t < 8; t++) {

    for (int i = 0; i < 7; i++) {
      for (int j = 0; j < 8; j++) {
        leds[j][i] = leds[j][i + 1];
      }
    }

    for (int j = 0; j < 8; j++) {
      leds[j][7] = patterns[p][j][t];
    }

    delay(del);
  }
}

void display() {
  digitalWrite(cols[col], HIGH);
  col++;
  if (col == 8) col = 0;

  for (int row = 0; row < 8; row++) {
    if (leds[col][7 - row])
      digitalWrite(rows[row], HIGH);
    else
      digitalWrite(rows[row], LOW);
  }

  digitalWrite(cols[col], LOW);
}
