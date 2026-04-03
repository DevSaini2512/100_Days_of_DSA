#include <stdio.h>
#include <stdlib.h>

// Node for adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Array of adjacency lists
    struct Node* adj[n];

    // Initialize all heads to NULL
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    int u, v;

    // Input edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        // Add v to u's list
        struct Node* temp = newNode(v);
        temp->next = adj[u];
        adj[u] = temp;

        // For undirected graph, also add u to v
        temp = newNode(u);
        temp->next = adj[v];
        adj[v] = temp;
    }

    // Print adjacency list
    for (int i = 0; i < n; i++) {
        printf("%d -> ", i);
        struct Node* temp = adj[i];

        while (temp) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }

    return 0;
}