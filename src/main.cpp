#include<Arduino.h>


//https://www.arduino.cc/en/Tutorial/ShiftOut

#define SerialDataInPin 4 //attach to SER
#define StorageRegisterClockPin 5 
#define  ShiftRegisterClockPin 6 // attach to SRCLK
#define SerialResetPin 7 // low to reset
#define ResetButtonPin 2 // button to reset

byte leds = 0;
bool fReset=false;

void setSR(){
     digitalWrite(SerialResetPin,HIGH);
     fReset=false;
}
void resetSR(){
     digitalWrite(SerialResetPin,LOW);
     fReset=true;;
}

void updateShiftRegister(byte v) 
{

     digitalWrite(StorageRegisterClockPin, LOW);
     shiftOut(SerialDataInPin, ShiftRegisterClockPin, LSBFIRST, v);
     digitalWrite(StorageRegisterClockPin, HIGH);
}

void setup() //called once
{
     pinMode(StorageRegisterClockPin, OUTPUT);
     pinMode(SerialDataInPin, OUTPUT);  
     pinMode(ShiftRegisterClockPin, OUTPUT);
     pinMode(SerialResetPin, OUTPUT);
     pinMode(ResetButtonPin, INPUT_PULLUP);

     attachInterrupt(digitalPinToInterrupt(ResetButtonPin), resetSR,FALLING);
     // attachInterrupt(digitalPinToInterrupt(ResetKeyPin), setSR,RISING);
     setSR();
     updateShiftRegister(leds);
     

}

void loop() 
{
     if(fReset){
          setSR();
          updateShiftRegister(leds=0);
          delay(2000);
     }
     else
     {
          updateShiftRegister(leds++);
          delay(100);
     }
}
 
