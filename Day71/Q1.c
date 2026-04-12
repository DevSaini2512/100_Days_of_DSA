#include <stdio.h>
#include <string.h>

#define SIZE 100

int table[SIZE];
int m; // table size

// Hash function
int hash(int key) {
    return key % m;
}

// Insert using quadratic probing
void insert(int key) {
    int i = 0;
    int index;

    while (i < m) {
        index = (hash(key) + i * i) % m;

        if (table[index] == -1) {
            table[index] = key;
            return;
        }
        i++;
    }

    printf("Table Full\n");
}

// Search using quadratic probing
int search(int key) {
    int i = 0;
    int index;

    while (i < m) {
        index = (hash(key) + i * i) % m;

        if (table[index] == key)
            return 1;

        if (table[index] == -1)
            return 0;

        i++;
    }
    return 0;
}

int main() {
    int q;
    scanf("%d", &m);   // size
    scanf("%d", &q);   // operations

    // Initialize table
    for (int i = 0; i < m; i++)
        table[i] = -1;

    char op[10];
    int key;

    while (q--) {
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(key);
        } else if (strcmp(op, "SEARCH") == 0) {
            if (search(key))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}