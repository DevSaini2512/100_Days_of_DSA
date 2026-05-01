#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return ((int*)a)[0] - ((int*)b)[0];
}

int main() {
    int intervals[][2] = {{1,3},{2,6},{8,10},{15,18}};
    int n = 4;

    qsort(intervals, n, sizeof(intervals[0]), cmp);

    int res[1000][2];
    int idx = 0;

    for(int i = 0; i < n; i++) {
        if(idx == 0 || res[idx-1][1] < intervals[i][0]) {
            res[idx][0] = intervals[i][0];
            res[idx][1] = intervals[i][1];
            idx++;
        } else {
            if(intervals[i][1] > res[idx-1][1]) {
                res[idx-1][1] = intervals[i][1];
            }
        }
    }

    for(int i = 0; i < idx; i++) {
        printf("[%d,%d] ", res[i][0], res[i][1]);
    }

    return 0;
}
