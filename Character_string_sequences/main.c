#include <stdio.h>
#include <stdlib.h>

// This program reads lines of text until a blank line is entered. It then displays each line character by character.

# define MAX 100
# define LEN 80

char text[MAX][LEN]; //An array of 100 character strings, each up to 79 characters long.

int main(){
	register int t,i,j;
	printf("Enter an empty line to quit.\n");
	
	for(t=0; t<MAX; t++){
		printf("%d: ",t);
		gets(text[t]);
		if(!*text[t]) break; // Exit on the blank line.
	}
	
	for(i=0; i<t; i++){
		for(j=0; text[i][j]; j++){
			putchar(text[i][j]);
		}
		putchar('\n');
	}
	
	return 0;
}


