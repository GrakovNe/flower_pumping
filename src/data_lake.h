#define OPTIMAL_HUMIDITY_ADDRESS 10
#define BUZZER_ENABLED_ADDRESS 15
#define LAST_WATERING_HOURS_ADDRESS 20

static bool is_water_tank_filled = true;
static int current_humidity = 999;

int read_current_humidity();

void write_current_humidity(int humidity);

int read_optimal_humidity();

void write_optimal_humidity(int humidity);

bool read_buzzer_enabled();

void write_buzzer_enabled(bool state);

int read_last_watering();

void write_last_watering(int hours);