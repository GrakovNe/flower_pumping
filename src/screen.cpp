#include <lib/U8g2/U8x8lib.h>
#include "screen.h"
#include "data_lake.h"

U8X8_SH1106_128X64_NONAME_HW_I2C u8x8(U8X8_PIN_NONE);

char screen_buffer[64];

void init_screen() {
    u8x8.begin();
    u8x8.setFont(u8x8_font_8x13B_1x2_r);

    u8x8.drawString(1, 11, "LOADING...");
    delay(500);
    u8x8.clearDisplay();
}

void draw_humidity() {
    sprintf(screen_buffer, "HUMIDITY: %04d", read_current_humidity());
    u8x8.drawString(1, 11, screen_buffer);
    delay(1000);
}
