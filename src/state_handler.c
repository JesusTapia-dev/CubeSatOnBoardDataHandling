#include "FreeRTOS.h"
#include "task.h"
#include "state_handler.h"
#include "boot.h"
#include "deployment.h"
#include "safe.h"
#include "nominal.h"
#include "transmitting.h"

SystemState currentState = STATE_BOOT;

void vTaskStateHandler(void *pvParameters) {
    for(;;) {
        switch (currentState) {
            case STATE_BOOT:
                vTaskBoot(NULL);
                break;
            case STATE_DEPLOYMENT:
                vTaskDeployment(NULL);
                break;
            case STATE_SAFE:
                vTaskSafe(NULL);
                break;
            case STATE_NOMINAL:
                vTaskNominal(NULL);
                break;
            case STATE_TRANSMITTING:
                vTaskTransmitting(NULL);
                break;
        }
        // Delay para permitir cambio de contexto a otras tareas
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}
