#include <SPI.h>
#include <Ethernet.h>

boolean reading = false;

// MAC address of Ethernet shield
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

// Static IP address
IPAddress ip(192, 168, 0, 31);

// Create Ethernet server on port 80
EthernetServer server(80);

void setup() {
  Serial.begin(9600);

  // Pins used for LED control
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  // Wait for serial port to connect
  while (!Serial) {
    ;
  }

  Serial.println("Ethernet WebServer Example");

  // Start Ethernet
  Ethernet.begin(mac, ip);

  // Check Ethernet shield
  if (Ethernet.hardwareStatus() == EthernetNoHardware) {
    Serial.println("Ethernet shield was not found.");
    while (true) {
      delay(1);
    }
  }

  // Check Ethernet cable
  if (Ethernet.linkStatus() == LinkOFF) {
    Serial.println("Ethernet cable is not connected.");
  }

  // Start server
  server.begin();
  Serial.print("Server is at ");
  Serial.println(Ethernet.localIP());
}

void loop() {
  checkForClient();
}

// Handle client requests
void checkForClient() {
  EthernetClient client = server.available();

  if (client) {
    boolean currentLineIsBlank = true;
    boolean sentHeader = false;

    while (client.connected()) {
      if (client.available()) {

        if (!sentHeader) {
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println();
          sentHeader = true;
        }

        char c = client.read();

        if (reading && c == ' ') reading = false;
        if (c == '?') reading = true;

        if (reading) {
          Serial.println(c);

          switch (c) {
            case '2':
              triggerPin(2, client);
              break;
            case '3':
              triggerPin(3, client);
              break;
            case '4':
              triggerPin(4, client);
              break;
            case '5':
              triggerPin(5, client);
              break;
          }
        }

        if (c == '\n' && currentLineIsBlank) {
          break;
        }

        if (c == '\n') {
          currentLineIsBlank = true;
        }
        else if (c != '\r') {
          currentLineIsBlank = false;
        }
      }
    }

    delay(1);
    client.stop();
  }
}

// Turn LED on selected pin
void triggerPin(int pin, EthernetClient client) {
  client.print("Turning on pin ");
  client.print(pin);
  client.print("<br>");

  digitalWrite(pin, HIGH);
  delay(250);
  digitalWrite(pin, LOW);
  delay(250);
}
