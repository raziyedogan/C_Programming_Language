#include <stdio.h>
#include <stdlib.h>

/* Bir diziye ilk de�er atama �zelli�ini kullanarak bir hata mesajlar� tablosu olu�tural�m.

char e1[12] = "Read error\n";
char e2[13] = "Write error\n";
char e3[18] = "Cannot open file\n";

Do�ru dizi boyutunu belirlemek i�in her mesaj�n karakterlerini elle saymak yorucudur. Dizilerin boyutlar�n� otomatik olarak hesaplama i�ini derleyi yapabilmektedir.
E�er bir diziye ilk de�er atama ifadesinde dizinin b�y�kl��� belirtilmemi�se, derleyici otomatik olarak mevcut t�m ilk de�erleri tutabilecek b�y�kl�kte bir dizi olu�turur.
Buna b�y�kl��� belirsiz dizi denir.
*/

int main(){
	char e1[12] = "Read error\n";
	char e2[13] = "Write error\n";
	char e3[18] = "Cannot open file\n";
	
	printf("%s has length %d\n", e2, sizeof e2);
}


/* Bir dizinin b�y�kl��� belirsiz b�rak�larak diziye ilk de�er atamak, daha az usand�r�c� olmas�n�n yan� s�ra, yanl�� dizi boyutu kullanma korkusu olmaks�z�n mesajlardan
herhangi birini de�i�tirmenizi m�mk�n k�lar.

Ayr�ca belirsiz b�y�kl�kteki dizilerin ilk kullan�ma haz�rlanmas� tek boyutlu dizilerle s�n�rl� de�ildir. �ok boyutlu diziler i�in en soldaki boyut hari�, t�m boyutlar�
belirtmelisiniz. Di�er boyutlar, derleyicinin diziyi do�ru bi�imde indekslemesine olanak vermek i�in gereklidir.
*/
