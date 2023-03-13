#include <stdio.h>

int main(){

   int *p1;
   char *p2;
   long long *p3;

   printf("P1 Old = %d\n", p1);
   p1++;
   printf("P1 New = %d\n", p1);

   printf("P2 Old = %d\n", p2);
   p2++;
   printf("P2 New = %d\n", p2);

   printf("P3 Old = %d\n", p3);
   p3++;
   printf("P3 New = %d\n", p3);

   printf("__P1  Was 16 After Increment it turned into  20 As Int = 4 So what happened here that the address Increased by 4 due to that int = 4 bytes \n__Char = 1 Byte So That It Will Find The Old Address Of p2 And Increase It 1 (If It Was 10, It Will Become 11), \n__Long Long = 8 Byte So That if It Was 10 It Will Be 18 like \n__(like char or int its all the same its just incresed by a fixed num).");

   return 0;
}


