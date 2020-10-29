#include "display_service.h"
#include "common_math.h"
#include "configuration.h"
#include "screen.h"
#include "data_lake.h"
#include "self_supply_sensor.h"
#include "humidity_sensor.h"

void show_battery_icon() {
    int self_supply_percentage = read_self_supply_percentage();
    draw_battery_icon(self_supply_percentage);
}

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

void show_watering_disabled() {
    draw_watering_disabled();
}

void show_last_watered() {
    int last_watered_hours = read_last_watered();
    draw_last_watered(last_watered_hours);
}

void show_watering() {
    draw_watering();
}

void clear_on_screen_changed() {
    clear_screen();
    finish_screen();
}

void update_screen() {
    finish_screen();
}