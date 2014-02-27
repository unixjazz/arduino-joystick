/* 
* -------------------------------------------------------------------------
* Digital Joystick Code for Sparkfun Pro Micro
* -------------------------------------------------------------------------
* Copyright Kevin Peat 2013
* kevin@kevinpeat.com
* This code module is licensed public domain
* -------------------------------------------------------------------------
* Modified for Ground Control Arcade Box
* -------------------------------------------------------------------------
* Uses modified HID.cpp and USBAPI.h provided by "That Guy"
* at http://www.imaginaryindustries.com/blog/?p=80
* -------------------------------------------------------------------------
*/

// Pin definitions
const int RIGHT_PIN = 4;
const int LEFT_PIN = 5;
const int UP_PIN = 3;
const int DOWN_PIN = 2;

const int BUT1_PIN = 6;
const int BUT2_PIN = 7;
const int BUT3_PIN = 8;
const int BUT4_PIN = 9;
const int BUT5_PIN = 10;
const int BUT6_PIN = 11;
const int BUT7_PIN = 12;
const int BUT8_PIN = 13;

// Previous states
boolean button1State = false;
boolean button2State = false;
boolean button3State = false;
boolean button4State = false;
boolean button5State = false;
boolean button6State = false;
boolean button7State = false;
boolean button8State = false;

boolean stickUp = false;
boolean stickDown = false;
boolean stickLeft = false;
boolean stickRight = false;

// Hold joystick state
JoyState_t joySt;

void setup()
{
  // Pin definitions
  pinMode(BUT1_PIN, INPUT);
  pinMode(BUT2_PIN, INPUT);
  pinMode(BUT3_PIN, INPUT);
  pinMode(BUT4_PIN, INPUT);
  pinMode(BUT5_PIN, INPUT);
  pinMode(BUT6_PIN, INPUT);
  pinMode(BUT7_PIN, INPUT);
  pinMode(BUT8_PIN, INPUT);

  pinMode(LEFT_PIN, INPUT);
  pinMode(UP_PIN, INPUT);
  pinMode(RIGHT_PIN, INPUT);
  pinMode(DOWN_PIN, INPUT);
  //pinMode(LED_PIN, OUTPUT);
  
  // Use pull-up resistors
  digitalWrite(BUT1_PIN, HIGH);
  digitalWrite(BUT2_PIN, HIGH);
  digitalWrite(BUT3_PIN, HIGH);
  digitalWrite(BUT4_PIN, HIGH);
  digitalWrite(BUT5_PIN, HIGH);
  digitalWrite(BUT6_PIN, HIGH);
  digitalWrite(BUT7_PIN, HIGH);
  digitalWrite(BUT8_PIN, HIGH);
  
  digitalWrite(LEFT_PIN, HIGH);
  digitalWrite(UP_PIN, HIGH);
  digitalWrite(RIGHT_PIN, HIGH);
  digitalWrite(DOWN_PIN, HIGH);

  // Set joystick initial state
  joySt.xAxis = 127;
  joySt.yAxis = 127;
  joySt.xRotAxis = 0;
  joySt.yRotAxis = 0;
  joySt.throttle = 0;
  joySt.buttons = 0;
}

void loop()
{ 
  // Button 1 pressed
  if (!button1State && digitalRead(BUT1_PIN) == LOW)
  {
    button1State = true;
    joySt.buttons = joySt.buttons | 1;
  }

  // Button 1 released
  if (button1State && digitalRead(BUT1_PIN) == HIGH)
  {
    button1State = false;
    joySt.buttons = joySt.buttons & 254;
  }

  // Button 2 pressed
  if (!button2State && digitalRead(BUT2_PIN) == LOW)
  {
    button2State = true;
    joySt.buttons = joySt.buttons | 2;
  }    

  // Button 2 released
  if (button2State && digitalRead(BUT2_PIN) == HIGH)
  {
    button2State = false;
    joySt.buttons = joySt.buttons & 252;
  }

  // Button 3 pressed
  if (!button3State && digitalRead(BUT3_PIN) == LOW)
  {
    button3State = true;
    joySt.buttons = joySt.buttons | 4;
  }

  // Button 3 released
  if (button3State && digitalRead(BUT3_PIN) == HIGH)
  {
    button3State = false;
    joySt.buttons = joySt.buttons & 248;
  }
  
  // Button 4 pressed
  if (!button4State && digitalRead(BUT4_PIN) == LOW)
  {
    button4State = true;
    joySt.buttons = 8;
  }

  // Button 4 released
  if (button4State && digitalRead(BUT4_PIN) == HIGH)
  {
    button4State = false;
    joySt.buttons = joySt.buttons & 246;
  }
  
  // Button 5 pressed
  if (!button5State && digitalRead(BUT5_PIN) == LOW)
  {
    button5State = true;
    joySt.buttons = 16;
  }

  // Button 5 released
  if (button5State && digitalRead(BUT5_PIN) == HIGH)
  {
    button5State = false;
    joySt.buttons = joySt.buttons & 238;
  }
  
  // Button 6 pressed
  if (!button6State && digitalRead(BUT6_PIN) == LOW)
  {
    button6State = true;
    joySt.buttons = 32;
  }

  // Button 6 released
  if (button6State && digitalRead(BUT6_PIN) == HIGH)
  {
    button6State = false;
    joySt.buttons = joySt.buttons & 128;
  }
  
  // Button 7 pressed
  if (!button7State && digitalRead(BUT7_PIN) == LOW)
  {
    button7State = true;
    joySt.buttons = 64;
  }

  // Button 7 released
  if (button7State && digitalRead(BUT7_PIN) == HIGH)
  {
    button7State = false;
    joySt.buttons = joySt.buttons & 48;
  }
  
  // Button 8 pressed
  if (!button8State && digitalRead(BUT8_PIN) == LOW)
  {
    button8State = true;
    joySt.buttons = 128;
  }

  // Button 8 released
  if (button8State && digitalRead(BUT8_PIN) == HIGH)
  {
    button8State = false;
    joySt.buttons = joySt.buttons & 16;
  }
  
  // Joystick pressed up
  if (digitalRead(UP_PIN) == LOW)
  {
    stickUp = true;
    joySt.yAxis = 255;
  }

  // Joystick was up but no longer
  if (stickUp && digitalRead(UP_PIN) == HIGH)
  {
    stickUp = false;
    joySt.yAxis = 127;
  }

  // Joystick pressed right
  if (digitalRead(RIGHT_PIN) == LOW)
  {
    stickRight = true;    
    joySt.xAxis = 255;
  }

  // Joystick was right but no longer
  if (stickRight && digitalRead(RIGHT_PIN) == HIGH)
  {
    stickRight = false;
    joySt.xAxis = 127;
  }

  // Joystick pressed down
  if (digitalRead(DOWN_PIN) == LOW)
  {
    stickDown = true;
    joySt.yAxis = 0;
  }

  // Joystick was down but no longer
  if (stickDown && digitalRead(DOWN_PIN) == HIGH)
  {
    stickDown = false;
    joySt.yAxis = 127;
  }

  // Joystick pressed left
  if (digitalRead(LEFT_PIN) == LOW)
  {
    stickLeft = true;
    joySt.xAxis = 0;
  }

  // Joystick was left but no longer
  if (stickLeft && digitalRead(LEFT_PIN) == HIGH)
  {
    stickLeft = false;
    joySt.xAxis = 127;
  }

  // Send joystick state
  Joystick.setState(&joySt);
}
