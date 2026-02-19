#include <DHT.h>
#include <SoftwareSerial.h>

#define DHTTYPE DHT11   // DHT11 sensor type
#define DHTPin 2

DHT dht(DHTPin, DHTTYPE);
SoftwareSerial BTSerial(10, 11);   // HC-06, RX: 10, TX: 11

void setup() {
  Serial.begin(9600);     // communication speed: 9600 baud
  BTSerial.begin(9600);   // communication speed: 9600 baud
  dht.begin();
}

void loop() {

  // sensor requires stabilization time
  delay(2000);

  float h = dht.readHumidity();      // read humidity
  float t = dht.readTemperature();   // read temperature

  // print error message if reading fails
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // send temperature and humidity separated by comma via Bluetooth
  BTSerial.print(t);
  BTSerial.print(",");
  BTSerial.print(h);
}
