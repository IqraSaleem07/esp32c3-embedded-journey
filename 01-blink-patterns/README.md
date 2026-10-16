# 01 - Blink Patterns

A timed LED pattern on the ESP32-C3 Super Mini, written in plain ESP-IDF C using the GPIO driver and FreeRTOS delays.

## Hardware
- Board: ESP32-C3 Super Mini
- LED pin: GPIO [8] (onboard LED)
- LED type: [active-high], based on what I observed

## Pattern
| Step | State | Duration |
| ---- | ----- | -------- |
| 1 | ON  | 0.2 s |
| 2 | OFF | 0.2 s |
| 3 | ON  | 0.2 s |
| 4 | OFF | 0.2 s |
| 5 | ON  | 0.6 s |
| 6 | OFF | 1.0 s |

Full cycle: 2.4 s, then the pattern repeats.

## How it works
- `gpio_set_direction` makes the pin an output.
- `led_pulse()` sets the pin HIGH, waits, sets it LOW, and waits.
- `app_main()` calls the pulses in order inside a `while (1)` loop.
- Timing comes from `vTaskDelay`, not a busy-wait loop, so the CPU isn't blocked.

## Lesson learned
My first prediction was 2 s per pulse and a 10 s cycle. The actual cycle is 2.4 s, because I added only the on-times and forgot the off-times. Every on-time and off-time has to be included in the total.

## Build and flash
```
idf.py set-target esp32c3
idf.py build
idf.py -p COM9 flash monitor
```
