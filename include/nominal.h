#ifndef NOMINAL_H
#define NOMINAL_H
#include "FreeRTOS.h"
#include "state_handler.h"
#include "tasksobc.h"
#include "transmitting.h" //verif

void vTaskNominal(void *pvParameters);

#endif // NOMINAL_H
