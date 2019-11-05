#include <Keyboard.h>
#include <Joystick.h>

/*#define upShift 3
#define downShift 4
#define drs 5
#define pit 6
#define neutral 7
#define clutch 8
#define radio 9
#define reverse 10*/
#define potPin A0
Joystick_ Joystick;

const int activeSize = 10;
int button[activeSize] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
char key[] = {'f', 'g', 'h', 'j', 'k', 'l', 'v', 'b', 'n', 'm'}; // set the pins to buttons and buttons to in-game functions
//int active[activeSize] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const int range[2] = {0, 1023};
int posX;

void pressKey();
 
void setup() 
{
  for(int j = 0; j < activeSize; j++)
  {
    pinMode(button[j], INPUT_PULLUP);
  }
  pinMode(potPin, INPUT);
  Joystick.begin();
  Keyboard.begin();
  Serial.begin(9600);
  Joystick.setXAxisRange(range[0], range[1]);
}



void loop() 
{
  posX = analogRead(potPin);
  Joystick.setXAxis(posX);
  
  for(int i = 0; i < activeSize; i++)
  {
    if(digitalRead(button[i]) == LOW)
    {
      Keyboard.press(key[i]);
      delay(15);
      Keyboard.release(key[i]);
    }
  }
}

/*void loop() 
{
  posX = analogRead(potPin);
  Joystick.setXAxis(posX);
  
  for(int i = 0; i < activeSize; i++)
  {
    (digitalRead(button[i]) == LOW) ? active[i] = 1 : active[i] = 0;
  }
  
  pressKey();
}

void pressKey()
{
  for(int m = 0; m < activeSize; m++)
  {
    if(active[m] == 1)
    {
      Keyboard.press(key[m]);
      delay(5);
      Keyboard.release(key[m]);
    }
  }
}*/
