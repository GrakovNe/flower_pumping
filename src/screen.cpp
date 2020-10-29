#include <lib/U8g2/U8x8lib.h>
#include <lib/U8g2/U8g2lib.h>
#include <Wire.h>
#include "screen.h"
#include "data_lake.h"
#include "configuration.h"

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);

static bool is_screen_initialized = false;

char screen_buffer[32];

void fill_previous(int x, int y, int width, int height) {
    u8g2.setDrawColor(0);
    u8g2.drawBox(x, y, width, height);
    u8g2.setDrawColor(1);
}

void draw_watering() {
    u8g2.setFont(u8g2_font_7x13B_tf);
    u8g2.drawStr(26, 45, "WATERING...");
}

void draw_last_watered(int last_watered_hours) {
    fill_previous(15, 41, 30, 20);

    u8g2.setFont(u8g2_font_7x13B_tf);

    u8g2.drawStr(20, 41, LAST_WATERED_PREFIX_STRING);

    sprintf(screen_buffer, "%03d", last_watered_hours);
    u8g2.drawStr(18, 56, screen_buffer);

    u8g2.drawStr(45, 56, LAST_WATERED_POSTFIX_STRING);
}

void draw_current_humidity(char *humidity_state) {
    fill_previous(0, 0, 108, 20);

    u8g2.setFont(u8g2_font_7x13B_tf);
    sprintf(screen_buffer, "%s", humidity_state);
    u8g2.drawStr(2, 10, screen_buffer);
}

void draw_self_check(int line, char *buffer) {
    u8g2.setFont(u8g2_font_5x7_mf);
    u8g2.drawStr(0, line, buffer);
}

void draw_state(int state) {
    u8g2.setFont(u8g2_font_5x7_mf);
    sprintf(screen_buffer, "state: %d", state);
    u8g2.drawStr(10, 20, screen_buffer);
    u8g2.sendBuffer();
}

void draw_battery_icon(int supply_percentage) {
    fill_previous(108, 1, 20, 10);

    u8g2.drawFrame(108, 1, 18, 10);
    u8g2.drawBox(126, 3, 2, 5);

    if (supply_percentage > LOW_BATTERY_LEVEL) {
        u8g2.drawBox(110, 3, 4, 6);
        return;
    }

    if (supply_percentage > MEDIUM_BATTERY_LEVEL) {
        u8g2.drawBox(115, 3, 4, 6);
        return;
    }

    if (supply_percentage > HIGH_BATTERY_LEVEL) {
        u8g2.drawBox(120, 3, 4, 6);
        return;
    }

}

void draw_watering_disabled() {
    fill_previous(15, 41, 30, 20);

    u8g2.setFont(u8g2_font_7x13B_tf);

    u8g2.drawStr(32, 41, "WATERING");
    u8g2.drawStr(25, 56, "IS DISABLED");
}

void init_screen() {
    u8g2.setBusClock(400000);
    u8g2.begin();
    u8g2.clearDisplay();
    u8g2.setFont(u8g2_font_9x15B_tf);
    u8g2.drawStr(1, 11, "LOADING...");
    delay(500);
}

void clear_screen() {
    u8g2.setDrawColor(0);
    u8g2.drawBox(0, 0, 128, 64);
    u8g2.setDrawColor(1);
}

void finish_screen() {
    u8g2.sendBuffer();
}