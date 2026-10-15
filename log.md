# Learning Log

## 2026-10-15 - Project 1.1: Blink patterns
- Prediction: 2 s per pulse, 10 s cycle.
- Measured: 2.4 s cycle. Each pulse's off-time adds to the total: (200+200) + (200+200) + (600+1000) = 2400 ms.
- Lesson: add every on-time and off-time when calculating a cycle. Predictions should include the full math.