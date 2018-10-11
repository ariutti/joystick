#include "ButtonDebounce.h"

// 2018-10-11
// using an Arduino micro to read 
// signals from a joystick
// and a push button

#define LEFT   2
#define RIGHT  3
#define DOWN   4
#define UP     5
#define PUSH   6

ButtonDebounce left(  LEFT,  50 );
ButtonDebounce right( RIGHT, 50 );
ButtonDebounce down(  DOWN,  50 );
ButtonDebounce up(    UP,    50 );
ButtonDebounce push(  PUSH,  50 );

// callback functions 
void leftChanged(int state){
  //Serial.println("Left Changed: " + String(state));
  printStates();
}

void rightChanged(int state){
  //Serial.println("Right Changed: " + String(state));
  printStates();
}

void downChanged(int state){
  //Serial.println("Down Changed: " + String(state));
  printStates();
}

void upChanged(int state){
  //Serial.println("Up Changed: " + String(state));
  printStates();
}

void pushChanged(int state){
  //Serial.println("Push Changed: " + String(state));
  printStates();
}

// SETUP /////////////////////////////////////////////////////////////////////
void setup() 
{
  Serial.begin(9600);

  left.setCallback(leftChanged);
  right.setCallback(rightChanged);
  down.setCallback(downChanged);
  up.setCallback(upChanged);
  push.setCallback(pushChanged);
}

// LOOP //////////////////////////////////////////////////////////////////////
void loop() 
{
  left.update();
  right.update();
  down.update();
  up.update();
  push.update();

  delay(1);
}

// PRINT STATES //////////////////////////////////////////////////////////////
void printStates()
{
  Serial.print( !left.state() );
  Serial.print( !right.state() );
  Serial.print( !down.state() );
  Serial.print( !up.state() );
  Serial.print( !push.state() );
  Serial.println(";");
}

