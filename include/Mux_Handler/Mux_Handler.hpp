
#ifndef _Mux_Handler
#define _Mux_Handler


typedef enum Channel_E
{
    Channel0,
    Channel1,
    Channel2,
    Channel3,
}Channel_t;

typedef struct Channel_Cfg
{
    char Selection_0;
    char Selection_1;
}Channel_Cfg_T;

void SelectChannel(Channel_t channel,Channel_Cfg_T Channel_Cfg);

#endif