#ifndef TC_PRUEBA_H
#define TC_PRUEBA_H

void vTaskTelecommand(void *pvParameters);
void vTaskTimeUpdate(void *pvParameters);
void setTime(int newTime);
void turnPayloadOn(void);
void turnPayloadOff(void);
void vTaskTelecommandReset(void *pvParameters);

#endif // TC_PRUEBA_H
