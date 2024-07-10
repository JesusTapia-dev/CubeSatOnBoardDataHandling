#include "transmitting.h"
#include "FreeRTOS.h"

#include <windows.h>
#include "queue.h" 
#include "task.h"

void vTaskTransmitting(void *pvParameters) {
    for(;;) {
        // Código para transmitir datos a la estación terrestre
        // ...
        printf("Transmitiendo");
        // Delay para permitir cambio de contexto a otras tareas
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
