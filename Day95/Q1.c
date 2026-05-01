#include <stdio.h>
#include <stdlib.h>

void insertionSort(float arr[], int n) {
    for(int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bucketSort(float arr[], int n) {
    // create buckets
    float* buckets[n];
    int count[n];

    for(int i = 0; i < n; i++) {
        buckets[i] = (float*)malloc(n * sizeof(float));
        count[i] = 0;
    }

    // distribute
    for(int i = 0; i < n; i++) {
        int idx = arr[i] * n;
        buckets[idx][count[idx]++] = arr[i];
    }

    // sort each bucket
    for(int i = 0; i < n; i++) {
        insertionSort(buckets[i], count[i]);
    }

    // concatenate
    int k = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < count[i]; j++) {
            arr[k++] = buckets[i][j];
        }
        free(buckets[i]);
    }
}

int main() {
    float arr[] = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47};
    int n = sizeof(arr)/sizeof(arr[0]);

    bucketSort(arr, n);

    for(int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);

    return 0;
}
