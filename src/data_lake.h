#define OPTIMAL_HUMIDITY_ADDRESS 10
#define BUZZER_ENABLED_ADDRESS 15
#define LAST_WATERED_HOURS_ADDRESS 20
#define IS_WATERING_ENABLED_ADDRESS 25
#define IS_DEVICE_INITIALIZED_ADDRESS 30

static bool is_water_tank_filled = true;

int read_optimal_humidity();

void write_optimal_humidity(int humidity);

bool read_buzzer_enabled();

void write_buzzer_enabled(bool state);

int read_last_watered();

void write_last_watered(int hours);

void write_watering_enabled(bool state);

int read_watering_enabled();

void initialize_data_lake();