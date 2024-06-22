#ifndef DEVICE_H
#define DEVICE_H

#include "WiFiBackendManager.h"
#include "WeightSensorController.h"
#include "SimulatedWeightSensorController.h"
#include "config.h"

class Device {
public:
    Device();
    void setup();
    void loop();

private:
    WiFiBackendManager wifiBackendManager;
    WeightSensorController sensorController;
    SimulatedWeightSensorController simulatedWeightSensorController;
    void sendDataToBackend(int occupiedCount);
};

#endif // DEVICE_H
