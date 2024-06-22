#include "SimulatedWeightSensorController.h"
#include <Arduino.h>

SimulatedWeightSensorController::SimulatedWeightSensorController(WeightSensorController& wsc)
  : numSensors(wsc.getNumSensors()) {
    simulatedSensors = new SimulatedWeightSensor*[numSensors];
    WeightSensor** sensors = wsc.getSensors();
    for (int i = 0; i < numSensors; ++i) {
      simulatedSensors[i] = new SimulatedWeightSensor(*sensors[i]);
    }
}

SimulatedWeightSensorController::~SimulatedWeightSensorController() {
  for (int i = 0; i < numSensors; ++i) {
    delete simulatedSensors[i];
  }
  delete[] simulatedSensors;
}

int SimulatedWeightSensorController::checkSensors() {
  int occupiedCount = 0;

  for (int i = 0; i < numSensors; ++i) {
    float reading = simulatedSensors[i]->getWeight();
    Serial.print("Simulated weight sensor ");
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
