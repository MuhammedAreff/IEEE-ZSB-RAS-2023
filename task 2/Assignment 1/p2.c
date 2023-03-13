#include <stdio.h>


void main(){
    int d = 0x3E2A5C;
    int *ptr = &d;

    ++*ptr;
    printf("%d\n", *ptr);
    printf("This Case Will Increase The Value Of Pointer 1\n");

    *ptr++;
    printf("%d\n", *ptr);
    printf("The Pointer Will Go To The Next Element\n");

    *++ptr;
    printf("%d\n",*ptr);
    printf("The Pointer Will Go To The Next Element And Take Its Value\n");
}

