#include <stdio.h>
#include <stdlib.h>

/* Bir diziye ilk deðer atama özelliðini kullanarak bir hata mesajlarý tablosu oluþturalým.

char e1[12] = "Read error\n";
char e2[13] = "Write error\n";
char e3[18] = "Cannot open file\n";

Doðru dizi boyutunu belirlemek için her mesajýn karakterlerini elle saymak yorucudur. Dizilerin boyutlarýný otomatik olarak hesaplama iþini derleyi yapabilmektedir.
Eðer bir diziye ilk deðer atama ifadesinde dizinin büyüklüðü belirtilmemiþse, derleyici otomatik olarak mevcut tüm ilk deðerleri tutabilecek büyüklükte bir dizi oluþturur.
Buna büyüklüðü belirsiz dizi denir.
*/

int main(){
	char e1[12] = "Read error\n";
	char e2[13] = "Write error\n";
	char e3[18] = "Cannot open file\n";
	
	printf("%s has length %d\n", e2, sizeof e2);
}


/* Bir dizinin büyüklüðü belirsiz býrakýlarak diziye ilk deðer atamak, daha az usandýrýcý olmasýnýn yaný sýra, yanlýþ dizi boyutu kullanma korkusu olmaksýzýn mesajlardan
herhangi birini deðiþtirmenizi mümkün kýlar.

Ayrýca belirsiz büyüklükteki dizilerin ilk kullanýma hazýrlanmasý tek boyutlu dizilerle sýnýrlý deðildir. Çok boyutlu diziler için en soldaki boyut hariç, tüm boyutlarý
belirtmelisiniz. Diðer boyutlar, derleyicinin diziyi doðru biçimde indekslemesine olanak vermek için gereklidir.
*/
