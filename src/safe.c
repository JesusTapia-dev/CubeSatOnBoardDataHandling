#include "safe.h"
#include "FreeRTOS.h"

#include <windows.h>
#include "queue.h" 
#include "task.h"

void vTaskSafe(void *pvParameters) {
    for(;;) {
        // Código para modo seguro
        // ...
        printf("estado safe \n");
        // Delay para conservar energía
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}