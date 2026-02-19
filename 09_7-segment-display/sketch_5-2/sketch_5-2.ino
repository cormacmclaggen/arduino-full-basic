/*// Sketch 5-2
//7-Segment Display Counter (5161SA - COMMON CATHODE)
// Display numbers from 0 to 9 on a 7-segment display

// Segment order: a b c d e f g dp
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

int pin = 2;   // Segment 'a' starts at digital pin 2
int num = 0;   // Number to display

void setup() {
  // Set digital pins 2 to 9 as OUTPUT
  for (int i = 2; i <= 9; i++) {
    pinMode(i, OUTPUT);
  }

  digitalWrite(9, HIGH); // dp OFF
}

void loop() {
  // Output segment data for the current number
  for (int i = 0; i < 8; i++) {
    digitalWrite(pin + i, numbers[num][i]);
  }

  num++;                 // Next number
  if (num > 9) num = 0;  // Back to 0
  delay(1000);           // 1 second delay
}

*/





/// -------------------------------------------------
// 7-Segment Display (5011AS - COMMON CATHODE)
// Display: 0-9 and A-F
// Book style (pin + i)
// HIGH = ON, LOW = OFF
// -------------------------------------------------

// Segment order: a b c d e f g dp
// 1 = ON, 0 = OFF  (COMMON CATHODE)
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

int pin = 2;   // segment 'a' starts at D2
int num = 0;   // current character index

void setup() {
  // Set D2 ~ D9 as OUTPUT
  for (int i = 2; i <= 9; i++) {
    pinMode(i, OUTPUT);
  }

  digitalWrite(9, LOW); // dp OFF
}

void loop() {
  // Output segment data
  for (int i = 0; i < 8; i++) {
    digitalWrite(pin + i, numbers[num][i]);
  }

  num++;              // next character
  if (num > 15) {
    num = 0;           // back to 0
  }

  delay(1000);        // 1 second delay
}





 
/*// -------------------------------------------------
// 7-Segment Display Counter (5161BS - COMMON ANODE)
// Display numbers from 0 to 9, one number per second
// -------------------------------------------------

// Segment order: a b c d e f g dp
// LOW  = segment ON  (COMMON ANODE)
// HIGH = segment OFF
byte numbers[10][8] = {
  {0,0,0,0,0,0,1,1}, // 0
  {1,0,0,1,1,1,1,1}, // 1
  {0,0,1,0,0,1,0,1}, // 2
  {0,0,0,0,1,1,0,1}, // 3
  {1,0,0,1,1,0,0,1}, // 4
  {0,1,0,0,1,0,0,1}, // 5
  {0,1,0,0,0,0,0,1}, // 6
  {0,0,0,1,1,1,1,1}, // 7
  {0,0,0,0,0,0,0,1}, // 8
  {0,0,0,0,1,0,0,1}  // 9
};

int pin = 2;     // Segment 'a' starts at digital pin 2
int num = 0;     // Current number to display

void setup() {
  // Set pins D2 to D9 as OUTPUT
  for (int i = 2; i <= 9; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, HIGH); // Turn all segments OFF initially
  }
}

void loop() {
  // Output segment data for the current number
  for (int i = 0; i < 8; i++) {
    digitalWrite(pin + i, numbers[num][i]);
  }

  // Move to next number
  num++;
  if (num > 9) num = 0;

  delay(1000); // Wait 1 second
}

*/
