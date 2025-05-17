#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cmp_nums(const void *a, const void *b) {
    int arg1 = *(int *)a;
    int arg2 = *(int *)b;
    return (arg1 > arg2) - (arg1 < arg2);
}

void fill_sorted(int *arr, size_t n) {
    for (size_t i = 0; i < n; i++)
        arr[i] = i;
}

void fill_reverse_sorted(int *arr, size_t n) {
    for (size_t i = 0; i < n; i++)
        arr[i] = n - i;
}

void fill_random(int *arr, size_t n) {
    for (size_t i = 0; i < n; i++)
        arr[i] = rand() % 100000;
}

int main() {
    const size_t n = 100000;
    int *arr = malloc(n * sizeof(int));
    if (!arr) {
        perror("malloc");
        return 1;
    }

    clock_t start, end;
    double elapsed;

    fill_sorted(arr, n);
    start = clock();
    qsort(arr, n, sizeof(int), cmp_nums);
    end = clock();
    elapsed = (double)(end - start) / CLOCKS_PER_SEC;
    printf("fill_sorted: %.6f s\n", elapsed);

    fill_reverse_sorted(arr, n);
    start = clock();
    qsort(arr, n, sizeof(int), cmp_nums);
    end = clock();
    elapsed = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Зворотно fill_reverse_sorted масив: %.6f s\n", elapsed);

    fill_random(arr, n);
    start = clock();
    qsort(arr, n, sizeof(int), cmp_nums);
    end = clock();
    elapsed = (double)(end - start) / CLOCKS_PER_SEC;
    printf("fill_random: %.6f s\n", elapsed);

    free(arr);
    return 0;
}
