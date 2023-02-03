#include <stdlib.h>
#include <stdio.h>
char Spieler1[50], Spieler2[50];

void Beginning();
void feldkoordinate();

int main(int argc, char **argv)
{
 Beginning();
 feldkoordinate();
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
