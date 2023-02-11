#include <stdio.h>
#include <stdlib.h>

// �ki boyutlu bir dizi, tek boyutlu dizilerden olu�an bir diziyi g�steren bir i�aret�iye indirgenebilir. Yani i�aret�i kullan�m�n�n kolay yollar�ndan biri, iki boyutlu
// bir dizinin bir sat�r�ndaki ��elere eri�mek i�in ayr� bir i�aret�i de�i�keni kullanmakt�r. Bu duruma dair bir uygulama, global tamsay� dizisi num'�n belirtilen sat�r�ndaki
// i�eri�i ekrana bast�ral�m.

/*
int num[2][2] = {{0,1},{2,3}};

void pr_row(int j){
	int *p, t;
	
	p = (int *) &num[j][0]; // j. sat�rdaki ilk �genin adresini okur.
	
	for(t=0; t<2; ++t)
		printf("%d ", *(p+t));
}

int main(){
	pr_row(1);
}
*/



// Yukar�daki i�lemleri genelle�tirelim.

void _pr_row(int j, int row_dimension, int *p){
	int t;
	p = p + (j*row_dimension);
	
	for(t=0; t<row_dimension; ++t)
		printf("%d ", *(p+t));
}

int main(){
	int num[2][2] = {{0,1},{2,3}};
	_pr_row(0,2,(int *)num);
}
