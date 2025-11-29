// clang-format off
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
// clang-format on
#include <stdlib.h>
#include <string.h>

#include "../src/BubbleSort.h"

static void test_bubble_sort_basic(void **state) {
  (void)state;
  int arr[] = {9, 3, 7, 4, 69, 420, 42};
  int expected[] = {3, 4, 7, 9, 42, 69, 420};

  bubble_sort(arr, 7);

  for (int i = 0; i < 7; ++i) {
    assert_int_equal(arr[i], expected[i]);
  }
}

static void test_bubble_sort_single_element(void **state) {
  (void)state;
  int arr[] = {5};
  bubble_sort(arr, 1);
  assert_int_equal(arr[0], 5);
}

static void test_bubble_sort_two_elements(void **state) {
  (void)state;
  int arr[] = {2, 1};
  bubble_sort(arr, 2);
  assert_int_equal(arr[0], 1);
  assert_int_equal(arr[1], 2);
}

static void test_bubble_sort_already_sorted(void **state) {
  (void)state;
  int arr[] = {1, 2, 3, 4, 5};
  int expected[] = {1, 2, 3, 4, 5};

  bubble_sort(arr, 5);

  for (int i = 0; i < 5; ++i) {
    assert_int_equal(arr[i], expected[i]);
  }
}

static void test_bubble_sort_reverse_order(void **state) {
  (void)state;
  int arr[] = {5, 4, 3, 2, 1};
  int expected[] = {1, 2, 3, 4, 5};

  bubble_sort(arr, 5);

  for (int i = 0; i < 5; ++i) {
    assert_int_equal(arr[i], expected[i]);
  }
}

int main(void) {
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_bubble_sort_basic),
      cmocka_unit_test(test_bubble_sort_single_element),
      cmocka_unit_test(test_bubble_sort_two_elements),
      cmocka_unit_test(test_bubble_sort_already_sorted),
      cmocka_unit_test(test_bubble_sort_reverse_order),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
