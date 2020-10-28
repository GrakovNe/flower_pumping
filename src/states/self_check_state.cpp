#include <Arduino.h>
#include <data_lake.h>
#include <watering.h>
#include <self_supply_sensor.h>
#include <screen.h>
#include "self_check_state.h"

void update_self_check();

void on_self_check_state() {
    while (true) {
        update_self_check();
        delay(1000);
        clear_screen();
    }
}

void update_self_check() {
    char self_check_screen_buffer[128];

    sprintf(self_check_screen_buffer, "Self check:");
    draw_self_check(7, self_check_screen_buffer);

    sprintf(self_check_screen_buffer, "Humidity: %d", read_current_humidity());
    draw_self_check(22, self_check_screen_buffer);

    sprintf(self_check_screen_buffer, "Optimal: %d", read_optimal_humidity());
    draw_self_check(32, self_check_screen_buffer);

    sprintf(self_check_screen_buffer, "Water tank: %d", check_water_tank());
    draw_self_check(42, self_check_screen_buffer);

    sprintf(self_check_screen_buffer, "Watering: %d", read_watering_enabled());
    draw_self_check(52, self_check_screen_buffer);

    sprintf(self_check_screen_buffer, "Ref supply: %d", read_self_supply_percentage());
    draw_self_check(62, self_check_screen_buffer);
}
