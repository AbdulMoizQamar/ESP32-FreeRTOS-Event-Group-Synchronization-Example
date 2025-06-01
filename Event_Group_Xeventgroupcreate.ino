#include <Arduino.h>
#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"

#define BIT_TASK1 (1 << 0)
#define BIT_TASK2 (1 << 1)

EventGroupHandle_t xCreatedEventGroup;

void Task1(void *pvParameters) {
  while (1) {
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    Serial.println("Task1: Setting BIT_TASK1");
    xEventGroupSetBits(xCreatedEventGroup, BIT_TASK1);
  }
}

void Task2(void *pvParameters) {
  while (1) {
    vTaskDelay(1500 / portTICK_PERIOD_MS);
    Serial.println("Task2: Setting BIT_TASK2");
    xEventGroupSetBits(xCreatedEventGroup, BIT_TASK2);
  }
}

void SupervisorTask(void *pvParameters) {
  EventBits_t uxBits;
  while (1) {
    uxBits = xEventGroupWaitBits(
        xCreatedEventGroup,         
        BIT_TASK1 | BIT_TASK2,     
        pdTRUE,                    
        pdTRUE,                    
        portMAX_DELAY);             

    if ((uxBits & (BIT_TASK1 | BIT_TASK2)) == (BIT_TASK1 | BIT_TASK2)) {
      Serial.println("Supervisor: Both events occurred. Proceeding...");
    }
  }
}

void setup() {
  Serial.begin(115200);
  xCreatedEventGroup = xEventGroupCreate();

    xTaskCreate(Task1, "Task1", 2048, NULL, 2, NULL);
    xTaskCreate(Task2, "Task2", 2048, NULL, 2, NULL);
    xTaskCreate(SupervisorTask, "Supervisor", 2048, NULL, 3, NULL);
}

void loop() {
  // Nothing here. Tasks are running independently.
}
