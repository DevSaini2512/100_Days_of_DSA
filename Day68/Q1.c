#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int size[MAX];
int indegree[MAX];

// Queue
int queue[MAX];
int front = 0, rear = 0;

void enqueue(int x) {
    queue[rear++] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

int main() {
    int n;
    scanf("%d", &n);

    // Initialize indegree
    for (int i = 0; i < n; i++)
        indegree[i] = 0;

    // Input adjacency list
    for (int i = 0; i < n; i++) {
        size[i] = 0;
        int x;

        while (1) {
            scanf("%d", &x);
            if (x == -1) break;

            adj[i][size[i]++] = x;
            indegree[x]++;   // count incoming edges
        }
    }

    // Push nodes with indegree 0
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            enqueue(i);
    }

    int count = 0;

    while (!isEmpty()) {
        int v = dequeue();
        printf("%d ", v);
        count++;

        for (int i = 0; i < size[v]; i++) {
            int next = adj[v][i];
            indegree[next]--;

            if (indegree[next] == 0)
                enqueue(next);
        }
    }

    // Check cycle
    if (count != n) {
        printf("\nCycle exists");
    }

    return 0;
}