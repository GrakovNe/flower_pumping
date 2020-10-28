#include <EEPROM.h>
#include "data_lake.h"

int read_optimal_humidity() {
    int result = 0;
    EEPROM.get(OPTIMAL_HUMIDITY_ADDRESS, result);

    return result;
}

void write_optimal_humidity(int humidity) {
    EEPROM.put(OPTIMAL_HUMIDITY_ADDRESS, humidity);
}

bool read_buzzer_enabled() {
    return EEPROM.read(BUZZER_ENABLED_ADDRESS);
}

void write_buzzer_enabled(bool state) {
    EEPROM.update(OPTIMAL_HUMIDITY_ADDRESS, state);
}

int read_last_watered() {
    int result = 0;
    EEPROM.get(LAST_WATERED_HOURS_ADDRESS, result);
    return result;
}

void write_last_watered(int hours) {
    EEPROM.put(LAST_WATERED_HOURS_ADDRESS, hours);
}

void write_watering_enabled(bool state) {
    EEPROM.update(IS_WATERING_ENABLED_ADDRESS, state);
}

int read_watering_enabled() {
    return EEPROM.read(IS_WATERING_ENABLED_ADDRESS);
}

void initialize_data_lake() {
    static bool is_water_tank_filled = true;
    static int current_humidity = 999;

//    if (EEPROM.read(IS_DEVICE_INITIALIZED_ADDRESS)) {
//        return;
//    }

    write_last_watered(0);
    write_buzzer_enabled(true);
    write_optimal_humidity(500);
    write_watering_enabled(false);
}