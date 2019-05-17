#include <stdio.h>

int wortlaenge(char *wort) {
	int i = 0;
	for (i = 0; wort[i] != '\0'; i++) {

	}
	return i;
}
void stringCat( char *ziel, char *sender) {
	int laengeStart = wortlaenge(ziel);
	int i = 0;
	int j = 0;
	for ( i = laengeStart, j = 0; sender[j] != '\0'; i++, j++) {
		ziel[i] = sender[j];
	}
	ziel[i] = '\0';
}
void stringCopy( char *ziel, char *sender ) {
	int i = 0;
	for ( i = 0; sender[i] != NULL; i++ ) {
		ziel[i] = sender[i];
	}
}

int main(int argc, char *argv[]) {
	char alphabetGross[26][1]; // Array für Großbuchstaben
	char alphabetKlein[26][1]; // Array für Kleinbuchstaben
	int buchstabenZaehler[26];
	int c = 0; // Buchstabenposition im Alphabet
	int b = 65; // ASCII Position Großbuchstaben
	int s = 97; // ASCII Position Kleinbuchstaben

	// Alphabet Array füllen
	for ( c = 0; c < 26; c++, b++, s++) {
		alphabetGross[c][0] = b;
		alphabetKlein[c][0] = s;
		buchstabenZaehler[c] = 0;
		//printf("alphabetGross[%d]: %c\n", c, alphabetGross[c][0] );
		//printf("alphabetKlein[%d]: %c\n", c, alphabetKlein[c][0] );
	}

	// ARGV ausgeben
	int i = 0;
	int j = 0;
	for ( i = 0; i < argc; i++ ) {
		//printf(" %d: %s\n", i, argv[i]);
	}
	fflush(stdin);

	// ARGV Strings in ein Array kopieren und Buchstaben zählen
	char test[500]; // Speicher Array für ARGV Inhalt
	stringCopy(test, ""); // Array Inhalt löschen
	if ( argc >= 2 ) {
		for ( i = 1; argv[i] != NULL; i++ ) {
			stringCat(test, argv[i]);
			stringCat(test, " ");
			//printf("i: %d\n", i);
		}
		printf("Test: %s\n", test);
		for ( i = 0; test[i] != '\0'; i++ ) {
			for ( j = 0; j < 26; j++ ) {
				if ( test[i] == alphabetGross[j][0] || test[i] == alphabetKlein[j][0] ) {
					buchstabenZaehler[j]++;
				}
			}
		}
	}
	// Buchstaben und Anzahl ausgeben
	for ( c = 0; c < 26; c++ ) {
		if ( buchstabenZaehler[c] > 0 ) {
			printf("%c:%d\n", alphabetGross[c][0], buchstabenZaehler[c] );
		}
	}

	return 0;
}
