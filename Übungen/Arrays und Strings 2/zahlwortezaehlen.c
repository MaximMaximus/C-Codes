#include <stdio.h>

#define MAX_LAENGE 100

void wort_eingabe(char *wort) {
	fgets(wort, MAX_LAENGE, stdin);
	int i = 0;
	// Newline am Ende vom String löschen
	for ( i = 0; wort[i] != '\0'; i++ ) {
	}
	wort[i-1] = '\0';

	// Kleinbuchstaben
	for ( i = 0; wort[i] != '\0'; i++ ) {
		if ( wort[i] >= 'A' && wort[i] <= 'Z' ) {
			wort[i] += 'a' - 'A';
		}
	}
}

// suchbegriff ist ein zweidimensionaler Array mit Zahlenworten
// k ist die Zahl nach der gesucht werden soll
int compare(char *wort, char *suchbegriff[], int k) {
	int i = 0;
	int j = 0;
	int gefunden = 0;
	int anzahl = 0;

	while( wort[i] != '\0' ) {
		j = 0;
		gefunden = 1;


		while( suchbegriff[k][j] != '\0' ) {
			//printf("i: %c j: %c\n", wort[j+i], suchbegriff[k][j]);
			//printf("%d\n", j);
			if ( suchbegriff[k][j] != wort[j+i] ) {
				gefunden = 0;
				break;
			}
			j++;
		}
		//printf("\n");
		if ( gefunden ) {
			anzahl++;
			i = i+j;
		} else {
			i++;
		}
	}
	//printf("gefunden %d\n", gefunden);
	//printf("anzahl: %d\n", anzahl);
	return anzahl;
}

void zahlworte_zaehlen() {
	char eingabe[MAX_LAENGE];
	int i = 0;
	int k = 0;
	int eingabe_on = 1;

	char *zahlen[] = {
		"null",
		"eins",
		"zwei",
		"drei",
		"vier",
		"f\201nf",
		"sechs",
		"sieben",
		"acht",
		"neun",
		"zehn",
		"elf",
		};
	
	int werte[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };

	int summe = 0;
	int gesamtsumme = 0;

	while ( eingabe_on ) {
		printf("Bitte geben Sie ein Wort ein: \n");
		wort_eingabe(eingabe);
		//printf("%d\n", sizeof(eingabe));
		//printf("%s\n", eingabe);
		//printf("eingabe on %d\n", eingabe_on);
		gesamtsumme = summe;

		for( k = 0; k <= 11; k++ ) {
			//printf("k %d compare %d\n", k, compare(eingabe, zahlen,k) );
			if ( compare(eingabe, zahlen, k ) > 0 ) {
				//printf("Zahl: %d, %d x mal\n", werte[k], compare(eingabe, zahlen, k));
				summe += (werte[k] * compare(eingabe, zahlen, k));
				if ( k < 11 ) {
					continue;
				} else if (k == 11) {
					break;
				}
			}
		}
		if ( gesamtsumme == summe ) {
			printf("Die Gesamtsumme der Zahlworte ist: %d\n", summe);
			eingabe_on = 0;
			break;
		}
	}
}

int main() {
	// äÄ öÖ üÜ ß
	//printf("Umlaute oktal : \204\216 \224\231 \201\232 \341\n");
	zahlworte_zaehlen();
	printf("Ende\n");
	
	return 0;
}
