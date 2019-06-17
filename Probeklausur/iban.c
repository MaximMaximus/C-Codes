#include <stdio.h>

void stringcat(char *ziel, char *sender) {
	int i = 0;
	int ziellaenge = stringlenght(ziel);

	for(i = 0; sender[i] != '\0'; i++, ziellaenge++) {
		ziel[ziellaenge] = sender[i];
	}
	ziel[i+ziellaenge] = '\0';
}

int stringlenght(char *str) {
	int i = 0;
	while(str[i] != '\0') {
		i++;
	}
	return i;
}

void generiere_iban(char alt[], char neu[]) {

	char *de = "DE";
	char *x = "X";
	char *null = "0";

	int i = 0;
	int altlenght = stringlenght(alt);
	int nullDifferenz = 0;

	// Neu leeren
	for(i = 0; neu[i] != '\0'; i++) {
		neu[i] = 0;
	}

	// Länderkennung
	stringcat(neu, de);

	// Prüfziffer berechnen
	int summe = 0;
	for ( i = 0; alt[i] != '\0'; i++ ) {
		summe = summe + alt[i] - '0';
	}
	summe = summe % 11;
	if ( summe < 10 ) neu[2] = summe + '0';
	else stringcat(neu, x);

	// Kontonummer auf Stellen Prüfen
	if ( altlenght < 10 ) {
		nullDifferenz = 10 - altlenght;
		for ( i = 0; i < nullDifferenz; i++) {
			stringcat(neu, null);
		}
		stringcat(neu, alt);
	} else if ( altlenght == 10 ) {
		stringcat(neu, alt);
	}
}

int main(void) {
	system("CLS");

	char iban[14];
	char alte_ktonr[] = "67892";

	printf("Alt : %s\n", alte_ktonr);

	generiere_iban(alte_ktonr, iban); 

	printf("IBAN: %s\n", iban); // DEX0000067892
	return 0;
}