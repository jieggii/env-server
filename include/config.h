//
// Created by jieggii on 2.2.2025.
//

#ifndef CONFIG_H
#define CONFIG_H

#include "cstdint"

namespace config {
    namespace httpServer {
        /*
         * Port to run HTTP server on.
         */
        constexpr uint16_t port = 80;
    }  // namespace httpServer

    namespace blynk {
        /*
         * Push measurements interval in milliseconds.
         * For example, if set to 5000, measurements will be pushed to Blynk once per 5 seconds.
         */
        constexpr uint32_t push_interval = 5 * 60 * 1000UL;
    }  // namespace blynk

    namespace env_sensor {
        /**
         * Temperature offset in C for the SCD40 sensor.
         */
        constexpr float temperatureOffset = 6.0f;
    }  // namespace env_sensor
}  // namespace config

#endif  // CONFIG_H
