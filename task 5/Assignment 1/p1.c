#include <stdio.h>
#include <stdlib.h>

int main() {
    int* ptr1;
    int* ptr2;
    int* ptr3;
    int i;

    // Allocate memory using malloc
    ptr1 = (int*)malloc(5 * sizeof(int));
    if(ptr1 == NULL) {
        printf("Error: Failed to allocate memory using malloc.\n");
        return 1;
    }

    printf("Memory allocated using malloc:\n");
    for(i = 0; i < 5; i++) {
        ptr1[i] = i;
        printf("%d ", ptr1[i]);
    }
    printf("\n");

    // Allocate memory using calloc
    ptr2 = (int*)calloc(5, sizeof(int));
    if(ptr2 == NULL) {
        printf("Error: Failed to allocate memory using calloc.\n");
        free(ptr1);
        return 1;
    }

    printf("Memory allocated using calloc:\n");
    for(i = 0; i < 5; i++) {
        ptr2[i] = i;
        printf("%d ", ptr2[i]);
    }
    printf("\n");

    // Reallocate memory using realloc
    ptr1 = (int*)realloc(ptr1, 10 * sizeof(int));
    if(ptr1 == NULL) {
        printf("Error: Failed to reallocate memory using realloc.\n");
        free(ptr2);
        return 1;
    }

    printf("Memory reallocated using realloc:\n");
    for(i = 0; i < 10; i++) {
        ptr1[i] = i;
        printf("%d ", ptr1[i]);
    }
    printf("\n");

    // Free allocated memory
    free(ptr1);
    free(ptr2);

    return 0;
}