#include <stdio.h>

enum operators{
    add = 55,
    sub = 66,
    multiply = 22,
    div = 77
};

void main(){
    printf("%d", sizeof(enum operators));
/*the size of enum is the same size of int, it is 4 byte.
men who write the compiler control its size;
 when i adds new elements to enum, its size is const.*/
}