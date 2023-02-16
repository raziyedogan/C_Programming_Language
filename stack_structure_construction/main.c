#include <stdio.h>
#include <stdlib.h>

//Bu program ile yap�lan, kullan�c� taraf�ndan girilen de�erler stack yap�s�na yerle�tirilir. 0 girilmesi durumunda y���ndan bir de�er ��kart�l�r. Program� durdurmak
//i�in -1 girilmesi gerekmektedir.

#define SIZE 50

void push(int i);
int pop();

int *tos, *p1, stack[SIZE];

int main(){
	
	int value;
	
	tos = stack;  //tos, stack'in tepesine i�aret eder.
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
