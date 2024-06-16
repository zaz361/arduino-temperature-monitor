# Arduino-thermometer
This project uses an Arduino to monitor the temperature using a DS18B20 sensor. The temperature is displayed on an LED matrix and sent to ThingSpeak for remote monitoring.

## Components
- Arduino Uno R4 WiFi
- DS18B20 Temperature Sensor
- LED Matrix
- Jumper Wires

## Circuit Diagram
Here is the circuit diagram for the project:
![thermometer visual](https://github.com/zaz361/arduino-temperature-monitor/assets/172925615/d9b4762e-464d-4e71-ad1d-8ea0341cb6ec)

The schematic was adapted from [Random Nerd Tutorials](https://randomnerdtutorials.com/guide-for-ds18b20-temperature-sensor-with-arduino/).

## Physical Setup
Here are pictures of the physical setup:
![1718528888199](https://github.com/zaz361/arduino-temperature-monitor/assets/172925615/656bb713-ce2d-4250-90e4-11f27b8c9b9b)

LED Matrix Displaying Temperature:
![1718528888203](https://github.com/zaz361/arduino-temperature-monitor/assets/172925615/9d22bdfe-ff58-4dec-9621-69fc570b1101)

(It is quite a challenge to take a good picture showing the LED matrix working, in this case the display says 26.5 *C)
![led matrix visualised](https://github.com/zaz361/arduino-temperature-monitor/assets/172925615/8502f0e9-21ad-4500-aabe-3d0ce53b051e)

## ThingSpeak Dashboard
Here is a screenshot of the ThingSpeak dashboard showing the uploaded temperature data:
![thingspeak_output](https://github.com/zaz361/arduino-temperature-monitor/assets/172925615/c52b3bf2-7794-4ce5-83f1-53dc20eb1ac2)

In this case the temperature readings are changing rapidly because I was testing out different parts of the house (Highest reading was in the kitchen).

## Usage
The temperature will be displayed on the LED matrix.
Temperature data will be sent to ThingSpeak every 30 seconds, but the user can chose whatever frequency they prefer (Keep in mind that free ThingSpeak trial allows no more than one request per 15 seconds).
Temperature readings will also be printed to the Serial Monitor.
![serial_monitor_output](https://github.com/zaz361/arduino-temperature-monitor/assets/172925615/4c015aa9-975f-4b9b-99d7-041af0735350)

## Benefits of the TemperatureMonitor Library

- **Integration**: Combines multiple functionalities, including temperature sensing, WiFi communication, and LED matrix display.
- **Simplicity**: Provides a simplified interface with high-level methods (`begin()`, `update()`, `displayTemperature()`, `clearDisplay()`).
- **Modularity**: Encapsulates the required operations, making the code more modular and maintainable.
- **Reuse of Established Libraries**: Leverages well-tested and optimized libraries for specific tasks, ensuring reliability and performance.

In the future I would like to learn to write my own libraries for individual components.

## References
- Project idea and the circuit schematic adapted from [Random Nerd Tutorials](https://randomnerdtutorials.com/guide-for-ds18b20-temperature-sensor-with-arduino/).
- [Arduino Official Documentation](https://www.arduino.cc/reference/en/)
- [OneWire Library](https://www.arduino.cc/reference/en/libraries/onewire/)
- [DallasTemperature Library](https://www.arduino.cc/reference/en/libraries/dallastemperature/)
- [ThingSpeak API Documentation](https://thingspeak.com/docs/)
- [Arduino_LED_Matrix](https://docs.arduino.cc/tutorials/uno-r4-wifi/led-matrix/)
- Problem-solving and bug fixing assistance using [ChatGPT](https://chatgpt.com)


