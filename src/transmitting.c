#include "transmitting.h"
// Variable global para el tiempo actual
int payloadState = 0; // 0: Off, 1: On
int currentTime = 0;

int groundComunicationStablished(){
    /*
    brief: 
    */

    return 1;
}
void sendBeacon(){
    /*
    brief: Logica para enviar el beacon cada 10 segundos
    */

}
void hardReset(void) {
    // Resetear el tiempo
    currentTime = 0;
    printf("Tiempo reseteado a: %d\n", currentTime);

    // Colocar el sistema en estado boot
    currentState = STATE_BOOT;
    printf("Sistema BOOTEADO.\n");
}
void vTaskTransmitting(void *pvParameters) {
    char command[50];

    for(;;) {
        // Código para transmitir datos a la estación terrestre
        // ...
        printf("Estado Transmitting \n");
        // Delay para permitir cambio de contexto a otras tareas


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
                break;
            } else {
                printf("Comando desconocido: %s\n", command);
            }
        }
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}



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

    while (1) {
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
                break;
            } else {
                printf("Comando desconocido: %s\n", command);
            }
        }

        // Delay para permitir cambio de contexto a otras tareas
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}
