#include "array_merge.h"
#include "../mergesort/mergesort.h"
#include <stdlib.h>

int* array_merge(int num_arrays, int* sizes, int** values) {
    int totalElements = 0;

    for (int i = 0; i < num_arrays; i++) {
        totalElements += sizes[i];
    }

    if (totalElements == 0) {
        int *zeroArray = (int *)malloc(sizeof(int));
        zeroArray[0] = 0;
        return zeroArray;
    }

    int *mergedArray = (int *)malloc(totalElements * sizeof(int));
    int index = 0;

    for (int i = 0; i < num_arrays; i++) {
        for (int j = 0; j < sizes[i]; j++) {
            mergedArray[index++] = values[i][j];
        }
    }

    mergesort(totalElements, mergedArray);

    int uniqueCount = 1;
    for (int i = 1; i < totalElements; i++) {
        if (mergedArray[i] != mergedArray[i - 1]) {
            mergedArray[uniqueCount++] = mergedArray[i];
        }
    }

    int *results = (int *)malloc((uniqueCount + 1) * sizeof(int));
    results[0] = uniqueCount;

    for (int i = 0; i < uniqueCount; i++) {
        results[i + 1] = mergedArray[i];
    }

    free(mergedArray);

    return results;
}
