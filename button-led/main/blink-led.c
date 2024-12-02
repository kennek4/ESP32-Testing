#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_log.h"

#include "driver/gpio.h"

// GPIO Pins
#define BLINK_LED 2
#define BUTTON 13

void app_main(void)
{

  char *ourTaskName = pcTaskGetName(NULL);
  ESP_LOGI(ourTaskName, "Hello, starting up!\n");

  gpio_reset_pin(BLINK_LED);
  gpio_set_direction(BLINK_LED, GPIO_MODE_OUTPUT);

  gpio_reset_pin(BUTTON);
  gpio_set_direction(BUTTON, GPIO_MODE_INPUT); 

  while(1) {
    if (gpio_get_level(BUTTON) != 1) { // Button is pressed
      gpio_set_level(BLINK_LED, 1);
      ESP_LOGI("Button", "Button has been pressed!\n");
    } else { // Button not pressed
      gpio_set_level(BLINK_LED, 0);
    } 
    
    vTaskDelay(1);
  }
}
