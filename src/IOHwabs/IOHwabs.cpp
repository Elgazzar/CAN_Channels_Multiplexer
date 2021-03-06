#include "IOHwabs/IOHwabs.hpp"
#include <Arduino.h>

void IOHwabs_init(void)
{
   /*Initalize IO PINS*/
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
}

void R_IOHwabs_5ms()
{
    digitalWrite(13,HIGH);
}