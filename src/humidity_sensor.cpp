#include <Arduino.h>
#include "humidity_sensor.h"
#include "pinout.h"
#include "configuration.h"

void enable_sensor() {
    digitalWrite(HUMIDITY_POWER_PIN, HIGH);
}

void disable_sensor() {
    digitalWrite(HUMIDITY_POWER_PIN, LOW);
}

void init_sensor() {
    pinMode(HUMIDITY_POWER_PIN, OUTPUT);
    digitalWrite(HUMIDITY_POWER_PIN, LOW);
}

int read_humidity() {
    cli();

    enable_sensor();

    delay(50);

    int result = analogRead(HUMIDITY_SENSOR_PIN);

    disable_sensor();

    sei();

    if (HUMIDITY_SENSOR_INVERSED) {
        result = 1023 - result;
    }

    return result;
}