#ifndef SIMULATED_WEIGHT_SENSOR_H
#define SIMULATED_WEIGHT_SENSOR_H

#include "WeightSensor.h"

class SimulatedWeightSensor {
  private:
    WeightSensor& weightSensor;
    float currentWeight;
    int iterationCount;

  public:
    SimulatedWeightSensor(WeightSensor& ws);
    float getWeight();
    float simulateWeight(float currentWeight);
};

#endif
