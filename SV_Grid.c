#include <stdlib.h>
#include <stdio.h>
#define SIZE 10

void createGrid();
int SpielfeldSpieler[SIZE][SIZE];
int SpielfeldGegner[SIZE][SIZE];

int main(int argc, char **argv)
{
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
