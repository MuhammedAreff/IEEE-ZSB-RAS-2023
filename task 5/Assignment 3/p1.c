//Implementation using Macros

#include <stdio.h>

#define my_sizeof(type) ((char *)(&type + 1) - (char *)&type)

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = my_sizeof(arr) / my_sizeof(arr[0]);
    printf("The size of the array is: %d\n", size);
    return 0;
}

// Implementation using inline Keyword

/*
#include <stdio.h>
#include <stdlib.h>

inline size_t my_sizeof(void *ptr) {
    char *p = ptr;
    size_t size = 0;
    while(*p++) {
        size++;
    }
    return size;
}

int main() {
    int *arr = (int *)malloc(5 * sizeof(int));
    int size = my_sizeof(arr) / my_sizeof(arr[0]);
    printf("The size of the dynamically allocated array is: %d\n", size);
    free(arr);
    return 0;
}
*/

// *******the differences between them and the regular sizeof()********

/*The regular sizeof() operator is a built-in operator in C that is always available and is evaluated at compile-time.

The macro implementation of sizeof() can be used to calculate the size of statically allocated types at compile-time, but cannot be used for dynamically allocated types.

The inline implementation of sizeof() can be used to calculate the size of dynamically allocated types at runtime, 
but may be less efficient than the regular sizeof() operator or the macro implementation.
*/
