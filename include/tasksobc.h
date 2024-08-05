#ifndef TASKSOBC_H
#define TASKSOBC_H

#define NUM_MAX_DEPLOY 11
// NUM_MAX_DEPLOY=11 solo se pueden generar 10 intentos según el diagrama de bloques

// Declaraciones de las tareas
void vTaskBoot(void *pvParameters);
void vTaskDeployment(void *pvParameters);
void vTaskSafe(void *pvParameters);
void vTaskNominal(void *pvParameters);
void vTaskTransmitting(void *pvParameters);

typedef struct battery_info {
    int voltage_status;
    int voltage_battery;
    int current_battery;
} battery_info;
extern battery_info battery;
void measureVoltageCurrent();
// Informacion compartida de adcs
typedef struct adcs_info {
    int adcs_antenna_status;
    int adcs_detumbling_status;

} adcs_info;
extern adcs_info adcs;
void checkADCS_status();
typedef struct thermalControl_info {
    int system_temperature;
} thermalControl_info;
extern thermalControl_info thermalControl;
void checkThermalControl_status();
#endif
