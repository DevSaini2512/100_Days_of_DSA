#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Build tree (level order)
struct Node* buildTree(int arr[], int n) {
    if (n == 0)
        return NULL;

    struct Node* root = newNode(arr[0]);

    struct Node* queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int i = 1;

    while (i < n) {
        struct Node* curr = queue[front++];

        if (i < n) {
            curr->left = newNode(arr[i++]);
            queue[rear++] = curr->left;
        }

        if (i < n) {
            curr->right = newNode(arr[i++]);
            queue[rear++] = curr->right;
        }
    }

    return root;
}

// Check Min-Heap property
int isMinHeap(struct Node* root) {
    if (root == NULL)
        return 1;

    // Check left child
    if (root->left) {
        if (root->data > root->left->data)
            return 0;
    }

    // Check right child
    if (root->right) {
        if (root->data > root->right->data)
            return 0;
    }

    return isMinHeap(root->left) && isMinHeap(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    if (isMinHeap(root))
        printf("YES");
    else
        printf("NO");

    return 0;
}