#include <stdio.h>
#include <stdbool.h>

int lengthOfLongestSubstring(char *s) {


    int maxLen = 0;                      // max len of substring
    int start = 0;                       // starting index of substring
    int newIndex[128] = {0};            // new index of each char
    bool allSpaces = true;              // flag 

        if (s == NULL || s[0] == '\0') {   // check if the input str empty
        return 0;
    }
          
    for (int i = 0; s[i] != '\0'; i++) { // f its all spacess
        if (!isspace(s[i])) {          
            allSpaces = false;          
            break;
        }
    }

    if (allSpaces) {                    // f the input str contains only spaces
        return 1;                      
    }
    if (s[1] == '\0') {                 // check if the input str has only one character
        return 1;
    }
    if (s[2] == '\0'&& s[0]==s[1]) {                 
        return 1;
    }
        if (s[2] == '\0') {                 
        return 2;
    }

    for (int i = 0; s[i] != '\0'; i++) { // for loop 3ady
        if (newIndex[s[i]] >= start) {  // if the current char is repeated
            start = newIndex[s[i]] + 1; // update starting index of substring
        }
        newIndex[s[i]] = i;            // update last index of the new char
        int len = i - start + 1;         // calculate current substring len
        if (len > maxLen) {              // if current substring len > maxLen
            maxLen = len;                // update maxLen
        }
    }
  


    return maxLen;                     
}