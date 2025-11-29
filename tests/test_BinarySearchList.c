// clang-format off
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
// clang-format on
#include <stdlib.h>

#include "../src/BinarySearchList.h"

static void test_bs_list_found_middle(void **state) {
  (void)state;
  int arr[] = {1, 3, 4, 69, 71, 81, 90, 99, 420, 1337, 69420};
  assert_true(bs_list(arr, 11, 69));
}

static void test_bs_list_not_found(void **state) {
  (void)state;
  int arr[] = {1, 3, 4, 69, 71, 81, 90, 99, 420, 1337, 69420};
  assert_false(bs_list(arr, 11, 1336));
}

static void test_bs_list_found_last(void **state) {
  (void)state;
  int arr[] = {1, 3, 4, 69, 71, 81, 90, 99, 420, 1337, 69420};
  assert_true(bs_list(arr, 11, 69420));
}

static void test_bs_list_not_found_after_last(void **state) {
  (void)state;
  int arr[] = {1, 3, 4, 69, 71, 81, 90, 99, 420, 1337, 69420};
  assert_false(bs_list(arr, 11, 69421));
}

static void test_bs_list_found_first(void **state) {
  (void)state;
  int arr[] = {1, 3, 4, 69, 71, 81, 90, 99, 420, 1337, 69420};
  assert_true(bs_list(arr, 11, 1));
}

static void test_bs_list_not_found_before_first(void **state) {
  (void)state;
  int arr[] = {1, 3, 4, 69, 71, 81, 90, 99, 420, 1337, 69420};
  assert_false(bs_list(arr, 11, 0));
}

int main(void) {
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_bs_list_found_middle),
      cmocka_unit_test(test_bs_list_not_found),
      cmocka_unit_test(test_bs_list_found_last),
      cmocka_unit_test(test_bs_list_not_found_after_last),
      cmocka_unit_test(test_bs_list_found_first),
      cmocka_unit_test(test_bs_list_not_found_before_first),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
