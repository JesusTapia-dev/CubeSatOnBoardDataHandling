#ifndef STATE_HANDLER_H
#define STATE_HANDLER_H

typedef enum {
    STATE_BOOT,
    STATE_DEPLOYMENT,
    STATE_SAFE,
    STATE_NOMINAL,
    STATE_TRANSMITTING
} SystemState;

extern SystemState currentState;

void vTaskStateHandler(void *pvParameters);

#endif // STATE_HANDLER_H