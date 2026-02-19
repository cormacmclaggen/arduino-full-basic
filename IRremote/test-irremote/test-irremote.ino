#include <IRremote.h>

#define IR_RECEIVE_PIN 2   // IR receiver data pin

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK); 
  // ENABLE_LED_FEEDBACK: blink LED on board when signal received
}

void loop() {
  if (IrReceiver.decode()) {
    // Print received IR data
    Serial.print("IR code: 0x");
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);

    // Resume receiver for next signal
    IrReceiver.resume();
  }
}
