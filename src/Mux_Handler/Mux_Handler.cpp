#include "Mux_Handler/Mux_Handler.hpp"
#include "IoHwAb/IoHwAb.hpp"
#include <Arduino.h>

void SelectChannel(Channel_t channel,Channel_Cfg_T Channel_Cfg)
{
    switch(channel)
    {
        case Channel0 :
            digitalWrite(Channel_Cfg.Selection_0,LOW);
            digitalWrite(Channel_Cfg.Selection_1,LOW);
            break;
        case Channel1 :
            digitalWrite(Channel_Cfg.Selection_0,HIGH);
            digitalWrite(Channel_Cfg.Selection_1,LOW);
            break;
        case Channel2 :
            digitalWrite(Channel_Cfg.Selection_0,LOW);
            digitalWrite(Channel_Cfg.Selection_1,HIGH);
            break;
        case Channel3 :
            digitalWrite(Channel_Cfg.Selection_0,HIGH);
            digitalWrite(Channel_Cfg.Selection_1,HIGH);
            break;
        default:
            /*Veh Channel*/
            digitalWrite(Channel_Cfg.Selection_0,LOW);
            digitalWrite(Channel_Cfg.Selection_1,LOW);
            break;
    }
}