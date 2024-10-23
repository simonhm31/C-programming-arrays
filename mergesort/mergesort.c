#include "mergesort.h"
#include <stdlib.h>
#include <stdbool.h>

bool requiresSorting(int rangeSize) {
    return rangeSize >= 2;
}

void combineRanges(int values[], int startIndex, int midPoint, int endIndex) {
    const int rangeSize = endIndex - startIndex;
    int *temp = (int *)malloc(rangeSize * sizeof(int));
    int leftIndex = startIndex;
    int rightIndex = midPoint;
    int tempIndex = 0;

    while (leftIndex < midPoint && rightIndex < endIndex) {
        if (values[leftIndex] < values[rightIndex]) {
            temp[tempIndex++] = values[leftIndex++];
        } else {
            temp[tempIndex++] = values[rightIndex++];
        }
    }

    while (leftIndex < midPoint) {
        temp[tempIndex++] = values[leftIndex++];
    }

    while (rightIndex < endIndex) {
        temp[tempIndex++] = values[rightIndex++];
    }

    for (int i = 0; i < rangeSize; i++) {
        values[i + startIndex] = temp[i];
    }

    free(temp);
}

void mergesortSection(int values[], int startIndex, int endIndex) {
    int rangeSize = endIndex - startIndex;
    if (requiresSorting(rangeSize)) {
        int midPoint = (startIndex + endIndex) / 2;
        mergesortSection(values, startIndex, midPoint);
        mergesortSection(values, midPoint, endIndex);
        combineRanges(values, startIndex, midPoint, endIndex);
    }
}

void mergesort(int size, int values[]) {
    mergesortSection(values, 0, size);
}
