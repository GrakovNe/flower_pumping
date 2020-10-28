#include <Arduino.h>
#include "watering.h"
#include "data_lake.h"
#include "pinout.h"

void init_watering_pump() {
    pinMode(WATER_TANK_SENSOR_PIN, OUTPUT);
    digitalWrite(WATER_TANK_SENSOR_PIN, LOW);
}

void enable_water_pump() {
    digitalWrite(WATER_TANK_SENSOR_PIN, HIGH);
}

void disable_water_pump() {
    digitalWrite(WATER_TANK_SENSOR_PIN, LOW);
}

void water_for_second() {
    if (!check_water_tank()) {
        return;
    }

    init_watering_pump();
    cli();

    enable_water_pump();
    delay(1000);
    disable_water_pump();

    sei();
}

bool check_water_tank() {
    is_water_tank_filled = true;
    return is_water_tank_filled;
}