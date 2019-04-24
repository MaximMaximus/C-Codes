#include <stdio.h>
#include "party.h"

int main() {

	short gerauchteZigarretten = 0;

	char wochentag;

	printf("Wie viele Zigaretten wurden auf der Party geraucht: ");
	fflush(stdin);
	scanf("%d", &gerauchteZigarretten);

	printf("m = Montag\nd = Dienstag\nM = Mittwoch\nD = Donnerstag\nf = Freitag\ns = Samstag\nS = Sonnntag\n");
	printf("Am welchen Tag war die Party: ");
	fflush(stdin);
	scanf(" %c", &wochentag);

	//printf("%d\n", squirrel_party(gerauchteZigarretten, wochentag));

	if (squirrel_party(gerauchteZigarretten, wochentag)) {
		printf("Die Party war ein Erfolg!\n");
	} else {
		printf("Die Party war ok.\n");
	}

	return 0;
}