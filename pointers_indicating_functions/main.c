#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Bir fonksiyonun adresini, fonksiyonun ad�n� parantezsiz ya da arg�mans�z olarak kullanarak elde edersiniz. ( Bu, bir dizinin adresini yaln�zca dizi ad�n�, indekssiz
//olarak, kullanarak elde etmeye benzer.) Bunun nas�l yap�ld���n� g�rmek i�in a�a��daki program� inceleyin. Program, kullan�c� taraf�ndan girilen iki karakter katar�n� 
//kar��la�t�r�r. check() fonksiyonunun deklarasyonuna ve fonksiyon i�aret�isi p'nin main() i�indeki deklarasyonuna �ok dikkat edin.

void check(char *a, char *b, int (*cmp)(const char *, const char *));

int main(){
	char s1[80], s2[80];
	int (*p)(const char *, const char *); //fonksyion i�aret�isi
	
	p = strcmp; //strcmp'nin adresini p'ye ata
	
	printf("Enter two strings\n");
	gets(s1);
	gets(s2);
	
	check(s1,s2,p); ////strcmp'nin adresini p aracal���yla aktar�r
	
	return 0;
}

void check(char *a, char *b, int (*cmp)(const char *, const char *)){
	printf("Testing for equality\n");
	if(!(*cmp)(a,b))
		printf("Equal");
	else
		printf("Not equal");
}
