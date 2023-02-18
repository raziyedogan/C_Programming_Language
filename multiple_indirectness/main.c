#include <stdio.h>
#include <stdlib.h>

int main(){
	int x, *p, **q;
	
	x=10;
	p=&x;
	q=&p;
	
	printf("x: %d\n", x);
	printf("p: %d\n", *p);
	printf("q: %d", **q);
}
