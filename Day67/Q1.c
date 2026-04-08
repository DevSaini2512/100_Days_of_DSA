#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int size[MAX];
int visited[MAX];

// Stack
int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

// DFS function
void dfs(int v) {
    visited[v] = 1;

    for (int i = 0; i < size[v]; i++) {
        int next = adj[v][i];
        if (!visited[next]) {
            dfs(next);
        }
    }

    // push after visiting children
    push(v);
}

int main() {
    int n;
    scanf("%d", &n);

    // Input adjacency list
    for (int i = 0; i < n; i++) {
        size[i] = 0;
        int x;

        while (1) {
            scanf("%d", &x);
            if (x == -1) break;

            adj[i][size[i]++] = x;
        }
    }

    // Initialize visited
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    // DFS for all nodes
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    // Print stack (reverse order)
    while (top != -1) {
        printf("%d ", stack[top--]);
    }

    return 0;
}