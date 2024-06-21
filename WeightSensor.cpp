#include "WeightSensor.h"
#include <Arduino.h>

WeightSensor::WeightSensor(int dout, int clk, float calibrationFactor)
  : doutPin(dout), clkPin(clk), calibrationFactor(calibrationFactor) {}

void WeightSensor::begin() {
  // Serial.println("Initializing HX711...");
  hx711.begin(doutPin, clkPin);

  if (!hx711.is_ready()) {
    Serial.println("HX711 not found.");
    while (1); // Stay here if the sensor is not found
  }
  // Serial.println("HX711 is ready.");

  hx711.set_scale(calibrationFactor);
  Serial.println("Taring the scale...");
  hx711.tare(10);  // Perform 10 readings, the average is the tare
  Serial.println("Tare complete.");
}

float WeightSensor::getWeight() {
  if (hx711.is_ready()) {
    return hx711.get_units(10);
  } else {
    Serial.println("HX711 not found.");
    return 0.0;
  }
}
