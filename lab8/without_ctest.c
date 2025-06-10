#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>
#include <setjmp.h>
#include <cmocka.h>
#include <math.h>

void FillRand(int A[], int n) {
    for (int i = 0; i < n; i++) {
        A[i] = rand() % 1000000000000000;
    }
}

static void test_FillRand(void **state) {
    (void)state;
    
    int n = 10;
    int A[n];
    
    FillRand(A, n);
    
    for (int i = 0; i < n; i++) {
        assert_true(A[i] >= 0);
        assert_true(A[i] < 1000000000000000);
    }
}

void SelectSort(int A[], int n, int *comparisons, int *swaps) {
    *comparisons = 0;
    *swaps = 0;

    for (int i = 0; i < n - 1; i++) {
        int k = i;
        
        for (int j = i + 1; j < n; j++) {
            (*comparisons)++;
            if (A[j] < A[k]) {
                k = j;
            }
        }
        
        int temp = A[i];
        A[i] = A[k];
        A[k] = temp;
        (*swaps)+=3;  
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
    
    assert_int_equal(comparisons, (pow(n, 2)-n)/2 );
    assert_int_equal(swaps, 3*(n-1));
}

void ShakerSort(int A[], int n, int *swaps, int *comparisons) {
    *swaps = 0;
    *comparisons = 0;
    int l = 0, r = n - 1, k = n - 1;

    do {
        for (int j = r; j > l; j--) {
            (*comparisons) += 1;
            if (A[j] < A[j - 1]) {
                int cp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = cp;
                k = j;
                (*swaps) += 3;
            }
        }
        l = k;
        for (int j = l; j < r; j++) {
            (*comparisons) += 1;
            if (A[j] > A[j + 1]) {
                int cp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = cp;
                k = j;
                (*swaps) += 3;
            }
        }
        r = k;
    } while (l < r);
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

void BubbleSort(int A[], int n, int *swaps, int *comparisons)
{
    *comparisons = 0;
    *swaps = 0;

    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j > i; j--) {
            (*comparisons)++;
            if (A[j] < A[j-1]) {
                int k = A[j];
                A[j] = A[j-1];
                A[j-1] = k;
                (*swaps) += 3;
            }
        }
    }
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

void InsertSort(int A[], int n, int *swaps, int *comparisons) {
    *swaps = 0;
    *comparisons = 0;
    for (int i = 1; i < n; i++) {
        int t = A[i], j = i - 1;
        while(j >= 0 && t < A[j]) {
            (*comparisons) += 1;
            A[j+1] = A[j];
            j--;
            (*swaps) += 1;
        }
        if (j >= 0) {
            (*comparisons)++;
        }
        A[j+1] = t;
        (*swaps) += 2;
    }
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

int Bubble(int n)
{
    int A[n], comparisons, swaps;
    FillRand(A, n);
    BubbleSort(A, n, &swaps, &comparisons);
    return comparisons + swaps;
}

int Shaker(int n)
{
    int A[n], comparisons, swaps;
    FillRand(A, n);
    ShakerSort(A, n, &swaps, &comparisons);
    return comparisons + swaps;
}

int Select(int n)
{
    int A[n], comparisons, swaps;
    FillRand(A, n);
    SelectSort(A, n, &swaps, &comparisons);
    return comparisons + swaps;
}

int Insert(int n)
{
    int A[n], comparisons, swaps;
    FillRand(A, n);
    InsertSort(A, n, &swaps, &comparisons);
    return comparisons + swaps;
}

static void test_functions(void **state) {
    (void)state;
    
    int n = 100;
    
    assert_true(Bubble(n) > 0);
    assert_true(Shaker(n) > 0);
    assert_true(Select(n) > 0);
    assert_true(Insert(n) > 0);
}


int main()
{
    int N[5];
    srand(time(NULL));

    for (int i = 1; i < 6; i++) {
        N[i-1] = i*100;
    }

    printf(" n |                 M+C(факт.)                |\n");
    printf("   |  Select  |  Bubble  |  Shaker  |  Insert  |\n");
    printf("---|----------|----------|----------|----------|\n");
    for (int i = 0; i < 5; i++) {
        printf("%d|  %-8d|  %-8d|  %-8d|  %-8d|\n", N[i], Select(N[i]), Bubble(N[i]), Shaker(N[i]), Insert(N[i]));
        printf("---|----------|----------|----------|----------|\n");
    }

    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_FillRand),
        cmocka_unit_test(test_SelectSort),
        cmocka_unit_test(test_ShakerSort),
        cmocka_unit_test(test_BubbleSort),
        cmocka_unit_test(test_InsertSort),
        cmocka_unit_test(test_functions)
    };
    
    return cmocka_run_group_tests(tests, NULL, NULL);

}
