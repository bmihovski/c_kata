#include "LinearSearchList.h"

bool linear_search(const int *haystack, size_t length, int needle) {
  for (size_t i = 0; i < length; ++i) {
    if (haystack[i] == needle) {
      return true;
    }
  }
  return false;
}
