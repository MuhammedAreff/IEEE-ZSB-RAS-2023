#include <stdio.h>

typedef int integer;
typedef float floating;
typedef double doubleing;
typedef char character;
typedef short short_integer;
typedef long long_integer;

int main() {
    printf("Size of integer: %ld bytes\n", sizeof(integer));
    printf("Size of floating: %ld bytes\n", sizeof(floating));
    printf("Size of doubleing: %ld bytes\n", sizeof(doubleing));
    printf("Size of character: %ld bytes\n", sizeof(character));
    printf("Size of short_integer: %ld bytes\n", sizeof(short_integer));
    printf("Size of long_integer: %ld bytes\n", sizeof(long_integer));

    return 0;
}