#include <stdio.h>
#include <stdlib.h>

int main() {
    int* ptr1;
    int* ptr2;
    int* ptr3;
    int* ptr4;
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

    // Free memory allocated using malloc
    free(ptr1);
    printf("Memory allocated using malloc freed.\n");

    // Allocate memory using calloc
    ptr4 = (int*)calloc(10, sizeof(int));
    if(ptr4 == NULL) {
        printf("Error: Failed to allocate memory using calloc.\n");
        free(ptr2);
        return 1;
    }

    printf("Memory allocated using calloc:\n");
    for(i = 0; i < 10; i++) {
        ptr4[i] = i;
        printf("%d ", ptr4[i]);
    }
    printf("\n");

    // Free allocated memory
    free(ptr2);
    free(ptr4);

    /*
        memory fragmentation will happen, where there is enough space in the free-store to allocate your requested memory block, 
        but not enough contiguous space for the size of the block you've requested.
    */


    return 0;
}