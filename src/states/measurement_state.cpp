#include "display_service.h"
#include <humidity_sensor.h>
#include <configuration.h>
#include "measurement_state.h"
#include "data_lake.h"
#include "states.h"
#include "common_math.h"

void on_measurement_state() {
    int current_humidity = read_humidity();
    int optimal_humidity = read_optimal_humidity();
    int is_watering_enabled = read_watering_enabled();

    show_battery_icon();
    show_current_humidity();

    if (is_watering_enabled) {
        show_last_watered();
    } else {
        show_watering_disabled();
    }

    int diff = calculate_diff(current_humidity, optimal_humidity);

    if (diff > HUMIDITY_THRESHOLD
        && current_humidity < optimal_humidity
        && !is_watering_enabled) { // revert!

        clear_on_screen_changed();
        current_state = WATERING_STATE;
        return;
    }

    update_screen();
}