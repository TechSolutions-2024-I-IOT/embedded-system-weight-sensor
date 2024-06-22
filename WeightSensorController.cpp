#include "WeightSensorController.h"
#include <Arduino.h>

WeightSensorController::WeightSensorController(int numSensors, const int* doutPins, const int* clkPins, float calibrationFactor)
  : numSensors(numSensors) {
    sensors = new WeightSensor*[numSensors];
    for (int i = 0; i < numSensors; ++i) {
      sensors[i] = new WeightSensor(doutPins[i], clkPins[i], calibrationFactor);
    }
}

WeightSensorController::~WeightSensorController() {
  for (int i = 0; i < numSensors; ++i) {
    delete sensors[i];
  }
  delete[] sensors;
}

void WeightSensorController::begin() {
  Serial.println("Starting weight sensors");

  for (int i = 0; i < numSensors; ++i) {
    Serial.print("Weight sensor ");
    Serial.print(i + 1);
    Serial.println("configuration");
    sensors[i]->begin();
  }
}

int WeightSensorController::checkSensors() {
  int occupiedCount = 0;

  for (int i = 0; i < numSensors; ++i) {
    float reading = sensors[i]->getWeight();
    Serial.print("Weight sensor ");
    Serial.print(i + 1);
    Serial.print(" : ");
    Serial.print(reading, 2); // Imprimir con 2 decimales

    if (reading > 15.0) {
      Serial.println(" kg - Taken");
      occupiedCount++;
    } else {
      Serial.println(" kg - Free");
    }
  }

  Serial.print("Number of seats occupied: ");
  Serial.println(occupiedCount);

  return occupiedCount;
}

int WeightSensorController::getNumSensors() const {
    return numSensors;
}

WeightSensor** WeightSensorController::getSensors() const {
    return sensors;
}
