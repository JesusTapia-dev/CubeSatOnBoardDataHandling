#include "nominal.h"

void vTaskNominal(void *pvParameters) {
    for(;;) {
        // Código para operaciones normales y carga útil
        // ...

        // Delay para permitir cambio de contexto a otras tareas
        // Retrasar la tarea por 1000 ms
        printf("Estado Nominal \n");
        sendBeacon();
        measureVoltageCurrent();
        if(groundComunicationStablished()){
            currentState=STATE_TRANSMITTING;
            break;
        }
        else {
             if(battery.voltage_status & adcs.adcs_antenna_status){

                vTaskDelay(1000 / portTICK_PERIOD_MS);//delay de 15 s
            }
            else {
                currentState=STATE_SAFE;
                break;
            }
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        }
    }
}
