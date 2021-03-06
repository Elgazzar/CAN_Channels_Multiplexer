#include "IoHwAb/IoHwAb.hpp"
#include <Arduino.h>

void IoHwAb_Init(void)
{
   /*Initalize IO PINS for first 8052*/
  pinMode(S0,OUTPUT);
  pinMode(S1,OUTPUT);
  /*Initalize IO PINS for Second 8052*/
  pinMode(S2,OUTPUT);
  pinMode(S3,OUTPUT);
}

void R_IOHwabs_5ms()
{
    /*Do Nothing for now*/
}