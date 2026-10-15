#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define LED_PIN GPIO_NUM_8   // check this matches your board's LED

static void led_pulse(uint32_t on_ms, uint32_t off_ms)
{
    gpio_set_level(LED_PIN, 1);
    vTaskDelay(on_ms / portTICK_PERIOD_MS);
    gpio_set_level(LED_PIN, 0);
    vTaskDelay(off_ms / portTICK_PERIOD_MS);
}

void app_main(void)
{
    gpio_reset_pin(LED_PIN);
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);

    while (1) {
        led_pulse(200, 200);    // short
        led_pulse(200, 200);    // short
        led_pulse(600, 1000);   // long
    }
}