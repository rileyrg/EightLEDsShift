#include<Arduino.h>


//https://www.arduino.cc/en/Tutorial/ShiftOut

#define SER_pin 4 //attach to SER
#define RCLK_pin 5 // attach to RCLK
#define  SRCLK_pin 6 // attach to SRCLK

byte leds = 0;
 
void updateShiftRegister() 
{
     digitalWrite(RCLK_pin, LOW);
     shiftOut(SER_pin, SRCLK_pin, LSBFIRST, leds);
     digitalWrite(RCLK_pin, HIGH);
}

void setup() //called once
{
     pinMode(RCLK_pin, OUTPUT);
     pinMode(SER_pin, OUTPUT);  
     pinMode(SRCLK_pin, OUTPUT);
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
 
