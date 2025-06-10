#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "math.h"
#include "/home/valeria/c-prog2/lab8/src/main.h"  

static void test_SelectSort(void **state) {
    (void)state;
    
    int A[] = {5,2,4,6,1,3,8,6,2,7};
    int n = sizeof(A)/sizeof(A[0]);
    int comparisons, swaps;
    
    SelectSort(A, n, &comparisons, &swaps);
    
    for (int i = 0; i < n-1; i++) {
        assert_true(A[i] <= A[i+1]);
    }
    
    assert_int_equal(comparisons, (pow(n, 2)-n)/2);
    assert_int_equal(swaps, 3*(n-1));
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_SelectSort)
    };
    
    return cmocka_run_group_tests(tests, NULL, NULL);
}