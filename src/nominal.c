#include "nominal.h"

void vTaskNominal(void *pvParameters) {
    for (;;) {
        // Código para operaciones normales y carga útil
        // ...

        // Delay para permitir cambio de contexto a otras tareas
        // Retrasar la tarea por 1000 ms
        printf("estado nominal \n");
        sendBeacon();
        measureVoltageCurrent();
        checkThermalControl_status();
        if (groundComunicationStablished()) {
            currentState = STATE_TRANSMITTING;
            break;
        } else {
            if (battery.voltage_status & adcs.adcs_antenna_status &
                thermalControl.system_temperature) {
                vTaskDelay(15000 / portTICK_PERIOD_MS); // delay de 15 s
            } else {
                currentState = STATE_SAFE;
                break;
            }
            vTaskDelay(1000 / portTICK_PERIOD_MS);
        }
    }
}
