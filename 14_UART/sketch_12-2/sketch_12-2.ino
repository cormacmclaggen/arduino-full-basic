#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };   //physical mac address

byte ip[]      = { 192, 168, 0, 100 };  // IP address in LAN - need to change according to your Network address
byte gateway[] = { 192, 168, 0, 1 };    // internet access via router
byte subnet[]  = { 255, 255, 255, 0 };  // subnet mask

EthernetServer server(80); //server port
String readString;

int BlueledPin = 2;
int RedledPin  = 3;

void setup(){

  pinMode(BlueledPin, OUTPUT);   //pin selected to control
  pinMode(RedledPin, OUTPUT);    //pin selected to control

  // Test LED
  digitalWrite(BlueledPin, HIGH); delay(500);
  digitalWrite(BlueledPin, LOW);  delay(500);
  digitalWrite(RedledPin, HIGH);  delay(500);
  digitalWrite(RedledPin, LOW);   delay(500);

  //start Ethernet
  Ethernet.begin(mac, ip, gateway, subnet);
  server.begin();
}

void loop(){

  // Create a client connection
  EthernetClient client = server.available();

  if (client) {
    while (client.connected()) {

      if (client.available()) {
        char c = client.read();

        //read char by char HTTP request
        if (readString.length() < 100) {

          //store characters to string
          readString += c;
        }

        // if HTTP request has ended-
        // 0x0D is Carriage Return \n ASCII
        if (c == 0x0D) {

          client.println("HTTP/1.1 200 OK"); //send new page
          client.println("Content-Type: text/html");
          client.println();

          client.println("<HTML>");
          client.println("<HEAD>");
          client.println("<TITLE> Arduino Ethernet Shield Test </TITLE>");
          client.println("</HEAD>");
          client.println("<BODY>");
          client.println("<hr>");
          client.println("<hr>");
          client.println("<br>");

          client.println("<H1 style=\"color:green;\"> Arduino Ethernet Shield: LED ON/OFF</H1>");

          client.println("<hr>");
          client.println("<br>");

          client.println("<H2><a href=\"/?BLUELEDON\"\">BLUE LED ON</a><br></H2>");
          client.println("<H2><a href=\"/?BLUELEDOFF\"\">BLUE LED OFF</a><br></H2>");
          client.println("<br>");
          client.println("<H2><a href=\"/?REDLEDON\"\">RED LED ON</a><br></H2>");
          client.println("<H2><a href=\"/?REDLEDOFF\"\">RED LED OFF</a><br></H2>");

          client.println("</BODY>");
          client.println("</HTML>");

          delay(10);
          client.stop(); //stopping client

          // control arduino pin
          if(readString.indexOf("?BLUELEDON") > -1)  //checks for LEDON
          {
            digitalWrite(BlueledPin, HIGH);  // set pin high
          }
          else if(readString.indexOf("?REDLEDON") > -1)  //checks for LEDON
          {
            digitalWrite(RedledPin, HIGH);   // set pin high
          }
          else{
            if(readString.indexOf("?BLUELEDOFF") > -1)  //checks for LEDOFF
            {
              digitalWrite(BlueledPin, LOW);   // set pin low
            }
            else if(readString.indexOf("?REDLEDOFF") > -1)  //checks for LEDOFF
            {
              digitalWrite(RedledPin, LOW);    // set pin low
            }
          }

          readString=""; //clearing string for next read
        }
      }
    }
  }
}
