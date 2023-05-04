
#include <string.h>

#define MAX_LENGTH 100

int main() {
    char input[MAX_LENGTH];
    char unique[MAX_LENGTH];
    char stop_code[] = "!!";
    int i, j, is_unique;

    while(1) {
        printf("Enter a string (enter '!!' to stop):\n");
        scanf("%s", input);

        if(strcmp(input, stop_code) == 0) {
            break;
        }

        memset(unique, 0, sizeof(unique)); // initialize unique array to 0

        for(i = 0; i < strlen(input); i++) {
            is_unique = 1;
            for(j = 0; j < strlen(unique); j++) {
                if(input[i] == unique[j]) {
                    is_unique = 0;
                    break;
                }
            }
            if(is_unique) {
                unique[strlen(unique)] = input[i];
            }
        }

        printf("Unique characters: %s\n", unique);
    }

    return 0;
}