/*//old version
#include <IRremote.h>

int RECV_PIN = 11;          // IR receiver pin
IRrecv irrecv(RECV_PIN);   // Create IR receiver object
decode_results results;    // Variable to store IR results

void setup()
{
  Serial.begin(9600);      // Start serial communication

  Serial.println("Enabling IRin");
  irrecv.enableIRIn();     // Start the IR receiver
  Serial.println("Enabled IRin");

  pinMode(5, OUTPUT);      // Set pin 5 as OUTPUT (LED)
}

void loop()
{
  // Check if IR signal is received
  if (irrecv.decode(&results))
  {
    // Print received IR code in HEX format
    Serial.println(results.value, HEX);

    irrecv.resume();       // Prepare to receive the next value

    // If button 1 is pressed, turn LED ON
    if (results.value == 0xFF30CF)
      digitalWrite(5, HIGH);

    // If button 2 is pressed, turn LED OFF
    if (results.value == 0xFF18E7)
      digitalWrite(5, LOW);
  }
}

*/
/*The old version of the IRremote library uses IRrecv and decode_results, which are now deprecated.
The new version uses the IrReceiver object, providing a simpler, more stable, and modern API that 
is recommended for embedded system development.
*/

//1 on , 2off
#include <IRremote.h>

#define RECV_PIN 11     // IR receiver pin
#define LED_PIN 5       // LED pin

void setup() {
  Serial.begin(9600);   // Start serial communication

  Serial.println("Enabling IRin");
  IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK); // Start IR receiver
  Serial.println("Enabled IRin");

  pinMode(LED_PIN, OUTPUT); // Set LED pin as OUTPUT
}

void loop() {
  // Check if IR signal is received
  if (IrReceiver.decode()) {

    // Print received IR code in HEX format
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);

    // If button 1 is pressed, turn LED ON
    if (IrReceiver.decodedIRData.decodedRawData == 0xBA45FF00) {
      digitalWrite(LED_PIN, HIGH);
    }

    // If button 2 is pressed, turn LED OFF
    if (IrReceiver.decodedIRData.decodedRawData == 0xB946FF00) {
      digitalWrite(LED_PIN, LOW);
    }

    IrReceiver.resume(); // Prepare to receive the next value
  }
}


/*
 #include <IRremote.h>

#define RECV_PIN 11     // IR receiver pin
#define LED_PIN 5       // LED pin

void setup() {
  Serial.begin(9600);   // Start serial communication

  Serial.println("Enabling IRin");
  IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK); // Start IR receiver
  Serial.println("Enabled IRin");

  pinMode(LED_PIN, OUTPUT); // Set LED pin as OUTPUT
}

void loop() {
  // Check if IR signal is received
  if (IrReceiver.decode()) {

    // Print received command in HEX format
    Serial.println(IrReceiver.decodedIRData.command, HEX);

    // If button 1 is pressed, turn LED ON
    if (IrReceiver.decodedIRData.command == 0x45) {
      digitalWrite(LED_PIN, HIGH);
    }

    // If button 2 is pressed, turn LED OFF
    if (IrReceiver.decodedIRData.command == 0x46) {
      digitalWrite(LED_PIN, LOW);
    }

    IrReceiver.resume(); // Prepare to receive the next value
  }
}


*/
 /* 2 toggle led
  * 
  *
#include <IRremote.hpp>

#define IR_RECEIVE_PIN 11
#define LED_PIN 5

bool ledState = false;   // LED state: OFF = false, ON = true

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);

  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
}

void loop() {
  if (IrReceiver.decode()) {

    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);

    // Button 1 → TOGGLE LED
    if (IrReceiver.decodedIRData.decodedRawData == 0xBA45FF00) {
      ledState = !ledState;              // toggle state
      digitalWrite(LED_PIN, ledState);   // apply state
    }

    IrReceiver.resume();
  }

  delay(150); // prevent multiple triggers
}*/
