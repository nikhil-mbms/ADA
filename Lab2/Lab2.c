
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mg(int a[], int l, int m, int r) {
    int i = l, j = m + 1, k = 0, t[r - l + 1];

    while (i <= m && j <= r)
        t[k++] = (a[i] <= a[j]) ? a[i++] : a[j++];

    while (i <= m) t[k++] = a[i++];
    while (j <= r) t[k++] = a[j++];

    for (i = l, k = 0; i <= r; i++, k++)
        a[i] = t[k];
}

void ms(int a[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        ms(a, l, m);
        ms(a, m + 1, r);
        mg(a, l, m, r);
    }
}

int main() {
    int sz[] = {10000, 20000, 30000, 40000, 50000};

    for (int s = 0; s < 5; s++) {
        int n = sz[s];
        int *a = (int*)malloc(n * sizeof(int));

        for (int i = 0; i < n; i++)
            a[i] = rand() % 100000;

        clock_t st = clock();

        ms(a, 0, n - 1);

        clock_t en = clock();

        double t = (double)(en - st) / CLOCKS_PER_SEC;

        printf("%d %.6f\n", n, t);

        free(a);
    }

    return 0;
}
