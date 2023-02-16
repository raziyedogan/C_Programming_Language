#include <stdio.h>
#include <stdlib.h>

//Bu program ile yapýlan, kullanýcý tarafýndan girilen deðerler stack yapýsýna yerleþtirilir. 0 girilmesi durumunda yýðýndan bir deðer çýkartýlýr. Programý durdurmak
//için -1 girilmesi gerekmektedir.

#define SIZE 50

void push(int i);
int pop();

int *tos, *p1, stack[SIZE];

int main(){
	
	int value;
	
	tos = stack;  //tos, stack'in tepesine iþaret eder.
	p1 = stack;
	
	do{
		printf("Enter value: ");
		scanf("%d", &value);
		
		if(value != 0)
			push(value);
		else
			printf("value on top is %d\n", pop());
	}while(value != -1);
	
	return 0;
}

void push(int i){
	
	p1++;
	if(p1 == (tos+SIZE)){
		printf("Stack Overflow.\n");
		exit(1);
	}
	*p1=i;
}

int pop(){
	
	if(p1 == tos){
		printf("Stack underflow.\n");
		exit(1);
	}
	p1--;
	return *(p1+1);
}
