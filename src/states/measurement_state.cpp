#include <screen.h>
#include <self_supply_sensor.h>
#include <humidity_sensor.h>
#include <configuration.h>
#include "measurement_state.h"
#include "data_lake.h"
#include "common_math.h"

void show_current_humidity() {
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

void show_last_watered() {
    int last_watered_hours = read_last_watered();
    draw_last_watered(last_watered_hours);
}

void on_measurement_state() {
    draw_battery_icon(read_self_supply_percentage());
    show_current_humidity();
    show_last_watered();
}