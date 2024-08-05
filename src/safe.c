#include "safe.h"

#include "FreeRTOS.h"

void vTaskSafe(void *pvParameters) {
    for (;;) {
        // Código para modo seguro
        // ...
        printf("estado safe \n");
        if (emergencyState()) {
            while (emergencyState()) {
                // Delay para conservar energía
                vTaskDelay(1000 / portTICK_PERIOD_MS);
                measureVoltageCurrent();
                checkThermalControl_status();
                checkADCS_status();
            }
        } else {
            currentState = STATE_NOMINAL;
            break;
        }
    }
}
