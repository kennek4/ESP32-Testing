#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_log.h"

#include "driver/gpio.h"

// Levels
#define HIGH 1
#define LOW 0

// GPIO Pins
#define BUTTON 21
#define BUZZER 14

void app_main(void)
{
  char *currTaskName = pcTaskGetName(NULL); 
  ESP_LOGI(currTaskName, "Hello, starting up!\n");

  gpio_reset_pin(BUTTON);
  gpio_set_direction(BUTTON, GPIO_MODE_INPUT);

  gpio_reset_pin(BUZZER);
  gpio_set_direction(BUZZER, GPIO_MODE_OUTPUT);

  while (1) {
    if (gpio_get_level(BUTTON) == LOW) {
      gpio_set_level(BUZZER, HIGH); 
      ESP_LOGI(currTaskName, "Buzzer is on.\n");
    } else {
      gpio_set_level(BUZZER, LOW);
    }

    vTaskDelay(1);
  }

} 
