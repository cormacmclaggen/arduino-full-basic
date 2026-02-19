/*
//old version
#include <IRremote.h>

int RECV_PIN = 11;        // DATA pin of the IR receiver
IRrecv irrecv(RECV_PIN); // Create an IR receiver object
decode_results results;  // Store the received data

void setup() {
  Serial.begin(9600);
  Serial.println("Enabling IRin");
  irrecv.enableIRIn();   // Start receiving IR signals
  Serial.println("Enabled IRin");
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX); // Print the remote code in HEX format
    irrecv.resume(); // Prepare to receive the next signal
  }
  delay(100);
}
*/

//  version
#include <IRremote.h>

#define RECV_PIN 11   // DATA pin of the IR receiver

void setup() {
  Serial.begin(9600);
  Serial.println("Enabling IRin");

  // Start IR receiver (new version)
  IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK);

  Serial.println("Enabled IRin");
}

void loop() {
  if (IrReceiver.decode()) {

    // Print received IR command in HEX format
    Serial.println(IrReceiver.decodedIRData.command, HEX);

    IrReceiver.resume(); // Prepare to receive the next signal
  }
  delay(100);
}
