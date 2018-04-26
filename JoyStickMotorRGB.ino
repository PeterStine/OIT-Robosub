#include <Servo.h>
/*
    Servo Libary Declarations. These are servo objects that can have pwm signal written to them.
*/
Servo servo0;
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;
Servo servo7;


// Global constants
const int servoP0 = 2;
const int servoP1 = 3;
const int servoP2 = 4;
const int servoP3 = 5;
const int servoP4 = 6;
const int servoP5 = 7;
const int servoP6 = 8;
const int servoP7 = 9;

// RGB led pins
const int redPin = 49;
const int greenPin = 51;
const int bluePin = 53;

const int VRxPin = 0;     //VRx pin connected to arduino pin A0
const int VRyPin = 1;     //VRy pin connected to arduino in A1
const int SwButtonPin = 52; //SW pin connected to arduino pin D8 variable will hold the Y-coordinate value

const int VRx1Pin = 2;     //VRx pin connected to arduino pin A2
const int VRy1Pin = 3;     //VRy pin connected to arduino in A3
const int Sw1ButtonPin = 50; //SW pin connected to arduino pin D50 variable will hold the Y-coordinate value

// Global Variables
int pressed = -1; //this variable will determine whether joystick has been pressed down (selected)
int x = -1;      //this variable will hold the X-coordinate value
int y = -1;      //this variable will hold the Y-coordinate value

int pressed1 = -1; //this variable will determine whether joystick has been pressed down (selected)
int x1 = -1;      //this variable will hold the X-coordinate value
int y1 = -1;      //this variable will hold the Y-coordinate value

int servo_counter = 0;


void setup() {
  /*
     Assign each servo object an output pin
  */

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);


  servo0.attach(2);
  servo1.attach(3);
  servo2.attach(4);
  servo3.attach(5);
  servo4.attach(6);
  servo5.attach(7);
  servo6.attach(8);
  servo7.attach(9);

  // Assign default pulse width to each servo motor
  servo0.writeMicroseconds(1500);
  servo1.writeMicroseconds(1500);
  servo2.writeMicroseconds(1500);
  servo3.writeMicroseconds(1500);
  servo4.writeMicroseconds(1500);
  servo5.writeMicroseconds(1500);
  servo6.writeMicroseconds(1500);
  servo7.writeMicroseconds(1500);

  pinMode(SwButtonPin, INPUT);    //sets the SW switch as input
  digitalWrite(SwButtonPin, HIGH);//sets the SW button HIGH

   pinMode(Sw1ButtonPin, INPUT);    //sets the SW switch as input
  digitalWrite(Sw1ButtonPin, HIGH);//sets the SW button HIGH
  
  Serial.begin(115200);           //sets the baud rate
}


// Use external count value to cycle through each pin running servos.
// joystick/potentiometer will map between 700-2300 for pulse width (Microseconds)
// Button will increment external counter
void servoSelect(int select_servo, int pulse_width)
{
  switch (select_servo)
  {
    case 0:
      servo0.writeMicroseconds(pulse_width);
      RGB(0);
      break;
    case 1:
      servo1.writeMicroseconds(pulse_width);
      RGB(1);
      break;
    case 2:
      servo2.writeMicroseconds(pulse_width);
      RGB(2);
      break;
    case 3:
      servo3.writeMicroseconds(pulse_width);
      RGB(3);
      break;
    case 4:
      servo4.writeMicroseconds(pulse_width);
      RGB(4);
      break;
    case 5:
      servo5.writeMicroseconds(pulse_width);
      RGB(5);
      break;
    case 6:
      servo6.writeMicroseconds(pulse_width);
      RGB(6);
      break;
    case 7:
      servo7.writeMicroseconds(pulse_width);
      RGB(7);
      break;
    default:
      servo0.writeMicroseconds(1500);
      servo1.writeMicroseconds(1500);
      servo2.writeMicroseconds(1500);
      servo3.writeMicroseconds(1500);
      servo4.writeMicroseconds(1500);
      servo5.writeMicroseconds(1500);
      servo6.writeMicroseconds(1500);
      servo7.writeMicroseconds(1500);
      break;
  }
}

void RGB(int color)
{
  switch (color)
  {
    case 0:
      digitalWrite(redPin, 0);
      digitalWrite(greenPin, 1);
      digitalWrite(bluePin, 1);
      break;
    case 1:
      digitalWrite(redPin, 1);
      digitalWrite(greenPin, 0);
      digitalWrite(bluePin, 1);
      break;
    case 2:
      digitalWrite(redPin, 1);
      digitalWrite(greenPin, 1);
      digitalWrite(bluePin, 0);
      break;
    case 3:
      digitalWrite(redPin, 1);
      digitalWrite(greenPin, 1);
      digitalWrite(bluePin, 1);
      break;
    case 4:
      digitalWrite(redPin, 1);
      digitalWrite(greenPin, 0);
      digitalWrite(bluePin, 0);
      break;
    case 5:
      digitalWrite(redPin, 0);
      digitalWrite(greenPin, 1);
      digitalWrite(bluePin, 0);
      break;
    case 6:
      digitalWrite(redPin, 0);
      digitalWrite(greenPin, 0);
      digitalWrite(bluePin, 0);
      break;
    case 7:
      digitalWrite(redPin, 0);
      digitalWrite(greenPin, 0);
      digitalWrite(bluePin, 1);
      break;
    default:
      digitalWrite(redPin, 0);
      digitalWrite(greenPin, 0);
      digitalWrite(bluePin, 0);
      break;
  }

}

