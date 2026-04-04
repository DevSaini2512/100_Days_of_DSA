#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Adjacency list
int adj[MAX][MAX];
int size[MAX];        // number of neighbors for each node
int visited[MAX];

// DFS function
void dfs(int v) {
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < size[v]; i++) {
        int next = adj[v][i];
        if (!visited[next]) {
            dfs(next);
        }
    }
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

    int s;
    scanf("%d", &s);

    // Initialize visited
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    // DFS call
    dfs(s);

    return 0;
}