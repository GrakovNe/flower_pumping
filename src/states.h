#define MEASUREMENT_STATE 0
#define WATERING_STATE 1
#define SETTINGS_STATE 2
#define ERROR_STATE 3
#define SELF_CHECK_STATE 4
#define LOADING_STATE 5


#define NO_ERROR 0
#define EMPTY_WATER_TANK 10

extern char current_state;
extern char current_error;