void readJoystick() {
  pressed = digitalRead(SwButtonPin); //reads whether joystick has been pressed down (selected) or not
  x = analogRead(VRxPin);           //reads the X-coordinate value
  y = analogRead(VRyPin);           //reads the Y-coordinate value

   pressed1 = digitalRead(Sw1ButtonPin); //reads whether joystick has been pressed down (selected) or not
  x1 = analogRead(VRx1Pin);           //reads the X-coordinate value
  y1 = analogRead(VRy1Pin);           //reads the Y-coordinate value
}

/*
 *  The inputs to this function are:
 *    X1 - X pos and neg axis joystick 1
 *    Y1 - Y pos and neg axis joystick 1
 *    X2 - X pos and neg axis joystick 2
 *    Y2 - Y pos and neg axis joystick 2
 *    
 *    The inputs assume a value between 0-1024 from the joystick.
 *    Input servo_pins is a 4-element array specifying which servo maps to horizontal a & b, 
 *    and the final 2 elements specify vertical a & b thrusters.
 *    
 *    Clock wise and Counter Clock wise motion is done through feeding a positive thrust
 *    to one horizontal motor, and an equal and opposite thrust to the counterpart horizontal
 *    motor.
*/
void four_motor_maneuvers(int X1, int Y1, int X2, int Y2, int servo_pins[3])
{
  // Assume Right-Stick Y controls horizontal forward and backward
  int pwm_val_FB = map(Y1, 0, 1023, 1400, 1600); // default is 700 and 2300
  //servoSelect(servo_pins[0], pwm_val_FB);
  //servoSelect(servo_pins[1], pwm_val_FB);
        servo0.writeMicroseconds(pwm_val_FB);
        servo1.writeMicroseconds(pwm_val_FB);
  
  // Assume Right-Stick X controls Rotate CW and CCW.
  int pwm_val_CW  = map(X1, 0, 1023, 1400, 1600); // default is 700 and 2300
//  servoSelect(servo_pins[0], pwm_val_CW);
//  servoSelect(servo_pins[1], 1500 + (1500 - pwm_val_CW));
        servo0.writeMicroseconds(pwm_val_CW);
        servo1.writeMicroseconds(1500 + (1500 - pwm_val_CW));
  
  // Assume Left-Stick Y controls vertical up and down
  int pwm_val_UD  = map(Y2, 0, 1023, 1400, 1600); // default is 700 and 2300
 // servoSelect(servo_pins[2], pwm_val_UD);
  //servoSelect(servo_pins[3], pwm_val_UD);
        servo0.writeMicroseconds(pwm_val_UD);
        servo1.writeMicroseconds(pwm_val_UD);
  
  }


void loop() {
  

  readJoystick();//calls this function which reads the digital input button SW, the X-coordinate and the Y-coordinate
  int rgb_val = map(x, 0, 1023, 0, 7);
  RGB(rgb_val);
  
  int pwm_valx = map(x, 0, 1023, 1400, 1600); // default is 700 and 2300
  int pwm_valy = map(y, 0, 1023, 1400, 1600); // default is 700 and 2300
    int pwm_valx1 = map(x1, 0, 1023, 1400, 1600); // default is 700 and 2300
  int pwm_valy1 = map(y1, 0, 1023, 1400, 1600); // default is 700 and 2300
//
//  if(pressed == 0 && servo_counter < 7)
//  {
//      servo_counter++;
//  }
//  else if(pressed == 0)
//  {
//    servo_counter = 0;  
//  }
//  
//  servoSelect(servo_counter, pwm_val);

  // 512 is a constant value to disable motors.
 // int pin_servo_map[4] = {0, 1, 2, 3};
 // four_motor_maneuvers(x,y,512,512,pin_servo_map);

  // when x axis is moved in either direction, only it's assigned thrusters should fire
  if (x >= 600 || x <= 400)
  {
     // foreward back
     servoSelect(1, pwm_valx);
     servoSelect(2, pwm_valx);
  }
  else if (y >= 600 || y <= 400)
  {
      // cw ccw
    servoSelect(1, pwm_valy);
    servoSelect(2, 1500 + (1500 - pwm_valy));
 
   }
   else if (x1 >= 600 || x1 <= 400)
  {
     // up down
     servoSelect(0, pwm_valx1);
     servoSelect(3, 1500 + (1500 - pwm_valx1));
  }
  else
  {
    servoSelect(1, 1500);
     servoSelect(2, 1500);
     servoSelect(0, 1500);
     servoSelect(3, 1500);
    }

delay(100);

//stupid delays, use ISR or something


 
  
  Serial.print("X: ");
  Serial.println(x);            //prints the X-coordinate
  Serial.print("Y: ");
  Serial.println(y);            //prints the Y-coordinate
  Serial.print ("Pressed: ");
  Serial.println(pressed);      //prints whether joystick knob has been pressed or not

 Serial.print("X1: ");
  Serial.println(x1);            //prints the X-coordinate
  Serial.print("Y1: ");
  Serial.println(y1);            //prints the Y-coordinate
  Serial.print ("Pressed1: ");
  Serial.println(pressed1);      //prints whether joystick knob has been pressed or not
  
  Serial.print("Pulse Width x: ");
  Serial.println(pwm_valx);
  Serial.print("Pulse Width y: ");
  Serial.println(pwm_valy);
  //Serial.print("Servo: ");
  //Serial.println(servo_counter);
  
  delay(200);
}
