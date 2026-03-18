#include <stdio.h>
#include <stdlib.h>

// Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Create node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Queue
struct Node* queue[1000];
int front = 0, rear = -1;

void enqueue(struct Node* node) {
    queue[++rear] = node;
}

struct Node* dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front > rear;
}

// Build tree
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    front = 0; rear = -1;

    struct Node* root = newNode(arr[0]);
    enqueue(root);

    int i = 1;

    while (i < n && !isEmpty()) {
        struct Node* curr = dequeue();

        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            enqueue(curr->left);
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            enqueue(curr->right);
        }
        i++;
    }

    return root;
}

// Level Order Traversal
void levelOrder(struct Node* root) {
    if (root == NULL) return;

    front = 0; rear = -1;

    enqueue(root);

    while (!isEmpty()) {
        struct Node* curr = dequeue();
        printf("%d ", curr->data);

        if (curr->left)
            enqueue(curr->left);

        if (curr->right)
            enqueue(curr->right);
    }
}

int main() {
    int N;
    scanf("%d", &N);

    int arr[1000];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, N);

    levelOrder(root);

    return 0;
}