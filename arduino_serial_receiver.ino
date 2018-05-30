// include the SoftwareSerial library so you can use its functions:
#include <SoftwareSerial.h>

#define rxPin 0
#define txPin 1

// set up a new serial port
SoftwareSerial mySerial =  SoftwareSerial(rxPin, txPin);

void setup()  {
  // define pin modes for tx, rx:
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
}

int incomingByte = 0;

void loop() {

  // reply only when you receive data:
  if (mySerial.available() > 0) {
    
    // read the incoming byte:
    incomingByte = mySerial.read();

    // say what you got:
    mySerial.println(incomingByte, HEX);
    
  }
}
