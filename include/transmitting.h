#ifndef TRANSMITTING_H
#define TRANSMITTING_H
#include "FreeRTOS.h"
#include "state_handler.h"
void vTaskTransmitting(void *pvParameters);
int groundComunicationStablished();
void sendBeacon();

#endif // TRANSMITTING_H
