#include <stdio.h>
#include <stdlib.h>

/*
�ki boyutlu diziler �o�unlukla oyun tahtas� matrislerini canland�rmak i�in kullan�l�r.

Bilgisayar �ok basit bir oyun oynamaktad�r. S�ra bilgisayara ge�ince, bilgisayar bo� bir kare bulmak amac�yla matrisi taramak i�in get_computer_move() fonksiyonunu kullan�r.
Bo� bir kare bulunca, bilgisayar oraya bir o yerle�tirir. Bilgisayar, bo� bir konum bulamazsa oyunun berabere bitti�ini rapor eder ve oyundan ��kar. get_player_move()
fonksiyonu, nereye bir x yerle�tirmek istedi�inizi size sorar. Sol �st k��enin konumu 1,1; sa� alt k��enin konumu 3,3't�r. 

Matris dizisine ba�lang��ta bo�luk i�erecek �ekilde ilk de�erler atan�r. Oyuncu ya da bilgisayar taraf�ndan yap�lan her hamle, bir bo�lu�u x ya da o'ya �evirir. Bu sayede,
matris ekranda kolayca g�r�nt�lenir.

Ne zaman bir hamle yap�lsa, program check() fonksiyonunu �a��r�r. Bu fonksiyon, hen�z bir kazanan yoksa, bir bo�luk d�nd�r�r; e�er siz kazanm��san�z, bir x ya da bilgisayar
kazanm�� ise bir o d�nd�r�r. Fonksiyon, sat�rlar�, s�tunlar� ve k��egenleri tarar ve t�m� x'lerden ya da o'lardan olu�an bir sat�r, s�tun ya da k��egen bulmaya �al���r.

disp_matrix() fonksiyonu oyunun mevcut durumunu g�r�nt�ler. 
*/

char matrix[3][3]; //dokuz ta� matrisi

char check();
void init_matrix();
void get_player_move();
void get_computer_move();
void disp_matrix();

int main(){
	
	char done = ' ';
	
	printf("Let's start playing!\n");
	
	init_matrix();
	
	do{
		disp_matrix();
		get_player_move();
		done = check(); //Kazand� m� diye bak�l�r.
		if(done != ' ') 
			break; //kazand�
		get_computer_move();
		done = check(); //kazand� m� diye bak�l�r.
	}while(done==' ');
	
	if(done == 'X')
		printf("You won!\n");
	else
		printf("I won!!!!\n");
	disp_matrix(); // en son konumlar g�sterilir.
	
	return 0;
}

// Matris ilk kullan�ma haz�rlan�r.
void init_matrix(){
	
	int i,j;
	
	for(i=0; i<3; i++){
		for(j=0; j<3; j++)
			matrix[i][j] = ' ';
	}
}

// Oyuncunun hamlesi okunur.
void get_player_move(){
	
	int x,y;
	
	printf("Enter X, Y coordinates for your move: ");
	scanf("%d%*c%d", &x, &y);
	
	x--;
	y--;
	
	if(matrix[x][y] != ' '){
		printf("Invalid move, try again.\n");
		get_player_move();
	}
	else 
		matrix[x][y] = 'X';
}

// Bilgisayar�n hamlesi okunur.
void get_computer_move(){
	
	int i,j;
	for(i=0; i<3; i++){
		for(j=0; j<3; j++)
			if(matrix[i][j] == ' ')
				break;
		if(matrix[i][j] == ' ')
			break;
	}
	
	if(i*j == 9){
		printf("draw\n");
		exit(0);
	}
	else 
		matrix[i][j] = 'o';
}

//Matris ekranda g�sterilir.
void disp_matrix(){
	
	int t;
	
	for(t=0; t<3; t++){
		printf("%c | %c | %c ", matrix[t][0], matrix[t][1], matrix[t][2]);
		
		if(t!=2)
			printf("\n--|---|---\n");
	}
	
	printf("");
}

//Kazanan var m� diye bak�l�r.
char check(){
	int i;
	
	for(i=0;i<3;i++) //sat�rlar� kontrol eder
	{
		if(matrix[i][0] == matrix[i][1] && matrix[i][0] == matrix[i][2])
			return matrix[i][0];
	}
	
	for(i=0;i<3;i++) //s�tunlar� kontrol eder
	{
		if(matrix[0][i] == matrix[1][i] && matrix[0][i] == matrix[2][i])
			return matrix[0][i];
	}
	
	//K��egenleri test eder
	if(matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2])
			return matrix[0][0];
			
	if(matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0])
			return matrix[0][2];
			
	return ' ';
}
