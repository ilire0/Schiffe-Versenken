#include <stdlib.h>
#include <conio.h>  
#include <time.h>
#include <stdio.h>
#include <string.h>
#define SIZE 10
#define AC_BLUE "\x1b[34m"
#define AC_CYAN "\x1b[36m"
#define AC_RED "\x1b[31m"
#define AC_YELLOW "\x1b[33m"
#define AC_NORMAL "\x1b[m"

//Globale Variablen
time_t t1,t2;
int botMemory[4][3];
char RandomNumbers[100];
char inputCorrect=1;
int saveloop = 0 ;
unsigned char Action[3];
unsigned char KWW; //Koordinatenwert Waagerecht
unsigned char KWS; //Koordinatenwert Senkrecht
char Spieler1[50], Spieler2[50];
char Bot[50] ="DITBOT";
int SpielerPunkte1 = 0 ;
int SpielerPunkte2 = 0 ;
int Fokus = 1;
int HitValue = 0;
unsigned char randomness = 0;
int SpielfeldSpieler1[SIZE][SIZE];
int SpielfeldSpieler2[SIZE][SIZE];
char koordinaten[2];
char winner = 0 ;
int Spielmodus ;
char meme[] = "Missing_NO";
int x = 0 ;
struct Boote{
    int Schlachtschiff ;
    int Kreuzer;
    int Zerstoerer;
    int UBoot;
};
struct Boote BooteP1 = {1, 2, 3, 4};
struct Boote BooteP2 = {1, 2, 3, 4};


//Funktionen
void Beginning();
void createGrid(int player);
void createHitGrid(int player);
void twoPlayer();
void singlePlayer();
void feldkoordinate();
void treffer1();
void treffer2();
void Schuss();
void placeShip1();
void placeShip2();
void placeShipBOT();
void Attack();
void BotSchuss();
void BFeldkoordinate();

