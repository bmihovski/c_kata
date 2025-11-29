#include "TwoCrystalBalls.h"
#include <math.h>

int two_crystal_balls(const int *breaks, size_t length) {
    if (length == 0) {
        return -1;
    }

    // Calculate the optimal jump size
    int jump_size = (int)sqrt((double)length);

    // First ball: find the range
    int i;
    for (i = jump_size; i < (int)length; i += jump_size) {
        if (breaks[i]) {
            break;
        }
    }

    // If we've gone past the end, no break point found
    if (i >= (int)length && !breaks[length - 1]) {
        return -1;
    }

    // Second ball: linear search in the range
    int start = i - jump_size;
    for (int j = start; j < i && j < (int)length; ++j) {
        if (breaks[j]) {
            return j;
        }
    }

    return -1;
}
