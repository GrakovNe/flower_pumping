#include <lib/U8g2/U8x8lib.h>
#include <lib/U8g2/U8g2lib.h>
#include "screen.h"
#include "data_lake.h"
#include "configuration.h"

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);

static bool is_screen_initialized = false;

char screen_buffer[64];

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

void draw_current_humidity(char *humidity_state) {
    init_screen();
    u8g2.setFont(u8g2_font_7x13B_tf);

    sprintf(screen_buffer, "%s", humidity_state);
    u8g2.drawStr(2, 10, screen_buffer);
    u8g2.sendBuffer();
    delay(1000);
}

void draw_self_check(int line, char *buffer) {
    init_screen();

    u8g2.setFont(u8g2_font_5x7_mf);
    u8g2.drawStr(0, line, buffer);
    u8g2.sendBuffer();
}

void draw_battery_icon(int supply_percentage) {
    init_screen();

    u8g2.setDrawColor(0);
    u8g2.drawBox(108, 1, 20, 10);
    u8g2.setDrawColor(1);
    init_screen();

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

void clear_screen() {
    u8g2.clearDisplay();
}