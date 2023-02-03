#include <stdlib.h>
#include <stdio.h>
char Spieler1[50], Spieler2[50];

void Beginning();
int main(int argc, char **argv)
{
	
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