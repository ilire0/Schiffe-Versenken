#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define SIZE 10
#define AC_BLUE "\x1b[34m"
#define AC_CYAN "\x1b[36m"
#define AC_RED "\x1b[31m"
#define AC_YELLOW "\x1b[33m"
#define AC_NORMAL "\x1b[m"

//Globale Variablen
char Spieler1[50], Spieler2[50];
int SpielerPunkte1 = 0 ;
int SpielerPunkte2 = 0 ;
int Fokus = 1;
int SpielfeldSpieler1[SIZE][SIZE];
int SpielfeldSpieler2[SIZE][SIZE];
char koordinaten[2];
char winner = 0 ;
int Spielmodus ;

//Funktionen
void Beginning();
void createGrid(int player);
void createHitGrid(int player);
void twoPlayer();
void feldkoordinate();
void treffer();
void Schuss();
void placeShip1();
void placeShip2();
struct Boote{
    int Schlachtschiff;
    int Kreuzer;
    int Zerstoerer;
    int UBoot;
};
struct Boote BooteP1 = {1, 2, 3, 4};
struct Boote BooteP2 = {1, 2, 3, 4};

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
    Beginning();
    if(Spielmodus == 2){
	twoPlayer();
	printf("\n");
	system("pause");
	if(winner == 1){
	printf("\n%s Bitte gehen Sie vom Bildschirm weg , da der Verlierer %s seine Strafe erhält.",Spieler1,Spieler2);
	system("pause");
	}
	if(winner == 2){
	printf("\n%s Bitte gehen Sie vom Bildschirm weg , da der Verlierer %s seine Strafe erhält.",Spieler2,Spieler1);
	system("pause");
	}
	system("start https://youtu.be/dQw4w9WgXcQ");
	printf("\n");
    }
    return 0;
}

