// -------------------------------------------------
// 7-Segment Display Test (5011AS - COMMON CATHODE)
// One segment ON at a time every 1 second
// Order: a → b → c → d → e → f → g → dp
// -------------------------------------------------

// Segment 'a' starts at digital pin 2
// a  -> D2
// b  -> D3
// c  -> D4
// d  -> D5
// e  -> D6
// f  -> D7
// g  -> D8
// dp -> D9
int basePin = 2;

void setup() {
  // Set all segment pins as OUTPUT
  for (int i = 2; i <= 9; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);  
    // For COMMON CATHODE:
    // LOW = OFF
  }
}

void loop() {
  // Loop through all 8 segments
  for (int i = 0; i < 8; i++) {

    // Control each segment
    for (int j = 0; j < 8; j++) {

      if (i == j) {
        digitalWrite(basePin + j, HIGH);
        // HIGH = ON (current flows from Arduino -> LED -> GND)
      } else {
        digitalWrite(basePin + j, LOW);
        // LOW = OFF
      }
    }

    delay(1000); // Keep each segment ON for 1 second
  }
}
  
