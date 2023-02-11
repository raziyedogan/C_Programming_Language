#include <stdio.h>
#include <stdlib.h>

// Ýki boyutlu bir dizi, tek boyutlu dizilerden oluþan bir diziyi gösteren bir iþaretçiye indirgenebilir. Yani iþaretçi kullanýmýnýn kolay yollarýndan biri, iki boyutlu
// bir dizinin bir satýrýndaki öðelere eriþmek için ayrý bir iþaretçi deðiþkeni kullanmaktýr. Bu duruma dair bir uygulama, global tamsayý dizisi num'ýn belirtilen satýrýndaki
// içeriði ekrana bastýralým.

/*
int num[2][2] = {{0,1},{2,3}};

void pr_row(int j){
	int *p, t;
	
	p = (int *) &num[j][0]; // j. satýrdaki ilk ögenin adresini okur.
	
	for(t=0; t<2; ++t)
		printf("%d ", *(p+t));
}

int main(){
	pr_row(1);
}
*/



// Yukarýdaki iþlemleri genelleþtirelim.

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
