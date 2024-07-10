#include "nominal.h"
#include "FreeRTOS.h"

#include <windows.h>
#include "queue.h" 
#include "task.h"

void vTaskNominal(void *pvParameters) {
    for(;;) {
        // Código para operaciones normales y carga útil
        // ...

        // Delay para permitir cambio de contexto a otras tareas
        // Retrasar la tarea por 1000 ms
        printf("estado nominal \n");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
