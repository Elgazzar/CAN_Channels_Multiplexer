#include <Arduino.h>
#include "IoHwAb/IoHwAb.hpp"
#include "Project.hpp"

/*Channel Configurations*/
Channel_Cfg_T ECU1;
Channel_Cfg_T ECU2;

void setup() {
  /*Call IoHwAbs init function*/
  IoHwAb_Init();
  ECU1.Selection_0 = S0;
  ECU1.Selection_1 = S1;
  ECU2.Selection_0 = S2;
  ECU2.Selection_1 = S3;
}

void loop() {
  // put your main code here, to run repeatedly:
  SelectChannel(Veh_Channel,ECU1);
}