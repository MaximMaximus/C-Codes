#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANDOM_NUMBERS 200
#define MAX_RANDOM 50

int main() {
	srand( time(NULL) );

	// Array mit Zufallszahlen füllen
	int zahlen[RANDOM_NUMBERS];

	int i = 0;
	for ( i = 1; i <= RANDOM_NUMBERS; i++ ) {
		zahlen[i] = rand() % MAX_RANDOM; // rand() % 100 + 1 bereich von 1 bis 100
		//printf("zahl[%d]: %d\n", i, zahlen[i]);
	}

	// den min und max Wert ermitteln
	int kleinsteZahl = MAX_RANDOM+1;
	int kleinsteZahlPosition = 0;
	int groesteZahl = -1;
	int groesteZahlPosition = 0;

	for ( i = 1; i <= RANDOM_NUMBERS; i++ ) {
		printf("zahl[%d]: %d\n", i, zahlen[i]);
	
		if ( zahlen[i] < kleinsteZahl ) {
			kleinsteZahl = zahlen[i];
			kleinsteZahlPosition = i;
		}

		if ( zahlen[i] > groesteZahl ) {
			groesteZahl = zahlen [i];
			groesteZahlPosition = i;
		}
	}
	printf("Kleinste Zahl: %d\tPosition: %d\n" , kleinsteZahl, kleinsteZahlPosition);
	printf("Groeste Zahl: %d\tPosition: %d\n" , groesteZahl, groesteZahlPosition);

	// den Mittelwert ermitteln
	int summe = 0;
	for ( i = 0; i <= RANDOM_NUMBERS; i++ ) {
		summe += zahlen[i];
	}
	printf("Summe: %d\n", summe);
	printf("Mittelwert: %d", summe/RANDOM_NUMBERS);


	return 0;
}
