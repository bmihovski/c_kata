#include "TwoCrystalBalls.h"
#include <math.h>

int two_crystal_balls(const int *breaks, size_t length) {
  if (length == 0) {
    return -1;
  }
  int jump_ammount = (int)sqrt((double)length);
  for (int start = 0; start < length; start += jump_ammount) {
    if (breaks[start]) {
      for (int found_start = start - jump_ammount; found_start < start;
           ++found_start) {
        if (found_start >= 0 && breaks[found_start]) {
          return found_start;
        } else {
          for (int start_neg = 0; start_neg < jump_ammount; ++start_neg) {
            if (breaks[start_neg]) {
              return start_neg;
            }
          }
        }
      }
    }
  }

  return -1;
}
