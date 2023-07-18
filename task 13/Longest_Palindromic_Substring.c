
#include <stdio.h>
#include <string.h>

char * longestPalindrome(char * s) {
    int n = strlen(s);
    if (n == 0) return "";  // empty str
    int start = 0, end = 0;  // start and end indices of longest palindrome
    int maxlen = 0;          // len of longest palindrome
    for (int i = 0; i < n; i++) {
        // check for pattern with single char in mid
        int len1 = expandAroundCenter(s, i, i);
        // check for palindromes with adjacent char in mid
        int len2 = expandAroundCenter(s, i, i+1);
        int len = len1 > len2 ? len1 : len2;
        if (len > maxlen)
         {
            maxlen = len;
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }
    char* res = (char*) malloc((maxlen + 1) * sizeof(char));  // allocate memory for res
    strncpy(res, s + start, maxlen);  // copy the longest palindrome into the res
    res[maxlen] = '\0';  
    return res;
}

// fun to expande around mid and and find the length of the longest pattern
int expandAroundCenter(char* s, int left, int right) {
    int n = strlen(s);
    while (left >= 0 && right < n && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1;
}
