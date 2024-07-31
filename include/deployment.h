#ifndef DEPLOYMENT_H
#define DEPLOYMENT_H
#include "state_handler.h"
#include "FreeRTOS.h"
#include "task.h"
//extern int antenna_released;
void vTaskDeployment(void *pvParameters);
int antenna_released();
#endif // DEPLOYMENT_H
