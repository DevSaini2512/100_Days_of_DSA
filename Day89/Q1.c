#include <stdio.h>

int isPossible(int arr[], int n, int m, int mid) {
    int students = 1, pages = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i] > mid) return 0;

        if(pages + arr[i] <= mid) {
            pages += arr[i];
        } else {
            students++;
            pages = arr[i];

            if(students > m) return 0;
        }
    }
    return 1;
}

int allocateBooks(int arr[], int n, int m) {
    if(m > n) return -1;

    int sum = 0, max = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
        if(arr[i] > max) max = arr[i];
    }

    int low = max, high = sum, ans = -1;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(isPossible(arr, n, m, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n = 4, m = 2;
    int arr[] = {12, 34, 67, 90};

    printf("%d", allocateBooks(arr, n, m));
    return 0;
}
