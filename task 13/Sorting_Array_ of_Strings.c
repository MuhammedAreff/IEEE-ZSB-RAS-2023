#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b){ //increasing order.
    return strcmp(a, b) > 0;
}

int lexicographic_sort_reverse(const char* a, const char* b){  //decreasing order.
    return strcmp(a, b) <= 0;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b){   //increasing order.
    int char1 = 0, char2 = 0;
    int hsh1[26] = {0}, hsh2[26] = {0};
    int num_of_char1 = strlen(a);
    int num_of_char2 = strlen(b);

    for(int i = 0; i < num_of_char1; i++){
        hsh1[a[i] - 'a'] = 1;   
    }

    for(int i = 0; i < num_of_char2; i++){
        hsh2[b[i] - 'a'] = 1;   
    }

    for(int i = 0; i < 26; i++){
        if(hsh1[i])
            char1++;
        if(hsh2[i])
            char2++;
    }
    if( char1 != char2)
        return char1 > char2;
    else
        return strcmp(a, b)  > 0;

}

int sort_by_length(const char* a, const char* b){   //increasing order.
    if(strlen(a) != strlen(b))
        return strlen(a) > strlen(b);
    else
        return strcmp(a, b) >  0;
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    for(int i = 1; i < len; i++){
        int j = i;
        char* ptr = arr[i];
        
        while(j > 0){
            if((*cmp_func)(arr[j-1],ptr) > 0 )
                arr[j] = arr[j-1];
            else
                break;
            j--;
        }
        arr[j] = ptr;
        
    }
}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}