#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int**)a)[0] - (*(int**)b)[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize,
            int* returnSize, int** returnColumnSizes) {

    qsort(intervals, intervalsSize, sizeof(int*), cmp);

    int** res = (int**)malloc(intervalsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(intervalsSize * sizeof(int));

    int idx = 0;

    for(int i = 0; i < intervalsSize; i++) {
        if(idx == 0 || res[idx-1][1] < intervals[i][0]) {
            res[idx] = (int*)malloc(2 * sizeof(int));
            res[idx][0] = intervals[i][0];
            res[idx][1] = intervals[i][1];
            (*returnColumnSizes)[idx] = 2;
            idx++;
        } else {
            if(intervals[i][1] > res[idx-1][1]) {
                res[idx-1][1] = intervals[i][1];
            }
        }
    }

    *returnSize = idx;
    return res;
}
