#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;
int n;

void push(int v) {
    stack[++top] = v;
}

void DFS(int v) {
    visited[v] = 1;

    for (int u = 0; u < n; u++) {
        if (graph[v][u] == 1 && !visited[u]) {
            DFS(u);
        }
    }

    push(v);
}

void topologicalSort() {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            DFS(i);
        }
    }

    printf("Topological Order: ");

    while (top != -1) {
        printf("%d ", stack[top--]);
    }

    printf("\n");
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    topologicalSort();

    return 0;
}
