#include <Arduino.h>
#include "self_supply_sensor.h"
#include "pinout.h"

int read_self_supply_percentage() {
    int raw_value = analogRead(SELF_SUPPLY_SENSOR_PIN);
    return raw_value * 100 / FULL_SUPPLIED;
}