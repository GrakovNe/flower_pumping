#include <lib/U8g2/U8x8lib.h>
#include <lib/U8g2/U8g2lib.h>
#include "screen.h"
#include "data_lake.h"

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);

static bool is_screen_initialized = false;

char screen_buffer[64];

void init_screen() {
    u8g2.begin();
    u8g2.clearDisplay();
    u8g2.setFont(u8g2_font_9x15B_tf);
    u8g2.drawStr(1, 11, "LOADING...");
    delay(500);
    clear_screen();

    is_screen_initialized = true;
}

void draw_humidity() {
    if (!is_screen_initialized) {
        init_screen();
    }

    sprintf(screen_buffer, "HUMIDITY: %04d", read_current_humidity());
    u8g2.drawStr(1, 11, screen_buffer);
    u8g2.sendBuffer();
    delay(1000);
}


void draw_self_check(int line, char *buffer) {
    if (!is_screen_initialized) {
        init_screen();
    }

    u8g2.setFont(u8g2_font_5x7_mf);
    u8g2.drawStr(0, line, buffer);
    u8g2.sendBuffer();
}

void draw_battery_icon(int supply_percentage) {
}

void clear_screen() {
    u8g2.clearDisplay();
}