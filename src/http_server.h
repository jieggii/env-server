//
// Created by jieggii on 2.2.2025.
//

#ifndef HTTP_HANDLERS_H
#define HTTP_HANDLERS_H

#include <ESP8266WebServer.h>
#include "env_sensor.h"

class HTTPServer {
   public:
    HTTPServer(const uint16_t port, env_sensor::EnvSensor& envSensor, const uint32_t& lastMeasurementTs)
        : server(port), envSensor(envSensor), lastMeasurementTs(lastMeasurementTs) {};

    /**
     * Set up the server;
     */
    void setup();

    /**
     * Begin running server.
     */
    void begin();

    /**
     * HTTP handler function for "/" route.
     */
    void handleRoot();

    /**
     * HTTP handler function for "/measurements" route.
     */
    void handleMeasurements();

    /**
     * Handle HTTP server clients.
     */
    void loop();

   private:
    ESP8266WebServer server;
    env_sensor::EnvSensor& envSensor;
    const uint32_t& lastMeasurementTs;
};

#endif  // HTTP_HANDLERS_H
