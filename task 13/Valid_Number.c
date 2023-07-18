#include <stdbool.h>
#include <ctype.h>

bool isNumber(char *s) {
    int i = 0;
    bool hasSign = false;
    bool hasDecimal = false;
    bool hasDigit = false;
    bool hasExponent = false;

    
    while (isspace(s[i])) {
        i++;
    }

    
    if (s[i] == '+' || s[i] == '-') {
        hasSign = true;
        i++;
    }

    
    while (isdigit(s[i]) || s[i] == '.') {
        if (isdigit(s[i])) {
            hasDigit = true;
        } else if (s[i] == '.') {
            if (hasDecimal || hasExponent) {
                
                return false;
            }
            hasDecimal = true;
        }
        i++;
    }

    
    if (s[i] == 'e' || s[i] == 'E') {
        if (!hasDigit) {
            
            return false;
        }
        hasExponent = true;
        hasDigit = false;
        hasSign = false;
        i++;
        if (s[i] == '+' || s[i] == '-') {
            hasSign = true;
            i++;
        }
        while (isdigit(s[i])) {
            hasDigit = true;
            i++;
        }
    }

    
    while (isspace(s[i])) {
        i++;
    }

    
    return (s[i] == '\0') && hasDigit;
}