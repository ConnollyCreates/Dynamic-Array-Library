#include <stdio.h>
#include <stdlib.h>
#include "DynamicArray.h"
#define MAX_SIZE 100

int main() {
    DynamicArray a;
    FILE *file = fopen("array_data.csv", "w");
    if (!file) {
        perror("Could not open file");
        return 1;
    }
    fprintf(file, "Insertion,Used,Size\n");

    int arrsize;
    
    printf("Welcome to the Visual Dynamic Array tool to gain a better understanding of how dynamic arrays work\n");
    printf("Enter how large you would like your array to be");

    scanf("%d", &arrsize);

    
    initArray(&a, arrsize);

    printf("An array of size %d has been initiliazed", arrsize);


    for (int i = 0; i < arrsize; i++) {
        insertArray(&a, i);
        fprintf(file, "%d,%zu,%zu\n", i + 1, a.used, a.size);
    } 

    fclose(file);
    freeArray(&a);

    return 0;
}
