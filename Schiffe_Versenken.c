#include <stdlib.h>
#include <stdio.h>
#define SIZE 10
char Spieler1[50], Spieler2[50];

int SpielfeldSpieler1[SIZE][SIZE];
int SpielfeldSpieler2[SIZE][SIZE];
char koordinaten[2];

void createGrid(int player);
void Beginning();
void feldkoordinate();
void treffer();
void Schuss();

int main(int argc, char **argv){
   system("@ECHO off");
    for(int i = 0 ; i < SIZE;i++){
        for(int y = 0 ;	y < SIZE;y++){
            SpielfeldSpieler1[i][y] = 0 ;
            SpielfeldSpieler2[i][y] = 0 ;
        }
    }
    Beginning();
    createGrid(1);
    system("cls");
    createGrid(2);
    Schuss();

    return 0;
}

void Beginning()
{
    printf("Willkommen zu Schiffe versenken\nBitte Spielername eingeben:\nSpieler 1:");
    scanf("%s", Spieler1);
    system("cls");
    printf("Spieler2:");
    scanf("%s", Spieler2);
    return;
}

void feldkoordinate()
{
    printf("Spalte angeben dann Zeile angeben: \n");
    scanf("%s", &koordinaten);
    koordinaten[0] = koordinaten[0] - 65;
    koordinaten[1] = koordinaten[1] - 48;
}

void createGrid(int player){
//ABC Koordinaten
	if(player == 1){
	printf("Spieler 1: %s\n",Spieler1);
	printf("\n");}
	if(player == 2){
	printf("Spieler 1: %s\n",Spieler1);
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
						case 1:		printf("| O "); break; //BOOT
						case 2:		printf("| X "); break; //HIT
						case 3:		printf("| ~ "); break; //MISS
						default: 	printf("|   "); break;
					}
				}if(player == 2){
					switch(SpielfeldSpieler2[i][y]) {
						case 0: 	printf("|   "); break; //LEER
						case 1:		printf("| O "); break; //BOOT
						case 2:		printf("| X "); break; //HIT
						case 3:		printf("| ~ "); break; //MISS
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




void Schuss()
{
    printf("\n %s schiesst \n", &Spieler1);
    feldkoordinate();
    treffer();
}

void treffer()
{
    switch(SpielfeldSpieler[koordinaten[0]][koordinaten[1]]){
        case 0: SpielfeldSpieler[koordinaten[0]][koordinaten[1]] = 3; printf("Du hast nichts getroffen"); break;
        case 1: SpielfeldSpieler[koordinaten[0]][koordinaten[1]] = 2; printf("Du hast getroffen!"); break;
        case 2: printf("Das Boot ist bereits getroffen"); Schuss(); break;
        case 3: printf("Hier hast du schonmal hingeschossen, hier ist nichts"); Schuss(); break;
    }
}
