#include "BinarySearchList.h"
#include <math.h>

bool bs_list(const int *haystack, size_t length, int needle) {
  size_t low = 0;
  size_t high = length;
  while (low < high) {
    size_t mid = floor(low + (high - low) / 2);
    if (haystack[mid] == needle) {
      return true;
    } else if (haystack[mid] < needle) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }

  return false;
}
