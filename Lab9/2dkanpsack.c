#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n, W1, W2;
    scanf("%d", &n);

    int w1[n], w2[n], val[n];

    for (int i = 0; i < n; i++) scanf("%d", &w1[i]);
    for (int i = 0; i < n; i++) scanf("%d", &w2[i]);
    for (int i = 0; i < n; i++) scanf("%d", &val[i]);

    scanf("%d %d", &W1, &W2);

    int dp[n + 1][W1 + 1][W2 + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W1; j++) {
            for (int k = 0; k <= W2; k++) {
                if (i == 0 || j == 0 || k == 0)
                    dp[i][j][k] = 0;
                else if (w1[i - 1] <= j && w2[i - 1] <= k)
                    dp[i][j][k] = max(val[i - 1] + dp[i - 1][j - w1[i - 1]][k - w2[i - 1]], dp[i - 1][j][k]);
                else
                    dp[i][j][k] = dp[i - 1][j][k];
            }
        }
    }

    printf("%d\n", dp[n][W1][W2]);

    return 0;
}
