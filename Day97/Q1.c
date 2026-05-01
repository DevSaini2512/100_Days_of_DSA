#include <stdio.h>
#include <stdlib.h>

// comparator for sorting by start time
int cmp(const void* a, const void* b) {
    return ((int*)a)[0] - ((int*)b)[0];
}

// min-heap functions
void swap(int* a, int* b) {
    int t = *a; *a = *b; *b = t;
}

void heapifyUp(int heap[], int i) {
    while(i > 0 && heap[(i - 1)/2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1)/2]);
        i = (i - 1)/2;
    }
}

void heapifyDown(int heap[], int size, int i) {
    while(2*i + 1 < size) {
        int left = 2*i + 1, right = 2*i + 2, smallest = i;

        if(heap[left] < heap[smallest]) smallest = left;
        if(right < size && heap[right] < heap[smallest]) smallest = right;

        if(smallest == i) break;

        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }
}

int main() {
    int intervals[][2] = {{0,30},{5,10},{15,20}};
    int n = 3;

    qsort(intervals, n, sizeof(intervals[0]), cmp);

    int heap[1000], size = 0;

    for(int i = 0; i < n; i++) {
        int start = intervals[i][0];
        int end = intervals[i][1];

        // if room free
        if(size > 0 && heap[0] <= start) {
            heap[0] = end;
            heapifyDown(heap, size, 0);
        } else {
            heap[size] = end;
            heapifyUp(heap, size);
            size++;
        }
    }

    printf("%d", size);
    return 0;
}
