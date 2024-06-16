#include "TemperatureMonitor.h"
#include "config.h"

// Define the pin for the OneWire bus
#define ONE_WIRE_BUS 4

TemperatureMonitor tempMonitor(ONE_WIRE_BUS, SECRET_SSID, SECRET_PASS, SECRET_APIKEY);

void setup() {
    tempMonitor.begin();
}

void loop() {
    tempMonitor.update();
}
