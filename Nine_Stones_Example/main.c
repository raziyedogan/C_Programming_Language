#include <stdio.h>
#include <stdlib.h>

/*
Ýki boyutlu diziler çoðunlukla oyun tahtasý matrislerini canlandýrmak için kullanýlýr.

Bilgisayar çok basit bir oyun oynamaktadýr. Sýra bilgisayara geçince, bilgisayar boþ bir kare bulmak amacýyla matrisi taramak için get_computer_move() fonksiyonunu kullanýr.
Boþ bir kare bulunca, bilgisayar oraya bir o yerleþtirir. Bilgisayar, boþ bir konum bulamazsa oyunun berabere bittiðini rapor eder ve oyundan çýkar. get_player_move()
fonksiyonu, nereye bir x yerleþtirmek istediðinizi size sorar. Sol üst köþenin konumu 1,1; sað alt köþenin konumu 3,3'tür. 

Matris dizisine baþlangýçta boþluk içerecek þekilde ilk deðerler atanýr. Oyuncu ya da bilgisayar tarafýndan yapýlan her hamle, bir boþluðu x ya da o'ya çevirir. Bu sayede,
matris ekranda kolayca görüntülenir.

Ne zaman bir hamle yapýlsa, program check() fonksiyonunu çaðýrýr. Bu fonksiyon, henüz bir kazanan yoksa, bir boþluk döndürür; eðer siz kazanmýþsanýz, bir x ya da bilgisayar
kazanmýþ ise bir o döndürür. Fonksiyon, satýrlarý, sütunlarý ve köþegenleri tarar ve tümü x'lerden ya da o'lardan oluþan bir satýr, sütun ya da köþegen bulmaya çalýþýr.

disp_matrix() fonksiyonu oyunun mevcut durumunu görüntüler. 
*/

char matrix[3][3]; //dokuz taþ matrisi

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
		done = check(); //Kazandý mý diye bakýlýr.
		if(done != ' ') 
			break; //kazandý
		get_computer_move();
		done = check(); //kazandý mý diye bakýlýr.
	}while(done==' ');
	
	if(done == 'X')
		printf("You won!\n");
	else
		printf("I won!!!!\n");
	disp_matrix(); // en son konumlar gösterilir.
	
	return 0;
}

// Matris ilk kullanýma hazýrlanýr.
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

// Bilgisayarýn hamlesi okunur.
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

//Matris ekranda gösterilir.
void disp_matrix(){
	
	int t;
	
	for(t=0; t<3; t++){
		printf("%c | %c | %c ", matrix[t][0], matrix[t][1], matrix[t][2]);
		
		if(t!=2)
			printf("\n--|---|---\n");
	}
	
	printf("");
}

//Kazanan var mý diye bakýlýr.
char check(){
	int i;
	
	for(i=0;i<3;i++) //satýrlarý kontrol eder
	{
		if(matrix[i][0] == matrix[i][1] && matrix[i][0] == matrix[i][2])
			return matrix[i][0];
	}
	
	for(i=0;i<3;i++) //sütunlarý kontrol eder
	{
		if(matrix[0][i] == matrix[1][i] && matrix[0][i] == matrix[2][i])
			return matrix[0][i];
	}
	
	//Köþegenleri test eder
	if(matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2])
			return matrix[0][0];
			
	if(matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0])
			return matrix[0][2];
			
	return ' ';
}
