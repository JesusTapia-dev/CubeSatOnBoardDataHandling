#include "tc_prueba.h"

#include <stdio.h>
#include <string.h>

#include "FreeRTOS.h"
#include "state_handler.h"
#include "task.h"

// Variable global para el tiempo actual
int currentTime = 0;
int payloadState = 0; // 0: Off, 1: On

void setTime(int newTime) {
    currentTime = newTime;
    printf("Tiempo ajustado a: %d\n", currentTime);
}

void turnPayloadOn(void) {
    payloadState = 1;
    printf("Carga útil encendida.\n");
}

void turnPayloadOff(void) {
    payloadState = 0;
    printf("Carga útil apagada.\n");
}

void hardReset(void) {
    // Resetear el tiempo
    currentTime = 0;
    printf("Tiempo reseteado a: %d\n", currentTime);

    // Colocar el sistema en estado boot
    currentState = STATE_BOOT;
    printf("Sistema en estado BOOT.\n");
}

void vTaskTimeUpdate(void *pvParameters) {
    while (1) {
        // Incrementar el tiempo cada segundo
        currentTime++;
        printf("Tiempo actual: %d\n", currentTime);

        // Esperar 1 segundo
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void vTaskTelecommand(void *pvParameters) {
    char command[50];

    // printf("Ingrese comando: ");
    if (fgets(command, sizeof(command), stdin) != NULL) {
        // Eliminar el salto de línea al final del comando
        command[strcspn(command, "\n")] = 0;

        if (strncmp(command, "SETTIME ", 8) == 0) {
            // Extraer el nuevo tiempo del comando
            int newTime = atoi(command + 8);
            setTime(newTime);
        } else if (strcmp(command, "PAYLOAD ON") == 0) {
            turnPayloadOn();
        } else if (strcmp(command, "PAYLOAD OFF") == 0) {
            turnPayloadOff();
        } else if (strcmp(command, "HARD RESET") == 0) {
            hardReset();
        } else {
            printf("Comando desconocido: %s\n", command);
        }
    }

    // Delay para permitir cambio de contexto a otras tareas
    vTaskDelay(pdMS_TO_TICKS(100));
}