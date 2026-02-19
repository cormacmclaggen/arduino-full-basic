#include <IRremote.h>   // Include IRremote library (new version)

// ---------------- PIN DEFINITIONS ----------------
#define IR_RECEIVE_PIN 11   // IR receiver DATA pin connected to D__
#define LED_PIN 5           // LED connected to pin_ (with 220Ω resistor)

// ---------------- VALID IR CODE ----------------
// Replace this value with the IR code of ONLY ONE button you want to allow
#define VALID_CODE 0xBA45FF00   // <-- CHANGE THIS to your remote button code

// ---------------- VARIABLES ----------------
bool ledState = false;   // Store current LED state
                         // false = LED OFF
                         // true  = LED ON

void setup() {
  Serial.begin(9600);        // Start Serial Monitor at 9600 baud
  pinMode(LED_PIN, OUTPUT); // Set LED pin as OUTPUT

  // Initialize IR receiver
  IrReceiver.begin(IR_RECEIVE_PIN);

  Serial.println("IR system ready");
  Serial.println("Waiting for button press...");
}

void loop() {

  // Check if an IR signal has been received
  if (IrReceiver.decode()) {

    // Read the raw IR code received from the remote
    unsigned long receivedCode = IrReceiver.decodedIRData.decodedRawData;

    // ---------------- IGNORE REPEAT CODE ----------------
    // When you HOLD a button, the remote sends 0xFFFFFFFF
    // This is NOT a real button press, so we ignore it
    if (receivedCode == 0xFFFFFFFF) {
      IrReceiver.resume();   // Prepare to receive the next signal
      return;                // Exit loop immediately
    }

    // ---------------- CHECK VALID BUTTON ----------------
    if (receivedCode == VALID_CODE) {

      // Toggle LED state (ON -> OFF, OFF -> ON)
      ledState = !ledState;

      // Apply LED state to the hardware pin
      digitalWrite(LED_PIN, ledState);

      // Print LED status to Serial Monitor
      if (ledState) {
        Serial.println("LED ON");
      } else {
        Serial.println("LED OFF");
      }

    } 
    else {
      // Any other button is NOT allowed
      Serial.println("ERROR: WRONG BUTTON");
    }

    delay(300);              // Debounce delay to avoid multiple triggers
    IrReceiver.resume();     // Ready to receive the next IR signal
  }
}
