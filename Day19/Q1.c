#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int minSum = arr[0] + arr[1];
    int a = arr[0], b = arr[1];

    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            int sum = arr[i] + arr[j];

            if(abs(sum) < abs(minSum)) {
                minSum = sum;
                a = arr[i];
                b = arr[j];
            }
        }
    }

    printf("%d %d", a, b);

    return 0;
}