# ESP32-FreeRTOS-Event-Group-Synchronization-Example
This project demonstrates task synchronization using Event Groups in FreeRTOS on the ESP32 platform
📝 Description:
This project demonstrates task synchronization using Event Groups in FreeRTOS on the ESP32 platform. It creates three tasks:
Task1 and Task2 periodically set their respective event bits.
SupervisorTask waits until both events occur, then proceeds to act.
The example highlights how FreeRTOS xEventGroupWaitBits() can be used to synchronize multiple tasks based on multiple events.

✅ Features:
FreeRTOS-based multitasking with event synchronization
Use of xEventGroupSetBits() and xEventGroupWaitBits()
Task coordination example for real-time applications
ESP32 compatible and Arduino-based

📦 Requirements:
ESP32 development board
Arduino IDE or PlatformIO
FreeRTOS (bundled with ESP32 Arduino core)
