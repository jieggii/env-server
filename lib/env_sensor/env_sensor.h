//
// Created by jieggii on 2.2.2025.
//

#ifndef ENVSENSOR_H
#define ENVSENSOR_H

#include "SparkFun_SCD4x_Arduino_Library.h"
#include "cstdint"

namespace env_sensor {
    using temperatureType = float;
    using humidityType = float;
    using co2Type = uint16_t;

    /**
     * Structure representing env sensor measurements.
     */
    struct Measurements {
        temperatureType temperature;
        humidityType humidity;
        co2Type co2;
    };

    class EnvSensor {
       public:
        /**
         * Set up the sensor.
         * @param temperatureOffset temperature offset in C.
         * @return true if set up successful.
         */
        bool setup(float temperatureOffset);

        /**
         * Perform measurements.
         * @return true if measurements has been updated.
         */
        bool measure();

        /**
         * Read stored measurements.
         * @return measurements read from the sensor.
         */
        Measurements readMeasurements();

       private:
        SCD4x sensor;
    };
}  // namespace env_sensor

#endif  // ENVSENSOR_H
