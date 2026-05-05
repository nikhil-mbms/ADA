#include <stdio.h>

#define INF 99999
#define MAX 100

int main() {
    int n, i, j, k;
    int D[MAX][MAX];

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &D[i][j]);

    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if (D[i][k] + D[k][j] < D[i][j])
                    D[i][j] = D[i][k] + D[k][j];

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (D[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", D[i][j]);
        }
        printf("\n");
    }

    return 0;
}