void Beginning(){
    printf(" Willkommen zu Schiffe versenken\n");
    printf("\n Jeder Spieler versteckt eine kleine Flotte von Schiffen vor seinem Gegner.\n Derjenige, der zuerst alle Schiffe des Gegners komplett getroffen und versenkt hat, gewinnt.\n");
    printf(" Jeder Treffer eines Schiffes wird mit 100 Punkten belohnt.\n Max. Punktzahl: 3000\n\n");
    printf(" Bitte waehlen Sie den Spielmodus aus:\n");
    printf(" 1-Einzelspieler\n 2-Mehrspieler\n\n>");
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
	printf("           Spieler 1: %s\n",Spieler1);
	printf("           Punkte: %d\n",SpielerPunkte1);
	printf("\n");}
	if(player == 2){
	printf("           Spieler 2: %s\n",Spieler2);
	printf("           Punkte: %d\n",SpielerPunkte2);
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

void createHitGrid(int player){
//ABC Koordinaten
	if(player == 1){
	printf("           Gegnerisches Feld: %s\n",Spieler1);
	printf("\n");}
	if(player == 2){
	printf("           Gegnerisches Feld: %s\n",Spieler2);
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
						case 2:		printf("| "); printf("%sX%s ",AC_RED,AC_NORMAL);break; //HIT
						case 3:		printf("| "); printf("%s~%s ",AC_YELLOW,AC_NORMAL);break; //MISS
						default: 	printf("|   "); break;
					}
				}if(player == 2){
					switch(SpielfeldSpieler2[i][y]) {
						case 0: 	printf("|   "); break; //LEER
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


void twoPlayer(){
	//-------------------------------------------
	//PLACE_BOAT PLAYER1&2
	//-------------------------------------------
	while(1){
	createGrid(1);
	createHitGrid(2);
	Schuss();
	fokus = 2 ; 
	if(SpielerPunkte1 == 3000){
		winner = 1 ;
		break;	
		}
	system("cls");
	createGrid(2);
	createHitGrid(1);
	Schuss();
	fokus = 1;
	if(SpielerPunkte2 == 3000){
		winner = 2 ;
		break;	
		}
	}
	switch(winner){
		case 1: system("cls");printf("Spieler 1: %s hat gewonnen !",Spieler1);break;
		case 2: system("cls");printf("Spieler 2: %s hat gewonnen !",Spieler2);break;
		default:system("cls");printf("Spieler Missing_NO: %s hat gewonnen !",meme);break;
		}
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
        case 1: SpielfeldSpieler2[koordinaten[0]][koordinaten[1]] = 2; printf("Du hast getroffen!\n");SpielerPunkte1 += 100; break;
        case 2: printf("Das Boot ist bereits getroffen\n"); Schuss(); break;
        case 3: printf("Hier hast du schonmal hingeschossen, hier ist nichts\n"); Schuss(); break;
    }
}

void treffer2()
{
    switch(SpielfeldSpieler1[koordinaten[0]][koordinaten[1]]){
        case 0: SpielfeldSpieler1[koordinaten[0]][koordinaten[1]] = 3; printf("Du hast nichts getroffen\n"); break;
        case 1: SpielfeldSpieler1[koordinaten[0]][koordinaten[1]] = 2; printf("Du hast getroffen!\n");SpielerPunkte2 += 100 break;
        case 2: printf("Das Boot ist bereits getroffen\n"); Schuss(); break;
        case 3: printf("Hier hast du schonmal hingeschossen, hier ist nichts\n"); Schuss(); break;
    }
}
void placeShip1(){
	while(1){
		
		char Startkoordinate[3];
		char Endkoordinate[3];
		int Speicher = 0;
		printf("Bitte Startkoordinate angeben:");
		scanf(" %s", Startkoordinate);
		printf("Bitte Endkoordinat angeben:");
		scanf(" %s", Endkoordinate);
		Startkoordinate[0] =Startkoordinate[0] - 48;
		Endkoordinate[0] =Endkoordinate[0] - 48;
		Startkoordinate[1] = Startkoordinate[1]-65;
		Endkoordinate[1] =Endkoordinate[1]- 65;
		x = x ;

		if (Startkoordinate[0]>SIZE || Startkoordinate[0]<0 || Startkoordinate[1]>SIZE || Startkoordinate[1]<0 ||Endkoordinate[0]>SIZE || Endkoordinate[0]<0 || Endkoordinate[1]>SIZE || Endkoordinate[1]<0 )
		{
			printf("\nBitte gueltige Werte eingeben");
		}

		if((Startkoordinate[0] != Endkoordinate[0]) && (Startkoordinate[1] == Endkoordinate[1])){
		
			Speicher = Startkoordinate[0] - Endkoordinate[0];  //4 - 6 = -2  3-0 = 3
			if ((Speicher*(-1)+1)>5){break;}
            		if (BooteP1.Schlachtschiff == 0){break;}
            		if (BooteP1.Kreuzer == 0){break;}
            		if (BooteP1.Zerstoerer == 0){break;}
            		if (BooteP1.UBoot == 0){break;}
            		switch((Speicher*(-1)+1)){
                		case 5: BooteP1.Schlachtschiff --;
                		case 4: BooteP1.Kreuzer --;
                		case 3: BooteP1.Zerstoerer --;
                		case 2: BooteP1.UBoot --;
            		}
			if(Speicher>0){ 
			
			//-------------------------------------Placement------------------------------------
					for(int i=0; i<=Speicher; i++ ){
						if(SpielfeldSpieler1[Startkoordinate[0]-i][Endkoordinate[1]] == 1){
						SpielfeldSpieler1[Startkoordinate[0]-i][Endkoordinate[1]] = 2;
						}else{ SpielfeldSpieler1[Startkoordinate[0]-i][Endkoordinate[1]] = 1;} // 3-i
					}
					break;
			}
			else{ 
				Speicher = Speicher * (-1); //3	
		//-------------------------------------Placement------------------------------------
				for(int i=0; i<=Speicher; i++ ){
					if(SpielfeldSpieler1[Endkoordinate[0]-i][Startkoordinate[1]] == 1){
						SpielfeldSpieler1[Endkoordinate[0]-i][Startkoordinate[1]] = 2; // 3-i
					}else{SpielfeldSpieler1[Endkoordinate[0]-i][Startkoordinate[1]] = 1;}
				}
				break;
				}
		}

		if((Startkoordinate[1] != Endkoordinate[1]) && (Startkoordinate[0] == Endkoordinate[0])) {
			Speicher = Startkoordinate[1] - Endkoordinate[1];  // 1A-1C -> 0 - 2 = -2  | 1C - 1A = 2 - 0 = 2
			if ((Speicher*(-1)+1)>5){break;}
            		if (BooteP1.Schlachtschiff == 0){break;}
            		if (BooteP1.Kreuzer == 0){break;}
            		if (BooteP1.Zerstoerer == 0){break;}
            		if (BooteP1.UBoot == 0){break;}
            		switch((Speicher*(-1)+1)){
                		case 5: BooteP1.Schlachtschiff --;
                		case 4: BooteP1.Kreuzer --;
                		case 3: BooteP1.Zerstoerer --;
                		case 2: BooteP1.UBoot --;
            		}
			if(Speicher>0){
		//-------------------------------------Placement------------------------------------
				for(int i=0; i<=Speicher; i++ ){
					if(SpielfeldSpieler1[Startkoordinate[0]][Startkoordinate[1]-i] == 1){
						SpielfeldSpieler1[Startkoordinate[0]][Startkoordinate[1]-i] = 2; // 3-i
					}else{SpielfeldSpieler1[Startkoordinate[0]][Startkoordinate[1]-i] = 1;} // [1] [2 -i]
				}
				break;
				}
		else{
			Speicher = Speicher * (-1); //2 
			if(Speicher>0){
		//-------------------------------------Placement------------------------------------
				for(int i=0; i<=Speicher; i++ ){
					if(SpielfeldSpieler1[Startkoordinate[0]][Endkoordinate[1]-i] == 1){
						SpielfeldSpieler1[Startkoordinate[0]][Endkoordinate[1]-i] = 2; // 3-i
				}else{SpielfeldSpieler1[Startkoordinate[0]][Endkoordinate[1]-i] = 1;}					
				
			}break;
		}
	}
		}else{system("cls");
			printf("Diagonalen sind nicht erlaubt!\n\n");
		}
		
	}
	if(x == 1){
		x = 0 ;
		system("cls");
		placeShip1();
	}
}

void placeShip2(){
	while(1){
		
		char Startkoordinate[3];
		char Endkoordinate[3];
		int Speicher = 0;
		printf("Bitte Startkoordinate angeben:");
		scanf(" %s", Startkoordinate);
		printf("Bitte Endkoordinat angeben:");
		scanf(" %s", Endkoordinate);
		Startkoordinate[0] =Startkoordinate[0] - 48;
		Endkoordinate[0] =Endkoordinate[0] - 48;
		Startkoordinate[1] = Startkoordinate[1]-65;
		Endkoordinate[1] =Endkoordinate[1]- 65;
		x = x ;

		if (Startkoordinate[0]>SIZE || Startkoordinate[0]<0 || Startkoordinate[1]>SIZE || Startkoordinate[1]<0 ||Endkoordinate[0]>SIZE || Endkoordinate[0]<0 || Endkoordinate[1]>SIZE || Endkoordinate[1]<0 )
		{
			printf("\nBitte gueltige Werte eingeben");
		}

		if((Startkoordinate[0] != Endkoordinate[0]) && (Startkoordinate[1] == Endkoordinate[1])){
		
			Speicher = Startkoordinate[0] - Endkoordinate[0];  //4 - 6 = -2  3-0 = 3
			if ((Speicher*(-1)+1)>5){break;}
            		if (BooteP2.Schlachtschiff == 0){break;}
            		if (BooteP2.Kreuzer == 0){break;}
            		if (BooteP2.Zerstoerer == 0){break;}
            		if (BooteP2.UBoot == 0){break;}
            		switch((Speicher*(-1)+1)){
                		case 5: BooteP2.Schlachtschiff --;
                		case 4: BooteP2.Kreuzer --;
                		case 3: BooteP2.Zerstoerer --;
                		case 2: BooteP2.UBoot --;
            		}
			if(Speicher>0){ 
			
			//-------------------------------------Placement------------------------------------
					for(int i=0; i<=Speicher; i++ ){
						if(SpielfeldSpieler2[Startkoordinate[0]-i][Endkoordinate[1]] == 1){
						SpielfeldSpieler2[Startkoordinate[0]-i][Endkoordinate[1]] = 2;
						}else{ SpielfeldSpieler2[Startkoordinate[0]-i][Endkoordinate[1]] = 1;} // 3-i
					}
					break;
			}
			else{ 
				Speicher = Speicher * (-1); //3	
		//-------------------------------------Placement------------------------------------
				for(int i=0; i<=Speicher; i++ ){
					if(SpielfeldSpieler2[Endkoordinate[0]-i][Startkoordinate[1]] == 1){
						SpielfeldSpieler2[Endkoordinate[0]-i][Startkoordinate[1]] = 2; // 3-i
					}else{SpielfeldSpieler2[Endkoordinate[0]-i][Startkoordinate[1]] = 1;}
				}
				break;
				}
		}

		if((Startkoordinate[1] != Endkoordinate[1]) && (Startkoordinate[0] == Endkoordinate[0])) {
			Speicher = Startkoordinate[1] - Endkoordinate[1];  // 1A-1C -> 0 - 2 = -2  | 1C - 1A = 2 - 0 = 2
			if ((Speicher*(-1)+1)>5){break;}
            		if (BooteP2.Schlachtschiff == 0){break;}
            		if (BooteP2.Kreuzer == 0){break;}
            		if (BooteP2.Zerstoerer == 0){break;}
            		if (BooteP2.UBoot == 0){break;}
            		switch((Speicher*(-1)+1)){
                		case 5: BooteP2.Schlachtschiff --;
                		case 4: BooteP2.Kreuzer --;
                		case 3: BooteP2.Zerstoerer --;
                		case 2: BooteP2.UBoot --;
            		}
			if(Speicher>0){
		//-------------------------------------Placement------------------------------------
				for(int i=0; i<=Speicher; i++ ){
					if(SpielfeldSpieler2[Startkoordinate[0]][Startkoordinate[1]-i] == 1){
						SpielfeldSpieler2[Startkoordinate[0]][Startkoordinate[1]-i] = 2; // 3-i
					}else{SpielfeldSpieler2[Startkoordinate[0]][Startkoordinate[1]-i] = 1;} // [1] [2 -i]
				}
				break;
				}
		else{
			Speicher = Speicher * (-1); //2 
			if(Speicher>0){
		//-------------------------------------Placement------------------------------------
				for(int i=0; i<=Speicher; i++ ){
					if(SpielfeldSpieler2[Startkoordinate[0]][Endkoordinate[1]-i] == 1){
						SpielfeldSpieler2[Startkoordinate[0]][Endkoordinate[1]-i] = 2; // 3-i
				}else{SpielfeldSpieler2[Startkoordinate[0]][Endkoordinate[1]-i] = 1;}					
				
			}break;
		}
	}
		}else{system("cls");
			printf("Diagonalen sind nicht erlaubt!\n\n");
		}
		
	
	if(x == 1){
		x = 0 ;
		system("cls");
		placeShip1();
	}
}
}
	
