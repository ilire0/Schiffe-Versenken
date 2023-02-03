#include <stdlib.h>
#include <stdio.h>
#define SIZE 10

void createGrid();
int SpielfeldSpieler[SIZE][SIZE];
int SpielfeldGegner[SIZE][SIZE];

int main(int argc, char **argv)
{
	printf("\n");
	printf("\n");
	for(int i = 0 ; i < SIZE;i++){
	for(int y = 0 ;	y < SIZE;y++){
		SpielfeldSpieler[i][y] = 0 ;
		SpielfeldGegner[i][y] = 0 ;
		}
	}
	createGrid();
	
	return 0;
}

void createGrid(){
//ABC Koordinaten
	printf("           ");
	for(unsigned char a = 0 ; a < SIZE; a++){
			unsigned char wert = 65;
			wert = wert + a;
			printf("| %c ",wert);
		}
	printf("|\n");
	printf("           -----------------------------------------\n");
	printf("\n");
		
//123 Koordinaten & Feldanzeige
	int x = 0  ;
	for(int i = 0 ; i < SIZE;i++){
		printf("           -----------------------------------------\n");
		printf("| %d |      ",x);
		x++;
			for(int y = 0 ;	y < SIZE;y++){
				switch(SpielfeldSpieler[i][y]) {
					case 0: 	printf("|   "); break;
					case 1:		printf("| O "); break;
					case 2:		printf("| X "); break;
					case 3:		printf("| ~ "); break;
					default: 	printf("|   "); break;
				}
			}
		printf("|\n");
	}
	printf("           -----------------------------------------\n");
	printf("\n");
	}
