#ifndef _IOHwabs
#define _IOHwabs

/*Selection Pins for First Mux 8052*/
#define S0 10 /*D10 on Arduino uno board*/
#define S1 11 /*D11 on Arduino uno board*/ 
/*Selection Pins for Second Mux 8052*/
#define S2 12 /*D12 on Arduino uno board*/
#define S3 13 /*D13 on Arduino uno board*/

/*Init function for IOHwabs*/
void IoHwAb_Init(void);

/*Runnable which gets triggered every 5ms*/
void R_IOHwabs_5ms();

#endif