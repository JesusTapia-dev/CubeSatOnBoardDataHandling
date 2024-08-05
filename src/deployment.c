#include "deployment.h"
adcs_info adcs;

void vTaskDeployment(void *pvParameters) {
    printf("Estado deployment\n");
    void checkADCS_status();
    if (adcs.adcs_antenna_status) {
        // Transición al siguiente estado
        currentState = STATE_NOMINAL;
    } else currentState = STATE_SAFE;
}
