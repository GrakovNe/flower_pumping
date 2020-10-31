#include <Arduino.h>
#include "pinout.h"
#include "screen.h"
#include "states.h"
#include "data_lake.h"
#include "watering.h"
#include "states/measurement_state.h"
#include "states/self_check_state.h"
#include "states/watering_state.h"
#include "self_supply_sensor.h"
#include "humidity_sensor.h"

void on_settings_state();

void on_error_state();

void setup() {
    init_sensor();
    init_screen();
    initialize_data_lake();

    current_state = MEASUREMENT_STATE;
}

void loop() {
    //draw_state(current_state);
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
            break;
        case SELF_CHECK_STATE:
            on_self_check_state();
            break;
    }
}

void on_error_state() {

}

void on_settings_state() {

}