int main(int argc, char **argv){
   system("@ECHO off");
   system("cls");
	printf("\n");
	printf("\n");
    for(int i = 0 ; i < SIZE;i++){
        for(int y = 0 ;	y < SIZE;y++){
            SpielfeldSpieler1[i][y] = 0 ;
            SpielfeldSpieler2[i][y] = 0 ;

        }
    }
    for(int v = 0 ; v < 4 ; v++){
    for(int y = 0 ; y < 3;y++){
            botMemory[v][y] = 0 ;
        }
    }
    Beginning();
    if(Spielmodus == 2){
	twoPlayer();
	printf("\n");
	system("pause");
	if(winner == 1){
	printf("\n\n%s , Sie haben dieses Spiel gewonnen und den Lob des Programms verdient . Für %s , ich wuensch ihnen viel Glueck beim naechsten mal.",Spieler1,Spieler2);
	system("pause");
	}
	if(winner == 2){
	printf("\n\n%s , Sie haben dieses Spiel gewonnen und den Lob des Programms verdient . Für %s , ich wuensch ihnen viel Glueck beim naechsten mal.",Spieler2,Spieler1);
	system("pause");
	}
	
	printf("\n");
    }
    if(Spielmodus == 1){
		singlePlayer();
		printf("\n");
	system("pause");
	if(winner == 1){
	printf("\n\n%s Herzlichen Glueckwunsch ! %s gibt sich geschlagen.",Spieler1,Bot);
	printf("\nDamit ist das Spiel beendet . Ich wuensche noch einen guten Tag.");
	system("pause");
	}
	if(winner == 2){
	printf("\n\n%s hat sein Wissen bewiesen und damit wird der Verlierer %s bestraft. Tut mir leid für dich ^-^",Bot,Spieler1);
	system("start https://youtu.be/dQw4w9WgXcQ");
	printf("\n");
	system("pause");
	}
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
    if(Spielmodus ==1) {
		printf(" DITBOT nimmt ihre Herausforderung an. \n");
		system("pause");
		system("cls");
	}
}

void feldkoordinate()
{	
	while(1){
    printf("Zeile angeben dann Spalte angeben: \n");
    scanf("%s", &koordinaten);
    koordinaten[0] = koordinaten[0] - 48;
    koordinaten[1] = koordinaten[1] - 65;
    if (koordinaten[0]>SIZE || koordinaten[0]<0 || koordinaten[1]>SIZE || koordinaten[1]<0 )
		{  inputCorrect = 0;break;}
		break;
	}
}

void createGrid(int player){
//ABC Koordinaten
	if(player == 1){
	printf("           Spieler 1: %s\n",Spieler1);
	printf("           Punkte: %d\n",SpielerPunkte1);
	if(Spielmodus == 1){
	printf("           Gegnerische Punkte: %d\n",SpielerPunkte2);
}
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
						case 3:		printf("| "); printf("%s#%s ",AC_YELLOW,AC_NORMAL);break; //MISS
						default: 	printf("|   "); break;
					}
				}if(player == 2){
					switch(SpielfeldSpieler2[i][y]) {
						case 0: 	printf("|   "); break; //LEER
						case 1:		printf("| "); printf("%sO%s ",AC_CYAN,AC_NORMAL);break; //BOOT
						case 2:		printf("| "); printf("%sX%s ",AC_RED,AC_NORMAL);break; //HIT
						case 3:		printf("| "); printf("%s#%s ",AC_YELLOW,AC_NORMAL);break; //MISS
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
						case 3:		printf("| "); printf("%s#%s ",AC_YELLOW,AC_NORMAL);break; //MISS
						default: 	printf("|   "); break;
					}
				}if(player == 2){
					switch(SpielfeldSpieler2[i][y]) {
						case 0: 	printf("|   "); break; //LEER
						case 2:		printf("| "); printf("%sX%s ",AC_RED,AC_NORMAL);break; //HIT
						case 3:		printf("| "); printf("%s#%s ",AC_YELLOW,AC_NORMAL);break; //MISS
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
	for(int i = 0 ; i <= 9 ; i++){
	createGrid(1);
	placeShip1();
	system("cls");
}
	for(int i = 0 ; i <= 9 ; i++){
	createGrid(2);
	placeShip2();
	system("cls");
}
	//-------------------------------------------
	while(1){
	system("cls");
	system("pause");
	createGrid(1);
	createHitGrid(2);
	Schuss();
	system("pause");
	Fokus = 2 ; 
	if(SpielerPunkte1 == 3000){
		winner = 1 ;
		break;	
		}
	system("cls");
	system("pause");
	createGrid(2);
	createHitGrid(1);
	Schuss();
	system("pause");
	Fokus = 1;
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

void singlePlayer(){
	for(int i = 0 ; i <= 9 ; i++){
	createGrid(1);
	placeShip1();
	system("cls");
}
//DITBot Legt seine Boote-------------------------------------------------
	placeShipBOT();
	printf("\n DITBot hat seine Schiffe platziert. \n\n");
	
//-----------------------------------------------------------------------
	while(1){
	system("cls");
	system("pause");
	createGrid(1);
	createHitGrid(2);
	Schuss();
	system("pause");
	Fokus = 2 ; 
	if(SpielerPunkte1 == 3000){
		winner = 1 ;
		break;	
		}
	system("cls");
	printf("Spieler 2: %s ist an der Reihe",Bot);
	printf("Punkte: %d\n",SpielerPunkte2);
	Attack();
	createHitGrid(1);
	system("pause");
	Fokus = 1;
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
	while(1){
	inputCorrect = 1;
    if (Fokus == 1){
        printf("\n %s schiesst \n", &Spieler1);
        feldkoordinate();
       if(inputCorrect ==0){printf("\n Falsche Eingabe , versuchs nochmal. \n");Schuss();break;}else{
		inputCorrect = 1;
        treffer1();
        break;
	}
	}
     if (Fokus == 2){
        printf("\n %s schiesst \n", &Spieler2);
        feldkoordinate();
        if(inputCorrect ==0){printf("\n Falsche Eingabe , versuchs nochmal. \n");Schuss();break;}else{
		inputCorrect = 1;
        treffer2();
        break;
	}
    }
    }
}

void treffer1()
{
    switch(SpielfeldSpieler2[koordinaten[0]][koordinaten[1]]){
        case 0: SpielfeldSpieler2[koordinaten[0]][koordinaten[1]] = 3; printf("\nDu hast nichts getroffen\n"); break;
        case 1: SpielfeldSpieler2[koordinaten[0]][koordinaten[1]] = 2; printf("\nDu hast getroffen!\n");SpielerPunkte1 += 100; break;
        case 2: printf("\nDas Boot ist bereits getroffen\n"); Schuss(); break;
        case 3: printf("\nHier hast du schonmal hingeschossen, hier ist nichts\n"); Schuss(); break;
    }
}

void treffer2(){ //Gegenspieler/ DITBot
    switch(SpielfeldSpieler1[koordinaten[0]][koordinaten[1]]){
        case 0: SpielfeldSpieler1[koordinaten[0]][koordinaten[1]] = 3; printf("\nDu hast nichts getroffen\n"); break;
        case 1: SpielfeldSpieler1[koordinaten[0]][koordinaten[1]] = 2; printf("\nDu hast getroffen!\n");SpielerPunkte2 += 100; break;
        case 2: printf("\nDas Boot ist bereits getroffen\n"); Schuss(); break;
        case 3: printf("\nHier hast du schonmal hingeschossen, hier ist nichts\n"); Schuss(); break;
        default:  if(Spielmodus==2){Schuss();}if(Spielmodus==1){Attack();} break;
    }
}

void trefferbot(){
	 switch(SpielfeldSpieler1[koordinaten[0]][koordinaten[1]]){
        case 0: SpielfeldSpieler1[koordinaten[0]][koordinaten[1]] = 3;printf("\n%s hast nicht getroffen%d\n",Bot,HitValue);HitValue=0;break;
        case 1: SpielfeldSpieler1[koordinaten[0]][koordinaten[1]] = 2;printf("\n%s hast getroffen!%d\n",Bot,HitValue);SpielerPunkte2 += 100 ; break;
        case 2: printf("\n Scannt Treffer... \n");randomness++;if(HitValue< 0){HitValue = 0;}else{HitValue-=1;};Attack(); break; 
        case 3: printf("\n Scannt Fehler... \n");randomness++;if(HitValue< 0){HitValue = 0;}else{HitValue-=1;};Attack();break;
        default: HitValue=0; break;
	}
	}

void placeShip1(){
	while(1){
		
		char Startkoordinate[3];
		char Endkoordinate[3];
		int Speicher = 0;
		int y = 0;
		while(1){
		printf("\nBitte Startkoordinate angeben:");
		scanf(" %s", Startkoordinate);
		printf("Bitte Endkoordinat angeben:");
		scanf(" %s", Endkoordinate);
		Startkoordinate[0] =Startkoordinate[0] - 48;
		Endkoordinate[0] =Endkoordinate[0] - 48;
		Startkoordinate[1] = Startkoordinate[1]-65;
		Endkoordinate[1] =Endkoordinate[1]- 65;

		if (Startkoordinate[0]>SIZE || Startkoordinate[0]<0 || Startkoordinate[1]>SIZE || Startkoordinate[1]<0 ||Endkoordinate[0]>SIZE || Endkoordinate[0]<0 || Endkoordinate[1]>SIZE || Endkoordinate[1]<0 )
		{
			printf("\nBitte gueltige Werte eingeben");
		}else {break;}
}
		if((Startkoordinate[0] != Endkoordinate[0]) && (Startkoordinate[1] == Endkoordinate[1])){
		
			Speicher = Startkoordinate[0] - Endkoordinate[0];  //4 - 6 = -2  3-0 = 3
			if (Speicher>0){Speicher=Speicher*(-1); y=1;}
			if ((Speicher*(-1)+1)<2){printf("\nBoote kleiner als 2 Felder gibt es nicht!\n");break;}
            		if ((Speicher*(-1)+1)>5){printf("\nBoote mit mehr als 5 Felder gibt es nicht!\n");break;}
            		switch((Speicher*(-1)+1)){
                case 5: if (BooteP1.Schlachtschiff == 0){printf("\nDu hast kein Schlachtschiff mehr frei!\n");x=1;break;}
                case 4: if (BooteP1.Kreuzer == 0){printf("\nDu hast keine Kreuzer mehr frei\n!");x=1;break;}
                case 3: if (BooteP1.Zerstoerer == 0){printf("\nDu hast keine Zerstoerer mehr frei!\n");x=1;break;}
                case 2: if (BooteP1.UBoot == 0){printf("\nDu hast keine U-Boote mehr frei!\n");x=1;break;}
			}
			if(x == 1){x = 0 ;placeShip1();break ;}
            		switch((Speicher*(-1)+1)){
                		case 5: BooteP1.Schlachtschiff --;x = 0 ;break;
                		case 4: BooteP1.Kreuzer --;break;
                		case 3: BooteP1.Zerstoerer --;break;
                		case 2: BooteP1.UBoot --;break;
                		default: break;
            		}
            if(Speicher<0 && y==1){Speicher=Speicher*(-1);y=0;}
			if(Speicher>0){ 
			
			//-------------------------------------Placement------------------------------------
					for(int i=0; i<=Speicher; i++ ){
						if(SpielfeldSpieler1[Startkoordinate[0]-i][Endkoordinate[1]] == 1){
						SpielfeldSpieler1[Startkoordinate[0]-i][Endkoordinate[1]] = 2; SpielerPunkte2+= 200;
						}else{ SpielfeldSpieler1[Startkoordinate[0]-i][Endkoordinate[1]] = 1;} // 3-i
					}
					break;
			}
			else{ 
				Speicher = Speicher * (-1); //3	
		//-------------------------------------Placement------------------------------------
				for(int i=0; i<=Speicher; i++ ){
					if(SpielfeldSpieler1[Endkoordinate[0]-i][Startkoordinate[1]] == 1){
						SpielfeldSpieler1[Endkoordinate[0]-i][Startkoordinate[1]] = 2;  SpielerPunkte2+= 200;// 3-i
					}else{SpielfeldSpieler1[Endkoordinate[0]-i][Startkoordinate[1]] = 1;}
				}
				break;
				}
		}
//-------------------------------------QUER----------------------------------------------------------------------------
		if((Startkoordinate[1] != Endkoordinate[1]) && (Startkoordinate[0] == Endkoordinate[0])) {
			Speicher = Startkoordinate[1] - Endkoordinate[1]; 
			if (Speicher>0){Speicher=Speicher*(-1); y=1;} // 1A-1C -> 0 - 2 = -2  | 1C - 1A = 2 - 0 = 2
			if ((Speicher*(-1)+1)<2){printf("\nBoote kleiner als 2 Felder gibt es nicht!\n");break;}
            		if ((Speicher*(-1)+1)>5){printf("\nBoote mit mehr als 5 Felder gibt es nicht!\n");break;}
            		switch((Speicher*(-1)+1)){
                case 5: if (BooteP1.Schlachtschiff == 0){printf("\nDu hast kein Schlachtschiff mehr frei!\n");x=1;break;}
                case 4: if (BooteP1.Kreuzer == 0){printf("\nDu hast keine Kreuzer mehr frei!\n");x=1;break;}
                case 3: if (BooteP1.Zerstoerer == 0){printf("\nDu hast keine Zerstoerer mehr frei!\n");x=1;break;}
                case 2: if (BooteP1.UBoot == 0){printf("\nDu hast keine U-Boote mehr frei!\n");x=1;break;}
			}if(x == 1){x = 0 ;placeShip1();break ;}
            		switch((Speicher*(-1)+1)){
                		case 5: BooteP1.Schlachtschiff --;break;
                		case 4: BooteP1.Kreuzer --;break;
                		case 3: BooteP1.Zerstoerer --;break;
                		case 2: BooteP1.UBoot --;break;
                		default: break;
            		}
            		if(Speicher<0 && y==1){Speicher=Speicher*(-1);y=0;}
			if(Speicher>0){
		//-------------------------------------Placement------------------------------------
				for(int i=0; i<=Speicher; i++ ){
					if(SpielfeldSpieler1[Startkoordinate[0]][Startkoordinate[1]-i] == 1){
						SpielfeldSpieler1[Startkoordinate[0]][Startkoordinate[1]-i] = 2; SpielerPunkte2+= 200;// 3-i
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
						SpielfeldSpieler1[Startkoordinate[0]][Endkoordinate[1]-i] = 2; SpielerPunkte2+= 200; // 3-i
				}else{SpielfeldSpieler1[Startkoordinate[0]][Endkoordinate[1]-i] = 1;}					
				
			}
			break;
		}
	}
		}else{system("cls");
			printf("Diagonalen sind nicht erlaubt!\n\n");
			x = 1;
		}
		
	
	if(x == 1){
		x = 0 ;
		system("cls");
		createGrid(1);
		placeShip1();
		system("cls");
		createGrid(1);
	}
}
}

void placeShip2(){
	while(1){
		
		char Startkoordinate[3];
		char Endkoordinate[3];
		int Speicher = 0;
		int y = 0;
		while(1){
		printf("Bitte Startkoordinate angeben:");
		scanf(" %s", Startkoordinate);
		printf("Bitte Endkoordinat angeben:");
		scanf(" %s", Endkoordinate);
		Startkoordinate[0] =Startkoordinate[0] - 48;
		Endkoordinate[0] =Endkoordinate[0] - 48;
		Startkoordinate[1] = Startkoordinate[1]-65;
		Endkoordinate[1] =Endkoordinate[1]- 65;

		if (Startkoordinate[0]>SIZE || Startkoordinate[0]<0 || Startkoordinate[1]>SIZE || Startkoordinate[1]<0 ||Endkoordinate[0]>SIZE || Endkoordinate[0]<0 || Endkoordinate[1]>SIZE || Endkoordinate[1]<0 )
		{
			printf("\nBitte gueltige Werte eingeben");
		}else{ break;}
}
		if((Startkoordinate[0] != Endkoordinate[0]) && (Startkoordinate[1] == Endkoordinate[1])){
		
			Speicher = Startkoordinate[0] - Endkoordinate[0];  //4 - 6 = -2  3-0 = 3
			if (Speicher>0){Speicher=Speicher*(-1); y=1;}
			if ((Speicher*(-1)+1)<2){printf("\nBoote kleiner als 2 Felder gibt es nicht!\n");break;}
            		if ((Speicher*(-1)+1)>5){printf("\nBoote mit mehr als 5 Felder gibt es nicht!\n");break;}
            		switch((Speicher*(-1)+1)){
                case 5: if (BooteP2.Schlachtschiff == 0){printf("\nDu hast kein Schlachtschiff mehr frei!\n");x=1;break;}
                case 4: if (BooteP2.Kreuzer == 0){printf("\nDu hast keine Kreuzer mehr frei!\n");x=1;break;}
                case 3: if (BooteP2.Zerstoerer == 0){printf("\nDu hast keine Zerstoerer mehr frei!\n");x=1;break;}
                case 2: if (BooteP2.UBoot == 0){printf("\nDu hast keine U-Boote mehr frei!\n");x=1;break;}
			}
			if(x == 1){x = 0 ;placeShip2();break ;}
            		switch((Speicher*(-1)+1)){
                		case 5: BooteP2.Schlachtschiff --;break;
                		case 4: BooteP2.Kreuzer --;break;
                		case 3: BooteP2.Zerstoerer --;break;
                		case 2: BooteP2.UBoot --;break;
                		default: break;
            		}
            if(Speicher<0 && y==1){Speicher=Speicher*(-1);y=0;}
			if(Speicher>0){ 
			
			//-------------------------------------Placement------------------------------------
					for(int i=0; i<=Speicher; i++ ){
						if(SpielfeldSpieler2[Startkoordinate[0]-i][Endkoordinate[1]] == 1){
						SpielfeldSpieler2[Startkoordinate[0]-i][Endkoordinate[1]] = 2; SpielerPunkte1+= 200;
						}else{ SpielfeldSpieler2[Startkoordinate[0]-i][Endkoordinate[1]] = 1;} // 3-i
					}
					break;
			}
			else{ 
				Speicher = Speicher * (-1); //3	
		//-------------------------------------Placement------------------------------------
				for(int i=0; i<=Speicher; i++ ){
					if(SpielfeldSpieler2[Endkoordinate[0]-i][Startkoordinate[1]] == 1){
						SpielfeldSpieler2[Endkoordinate[0]-i][Startkoordinate[1]] = 2;  SpielerPunkte1+= 200;// 3-i
					}else{SpielfeldSpieler2[Endkoordinate[0]-i][Startkoordinate[1]] = 1;}
				}
				break;
				}
		}
//-------------------------------------QUER----------------------------------------------------------------------------
		if((Startkoordinate[1] != Endkoordinate[1]) && (Startkoordinate[0] == Endkoordinate[0])) {
			Speicher = Startkoordinate[1] - Endkoordinate[1]; 
			if (Speicher>0){Speicher=Speicher*(-1); y=1;} // 1A-1C -> 0 - 2 = -2  | 1C - 1A = 2 - 0 = 2
			if ((Speicher*(-1)+1)<2){printf("\nBoote kleiner als 2 Felder gibt es nicht!\n");break;}
            		if ((Speicher*(-1)+1)>5){printf("\nBoote mit mehr als 5 Felder gibt es nicht!\n");break;}
            		switch((Speicher*(-1)+1)){
                case 5: if (BooteP2.Schlachtschiff == 0){printf("\nDu hast kein Schlachtschiff mehr frei!\n");x=1;break;}
                case 4: if (BooteP2.Kreuzer == 0){printf("\nDu hast keine Kreuzer mehr frei!\n");x=1;break;}
                case 3: if (BooteP2.Zerstoerer == 0){printf("\nDu hast keine Zerstoerer mehr frei!\n");x=1;break;}
                case 2: if (BooteP2.UBoot == 0){printf("\nDu hast keine U-Boote mehr frei!\n");x=1;break;}
			}if(x == 1){x = 0 ;placeShip2();break ;}
            		switch((Speicher*(-1)+1)){
                		case 5: BooteP2.Schlachtschiff --;break;
                		case 4: BooteP2.Kreuzer --;break;
                		case 3: BooteP2.Zerstoerer --;break;
                		case 2: BooteP2.UBoot --;break;
                		default: break;
            		}
            		if(Speicher<0 && y==1){Speicher=Speicher*(-1);y=0;}
			if(Speicher>0){
		//-------------------------------------Placement------------------------------------
				for(int i=0; i<=Speicher; i++ ){
					if(SpielfeldSpieler2[Startkoordinate[0]][Startkoordinate[1]-i] == 1){
						SpielfeldSpieler2[Startkoordinate[0]][Startkoordinate[1]-i] = 2; SpielerPunkte1+= 200;// 3-i
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
						SpielfeldSpieler2[Startkoordinate[0]][Endkoordinate[1]-i] = 2; SpielerPunkte1+= 200; // 3-i
				}else{SpielfeldSpieler2[Startkoordinate[0]][Endkoordinate[1]-i] = 1;}					
				
			}
			break;
		}
	}
		}else{system("cls");
			printf("Diagonalen sind nicht erlaubt!\n\n");
			x = 1;
		}
		
	
	if(x == 1){
		x = 0 ;
		system("cls");
		createGrid(2);
		placeShip2();
		system("cls");
		createGrid(2);
	}
}
}

void placeShipBOT(){
    char PlacePatternStart[3][11][3] = {{{"0A"},{"6A"},{"3C"},{"2H"},{"6G"},{"2A"},{"0J"},{"8J"},{"9E"},{"4I"}},
                                        {{"8F"},{"1I"},{"2B"},{"9H"},{"8C"},{"0D"},{"5H"},{"7J"},{"0A"},{"6A"}},
                                        {{"5G"},{"0D"},{"2I"},{"8F"},{"6I"},{"4J"},{"8A"},{"3A"},{"1A"},{"0H"}}};
    char PlacePatternEnde[3][11][3] = {{{"0E"},{"9A"},{"6C"},{"2F"},{"6E"},{"2B"},{"2J"},{"9J"},{"9F"},{"5I"}},
                                       {{"4F"},{"1F"},{"5B"},{"9F"},{"6C"},{"2D"},{"5I"},{"8J"},{"0B"},{"7A"}},
                                       {{"5C"},{"3D"},{"2F"},{"8D"},{"8I"},{"4H"},{"8B"},{"4A"},{"1B"},{"0I"}}};
    int y = 0 ;
    int Samen;
    srand((unsigned) time (&t1));
    Samen =(rand() % 3);
    for(int j = 0 ; j <= 9 ; j++){
	while(1){
		char Startkoordinate[3];
		char Endkoordinate[3];
		int Speicher = 0;
        Startkoordinate[0]=PlacePatternStart[Samen][j][0];
        Startkoordinate[1]=PlacePatternStart[Samen][j][1];
        Endkoordinate[0]=PlacePatternEnde[Samen][j][0];
        Endkoordinate[1]=PlacePatternEnde[Samen][j][1];
		Startkoordinate[0] =Startkoordinate[0] - 48;
		Endkoordinate[0] =Endkoordinate[0] - 48;
		Startkoordinate[1] = Startkoordinate[1]-65;
		Endkoordinate[1] =Endkoordinate[1]- 65;


		if (Startkoordinate[0]>SIZE || Startkoordinate[0]<0 || Startkoordinate[1]>SIZE || Startkoordinate[1]<0 ||Endkoordinate[0]>SIZE || Endkoordinate[0]<0 || Endkoordinate[1]>SIZE || Endkoordinate[1]<0 )
		{
			printf("\nBitte gueltige Werte eingeben");
						placeShipBOT();
		}

		if((Startkoordinate[0] != Endkoordinate[0]) && (Startkoordinate[1] == Endkoordinate[1])){
		
			Speicher = Startkoordinate[0] - Endkoordinate[0];  //4 - 6 = -2  3-0 = 3
			if (Speicher>0){Speicher=Speicher*(-1); y=1;}
			if ((Speicher*(-1)+1)<2){printf("\nBoote kleiner als 2 Felder gibt es nicht!\n");break;}
            		if ((Speicher*(-1)+1)>5){printf("\nBoote mit mehr als 5 Felder gibt es nicht!\n");break;}
            		switch((Speicher*(-1)+1)){
                case 5: if (BooteP2.Schlachtschiff == 0){printf("\nDu hast kein Schlachtschiff mehr frei!\n");x=1;break;}
                case 4: if (BooteP2.Kreuzer == 0){printf("\nDu hast keine Kreuzer mehr frei!\n");x=1;break;}
                case 3: if (BooteP2.Zerstoerer == 0){printf("\nDu hast keine Zerstoerer mehr frei!\n");x=1;break;}
                case 2: if (BooteP2.UBoot == 0){printf("\nDu hast keine U-Boote mehr frei!\n");x=1;break;}
			}
			if(x == 1){x = 0 ;placeShipBOT();break ;}
            		switch((Speicher*(-1)+1)){
                		case 5: BooteP2.Schlachtschiff --;break;
                		case 4: BooteP2.Kreuzer --;break;
                		case 3: BooteP2.Zerstoerer --;break;
                		case 2: BooteP2.UBoot --;break;
                		default: break;
            		}
            if(Speicher<0 && y==1){Speicher=Speicher*(-1);y=0;}
			if(Speicher>0){ 
			
			//-------------------------------------Placement------------------------------------
					for(int i=0; i<=Speicher; i++ ){
						if(SpielfeldSpieler2[Startkoordinate[0]-i][Endkoordinate[1]] == 1){
						SpielfeldSpieler2[Startkoordinate[0]-i][Endkoordinate[1]] = 2; SpielerPunkte1+= 200;
						}else{ SpielfeldSpieler2[Startkoordinate[0]-i][Endkoordinate[1]] = 1;} // 3-i
					}
					break;
			}
			else{ 
				Speicher = Speicher * (-1); //3	
		//-------------------------------------Placement------------------------------------
				for(int i=0; i<=Speicher; i++ ){
					if(SpielfeldSpieler2[Endkoordinate[0]-i][Startkoordinate[1]] == 1){
						SpielfeldSpieler2[Endkoordinate[0]-i][Startkoordinate[1]] = 2;  SpielerPunkte1+= 200;// 3-i
					}else{SpielfeldSpieler2[Endkoordinate[0]-i][Startkoordinate[1]] = 1;}
				}
				break;
				}
		}
//-------------------------------------QUER----------------------------------------------------------------------------
		if((Startkoordinate[1] != Endkoordinate[1]) && (Startkoordinate[0] == Endkoordinate[0])) {
			Speicher = Startkoordinate[1] - Endkoordinate[1]; 
			if (Speicher>0){Speicher=Speicher*(-1); y=1;} // 1A-1C -> 0 - 2 = -2  | 1C - 1A = 2 - 0 = 2
			if ((Speicher*(-1)+1)<2){printf("\nBoote kleiner als 2 Felder gibt es nicht!\n");break;}
            		if ((Speicher*(-1)+1)>5){printf("\nBoote mit mehr als 5 Felder gibt es nicht!\n");break;}
            		switch((Speicher*(-1)+1)){
                case 5: if (BooteP2.Schlachtschiff == 0){printf("\nDu hast kein Schlachtschiff mehr frei!\n");x=1;break;}
                case 4: if (BooteP2.Kreuzer == 0){printf("\nDu hast keine Kreuzer mehr frei!\n");x=1;break;}
                case 3: if (BooteP2.Zerstoerer == 0){printf("\nDu hast keine Zerstoerer mehr frei!\n");x=1;break;}
                case 2: if (BooteP2.UBoot == 0){printf("\nDu hast keine U-Boote mehr frei!\n");x=1;break;}
			}if(x == 1){x = 0 ;placeShipBOT();break ;}
            		switch((Speicher*(-1)+1)){
                		case 5: BooteP2.Schlachtschiff --;break;
                		case 4: BooteP2.Kreuzer --;break;
                		case 3: BooteP2.Zerstoerer --;break;
                		case 2: BooteP2.UBoot --;break;
                		default: break;
            		}
            		if(Speicher<0 && y==1){Speicher=Speicher*(-1);y=0;}
			if(Speicher>0){
		//-------------------------------------Placement------------------------------------
				for(int i=0; i<=Speicher; i++ ){
					if(SpielfeldSpieler2[Startkoordinate[0]][Startkoordinate[1]-i] == 1){
						SpielfeldSpieler2[Startkoordinate[0]][Startkoordinate[1]-i] = 2; SpielerPunkte1+= 200;// 3-i
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
						SpielfeldSpieler2[Startkoordinate[0]][Endkoordinate[1]-i] = 2; SpielerPunkte1+= 200; // 3-i
				}else{SpielfeldSpieler2[Startkoordinate[0]][Endkoordinate[1]-i] = 1;}					
				
			}
			break;
		}
	}
		}else{system("cls");
			printf("Diagonalen sind nicht erlaubt!\n\n");
			x = 1;
		}
		
	
	if(x == 1){
		x = 0 ;
		system("cls");
		placeShipBOT();
		system("cls");

	}
}
}
}

void Attack(){
	//Standard Action --- If its Searching
	srand(time(NULL));
	KWW =(rand() % 10); 
	srand(randomness);
	for(int rounds = 0 ; rounds <= 50; rounds++){
	RandomNumbers[rounds] = rand()%10;
 }
	KWS = RandomNumbers[randomness];
	for(int b = 0 ; b<3 ;b++){
	botMemory[b+1][0]=botMemory[b][0];
	botMemory[b+1][1]=botMemory[b][1];
}
	botMemory[0][0]= KWW; //Memory
	botMemory[0][1]= KWS;
	
	Action[0] = botMemory[3][0] ; //Aktion
	Action[1] = botMemory[3][1] ; 


switch(HitValue){
	case 1:
		KWW = botMemory[3][0] - 1;
		if(KWW >9){ KWW = botMemory[3][0];} 
		Action[1] = botMemory[3][1] ;
		Action[0] = KWW;
		break;
	case 2:KWW = botMemory[3][0] + 1;
		if(KWW >9){ KWW = botMemory[3][0];} 
		Action[1] = botMemory[3][1] ;
		Action[0] = KWW;
		break;	
	case 3:
		KWS = botMemory[3][1] + 1 ;
		if(KWS >9) { KWS = botMemory[3][1];}
		Action[1] = KWS;
		Action[0] = botMemory[3][0] ;
		break;
	
	case 4:
		KWS = botMemory[3][1] - 1 ;
		if(KWS >9) { KWS = botMemory[3][1];}
		Action[1] = KWS;
		Action[0] = botMemory[3][0] ;
		break;
	default: HitValue = 0 ; break;
	 } 	
	 
	 
	 
 randomness++ ;
 if(randomness >100){randomness = 0 ;}
 HitValue++;
 saveloop++;
 if(saveloop > 4){HitValue = 0; saveloop=0;}
 BotSchuss();
}

void BotSchuss(){
 if (Fokus == 2){
        BFeldkoordinate();
        trefferbot();
    }
	}

void BFeldkoordinate(){
	koordinaten[0] = Action[0] ;
	koordinaten[1] = Action[1] ;
	}
