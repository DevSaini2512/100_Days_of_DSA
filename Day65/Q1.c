#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int size[MAX];
int visited[MAX];

// DFS function to detect cycle
int dfs(int v, int parent) {
    visited[v] = 1;

    for (int i = 0; i < size[v]; i++) {
        int next = adj[v][i];

        if (!visited[next]) {
            if (dfs(next, v))
                return 1;
        }
        else if (next != parent) {
            // visited and not parent → cycle
            return 1;
        }
    }

    return 0;
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

    // Check all components
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1)) {
                printf("YES");
                return 0;
            }
        }
    }

    printf("NO");

    return 0;
}