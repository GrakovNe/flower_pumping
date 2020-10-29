#include "watering_state.h"
#include "watering.h"
#include "states.h"
#include "display_service.h"

void on_watering_state() {

//    if(!check_water_tank()) {
//        current_state = EMPTY_WATER_TANK;
//        current_state = ERROR_STATE;
//
//        return;
//    }

    show_current_humidity();
    show_battery_icon();
    show_watering();
    update_screen();

    water_for_second();

    current_state = MEASUREMENT_STATE;

    clear_on_screen_changed();
}