#ifndef WEIGHT_SENSOR_H
#define WEIGHT_SENSOR_H

#include "HX711.h"

class WeightSensor {
  private:
    HX711 hx711;
    const float calibrationFactor;
    const int doutPin;
    const int clkPin;
  public:
    WeightSensor(int dout, int clk, float calibrationFactor);
    void begin();
    float getWeight();
};

#endif
