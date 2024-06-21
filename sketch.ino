#include <HTTPClient.h>
#include "WiFiBackendManager.h"
#include "WeightSensorController.h"

#define WIFI_SSID "Wokwi-GUEST"
#define WIFI_PASSWORD ""
#define EDGE_BACKEND_URL "https://taskedgelayerservice.azurewebsites.net/api/v1/sensor-data"

// Define pins for multiple sensors
const int DOUT_PINS[] = {19, 21, 17, 25, 4, 14};
const int CLK_PINS[] = {18, 22, 16, 26, 0, 12};
const int NUM_SENSORS = 6;

WiFiBackendManager wifiBackendManager(WIFI_SSID, WIFI_PASSWORD, EDGE_BACKEND_URL);
WeightSensorController sensorController(NUM_SENSORS, DOUT_PINS, CLK_PINS, 420.00);

// HTTP Client
HTTPClient client_http;

// WiFi Client
WiFiClient client_wifi;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  wifiBackendManager.connectWifi();
  // wifiBackendManager.connectBackend();
  sensorController.begin();
}

void loop() {
  // Check the sensors and get the number of occupied seats
  int occupiedCount = sensorController.checkSensors();

  // Send data to backend
  // wifiBackendManager.sendData(occupiedCount);
  delay(10000); 
}
