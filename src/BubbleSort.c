#include "BubbleSort.h"

void bubble_sort(int *arr, size_t length) {
    if (arr == NULL || length <= 1) {
        return;
    }

    for (size_t i = 0; i < length - 1; ++i) {
        for (size_t j = 0; j < length - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
