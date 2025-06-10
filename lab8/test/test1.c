#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "math.h"
#include "/home/valeria/c-prog2/lab8/src/main.h"  

static void test_FillRand(void **state) {
    (void)state;
    
    int n = 10;
    int A[n];
    
    FillRand(A, n);
    
    for (int i = 0; i < n; i++) {
        assert_true(A[i] >= 0);
        assert_true(A[i] < 1000);
    }
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_FillRand)
    };
    
    return cmocka_run_group_tests(tests, NULL, NULL);
}