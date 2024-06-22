#include "SimulatedWeightSensor.h"
#include <Arduino.h>

SimulatedWeightSensor::SimulatedWeightSensor(WeightSensor& ws)
  : weightSensor(ws), currentWeight(0.0), iterationCount(0) {
    if (random(0, 100) < 50) { // 50% empty seat
        currentWeight = 0;
    } else {
        currentWeight = random(50, 100);
    }
}

float SimulatedWeightSensor::getWeight() {
    iterationCount++;

    if (iterationCount <= 5) {
        return currentWeight;
    }

    // Reset current weight after 15 iterations
    if (iterationCount > 15) {
        iterationCount = 1; // Reset count
        if (random(0, 100) < 50) { // 50% empty seat
            currentWeight = 0;
        } else {
            currentWeight = random(50, 100);
        }
    }

    currentWeight = simulateWeight(currentWeight);
    return currentWeight;
}

float SimulatedWeightSensor::simulateWeight(float currentWeight) {
    float variation = random(-10, 10) / 10.0;
    float newWeight = currentWeight + variation;

    if (newWeight < 0) {
        newWeight = 0;
    }

    return newWeight;
}
