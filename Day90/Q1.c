#include <stdio.h>

int isPossible(int arr[], int n, int k, int mid) {
    int painters = 1, time = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i] > mid) return 0;

        if(time + arr[i] <= mid) {
            time += arr[i];
        } else {
            painters++;
            time = arr[i];

            if(painters > k) return 0;
        }
    }
    return 1;
}

int minTime(int arr[], int n, int k) {
    int max = 0, sum = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i] > max) max = arr[i];
        sum += arr[i];
    }

    int low = max, high = sum, ans = sum;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(isPossible(arr, n, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n = 4, k = 2;
    int arr[] = {10, 20, 30, 40};

    printf("%d", minTime(arr, n, k));
    return 0;
}
