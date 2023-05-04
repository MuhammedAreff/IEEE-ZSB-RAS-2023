#include <stdio.h>
#include <stdlib.h>

#define ASCENDING_SORT 1
#define DESCENDING_SORT 2

int* sort_array(int* array, int size, int sort_order) {
    int i, j, temp;

    for(i = 0; i < size - 1; i++) {
        for(j = i + 1; j < size; j++) {
            if((sort_order == ASCENDING_SORT && array[i] > array[j]) ||
               (sort_order == DESCENDING_SORT && array[i] < array[j])) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    return array;
}

#ifdef ASCENDING_SORT
int* sort(int* array, int size) {
    return sort_array(array, size, ASCENDING_SORT);
}
#elif defined DESCENDING_SORT
int* sort(int* array, int size) {
    return sort_array(array, size, DESCENDING_SORT);
}
#endif

int main() {
    int size, i;
    int* array;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    array = (int*)malloc(size * sizeof(int));

    printf("Enter %d integers:\n", size);
    for(i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    array = sort(array, size);

    printf("Sorted array:\n");
    for(i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);

    return 0;
}
