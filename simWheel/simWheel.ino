#include <Joystick.h>
#include <Keyboard.h>

/*#define upShift 3
#define downShift 4
#define drs 5
#define pit 6
#define neutral 7
#define clutch 8
#define radio 9
#define reverse 10*/
#define wheelPot A0
Joystick_ Joystick;

const int activeSize = 12;
int button[activeSize] = {2, 3, 5, 6, 7, 8, 9, 10, 11, 12, 13, 16}; // gas 15, bremza 4 mankata da se ne piše črk k se gumb pritiska /// 14 je neki narobe - skor skos je prtisnen
char key[] = {'f', 'g', 'h', 'j', 'k', 'l', 'v', 'b', 'n', 'm', 't', 'u'}; // set the pins to buttons and buttons to in-game functions
/*
const int activeSize = 2;
int button[activeSize] = {7, 8};
char key[] = {'f', 'g'};
*/
//int active[activeSize] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const int range[2] = {0, 1023};
int thrPos = 0;
int brkPos = 0;

void pressKey();
 
void setup() 
{
  for(int j = 0; j < activeSize; j++)
  {
    pinMode(button[j], INPUT_PULLUP);
  }
  pinMode(wheelPot, INPUT);
  Joystick.setXAxisRange(range[0], range[1]);
  Joystick.setYAxisRange(range[0], range[1]);
  Joystick.setZAxisRange(range[0], range[1]);
  Joystick.begin();
  Keyboard.begin();
}

void loop()
{
  Joystick.setXAxis(analogRead(wheelPot));
  if(digitalRead(15) == LOW){
    if(thrPos + 100 >= 1023) thrPos = 1023;
    else thrPos += 100;
    Joystick.setYAxis(thrPos);
  }else{
    if(thrPos - 100 <= 0) thrPos = 0;
    else thrPos -= 100;
    Joystick.setYAxis(thrPos);
  }
  if(digitalRead(4) == LOW){
    if(brkPos + 100 >= 1023) brkPos = 1023;
    else brkPos += 100;
    Joystick.setZAxis(brkPos);
  }else{
    if(brkPos - 100 <= 0) brkPos = 0;
    else brkPos -= 100;
    Joystick.setZAxis(brkPos);
  }
  
  for(int i = 0; i < activeSize; i++)
  {
    if(digitalRead(button[i]) == LOW)
    {
      Joystick.pressButton(button[i]);
      delay(5);
      Joystick.releaseButton(button[i]);
    }
  }
}
