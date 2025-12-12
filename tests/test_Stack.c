// clang-format off
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
// clang-format on
#include <stdlib.h>

#include "../src/Stack.h"

static void test_stack_basic_operations(void **state) {
  (void)state;
  Stack *list = createStack();
  assert_non_null(list);

  push(list, 5);
  push(list, 7);
  push(list, 9);

  assert_int_equal(pop(list), 9);
  assert_int_equal(length(list), 2);

  push(list, 11);
  assert_int_equal(pop(list), 11);
  assert_int_equal(pop(list), 7);
  assert_int_equal(peek(list), 5);
  assert_int_equal(pop(list), 5);
  assert_int_equal(pop(list), -1); // undefined in TypeScript
  assert_int_equal(length(list), 0);

  // Test adding after emptying
  push(list, 69);
  assert_int_equal(peek(list), 69);
  assert_int_equal(length(list), 1);

  destroyStack(list);
}

static void test_stack_empty(void **state) {
  (void)state;
  Stack *s = createStack();
  assert_non_null(s);

  assert_int_equal(length(s), 0);
  assert_int_equal(peek(s), -1);
  assert_int_equal(pop(s), -1);

  destroyStack(s);
}

static void test_stack_single_element(void **state) {
  (void)state;
  Stack *s = createStack();
  assert_non_null(s);

  push(s, 42);
  assert_int_equal(length(s), 1);
  assert_int_equal(peek(s), 42);
  assert_int_equal(pop(s), 42);
  assert_int_equal(length(s), 0);

  destroyStack(s);
}

static void test_stack_multiple_enqueue_dequeue(void **state) {
  (void)state;
  Stack *s = createStack();
  assert_non_null(s);

  // Enqueue multiple
  for (int i = 0; i < 10; i++) {
    push(s, i);
  }
  assert_int_equal(length(s), 10);

  // Dequeue all
  for (int i = length(s) - 1; i >= 0; --i) {
    assert_int_equal(pop(s), i);
  }
  assert_int_equal(length(s), 0);

  // Enqueue again
  push(s, 100);
  assert_int_equal(peek(s), 100);

  destroyStack(s);
}

int main(void) {
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_stack_basic_operations),
      cmocka_unit_test(test_stack_empty),
      cmocka_unit_test(test_stack_single_element),
      cmocka_unit_test(test_stack_multiple_enqueue_dequeue),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
