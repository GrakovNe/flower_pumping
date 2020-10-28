#include <Arduino.h>
#include "pinout.h"
#include "screen.h"
#include "states.h"
#include "data_lake.h"
#include "watering.h"
#include "self_supply_sensor.h"

void on_measurement_state();

void on_watering_state();

void on_settings_state();

void on_error_state();

void on_self_check_state();

void setup() {
    initialize_data_lake();
}

void loop() {
    current_state = SELF_CHECK_STATE;

    switch (current_state) {
        case MEASUREMENT_STATE:
            on_measurement_state();
            break;
        case WATERING_STATE:
            on_watering_state();
            break;
        case SETTINGS_STATE:
            on_settings_state();
            break;
        case ERROR_STATE:
            on_error_state();
        case SELF_CHECK_STATE:
            on_self_check_state();
        default:
            current_state = MEASUREMENT_STATE;
            break;
    }
}

void on_error_state() {

}

void on_settings_state() {

}

void on_watering_state() {

}

void on_measurement_state() {

}
