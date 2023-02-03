#include <stdlib.h>
#include <stdio.h>
#define SIZE 10
char Spieler1[50], Spieler2[50];
int SpielfeldSpieler[SIZE][SIZE];
int SpielfeldGegner[SIZE][SIZE];

void createGrid();
void Beginning();
void feldkoordinate();

int main(int argc, char **argv)
{
	for(int i = 0 ; i < SIZE;i++){
	for(int y = 0 ;	y < SIZE;y++){
		SpielfeldSpieler[i][y] = 0 ;
		SpielfeldGegner[i][y] = 0 ;
		}
	}
	

	return 0;
	return 0;
}

void Beginning()
{
    printf("Willkommen zu Schiffe versenken\nBitte Spielername eingeben:\nSpieler 1:");
    scanf("%s", &Spieler1);
    printf("Spieler2:");
    scanf("%s", &Spieler2);
    return;
}

void feldkoordinate()
{
    char koordinaten[2];
    printf("Spalte angeben dann Zeile angeben: \n");
    scanf("%s", &koordinaten);
    koordinaten[0] = koordinaten[0] - 65;
    koordinaten[1] = koordinaten[1] - 48;
    printf("Spalte %d, Zeile %d \n", koordinaten[0], koordinaten[1]);
}

void createGrid(){
	for(int i = 0 ; i < SIZE;i++){
		printf("-----------------------------------------\n");
		for(int y = 0 ;	y < SIZE;y++){
			switch(SpielfeldSpieler[i][y]) {
				case 0: 	printf("|   "); break;
				case 1:		printf("| O "); break;
				case 2:		printf("| X "); break;
				case 3:		printf("| ~ "); break;
			   default: 	printf("|   "); break;
				}
			}
		printf("|");
		printf("\n");
		}
		printf("-----------------------------------------");
	}

