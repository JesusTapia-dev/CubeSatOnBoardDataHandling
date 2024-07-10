#include "boot.h"
#include "state_handler.h"

void vTaskBoot(void *pvParameters) {
    // Código de inicialización del sistema
    // ...
    printf("Estado Boot \n");
    // Transición al siguiente estado
    currentState = STATE_DEPLOYMENT;
}
