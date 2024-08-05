#include "boot.h"
adcs_info adcs;
battery_info battery;
thermalControl_info thermalControl;

void vTaskBoot(void *pvParameters) {
    // Código de inicialización del sistema
    // ...
    printf("Estado boot\n");
    int trydeploy = 0;
    printf("trdeploy=: %d\n", trydeploy);
    while (trydeploy < NUM_MAX_DEPLOY) {
        printf("Intento de despliegue: %d\n", trydeploy);
        SystemInit();
        printf("Después de SystemInit\n");
        measureVoltageCurrent();
        checkADCS_status();
        if (battery.voltage_status & adcs.adcs_antenna_status &
            thermalControl.system_temperature & trydeploy < (NUM_MAX_DEPLOY - 1)) {
            // en este caso voltage_status verifica el estado de la bateria, se podría poner
            // como una variable booleana, tal que si este valor >= ValMinOpeEstNom ->
            // voltage_status=true; de la misma manera adcs_antenna_status podría ser una var.
            // bool tal que si la funcion antennas_deployed()=1-> esa var. es true; ojo en este
            // caso tambien podría añadirse temperatura del sistema, controlado por el subs. de
            // control termico investigar
            currentState = STATE_DEPLOYMENT;
            break;
        } else {
            printf("error en deployment\n ");
            currentState = STATE_SAFE;
            break;
        }
        trydeploy++;
    }
}
/*
se podria colocar a esta funcion como booleana
int Antennas_deployed() {
    // Lógica para determinar si las antenas pueden ser desplegadas
    // ...
    return 1; // Retornar 1 si pueden ser desplegadas, 0 en caso contrario
}
*/
