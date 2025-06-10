#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "math.h"
#include "/home/valeria/c-prog2/lab8/src/main.h"  // Подключаем основной файл с реализацией функций

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

static void test_ShakerSort(void **state) {
    (void)state;
    
    int A[] = {5,2,4,6,1,3,8,6,2,7};
    int n = sizeof(A)/sizeof(A[0]);
    int comparisons, swaps;
    
    ShakerSort(A, n, &swaps, &comparisons);
    
    for (int i = 0; i < n-1; i++) {
        assert_true(A[i] <= A[i+1]);
    }
    
    assert_true(comparisons <= (pow(n,2)-n)/2);
    assert_true(swaps > 0);
    assert_true(swaps <= 3*((pow(n,2)-n)/2));
}

static void test_BubbleSort(void **state) {
    (void)state;
    
    int A[] = {5,2,4,6,1,3,8,6,2,7};
    int n = sizeof(A)/sizeof(A[0]);
    int comparisons, swaps;
    
    BubbleSort(A, n, &swaps, &comparisons);
    
    for (int i = 0; i < n-1; i++) {
        assert_true(A[i] <= A[i+1]);
    }
    
    assert_int_equal(comparisons, (pow(n,2)-n)/2);
    assert_true(swaps >= 0);
    assert_true(swaps <= 3*((pow(n,2)-n)/2));
}

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
        cmocka_unit_test(test_FillRand),
        cmocka_unit_test(test_SelectSort),
        cmocka_unit_test(test_ShakerSort),
        cmocka_unit_test(test_BubbleSort),
        cmocka_unit_test(test_InsertSort),
        cmocka_unit_test(test_Bubble_Shaker_Select_Insert)
    };
    
    return cmocka_run_group_tests(tests, NULL, NULL);
}