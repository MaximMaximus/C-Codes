#include <stdio.h>

int squirrel_party(short stueck, char tag) {

	short fun = 0;

	switch(tag) {
		case 'm':
		case 'd':
		case 'M':
		case 'D':
		case 'f':
			if (stueck <= 40 || stueck >= 60 ) {
				fun = 0;
			} else {
				fun = 1;
			}
			break;
		case 's':
		case 'S':
			if ( stueck >= 40 ) {
				fun = 1;
			} else {
				fun = 0;
			}
			break;
		default : 
			break;
	}
	
	return fun;
}

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