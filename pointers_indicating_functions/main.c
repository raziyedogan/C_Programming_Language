#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Bir fonksiyonun adresini, fonksiyonun adýný parantezsiz ya da argümansýz olarak kullanarak elde edersiniz. ( Bu, bir dizinin adresini yalnýzca dizi adýný, indekssiz
//olarak, kullanarak elde etmeye benzer.) Bunun nasýl yapýldýðýný görmek için aþaðýdaki programý inceleyin. Program, kullanýcý tarafýndan girilen iki karakter katarýný 
//karþýlaþtýrýr. check() fonksiyonunun deklarasyonuna ve fonksiyon iþaretçisi p'nin main() içindeki deklarasyonuna çok dikkat edin.

void check(char *a, char *b, int (*cmp)(const char *, const char *));

int main(){
	char s1[80], s2[80];
	int (*p)(const char *, const char *); //fonksyion iþaretçisi
	
	p = strcmp; //strcmp'nin adresini p'ye ata
	
	printf("Enter two strings\n");
	gets(s1);
	gets(s2);
	
	check(s1,s2,p); ////strcmp'nin adresini p aracalýðýyla aktarýr
	
	return 0;
}

void check(char *a, char *b, int (*cmp)(const char *, const char *)){
	printf("Testing for equality\n");
	if(!(*cmp)(a,b))
		printf("Equal");
	else
		printf("Not equal");
}
