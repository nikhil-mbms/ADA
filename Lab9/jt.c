#include <stdio.h>

int p[10], dir[10];

int mobile(int n) {
    int m = 0, pos = -1;

    for (int i = 0; i < n; i++) {
        if (dir[p[i]] == -1 && i != 0 && p[i] > p[i - 1] && p[i] > m) {
            m = p[i];
            pos = i;
        }

        if (dir[p[i]] == 1 && i != n - 1 && p[i] > p[i + 1] && p[i] > m) {
            m = p[i];
            pos = i;
        }
    }

    return pos;
}

void printPerm(int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        p[i] = i + 1;
        dir[i + 1] = -1;
    }

    printPerm(n);

    while (1) {
        int pos = mobile(n);

        if (pos == -1)
            break;

        int k = p[pos];
        int newPos = pos + dir[k];

        int temp = p[pos];
        p[pos] = p[newPos];
        p[newPos] = temp;

        for (int i = 1; i <= n; i++) {
            if (i > k)
                dir[i] *= -1;
        }

        printPerm(n);
    }

    return 0;
}
