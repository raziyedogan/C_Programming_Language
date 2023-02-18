#include <stdio.h>
#include <stdlib.h>


void putstr(char *s){
	int t;
	
	for(t=0; s[t]; t++)
		putchar(s[t]);
}

void _putstr(char *s){
	while(*s)
		putchar(*s++);
}

int main(){
	char str[]="the coffee";
	putstr(str);
	printf("\n");
	_putstr(str);
}
