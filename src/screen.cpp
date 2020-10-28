#include <lib/U8g2/U8x8lib.h>
#include <lib/U8g2/U8g2lib.h>
#include "screen.h"
#include "data_lake.h"
#include "configuration.h"

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);

static bool is_screen_initialized = false;

char screen_buffer[64];

void fill_previous(int x, int y, int width, int height) {
    u8g2.setDrawColor(0);
    u8g2.drawBox(x, y, width, height);
    u8g2.setDrawColor(1);
}

void init_screen() {
    if (is_screen_initialized) {
        return;
    }

    u8g2.begin();
    u8g2.clearDisplay();
    u8g2.setFont(u8g2_font_9x15B_tf);
    u8g2.drawStr(1, 11, "LOADING...");
    delay(500);
    clear_screen();

    is_screen_initialized = true;
}

void draw_last_watered(int last_watered_hours) {
    init_screen();
    fill_previous(15, 41, 30, 20);

    u8g2.setFont(u8g2_font_7x13B_tf);

    sprintf(screen_buffer, LAST_WATERED_PREFIX_STRING);
    u8g2.drawStr(20, 41, screen_buffer);

    sprintf(screen_buffer, "%03d", last_watered_hours);
    u8g2.drawStr(18, 56, screen_buffer);

    sprintf(screen_buffer, LAST_WATERED_POSTFIX_STRING);
    u8g2.drawStr(45, 56, screen_buffer);

    u8g2.sendBuffer();
}

void draw_current_humidity(char *humidity_state) {
    init_screen();
    fill_previous(0, 0, 108, 20);

    u8g2.setFont(u8g2_font_7x13B_tf);
    sprintf(screen_buffer, "%s", humidity_state);
    u8g2.drawStr(2, 10, screen_buffer);
    u8g2.sendBuffer();
}

void draw_self_check(int line, char *buffer) {
    init_screen();

    u8g2.setFont(u8g2_font_5x7_mf);
    u8g2.drawStr(0, line, buffer);
    u8g2.sendBuffer();
}

void draw_state(int state) {
    init_screen();

    u8g2.setFont(u8g2_font_5x7_mf);
    sprintf(screen_buffer, "state: %d", state);
    u8g2.drawStr(10, 20, screen_buffer);
    u8g2.sendBuffer();

    delay(1000);
}

void draw_battery_icon(int supply_percentage) {
    init_screen();
    fill_previous(108, 1, 20, 10);

    u8g2.drawFrame(108, 1, 18, 10);
    u8g2.drawBox(126, 3, 2, 5);

    if (supply_percentage > LOW_BATTERY_LEVEL) {
        u8g2.drawBox(110, 3, 4, 6);
    }

    if (supply_percentage > MEDIUM_BATTERY_LEVEL) {
        u8g2.drawBox(115, 3, 4, 6);
    }

    if (supply_percentage > HIGH_BATTERY_LEVEL) {
        u8g2.drawBox(120, 3, 4, 6);
    }

    u8g2.sendBuffer();
}

void draw_watering_disabled() {
    init_screen();
    fill_previous(15, 41, 30, 20);

    u8g2.setFont(u8g2_font_7x13B_tf);
    sprintf(screen_buffer, "WATERING");
    u8g2.drawStr(32, 41, screen_buffer);

    sprintf(screen_buffer, "IS DISABLED");
    u8g2.drawStr(25, 56, screen_buffer);

    u8g2.sendBuffer();
}

void clear_screen() {
    u8g2.clearDisplay();
}