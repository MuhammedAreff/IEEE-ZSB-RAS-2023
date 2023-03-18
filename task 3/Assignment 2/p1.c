#include <stdio.h>

struct Date {
    
    char *d;
    char *m;
    char *y;

}d1,d2;

int main() {
    
    //First date Entry
    printf("Enter the first date >> \n");
    scanf("%s %s %s",&d2.d,&d1.m,&d1.y);
    
    //Second date Entry
    printf("Enter the second date >> \n");
    scanf("%s %s %s",&d2.d,&d2.m,&d2.y);
    
    //Checking if the two dates equals or not
    if(d1.d == d2.d && d1.m == d2.m && d1.y == d2.y){
        printf("Dates are equal");
    }
    
    else{ printf("Dates are not equal"); }

    return 0;
}
