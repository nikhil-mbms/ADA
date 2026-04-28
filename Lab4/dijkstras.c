#include <stdio.h>
#define N 5
#define INF 9999

int min(int d[], int v[]) {
    int m = INF, idx = -1;
    for (int i = 0; i < N; i++) {
        if (!v[i] && d[i] < m) {
            m = d[i];
            idx = i;
        }
    }
    return idx;
}

void dijk(int g[N][N], int s) {
    int d[N], v[N] = {0};

    for (int i = 0; i < N; i++)
        d[i] = INF;

    d[s] = 0;

    for (int i = 0; i < N - 1; i++) {
        int u = min(d, v);
        v[u] = 1;

        for (int j = 0; j < N; j++) {
            if (!v[j] && g[u][j] && d[u] + g[u][j] < d[j]) {
                d[j] = d[u] + g[u][j];
            }
        }
    }

    printf("Node  Dist\n");
    for (int i = 0; i < N; i++)
        printf("%d     %d\n", i, d[i]);
}

int main() {
    int g[N][N] = {
        {0, 10, 0, 30, 100},
        {0, 0, 50, 0, 0},
        {0, 0, 0, 0, 10},
        {0, 0, 20, 0, 60},
        {0, 0, 0, 0, 0}
    };

    dijk(g, 0);
    return 0;
}