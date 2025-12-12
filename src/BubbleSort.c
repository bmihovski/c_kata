#include "BubbleSort.h"
#include <stdbool.h>

void bubble_sort(int *arr, size_t length) {
  if (1 >= length || !arr) {
    return;
  }
  bool swapped;
  int end = length - 1;
  do {
    swapped = false;
    for (size_t start = 0; start < end; ++start) {
      if (arr[start] > arr[start + 1]) {
        int current = arr[start];
        arr[start] = arr[start + 1];
        arr[start + 1] = current;
        swapped = true;
      }
    }
    --end;
  } while (swapped);
}
