#include <Joystick.h>
#include <Keyboard.h>
#define thrPot A0
#define brkPot A1

Joystick_ Joystick;
const int range[2] = {0, 1023};

void setup() 
{
  pinMode(thrPot, INPUT);
  Joystick.setYAxisRange(range[0], range[1]);
  Joystick.setZAxisRange(range[0], range[1]);
  Joystick.begin();
  Keyboard.begin();
}

void loop()
{
  Joystick.setYAxis(analogRead(thrPot));
  Joystick.setZAxis(analogRead(brkPot));
}
