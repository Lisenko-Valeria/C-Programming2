#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void FillRand(int A[], int n);
void SelectSort(int A[], int n, int *comparisons, int *swaps);
void ShakerSort(int A[], int n, int *swaps, int *comparisons);
void BubbleSort(int A[], int n, int *swaps, int *comparisons);
void InsertSort(int A[], int n, int *swaps, int *comparisons);
int Bubble(int n);
int Shaker(int n);
int Select(int n);
int Insert(int n);