# env-server
A compact environmental measurement server for the ESP8266 that streams real-time data to your Blynk dashboard and exposes a simple HTTP `/measurements` endpoint for easy access.

![blynk preview](https://imgur.com/CDxWU6B.jpg)

![http preview](https://imgur.com/9f28vwZ.jpg)

## Requirements
- PlatformIO Core

## Wiring
| SCD40 pin | esp8266 pin |
|-----------|-------------|
| `SCL`     | `D1`        | 
| `SDA`     | `D2`        |
| `VCC`     | `5V`        |
| `GND`     | `GND`       |

## Setup
Before building the project, please make sure to create `include/secrets.h` file using `include/secrets.h.template` as a template. Fill in your WiFi and Blynk credentials.

After that you are ready to build and flash the project using the PlatformIO CLI:

`pio run -t upload`
