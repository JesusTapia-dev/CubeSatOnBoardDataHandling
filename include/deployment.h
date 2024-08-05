#ifndef DEPLOYMENT_H
#define DEPLOYMENT_H
#include "FreeRTOS.h"
#include "state_handler.h"
#include "tasksobc.h"

void vTaskDeployment(void *pvParameters);
int antenna_released();
#endif // DEPLOYMENT_H
