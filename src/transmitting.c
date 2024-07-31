#include "transmitting.h"

int groundComunicationStablished(){
    /*
    brief: 
    */

    return 1;
}
void sendBeacon(){
    /*
    brief: Logica para enviar el beacon cada 10 segundos
    */

}

void vTaskTransmitting(void *pvParameters) {
    for(;;) {
        // Código para transmitir datos a la estación terrestre
        // ...
        printf("Estado Transmitting \n");
        // Delay para permitir cambio de contexto a otras tareas
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
