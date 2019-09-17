#include<Arduino.h>

int latchPin = 5;
int clockPin = 6;
int dataPin = 4; 

byte leds = 0;
 
void updateShiftRegister() //tst for treemacs gitmode
{
     digitalWrite(latchPin, LOW);
     shiftOut(dataPin, clockPin, LSBFIRST, leds);
     digitalWrite(latchPin, HIGH);
}

void setup() //called once
{
     pinMode(latchPin, OUTPUT);
     pinMode(dataPin, OUTPUT);  
     pinMode(clockPin, OUTPUT);
}

void loop() 
{
     leds = 0;
     updateShiftRegister();
     delay(500);
     for (int i = 0; i < 8; i++){
          bitSet(leds, i);
          updateShiftRegister();
          delay(500);
     }
}
 
