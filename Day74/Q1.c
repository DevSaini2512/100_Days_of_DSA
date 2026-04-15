#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000
#define LEN 50

// Compare function for sorting strings
int cmp(const void *a, const void *b) {
    return strcmp((char *)a, (char *)b);
}

int main() {
    int n;
    char names[MAX][LEN];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    // Sort names
    qsort(names, n, sizeof(names[0]), cmp);

    int maxCount = 1, count = 1;
    char winner[LEN];
    strcpy(winner, names[0]);

    for (int i = 1; i < n; i++) {
        if (strcmp(names[i], names[i - 1]) == 0) {
            count++;
        } else {
            if (count > maxCount) {
                maxCount = count;
                strcpy(winner, names[i - 1]);
            }
            count = 1;
        }
    }

    // Check last group
    if (count > maxCount) {
        maxCount = count;
        strcpy(winner, names[n - 1]);
    }

    printf("%s %d\n", winner, maxCount);

    return 0;
}