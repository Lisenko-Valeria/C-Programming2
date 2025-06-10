#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "math.h"
#include "/home/valeria/c-prog2/lab8/src/main.h"  

static void test_Bubble_Shaker_Select_Insert(void **state) {
    (void)state;
    
    int n = 100;
    
    assert_true(Bubble(n) > 0);
    assert_true(Shaker(n) > 0);
    assert_true(Select(n) > 0);
    assert_true(Insert(n) > 0);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_Bubble_Shaker_Select_Insert)
    };
    
    return cmocka_run_group_tests(tests, NULL, NULL);
}