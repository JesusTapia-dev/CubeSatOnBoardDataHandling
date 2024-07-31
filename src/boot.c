#include "boot.h"
adcs_info adcs;
battery_info battery;

void vTaskBoot(void *pvParameters) {
    // Código de inicialización del sistema
    // ...
    printf("Estado boot\n");
    int trydeploy=0;
    while(trydeploy<NUM_MAX_DEPLOY){
        SystemInit();
        measureVoltageCurrent();
        checkADCS_status();
        if(battery.voltage_status & adcs.adcs_antenna_status & trydeploy<(NUM_MAX_DEPLOY-1)){
            currentState = STATE_DEPLOYMENT;
            break;
        }  
        else {
            printf("error en deployment\n ");
            currentState = STATE_SAFE;
            break;
        }  
        trydeploy++;
    }
}

