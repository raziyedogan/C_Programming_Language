#include <stdio.h>
#include <stdlib.h>

void display_array(int *g[]){
	int i;
	
	for(i=0; i<4; i++){
		printf("%d ", *g[i]);
	}
}

int main(){
	int *x[4];
	
	int value1=1;
	int value2=2;
	int value3=3;
	int value4=4;
	
	x[0] = &value1;
	x[1] = &value2;
	x[2] = &value3;
	x[3] = &value4;
	
	display_array(x);
}
