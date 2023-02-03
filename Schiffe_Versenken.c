#include <stdio.h>
#define SIZE 10
char Spieler1[50], Spieler2[50];
int SpielfeldSpieler[SIZE][SIZE];
int SpielfeldGegner[SIZE][SIZE];
char koordinaten[2];

void createGrid();
void Beginning();
void feldkoordinate();
void treffer();
void Schuss();

int main(int argc, char **argv)
{
    for(int i = 0 ; i < SIZE;i++){
        for(int y = 0 ;	y < SIZE;y++){
            SpielfeldSpieler[i][y] = 0 ;
            SpielfeldGegner[i][y] = 0 ;
        }
    }
    Beginning();
    createGrid();
    Schuss();

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
