#include <stdio.h>
#include <stdlib.h>
int board[20], n;

int isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return 0;
    }
    return 1;
}

int solve(int row) {
    if (row == n) {
        for (int i = 0; i < n; i++)
            printf("%d ", board[i]);
        printf("\n");
        return 1;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            solve(row + 1);
        }
    }
    return 0;
}

int main() {
    scanf("%d", &n);
    solve(0);
    return 0;
}
