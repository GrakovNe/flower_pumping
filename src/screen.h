void init_screen();

void draw_self_check(int line, char *buffer);

void clear_screen();

void draw_battery_icon(int supply_percentage);

void draw_current_humidity(char *humidity_state);

void draw_last_watered(int last_watered_hours);

void draw_watering_disabled();