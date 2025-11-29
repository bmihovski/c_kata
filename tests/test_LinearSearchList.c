// clang-format off
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
// clang-format on
#include <stdlib.h>

#include "../src/LinearSearchList.h"

static void test_linear_search_found(void **state) {
  (void)state;
  int arr[] = {1, 3, 4, 69, 71, 81, 90, 99, 420, 1337, 69420};
  assert_true(linear_search(arr, 11, 69));
}

static void test_linear_search_not_found(void **state) {
  (void)state;
  int arr[] = {1, 3, 4, 69, 71, 81, 90, 99, 420, 1337, 69420};
  assert_false(linear_search(arr, 11, 1336));
}

static void test_linear_search_empty_array(void **state) {
  (void)state;
  int arr[] = {};
  assert_false(linear_search(arr, 0, 5));
}

int main(void) {
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_linear_search_found),
      cmocka_unit_test(test_linear_search_not_found),
      cmocka_unit_test(test_linear_search_empty_array),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
