#include "common_math.h"

int calculate_diff(int first_number, int second_number) {
    int result = second_number - first_number;

    if (result < 0) {
        result *= -1;
    }

    return result;
}