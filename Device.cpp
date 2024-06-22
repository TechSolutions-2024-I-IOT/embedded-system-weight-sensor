#include "Device.h"

Device::Device()
  : wifiBackendManager(WIFI_SSID, WIFI_PASSWORD, EDGE_BACKEND_URL),
    sensorController(NUM_SENSORS, DOUT_PINS, CLK_PINS, CALIBRATION_FACTOR),
    simulatedWeightSensorController(sensorController){}

void Device::setup() {
    Serial.begin(115200);
    Serial.println("Hello, ESP32!");
    wifiBackendManager.connectWifi();
    // wifiBackendManager.connectBackend();
    sensorController.begin();
}

void Device::loop() {

  // Aquí puedes elegir usar el peso simulado o el real
    boolean useSimulation = true; // Cambia esto a false para usar los dispositivos manualmente

    int occupiedCount;
    if (useSimulation) {
        occupiedCount = simulatedWeightSensorController.checkSensors();
    } else {
        occupiedCount = sensorController.checkSensors();
    }

    // sendDataToBackend(occupiedCount);
    delay(5000);
}

void Device::sendDataToBackend(int occupiedCount) {
    wifiBackendManager.sendData(occupiedCount);
}
