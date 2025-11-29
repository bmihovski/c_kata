#include "BinarySearchList.h"

bool bs_list(const int *haystack, size_t length, int needle) {
    int left = 0;
    int right = (int)length - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (haystack[mid] == needle) {
            return true;
        } else if (haystack[mid] < needle) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return false;
}
