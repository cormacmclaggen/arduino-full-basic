#include "DHT.h"          // Include DHT sensor library
#include <Wire.h>

#define DHTPIN 2          // DHT data pin connected to digital pin 2
#define DHTTYPE DHT11     // Define DHT sensor type as DHT11

DHT dht(DHTPIN, DHTTYPE); // Create DHT object

char c;                   // Variable to store request character
int h;                    // Variable to store humidity value
int t;                    // Variable to store temperature value

void setup() {
  Wire.begin(18);                  // Initialize I2C as slave with address 18
  Wire.onRequest(requestEvent);    // Register function when master requests data
  Wire.onReceive(receiveEvent);    // Register function when data received from master

  Serial.begin(9600);              // Start serial communication
}

void loop() {
  h = dht.readHumidity();          // Read humidity value
  t = dht.readTemperature();       // Read temperature value

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print("%\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" C");

  delay(1000);                     // Read sensor every 1 second
}
/*receiveEvent() – Receive request from master
void receiveEvent(int howMany) {
  // Remember the request: 'H' = humidity, 'T' = temperature
  while (0 < Wire.available()) {
    byte x = Wire.read();
    c = x;                         // Store request character
    Serial.println(c);
  }
}
🔹 requestEvent() – Send data to master
void requestEvent() {
  // Respond to the request
  if (c == 'H') {
    Wire.write(h);                 // Send humidity value
    Serial.print("Current humidity = ");
    Serial.println(h);
  }
  else {
    Wire.write(t);                 // Send temperature value
    Serial.print("Current temperature = ");
    Serial.println(t);
  }
}
📌 Purpose
Slave continuously reads DHT11 sensor values
Master sends a request character:
'H' → humidity
'T' → temperature
Slave responds with requested sensor data via I2C
⚠️ Note (không sửa code):
dht.begin() is missing → sensor may not work unless initialized
(OK để học, nhưng khi làm thật cần thêm) 66*/