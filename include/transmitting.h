#ifndef TRANSMITTING_H
#define TRANSMITTING_H
#include "FreeRTOS.h"
#include "state_handler.h"
#include "tasksobc.h"

void vTaskTransmitting(void *pvParameters);
int groundComunicationStablished();
int telecommandExists();
void sendBeacon();

#endif // TRANSMITTING_H