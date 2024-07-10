#ifndef TASKSOBC_H
#define TASKSOBC_H

// Declaraciones de las tareas
void vTaskBoot(void *pvParameters);
void vTaskDeployment(void *pvParameters);
void vTaskSafe(void *pvParameters);
void vTaskNominal(void *pvParameters);
void vTaskTransmitting(void *pvParameters);

#endif // TASKS_H
