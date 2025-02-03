#include <Arduino.h>
#include <Wire.h>
#include <ESP8266WebServer.h>
#include "blynk_template.h"  // this include is required in order to provide template information to Blynk
#include <BlynkSimpleEsp8266.h>
#include "cstdint"

#include "env_sensor.h"
#include "config.h"
#include "secrets.h"
#include <http_server.h>

uint32_t LAST_PUSH_TS = 0;          // timestamp when the measurements were pushed to blynk last time
uint32_t LAST_MEASUREMENTS_TS = 0;  // timestamp when the measurements were read last time
env_sensor::EnvSensor ENV_SENSOR;
HTTPServer SERVER(config::httpServer::port, ENV_SENSOR, LAST_MEASUREMENTS_TS);

void setup() {
    delay(1000);

    Serial.begin(9600);
    Serial.println("starting...");

    // init SCD40:
    Wire.begin(D2, D1);  // init i2c
    if (!ENV_SENSOR.setup()) {
        Serial.println("failed to set up env sensor, please reboot");
        while (true) {
        }
    }

    // init Blynk (it will also manage Wi-Fi connection):
    Blynk.begin(secrets::blynk::authToken, secrets::wifi::ssid, secrets::wifi::password);
    Serial.print("successfully connected to Wi-Fi, IP address: ");
    Serial.println(WiFi.localIP());

    // set up and start the HTTP server:
    SERVER.setup();
    SERVER.begin();
    Serial.println("HTTP server is listening");
}

void loop() {
    // perform env sensor measurements
    if (ENV_SENSOR.measure()) {
        LAST_MEASUREMENTS_TS = millis();
        Serial.println("fresh measurements are available");
    }

    // push measurements to Blynk if it is time to do that:
    if (const uint32_t now = millis(); now - LAST_PUSH_TS >= config::blynk::push_interval || LAST_PUSH_TS == 0) {
        LAST_PUSH_TS = now;

        const auto [temperature, humidity, co2] = ENV_SENSOR.readMeasurements();
        Blynk.virtualWrite(V0, temperature);
        Blynk.virtualWrite(V1, humidity);
        Blynk.virtualWrite(V2, co2);

        Serial.println("measurements have been pushed to Blynk");
    }

    // handle Blynk:
    Blynk.run();

    // handle HTTP server:
    SERVER.loop();
}
