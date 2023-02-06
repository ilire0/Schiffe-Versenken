#include <stdlib.h>
#include <stdio.h>
#define SIZE 10
char Spieler1[50], Spieler2[50];
int Fokus = 1;
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
    //Für die einzelnen Boote (irgendwie) -> Loop ?
    feldkoordinate();
    //Boote plazieren
    system("cls");
    createGrid(2);
    //Für die einzelnen Boote-Gegner (irgendwie)-> Loop ?
    feldkoordinate();
    //Spielphase beginnt hier (while loop)
    Schuss();
    /*
    * Gewinner wird ausgewählt .
    * Gewinner wird ausgegeben.
    * Verlierer wird gerickrolled.
    * Außer bei Einzelspieler
    */
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
    printf("Zeile angeben dann Spalte angeben: \n");
    scanf("%s", &koordinaten);
    koordinaten[0] = koordinaten[0] - 48;
    koordinaten[1] = koordinaten[1] - 65;
}

void createGrid(int player){
//ABC Koordinaten
	if(player == 1){
	printf("Spieler 1: %s\n",Spieler1);
	printf("\n");}
	if(player == 2){
	printf("Spieler 2: %s\n",Spieler2);
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
    if (Fokus == 1){
        printf("\n %s schiesst \n", &Spieler1);
        feldkoordinate();
        treffer1();
    } if (Fokus == 2){
        printf("\n %s schiesst \n", &Spieler2);
        feldkoordinate();
        treffer2();
    }
}

void treffer1()
{
    switch(SpielfeldSpieler2[koordinaten[0]][koordinaten[1]]){
        case 0: SpielfeldSpieler2[koordinaten[0]][koordinaten[1]] = 3; printf("Du hast nichts getroffen\n"); break;
        case 1: SpielfeldSpieler2[koordinaten[0]][koordinaten[1]] = 2; printf("Du hast getroffen!\n"); break;
        case 2: printf("Das Boot ist bereits getroffen\n"); Schuss(); break;
        case 3: printf("Hier hast du schonmal hingeschossen, hier ist nichts\n"); Schuss(); break;
    }
}

void treffer2()
{
    switch(SpielfeldSpieler1[koordinaten[0]][koordinaten[1]]){
        case 0: SpielfeldSpieler1[koordinaten[0]][koordinaten[1]] = 3; printf("Du hast nichts getroffen\n"); break;
        case 1: SpielfeldSpieler1[koordinaten[0]][koordinaten[1]] = 2; printf("Du hast getroffen!\n"); break;
        case 2: printf("Das Boot ist bereits getroffen\n"); Schuss(); break;
        case 3: printf("Hier hast du schonmal hingeschossen, hier ist nichts\n"); Schuss(); break;
    }
}
