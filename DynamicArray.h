#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

typedef struct {
    int *array;
    size_t used;
    size_t size;
} DynamicArray;

void initArray(DynamicArray *a, size_t initialSize);
void insertArray(DynamicArray *a, int element);
void freeArray(DynamicArray *a);
void removeElement(DynamicArray *a, size_t index);
void resizeArray(DynamicArray *a, size_t newSize);

#endif
