#ifndef _Application_
#define _Application_

#include "Mux_Handler/Mux_Handler.hpp"

void Process_Application_Data(char *received_data);
void Application_Init(void);

/*Array IDX*/
#define IDX_0 0
#define IDX_1 1
#define IDX_2 2

/*EEPROM Addresses for the data*/
#define Channel_Cfg_Address 0
#define ECU_Cfg_Address 1
/*define string max length*/
#define Max_Length 3 /*Max Length is a 3 Char*/

/*Define channel names with ECU Channels names*/
#define Veh_Channel Channel0
#define MRR_Channel Channel1
#define SRR_F_Channel Channel2
#define SRR_R_Channel Channel3


#endif