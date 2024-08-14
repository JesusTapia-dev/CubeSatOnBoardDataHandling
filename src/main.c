#include "FreeRTOS.h"
#include "task.h"
#include "state_handler.h"
#include <stdio.h>
#include "system_init.h"
#include "transmitting.h"

void vAssertCalled(void) { 
    taskDISABLE_INTERRUPTS();
    for( ;; );
}


void vTaskTest(void *pvParameters) {
    for(;;) {
        printf("Corriendo vTaskTest...\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

int main(void) {
    // Inicialización del sistema
   //  SystemInit();

    // Creación de la tarea de gestión de estados
    xTaskCreate(vTaskStateHandler, "StateHandler", 1000, NULL, 2 , NULL);

    // Creación de una tarea de prueba
  //  xTaskCreate(vTaskTest, "TestTask", 1000, NULL, 2, NULL);



    // Creación de la tarea de telecomando
     // xTaskCreate(vTaskTelecommand, "Telecommand", 1000, NULL, 2, NULL);

    // Creación de la tarea de actualización de tiempo
    xTaskCreate(vTaskTimeUpdate, "TimeUpdate", 1000, NULL, 2, NULL);

    // Inicio del scheduler
    vTaskStartScheduler();

    // El programa no debería llegar aquí
    for(;;);
    return 0;
}
