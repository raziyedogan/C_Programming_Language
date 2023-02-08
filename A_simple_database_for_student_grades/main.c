#include <stdio.h>
#include <stdlib.h>

#define CLASSES 3
#define GRADES 5

int grade[CLASSES][GRADES];

void enter_grades();	//This function is used to enter student grades.
int get_grade(int num); //This function is used to read a grade.
void show_grades(int g[][GRADES]); //This function is used to show grades. 

int main(){
	char ch, str[80];
	
	for(;;){
		
		do{
			printf("(E)nter grades\n");
			printf("(R)eport grades\n");
			printf("(Q)uit\n");
			gets(str);
			ch = toupper(*str);  //All letters have been converted to capital letters.
		}while(ch!='E' && ch!='R' && ch!='Q');
		
		switch(ch){
			case 'E':
				enter_grades();
				break;
			case 'R':
				show_grades(grade);
				break;
			case 'Q':
				exit(0);
		}
	}
	return 0;
}

void enter_grades(){
	int t,i;
	
	for(t=0; t<CLASSES; t++){
		printf("Class %d:\n",t+1);
		for(i=0; i<GRADES; i++){
			grade[t][i] = get_grade(i);
		}
	}
}

int get_grade(int num){
	char s[80];
	
	printf("Enter grade for student %d:\n", num+1);
	gets(s);
	return(atoi(s)); //The atoi() function converts a character string to an int value.
}

void show_grades(int g[][GRADES]){
	int t,i;
	
	for(t=0; t<CLASSES; t++){
		printf("Class %d:\n", t+1);
		for(i=0; i<GRADES; i++){
			printf("Student #%d is %d\n", i+1, g[t][i]);
		}
	}
}
