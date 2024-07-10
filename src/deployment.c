#include "deployment.h"
#include "state_handler.h"
#include "FreeRTOS.h"
#include "task.h"
int deploy=0;
void vTaskDeployment(void *pvParameters) {
    // Código para desplegar antenas y paneles solares
    // ...
    for(;;){
        deploy=deploy+1;
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        if(deploy>10){
            printf("Error en el despliegue\n");
            break;
        } 
    }
    
    // Transición al siguiente estado
    currentState = STATE_NOMINAL;
}
