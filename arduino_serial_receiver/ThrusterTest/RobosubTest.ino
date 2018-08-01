String readString;

#include <Servo.h>

Servo thruster1;
Servo thruster2;
Servo thruster3;
Servo thruster4;
Servo thruster5;
Servo thruster6;

String read1;
String read2;
String read3;
String read4;
String read5;
String read6;

int ind1;
int ind2;
int ind3;
int ind4;
int ind5;
int ind6;
 
void setup() {
  Serial.begin(9600);
  
  thruster1.attach(3);
  thruster2.attach(5);
  thruster3.attach(6);
  thruster4.attach(9);
  thruster5.attach(10);
  thruster6.attach(11);
  
  Serial.println("Servo test");
}

void loop() {
  thrusterStart();
}

void thrusterStart() {
  if (Serial.available())  {
    char c = Serial.read();
    if (c == '>') {
      //do stuff
      
      Serial.println();
      
      ind1 = readString.indexOf(',');
      read1 = readString.substring(1, ind1);
      ind2 = readString.indexOf(',', ind1+1 );
      read2 = readString.substring(ind1+1, ind2);
      ind3 = readString.indexOf(',', ind2+1 );
      read3 = readString.substring(ind2+1, ind3);
      ind4 = readString.indexOf(',', ind3+1 );
      read4 = readString.substring(ind3+1, ind4);
      ind5 = readString.indexOf(',', ind4+1 );
      read5 = readString.substring(ind4+1, ind5);
      ind6 = readString.indexOf(',', ind5+1 );
      read6 = readString.substring(ind5+1);      
      
      
      Serial.print("thruster1 = ");
      Serial.println(read1); 
      Serial.print("thruster2 = ");
      Serial.println(read2);
      Serial.print("thruster3 = ");
      Serial.println(read3);
      Serial.print("thruster4 = ");
      Serial.println(read4);
      Serial.print("thruster5 = ");
      Serial.println(read5);
      Serial.print("thruster6 = ");
      Serial.println(read6);
      Serial.println();
      Serial.println();
      
      servoMovement();
      
      clearServoData();
    }  
    else
    {     
      readString += c;
    }
  }
}

void servoMovement(){
  int a = read1.toInt();
      int b = read2.toInt();
      int c = read3.toInt();
      int d = read4.toInt();
      int e = read5.toInt();
      int f = read6.toInt();
      
      thruster1.writeMicroseconds(a);
      thruster2.writeMicroseconds(b);
      thruster3.writeMicroseconds(c);
      thruster4.writeMicroseconds(d);
      thruster5.writeMicroseconds(e);
      thruster6.writeMicroseconds(f);
}

void clearServoData(){
  readString= "";
  read1 = "";
  read2 = "";
  read3 = "";
  read4 = "";
  read5 = "";
  read6 = "";
}

