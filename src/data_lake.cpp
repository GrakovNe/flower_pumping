#include <EEPROM.h>
#include "data_lake.h"


int read_current_humidity() {
    return current_humidity;
}

void write_current_humidity(int humidity) {
    current_humidity = humidity;
}

int read_optimal_humidity() {
    return EEPROM.read(OPTIMAL_HUMIDITY_ADDRESS);
}

void write_optimal_humidity(int humidity) {
    EEPROM.update(OPTIMAL_HUMIDITY_ADDRESS, humidity);
}

bool read_buzzer_enabled() {
    return EEPROM.read(BUZZER_ENABLED_ADDRESS);
}

void write_buzzer_enabled(bool state) {
    EEPROM.update(OPTIMAL_HUMIDITY_ADDRESS, state);
}

int read_last_watering() {
    return EEPROM.read(LAST_WATERING_HOURS_ADDRESS);
}

void write_last_watering(int hours) {
    EEPROM.update(OPTIMAL_HUMIDITY_ADDRESS, hours);
}