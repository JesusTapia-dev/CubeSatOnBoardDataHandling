#include "deployment.h"

int antenna_released(){
    /*
        brief: revisa si la antena es desplegada 
        accede a la información de adcs y 
    */
   return 1;
} 
void vTaskDeployment(void *pvParameters) {

    //Intentamos 5 intentos de desplegar la antena 
    printf("Estado Deployment\n");
     // Transición al siguiente estado
    if(antenna_released())    currentState = STATE_NOMINAL;
    else currentState = STATE_SAFE;
}