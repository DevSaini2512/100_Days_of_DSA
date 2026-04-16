#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Simple hash map using arrays
struct Hash {
    int key;
    int value;
};

struct Hash map[MAX];
int size = 0;

// Find index of key in map
int find(int key) {
    for (int i = 0; i < size; i++) {
        if (map[i].key == key)
            return map[i].value;
    }
    return -1;
}

// Insert key with value
void insert(int key, int value) {
    map[size].key = key;
    map[size].value = value;
    size++;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[MAX];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int sum = 0, maxLen = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == 0)
            maxLen = i + 1;

        int prevIndex = find(sum);

        if (prevIndex != -1) {
            if (i - prevIndex > maxLen)
                maxLen = i - prevIndex;
        } else {
            insert(sum, i);
        }
    }

    printf("%d\n", maxLen);

    return 0;
}