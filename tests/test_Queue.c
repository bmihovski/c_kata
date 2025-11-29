// clang-format off
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
// clang-format on
#include <stdlib.h>

#include "../src/Queue.h"

static void test_queue_basic_operations(void **state) {
    (void)state;
    Queue *list = queue_create();
    assert_non_null(list);

    queue_enqueue(list, 5);
    queue_enqueue(list, 7);
    queue_enqueue(list, 9);

    assert_int_equal(queue_dequeue(list), 5);
    assert_int_equal(queue_length(list), 2);

    queue_enqueue(list, 11);
    assert_int_equal(queue_dequeue(list), 7);
    assert_int_equal(queue_dequeue(list), 9);
    assert_int_equal(queue_peek(list), 11);
    assert_int_equal(queue_dequeue(list), 11);
    assert_int_equal(queue_dequeue(list), -1); // undefined in TypeScript
    assert_int_equal(queue_length(list), 0);

    // Test adding after emptying
    queue_enqueue(list, 69);
    assert_int_equal(queue_peek(list), 69);
    assert_int_equal(queue_length(list), 1);

    queue_destroy(list);
}

static void test_queue_empty(void **state) {
    (void)state;
    Queue *q = queue_create();
    assert_non_null(q);

    assert_int_equal(queue_length(q), 0);
    assert_int_equal(queue_peek(q), -1);
    assert_int_equal(queue_dequeue(q), -1);

    queue_destroy(q);
}

static void test_queue_single_element(void **state) {
    (void)state;
    Queue *q = queue_create();
    assert_non_null(q);

    queue_enqueue(q, 42);
    assert_int_equal(queue_length(q), 1);
    assert_int_equal(queue_peek(q), 42);
    assert_int_equal(queue_dequeue(q), 42);
    assert_int_equal(queue_length(q), 0);

    queue_destroy(q);
}

static void test_queue_multiple_enqueue_dequeue(void **state) {
    (void)state;
    Queue *q = queue_create();
    assert_non_null(q);

    // Enqueue multiple
    for (int i = 0; i < 10; i++) {
        queue_enqueue(q, i);
    }
    assert_int_equal(queue_length(q), 10);

    // Dequeue all
    for (int i = 0; i < 10; i++) {
        assert_int_equal(queue_dequeue(q), i);
    }
    assert_int_equal(queue_length(q), 0);

    // Enqueue again
    queue_enqueue(q, 100);
    assert_int_equal(queue_peek(q), 100);

    queue_destroy(q);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_queue_basic_operations),
        cmocka_unit_test(test_queue_empty),
        cmocka_unit_test(test_queue_single_element),
        cmocka_unit_test(test_queue_multiple_enqueue_dequeue),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
