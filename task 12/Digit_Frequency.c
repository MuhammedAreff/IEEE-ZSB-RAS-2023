#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */  

	  char s[100000];
	  int f[10] = {0}; 
	  int i, len;

	 
	  scanf("%s", s);

	  len = strlen(s);

	  for (i = 0; i < len; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
		  f[s[i] - '0']++;
		}
	  }
	 
	  for (i = 0; i < 10; i++) {
		printf("%d ", f[i]);
	  }

}


