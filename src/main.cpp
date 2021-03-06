#include <Arduino.h>
#include "IoHwAb/IoHwAb.hpp"
#include "Project.hpp"

void Process_Data(void);

/*Channel Configurations*/
Channel_Cfg_T ECU1;
Channel_Cfg_T ECU2;

/*Serial Configuration*/
char incomingByte;
char incomingByte_Idx = 0;
char received_data[Max_Length];


void setup() {
  /*Call IoHwAbs init function*/
  IoHwAb_Init();
  Serial.begin(9600);
  ECU1.Selection_0 = S0;
  ECU1.Selection_1 = S1;
  ECU2.Selection_0 = S2;
  ECU2.Selection_1 = S3;
}

void loop() {
  // put your main code here, to run repeatedly:
  SelectChannel(Veh_Channel,ECU1);
  if (Serial.available() > 0)
  {
    incomingByte = Serial.read();
    received_data[incomingByte_Idx]=incomingByte;
    incomingByte_Idx++;
    if (incomingByte == '\n')
    {
      incomingByte_Idx = 0;
      Process_Data();
    }
  }
}

void Process_Data()
{
    if ( (received_data[0] == 'V') && (received_data[1] == '1') )
    {
      Serial.println("Veh Channel Connected for ECU1");
    }
    else if ( (received_data[IDX_0] == 'V') && (received_data[IDX_1] == '2') )
    {
      Serial.println("Veh Channel Connected for ECU2");
    }
    else if ( (received_data[IDX_0] == 'M') && (received_data[IDX_1] == '1') )
    {
      Serial.println("MRR Channel Connected for ECU1");
    }
    else if ( (received_data[IDX_0] == 'M') && (received_data[IDX_1] == '2') )
    {
      Serial.println("MRR Channel Connected for ECU2");
    }
    else if ( (received_data[IDX_0] == 'S') && (received_data[IDX_1] == '1') )
    {
      Serial.println("SRR Front Channel Connected for ECU1");
    }
    else if ( (received_data[IDX_0] == 'S') && (received_data[IDX_1] == '2') )
    {
      Serial.println("SRR Front Channel Connected for ECU2");
    }
    else if ( (received_data[IDX_0] == 'R') && (received_data[IDX_1] == '1') )
    {
      Serial.println("SRR Rear Channel Connected for ECU1");
    }
    else if ( (received_data[IDX_0] == 'R') && (received_data[IDX_1] == '2') )
    {
      Serial.println("SRR Rear Channel Connected for ECU2");
    }
    else
    {
      //Serial.println("Veh Channel Connected for ECU1");
      //Serial.println("Veh Channel Connected for ECU2");
    }
    received_data[IDX_0] = '\0';
    received_data[IDX_1] = '\0';
    received_data[IDX_2] = '\0';
}