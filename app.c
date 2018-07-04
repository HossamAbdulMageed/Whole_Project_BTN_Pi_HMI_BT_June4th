#include <stdint.h>
#include "BTN.h"
#include "BTN_Cfg.h"
#include "GPIO.h"
#include "PiMngr.h"
#include "PiMngr_Cfg.h"
#include"app.h"
#include "HMIManager.h"
#include "HMIManager_Cfg.h"
#include "HMI.h"
#include "HMI_Cfg.h"
#include "BT.h"
#include "BT_Cfg.h"



//state = 0;
//counter = 0;
uint8_t StateX,x=0;
uint32_t counter=0,state=0;
void app(void)
{

    if(StateX == BTN_ON)
    {
        state=1;
        StateX = BTN_OFF;
        HMI_RecognitionState(0,1);
    }
    if(state==1)
    {
        counter++;
        if(counter==1)
        {
            PiMngr_GetStatus();
        }
        PiMngr_StartRecognition();
        PiMngr_RequestData();
    }

    if(state==2)
    {
        HMI_RecognitionState(0,0);
        x^=1;
        Engine_Status_Display(0,x);
        state =3;
    }
    if(state==6)
    {
        /**/
        HMI_RecognitionState(0,0);
        GPS_Request();


        state =3;
    }
    if(state==7)
     {
         /**/
        HMI_RecognitionState(0,0);
         SendCmd(BT_Call,"01065233286");
       // SendCmd(BT_Call,"01111709622");
        //  Music_Status_Display(0 , Stop);
         state =3;
     }



    }

