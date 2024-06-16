#ifndef TEMPERATURE_MONITOR_H
#define TEMPERATURE_MONITOR_H

#include <OneWire.h>
#include <DallasTemperature.h>
#include "WiFiS3.h"
#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"

// Class to manage temperature monitoring, display, and uploading to ThingSpeak
class TemperatureMonitor {
public:
    // Constructor: initializes with required pins and credentials
    TemperatureMonitor(int oneWireBus, const char* ssid, const char* password, const char* apiKey);
    
    // Initializes the sensors, matrix, and WiFi connection
    void begin();
    
    // Main update function to request temperature, display it, and send to ThingSpeak
    void update();
    
    // Displays the temperature on the LED matrix
    void displayTemperature(float temperature);
    
    // Clears the LED matrix display
    void clearDisplay();

private:
    // OneWire instance for temperature sensor communication
    OneWire oneWire;
    
    // DallasTemperature instance for handling temperature readings
    DallasTemperature sensors;
    
    // LED matrix instance for displaying information
    ArduinoLEDMatrix matrix;
    
    // WiFi client instance for network communication
    WiFiClient client;

    // WiFi credentials and ThingSpeak API key
    const char* ssid;
    const char* password;
    const char* apiKey;
    const char* server = "api.thingspeak.com"; // ThingSpeak server URL
    int status; // WiFi connection status

    // Connects to the WiFi network
    void connectToWiFi();
    
    // Sends temperature data to ThingSpeak
    void sendToThingSpeak(float temperature);
};

#endif
