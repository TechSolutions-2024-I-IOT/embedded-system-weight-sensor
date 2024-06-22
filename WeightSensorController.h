#ifndef WEIGHT_SENSOR_CONTROLLER_H
#define WEIGHT_SENSOR_CONTROLLER_H

#include "WeightSensor.h"

class WeightSensorController {
  private:
    WeightSensor** sensors;
    int numSensors;
  
  public:
    WeightSensorController(int numSensors, const int* doutPins, const int* clkPins, float calibrationFactor);
    ~WeightSensorController();
    void begin();
    int checkSensors();
    int getNumSensors() const;
    WeightSensor** getSensors() const;
};

#endif
