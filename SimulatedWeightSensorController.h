#ifndef SIMULATED_WEIGHT_SENSOR_CONTROLLER_H
#define SIMULATED_WEIGHT_SENSOR_CONTROLLER_H

#include "WeightSensorController.h"
#include "SimulatedWeightSensor.h"

class SimulatedWeightSensorController {
  private:
    SimulatedWeightSensor** simulatedSensors;
    int numSensors;

  public:
    SimulatedWeightSensorController(WeightSensorController& wsc);
    ~SimulatedWeightSensorController();
    int checkSensors();
};

#endif
