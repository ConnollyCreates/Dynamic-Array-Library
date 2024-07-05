#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "DynamicArray.h"

void initArray(DynamicArray *a, size_t initialSize) {
    a->array = (int *)malloc(initialSize * sizeof(int));
    a->used = 0;
    a->size = initialSize;
}

void insertArray(DynamicArray *a, int element) {
    if (a->used == a->size) {
        a->size *= 2;
        a->array = (int *)realloc(a->array, a->size * sizeof(int));
    }
    a->array[a->used++] = element;
}

void freeArray(DynamicArray *a) {
    free(a->array);
    a->array = NULL;
    a->used = a->size = 0;
}

void removeElement(DynamicArray *a, size_t index) {
    if (index < a->used) {
        for (size_t i = index; i < a->used - 1; ++i) {
            a->array[i] = a->array[i + 1];
        }
        a->used--;
    }
}

void resizeArray(DynamicArray *a, size_t newSize) {
    if (newSize > a->size) {
        a->array = (int *)realloc(a->array, newSize * sizeof(int));
        a->size = newSize;
    }
}
