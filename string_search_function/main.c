#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int search(char *p[], char *name);

char *names[] = {
	"Herb",
	"Rex",
	"Dennis",
	"John",
	NULL}; // null iþaretçi sabiti listeyi sonlandýrýr.
	
int main(){
	
	if(search(names, "Dennis") != -1)
		printf("Dennis is in list.\n");
		
	if(search(names, "Bill") == -1)
		printf("Bill not found.\n");
		
	return 0;
}

int search(char *p[], char *name){
	int i, cnt=0;
	
	for(i=0; p[i]; i++){
		if(!strcmp(p[i], name))
			return i;
		else	
			cnt++;
		
		if(cnt==4)
			return -1; //bulunamadi
	}
}
