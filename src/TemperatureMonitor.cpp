#include "TemperatureMonitor.h"

TemperatureMonitor::TemperatureMonitor(int oneWireBus, const char* ssid, const char* password, const char* apiKey)
    : oneWire(oneWireBus), sensors(&oneWire), ssid(ssid), password(password), apiKey(apiKey), status(WL_IDLE_STATUS) {}

void TemperatureMonitor::begin() {
    Serial.begin(9600);
    while (!Serial) { ; }

    if (WiFi.status() == WL_NO_MODULE) {
        while (true);
    }

    connectToWiFi();
    sensors.begin();
    matrix.begin();
}

void TemperatureMonitor::update() {
    sensors.requestTemperatures();
    float celsiusTemp = sensors.getTempCByIndex(0);

    displayTemperature(celsiusTemp);

    Serial.print("Temperature: ");
    Serial.print(celsiusTemp);
    Serial.println(" *C");

    if (WiFi.status() == WL_CONNECTED) {
        sendToThingSpeak(celsiusTemp);
    }

    delay(15000); // Display temperature for 15 seconds
    clearDisplay(); // Clear the display
    delay(15000); // Wait another 15 seconds before the next update
}

void TemperatureMonitor::displayTemperature(float temperature) {
    char tempStr[6];
    snprintf(tempStr, sizeof(tempStr), "%4.1f", temperature);

    matrix.beginDraw();
    matrix.clear();
    matrix.textFont(Font_4x6);

    int xPos = 0;
    for (int i = 0; i < 4; i++) {
        if (tempStr[i] == '.') {
            matrix.beginText(xPos - 1, 5, 0xFFFFFF);
            matrix.print(".");
            matrix.endText(NO_SCROLL);
        } else {
            matrix.beginText(xPos, 0, 0xFFFFFF);
            matrix.print(tempStr[i]);
            matrix.endText(NO_SCROLL);
            xPos += 4;
        }
    }

    matrix.endDraw();
}

void TemperatureMonitor::clearDisplay() {
    matrix.beginDraw();
    matrix.clear();
    for (int x = 0; x < 12; x++) {
        for (int y = 0; y < 7; y++) {
            matrix.beginText(x, y, 0x000000);
            matrix.print(" ");
            matrix.endText(NO_SCROLL);
        }
    }
    matrix.endDraw();
}

void TemperatureMonitor::connectToWiFi() {
    while (status != WL_CONNECTED) {
        Serial.print("Attempting to connect to SSID: ");
        Serial.println(ssid);
        status = WiFi.begin(ssid, password);
        delay(10000);
    }
    Serial.println("Connected to WiFi");
}

void TemperatureMonitor::sendToThingSpeak(float temperature) {
    if (client.connect(server, 80)) {
        Serial.println("Sent to ThingSpeak");
        String getStr = "/update?api_key=";
        getStr += apiKey;
        getStr += "&field1=";
        getStr += String(temperature);

        client.print(String("GET ") + getStr + " HTTP/1.1\r\n" +
                     "Host: " + server + "\r\n" +
                     "Connection: close\r\n\r\n");

        client.stop();
    }
}
