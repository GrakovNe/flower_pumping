#include <Arduino.h>
#include "pinout.h"
#include "screen.h"
#include "data_lake.h"

void setup() {
    init_screen();
}

void loop() {

    digitalWrite(HUMIDITY_SENSOR_PIN, 1);
// write your code here
}