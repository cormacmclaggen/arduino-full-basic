/*
  Sketch 13-4 (Processing)
  UART/Serial logging from Arduino -> PC

  What this program does:
  - Connects to Arduino via Serial (USB)
  - Prints incoming data to the Processing console
  - Saves incoming data to a text file
  - Press any key to stop and close the file safely

  Serial port settings:
  - Windows example: "COM5"
  - Linux example:   "/dev/ttyACM0"
  - Baud rate must match Arduino sketch: 9600
*/
import processing.serial.*;

PrintWriter out;   // file declaration
Serial p;

void setup() {
  /*p = new Serial(this, "COM5", 9600);   // Check COM port in Arduino IDE for Windows 
   *
  out = createWriter("c:/my.txt");      // file name
}*/
  p = new Serial(this, "/dev/ttyACM0", 9600);
   // Check COM port in Arduino IDE for linux
  out = createWriter("/home/lananh/my.txt");      // file name
}
void draw() {
  if (p.available() > 0) {
    String m = p.readString();
    print(m);

    if (m != null) {
      out.print(m);   // save data
    }
  }
}

void keyPressed() {   // press any key to terminate the program
  out.flush();        // writes remaining data to the file
  out.close();        // finishes the file
  exit();             // stops the program
}
