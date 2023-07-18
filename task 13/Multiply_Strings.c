#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* multiply(char* num1, char* num2) {
   
    if (strcmp(num1, "0") == 0 || strcmp(num2, "0") == 0) return "0";
    
   
    int n1 = strlen(num1), n2 = strlen(num2);
    int n = n1 + n2;
    int* num = (int*) calloc(n, sizeof(int));
    
   
    for (int i = n1 - 1; i >= 0; --i) {
        for (int j = n2 - 1; j >= 0; --j) {
            num[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
            num[i + j] += num[i + j + 1] / 10;
            num[i + j + 1] %= 10;
        }
    }
    
    
    int i = 0;
    while (i < n && num[i] == 0) ++i;
    
   
    char* res = (char*) malloc((n - i + 1) * sizeof(char));
    strncpy(res, "", 1);
    while (i < n) {
        char digit = num[i++] + '0';
        strncat(res, &digit, 1);
    }
    free(num);
    
    return res;
}