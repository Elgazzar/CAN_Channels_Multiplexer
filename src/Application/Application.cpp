#include <Arduino.h>
#include <EEPROM.h>
#include "Application/Application.hpp"
#include "IoHwAb/IoHwAb.hpp"

/*Channel Configurations*/
Channel_Cfg_T ECU1;
Channel_Cfg_T ECU2;

char Channel_Cfg;
char ECU_Cfg;


/*********************************************************************
 * A Function that initalize Configuration related to Application
 *********************************************************************/
void Application_Init()
{
  /*Pins Configurations*/
  ECU1.Selection_0 = S0;
  ECU1.Selection_1 = S1;
  ECU2.Selection_0 = S2;
  ECU2.Selection_1 = S3;
  
  /*Read Channel Configuration from EEPROM*/
  Channel_Cfg = EEPROM.read(Channel_Cfg_Address);
  ECU_Cfg = EEPROM.read(ECU_Cfg_Address);

  /*TODO Assign Read Data from EEPROM to read data buffer*/
  /*TODO Set channel to the savedd channel from EEPROM*/
  
  /*Set Channel to the correct channel number*/
  SelectChannel(Veh_Channel , ECU1);
  SelectChannel(Veh_Channel , ECU2);
  /*Print that veh channel is the connected channel*/
  Serial.println("Veh Channel Connected for ECU1");
  Serial.println("Veh Channel Connected for ECU2");
  
}
/*********************************************************************
 * A Function that Process the data received from UART and handles it .
 *********************************************************************/
void Process_Application_Data(char *received_data)
{
    if ( (received_data[0] == 'V') && (received_data[1] == '1') )
    {
      /*Set channel veh channel for ECU1*/
      Serial.println("Veh Channel Connected for ECU1");
      SelectChannel(Veh_Channel , ECU1);
      EEPROM.write(Channel_Cfg,received_data[0]);
      EEPROM.write(ECU_Cfg_Address,received_data[1]);
    }
    else if ( (received_data[IDX_0] == 'V') && (received_data[IDX_1] == '2') )
    {
      /*Set channel veh channel for ECU2*/
      Serial.println("Veh Channel Connected for ECU2");
      SelectChannel(Veh_Channel , ECU2);
    }
    else if ( (received_data[IDX_0] == 'M') && (received_data[IDX_1] == '1') )
    {
      /*Set channel MRR channel for ECU1*/
      Serial.println("MRR Channel Connected for ECU1");
      SelectChannel(MRR_Channel , ECU1);
    }
    else if ( (received_data[IDX_0] == 'M') && (received_data[IDX_1] == '2') )
    {
      /*Set channel MRR channel for ECU2*/
      Serial.println("MRR Channel Connected for ECU2");
      SelectChannel(MRR_Channel , ECU2);
    }
    else if ( (received_data[IDX_0] == 'S') && (received_data[IDX_1] == '1') )
    {
      /*Set channel SRR_F channel for ECU1*/
      Serial.println("SRR Front Channel Connected for ECU1");
      SelectChannel(SRR_F_Channel , ECU1);
    }
    else if ( (received_data[IDX_0] == 'S') && (received_data[IDX_1] == '2') )
    {
      /*Set channel SRR_F channel for ECU2*/
      Serial.println("SRR Front Channel Connected for ECU2");
      SelectChannel(SRR_F_Channel , ECU2);
    }
    else if ( (received_data[IDX_0] == 'R') && (received_data[IDX_1] == '1') )
    {
      /*Set channel SRR_R channel for ECU1*/
      Serial.println("SRR Rear Channel Connected for ECU1");
      SelectChannel(SRR_R_Channel , ECU1);
    }
    else if ( (received_data[IDX_0] == 'R') && (received_data[IDX_1] == '2') )
    {
      /*Set channel SRR_R channel for ECU2*/
      Serial.println("SRR Rear Channel Connected for ECU2");
      SelectChannel(SRR_R_Channel , ECU2);
    }
    else
    {
      /*Do Nothing*/
    }
    /*Reset received_data after processing*/
    received_data[IDX_0] = '\0';
    received_data[IDX_1] = '\0';
    received_data[IDX_2] = '\0';
}