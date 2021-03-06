#include <Arduino.h>
#include "IOHwabs/IOHwabs.hpp"

void setup() {
  /*Call IOHwabs init function*/
  IOHwabs_init();
}

void loop() {
  // put your main code here, to run repeatedly:
  R_IOHwabs_5ms();
}