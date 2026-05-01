#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pos;
    int speed;
} Car;

// sort by position descending
int cmp(const void* a, const void* b) {
    return ((Car*)b)->pos - ((Car*)a)->pos;
}

int main() {
    int target = 12;
    int position[] = {10, 8, 0, 5, 3};
    int speed[] = {2, 4, 1, 1, 3};
    int n = 5;

    Car cars[n];
    for(int i = 0; i < n; i++) {
        cars[i].pos = position[i];
        cars[i].speed = speed[i];
    }

    qsort(cars, n, sizeof(Car), cmp);

    int fleets = 0;
    double prevTime = 0.0;

    for(int i = 0; i < n; i++) {
        double time = (double)(target - cars[i].pos) / cars[i].speed;

        if(time > prevTime) {
            fleets++;
            prevTime = time;
        }
    }

    printf("%d", fleets);
    return 0;
}
