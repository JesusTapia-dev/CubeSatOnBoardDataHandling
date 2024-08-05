#include <stdio.h>

#include "FreeRTOS.h"
#include "state_handler.h"
#include "system_init.h"
#include "task.h"
#include "tasksobc.h"
// #include "queue.h"
// #include "windows.h"
void vAssertCalled(void) {
    taskDISABLE_INTERRUPTS();
    for (;;);
}

void vTaskTest(void *pvParameters) {
    for (;;) {
        printf("Corriendo vTaskTest...\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

int main(void) {
    // Inicialización del sistema
    SystemInit();

    // Creación de la tarea de gestión de estados
    xTaskCreate(vTaskStateHandler, "StateHandler", 1000, NULL, 3, NULL);

    // Creación de una tarea de prueba
    xTaskCreate(vTaskTest, "TestTask", 1000, NULL, 2, NULL);

    // Inicio del scheduler
    vTaskStartScheduler();

    // El programa no debería llegar aquí
    for (;;);
    return 0;
}
