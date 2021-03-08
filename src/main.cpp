#include <Arduino.h>
#include "IoHwAb/IoHwAb.hpp"
#include "Application/Application.hpp"



/*Serial Configuration*/
char incomingByte;
char incomingByte_Idx = 0;
char received_data[Max_Length];


void setup() {
  /*Call IoHwAbs init function*/
  IoHwAb_Init();
  /*Initalize Application Configuration*/
  Application_Init();
  /*start Serial communication with baud rate 9600*/
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0)
  {
    incomingByte = Serial.read();
    received_data[incomingByte_Idx] = incomingByte;
    incomingByte_Idx++;
    if (incomingByte == '\n')
    {
      incomingByte_Idx = 0;
      Process_Application_Data(received_data);
    }
  }
}
