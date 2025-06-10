#include "main.h"

void FillRand(int A[], int n) {
    for (int i = 0; i < n; i++) {
        A[i] = rand() % 100;
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

void BubbleSort(int A[], int n, int *swaps, int *comparisons) {
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

int Bubble(int n) {
    int A[n], comparisons, swaps;
    FillRand(A, n);
    BubbleSort(A, n, &swaps, &comparisons);
    return comparisons + swaps;
}

int Shaker(int n) {
    int A[n], comparisons, swaps;
    FillRand(A, n);
    ShakerSort(A, n, &swaps, &comparisons);
    return comparisons + swaps;
}

int Select(int n) {
    int A[n], comparisons, swaps;
    FillRand(A, n);
    SelectSort(A, n, &swaps, &comparisons);
    return comparisons + swaps;
}

int Insert(int n) {
    int A[n], comparisons, swaps;
    FillRand(A, n);
    InsertSort(A, n, &swaps, &comparisons);
    return comparisons + swaps;
}