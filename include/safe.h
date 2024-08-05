#ifndef SAFE_H
#define SAFE_H
#include "FreeRTOS.h"
#include "state_handler.h"
#include "tasksobc.h"

void vTaskSafe(void *pvParameters);
int emergencyState();
// en esa funcion se coloca los parametros que mantienen al satelite en estado de emergencia
#endif // SAFE_H
