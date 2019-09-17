#include<Arduino.h>


//https://www.arduino.cc/en/Tutorial/ShiftOut

#define SerialDataInPIn 4 //attach to SER
#define StorageRegisterClockPin 5 
#define  ShiftRegisterClockPin 6 // attach to SRCLK

byte leds = 0;

void updateShiftRegister() 
{
     digitalWrite(StorageRegisterClockPin, LOW);
     shiftOut(SerialDataInPIn, ShiftRegisterClockPin, LSBFIRST, leds);
     digitalWrite(StorageRegisterClockPin, HIGH);
}

void setup() //called once
{
     pinMode(StorageRegisterClockPin, OUTPUT);
     pinMode(SerialDataInPIn, OUTPUT);  
     pinMode(ShiftRegisterClockPin, OUTPUT);
}

void loop() 
{
     leds = 0;
     updateShiftRegister();
     delay(500);
     for (int i = 0; i < 256; i++){
//          bitSet(leds, i);
          leds=i;
          updateShiftRegister();
          delay(50);
     }
}
 
