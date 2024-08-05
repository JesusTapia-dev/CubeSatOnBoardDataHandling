#include "transmitting.h"

#include "FreeRTOS.h"
#include "tc_prueba.h"

void vTaskTransmitting(void *pvParameters) {
    for (;;) {
        // Código para transmitir datos a la estación terrestre
        // ...
        printf("estado transmitiendo");
        sendBeacon(); // posible funcion para enviar el beacon cada 10 segundos
        measureVoltageCurrent();
        checkThermalControl_status();
        if (groundComunicationStablished) {
            if (telecommandExists) {
                // Crear una tarea para manejar los telecomandos revisar
                xTaskCreate(vTaskTelecommand, "TelecommandTask", configMINIMAL_STACK_SIZE,
                            NULL, 1, NULL);
            } else {
                if (battery.voltage_status & adcs.adcs_antenna_status &
                    thermalControl.system_temperature) {
                    // vTaskDelay(1000 / portTICK_PERIOD_MS); delay de 1s
                } else {
                    currentState = STATE_SAFE;
                    break;
                }
            }
        } else {
            currentState = STATE_NOMINAL;
            break;
        }
        // Delay para permitir cambio de contexto a otras tareas
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
