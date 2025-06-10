#include "main.h"

int main() {
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

    return 0;
}