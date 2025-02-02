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
    namespace env_sensor {
        /*
         * Measurement period in seconds.
         * For example, if set to 5000, measurements will be performed once per 5 seconds.
         */
        constexpr uint32_t measurement_period = 30 * 1000UL;
    }  // namespace env_sensor
}  // namespace config

#endif  // CONFIG_H
