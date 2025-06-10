#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "math.h"
#include "/home/valeria/c-prog2/lab8/src/main.h"  

static void test_InsertSort(void **state) {
    (void)state;
    
    int A[] = {5,2,4,6,1,3,8,6,2,7};
    int n = sizeof(A)/sizeof(A[0]);
    int comparisons, swaps;
    
    InsertSort(A, n, &swaps, &comparisons);
    
    for (int i = 0; i < n-1; i++) {
        assert_true(A[i] <= A[i+1]);
    }
    
    assert_true(comparisons >= n-1);
    assert_true(comparisons <= (pow(n,2)-n)/2);
    assert_true(swaps >= 2*(n-1));
    assert_true(swaps <= (pow(n,2)-n)/2+2*n-2);
}


int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_InsertSort)
    };
    
    return cmocka_run_group_tests(tests, NULL, NULL);
}