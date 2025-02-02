//
// Created by jieggii on 2.2.2025.
//

#include "env_sensor.h"

namespace env_sensor {
    bool EnvSensor::setup() {
        if (const bool ok = this->sensor.begin(); !ok) {
            return false;
        }
        if (const bool ok = this->sensor.startPeriodicMeasurement(); !ok) {
            return false;
        }
        return true;
    }

    bool EnvSensor::measure() { return this->sensor.readMeasurement(); }

    Measurements EnvSensor::readMeasurements() {
        return Measurements{
            .temperature = this->sensor.getTemperature(),
            .humidity = this->sensor.getHumidity(),
            .co2 = this->sensor.getCO2(),
        };
    }
}  // namespace env_sensor