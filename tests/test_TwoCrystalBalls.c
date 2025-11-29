// clang-format off
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
// clang-format on
#include <stdlib.h>
#include <time.h>

#include "../src/TwoCrystalBalls.h"

static void test_two_crystal_balls_break_at_random(void **state) {
    (void)state;
    srand(time(NULL));
    int idx = rand() % 10000;
    int *data = (int *)malloc(10000 * sizeof(int));

    for (int i = 0; i < 10000; ++i) {
        data[i] = (i >= idx) ? 1 : 0;
    }

    assert_int_equal(two_crystal_balls((const int *)data, 10000), idx);
    free(data);
}

static void test_two_crystal_balls_no_break(void **state) {
    (void)state;
    int data[821];
    for (int i = 0; i < 821; ++i) {
        data[i] = 0;
    }
    assert_int_equal(two_crystal_balls((const int *)data, 821), -1);
}

static void test_two_crystal_balls_break_at_start(void **state) {
    (void)state;
    int data[100];
    data[0] = 1;
    for (int i = 1; i < 100; ++i) {
        data[i] = 1;
    }
    assert_int_equal(two_crystal_balls((const int *)data, 100), 0);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_two_crystal_balls_break_at_random),
        cmocka_unit_test(test_two_crystal_balls_no_break),
        cmocka_unit_test(test_two_crystal_balls_break_at_start),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
