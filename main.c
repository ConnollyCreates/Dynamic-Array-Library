#include <stdio.h>
#include <stdlib.h>
#include "DynamicArray.h"

int main() {
    DynamicArray a;
    FILE *file = fopen("array_data.csv", "w");
    if (!file) {
        perror("Could not open file");
        return 1;
    }
    fprintf(file, "Insertion,Used,Size\n");

    initArray(&a, 5);
    
    for (int i = 0; i < 40; i++) {
        insertArray(&a, i);
        fprintf(file, "%d,%zu,%zu\n", i + 1, a.used, a.size);
    }

    fclose(file);
    freeArray(&a);

    return 0;
}
