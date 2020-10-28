#include <Arduino.h>
#include "humidity_sensor.h"
#include "pinout.h"

void enable_sensor() {
    digitalWrite(HUMIDITY_SENSOR_PIN, LOW);
}

void disable_sensor() {
    digitalWrite(HUMIDITY_SENSOR_PIN, HIGH);
}

void init_sensor() {
    pinMode(HUMIDITY_SENSOR_PIN, OUTPUT);
    digitalWrite(HUMIDITY_SENSOR_PIN, HIGH);
}

int read_humidity() {
    enable_sensor();
    delay(500);

    int result = analogRead(HUMIDITY_SENSOR_PIN);

    disable_sensor();
    return result;
}