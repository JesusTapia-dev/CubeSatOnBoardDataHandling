#ifndef TRANSMITTING_H
#define TRANSMITTING_H
#include "FreeRTOS.h"
#include "state_handler.h"
#include <stdio.h>
#include <string.h>
void vTaskTransmitting(void *pvParameters);
int groundComunicationStablished();
void sendBeacon();
void vTaskTelecommand(void *pvParameters);
void vTaskTimeUpdate(void *pvParameters);
void setTime(int newTime);
void turnPayloadOn(void);
void turnPayloadOff(void);
void vTaskTelecommandReset(void *pvParameters);

#endif // TRANSMITTING_H
