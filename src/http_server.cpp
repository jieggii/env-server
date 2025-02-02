//
// Created by jieggii on 2.2.2025.
//

#include "http_server.h"

#include <ArduinoJson.h>

void HTTPServer::setup() {
    this->server.on("/", [this] { this->handleRoot(); });
    this->server.on("/measurements", [this] { this->handleMeasurements(); });
}

void HTTPServer::begin() { this->server.begin(); }

void HTTPServer::handleRoot() { this->server.send(200, "text/plain", "env-server is running."); }

void HTTPServer::handleMeasurements() {
    JsonDocument jsonDoc;

    const auto [temperature, humidity, co2] = this->envSensor.readMeasurements();

    jsonDoc["temperature"] = temperature;
    jsonDoc["humidity"] = humidity;
    jsonDoc["co2"] = co2;
    jsonDoc["timedelta"] = millis() - this->lastMeasurementTs;

    String jsonResponse;
    serializeJson(jsonDoc, jsonResponse);

    this->server.send(200, "application/json", jsonResponse);
}

void HTTPServer::loop() { this->server.handleClient(); }
