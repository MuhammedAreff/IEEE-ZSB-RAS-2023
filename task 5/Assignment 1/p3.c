#include <stdio.h>
#include <string.h>

int main() {
    char name[100];
    int max_length, i, j;
    int freq[100] = {0};
    int max_freq = 0;
    char most_repeated_char;

    printf("Enter the maximum length of your name:\n");
    scanf("%d", &max_length);

    printf("Enter your name (maximum %d characters):\n", max_length );
    scanf("%s", name);

    printf("Your name is: %s\n", name);

    // Calculate the frequency of each character in the name
    for(i = 0; i < strlen(name); i++) {
        for(j = i + 1; j < strlen(name); j++) {
            if(name[i] == name[j]) {
                freq[i]++;
            }
        }
    }

    // Find the character with the highest frequency
    for(i = 0; i < strlen(name); i++) {
        if(freq[i] > max_freq) {
            max_freq = freq[i];
            most_repeated_char = name[i];
        }
    }

    printf("The most repeated character in your name is '%c', which appears %d times.\n", most_repeated_char, max_freq + 1);

    return 0;
}
