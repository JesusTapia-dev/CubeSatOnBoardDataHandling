#ifndef SAFE_H
#define SAFE_H
#include "FreeRTOS.h"
#include "state_handler.h"
#include "tasksobc.h"

void vTaskSafe(void *pvParameters);
int emergencyState();
#endif // SAFE_H
