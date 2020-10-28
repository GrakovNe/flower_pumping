#include <Arduino.h>
#include <screen.h>
#include <self_supply_sensor.h>
#include <humidity_sensor.h>
#include <configuration.h>
#include "measurement_state.h"
#include "data_lake.h"

void draw_humidity() {
    int current_humidity = read_humidity();
    int optimal_humidity = read_optimal_humidity();

    int diff = calculate_diff(current_humidity, optimal_humidity);

    if (diff < HUMIDITY_THRESHOLD) {
        draw_current_humidity(HUMIDITY_TOLERANT_STRING);
        return;
    }

    if (current_humidity < optimal_humidity) {
        draw_current_humidity(HUMIDITY_BELOW_STRING);
        return;
    }

    if (current_humidity > optimal_humidity) {
        draw_current_humidity(HUMIDITY_ABOVE_STRING);
        return;
    }
}

void on_measurement_state() {
    draw_battery_icon(read_self_supply_percentage());
    draw_humidity();
}