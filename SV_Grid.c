#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define SIZE 10
#define AC_BLUE "\x1b[34m"
#define AC_CYAN "\x1b[36m"
#define AC_RED "\x1b[31m"
#define AC_YELLOW "\x1b[33m"
#define AC_NORMAL "\x1b[m"

void Beginning();
void createGrid(int player);
int SpielfeldSpieler1[SIZE][SIZE];
int SpielfeldSpieler2[SIZE][SIZE];
char Spieler1[50];
char Spieler2[50];
char meme[] = "RickAstley";
int result;
int Spielmodus = 2 ;

int main(int argc, char **argv){
	system("@ECHO off");
	printf("\n");
	printf("\n");
	for(int i = 0 ; i < SIZE;i++){
	for(int y = 0 ;	y < SIZE;y++){
		SpielfeldSpieler1[i][y] = 0 ;
		SpielfeldSpieler2[i][y] = 0 ;
		}
	}
	
	SpielfeldSpieler1[0][0] = 1 ;
	SpielfeldSpieler1[0][1] = 1 ;
	SpielfeldSpieler1[0][2] = 1 ;
	
	
	//printf(" Willkommen zu Schiffe versenken\n\n Bitte Spielername eingeben:\n Spieler 1: ");
    //scanf("%s", Spieler1);
    //result = strcmp(Spieler1,meme);
    //if(result == 0){
	//system("start https://youtu.be/dQw4w9WgXcQ");
//}
	//printf(" Spieler 2: ");
    //scanf("%s", Spieler2);
    Beginning();
    system("cls");
	createGrid(1);
	system("pause");
	system("cls"); //CLEAR SCREEN FOR ENEMY GRID
	printf("\n");
	SpielfeldSpieler2[1][0] = 1 ;
	SpielfeldSpieler2[1][1] = 1 ;
	SpielfeldSpieler2[1][2] = 1 ;
	createGrid(2);
	printf("\n");
	printf("\n");

	return 0;
}
void Beginning()
{
    printf("Willkommen zu Schiffe versenken\nBitte einen Spielmodus waehlen\n");
    printf("1-Einzelspieler\n2-Mehrspieler\n>\n");
    scanf("%d", &Spielmodus);
    system("cls");
    printf("Bitte Spielername eingeben:\n\nSpieler 1:\n\n");
    scanf("%s", Spieler1);
    system("cls");
    if (Spielmodus ==2) {
		printf("Bitte Spielername eingeben:\n");
        printf("\nSpieler 2:\n\n");
        scanf("%s", Spieler2);
        system("cls");
    }
}

void createGrid(int player){
//ABC Koordinaten
	if(player == 1){
	printf("           Spieler 1: %s\n",Spieler1);
	printf("\n");}
	if(player == 2){
	printf("           Spieler 2: %s\n",Spieler2);
	printf("\n");}
	printf("           ");
	for(unsigned char a = 0 ; a < SIZE; a++){
			unsigned char wert = 65;
			wert = wert + a;
			printf("| %c ",wert);
		}
	printf("|\n");
	printf("           ");
	for(unsigned char a = 0 ; a < SIZE; a++){
			printf("----");
		}
	printf("-\n");
	printf("\n");
		
//123 Koordinaten
	int x = 0  ;
	for(int i = 0 ; i < SIZE;i++){
		printf("           ");
		for(unsigned char a = 0 ; a < SIZE; a++){
			printf("----");
		}
		printf("-\n");
		printf("| %d |      ",x);
		x++;
			for(int y = 0 ;	y < SIZE;y++){
				if(player == 1){
					switch(SpielfeldSpieler1[i][y]) {
						case 0: 	printf("|   "); break; //LEER
						case 1:		printf("| "); printf("%sO%s ",AC_BLUE,AC_NORMAL);break; //BOOT
						case 2:		printf("| "); printf("%sX%s ",AC_RED,AC_NORMAL);break; //HIT
						case 3:		printf("| "); printf("%s~%s ",AC_YELLOW,AC_NORMAL);break; //MISS
						default: 	printf("|   "); break;
					}
				}if(player == 2){
					switch(SpielfeldSpieler2[i][y]) {
						case 0: 	printf("|   "); break; //LEER
						case 1:		printf("| "); printf("%sO%s ",AC_CYAN,AC_NORMAL);break; //BOOT
						case 2:		printf("| "); printf("%sX%s ",AC_RED,AC_NORMAL);break; //HIT
						case 3:		printf("| "); printf("%s~%s ",AC_YELLOW,AC_NORMAL);break; //MISS
						default: 	printf("|   "); break;
					}
				 }	
			}
		printf("|\n");
	}
	printf("           ");
	for(unsigned char a = 0 ; a < SIZE; a++){
			printf("----");
		}
	printf("-\n");
	printf("\n");
}
