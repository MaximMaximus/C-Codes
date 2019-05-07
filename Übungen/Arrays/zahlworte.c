#include <stdio.h>
#include <string.h>

int zahllaenge(int zahl) {
	int laenge = 0;
	int i = 0;
	if ( zahl < 0 ) {
		zahl *= -1;
	}
	for (i = 1; i <= zahl; i*=10) {
		laenge++;
	}
	return laenge;
}

int wortlaenge(char *wort) {
	int i = 0;
	for (i = 0; wort[i] != '\0'; i++) {
	}
	return i;
}

void stringCat(char *ziel, char *ursprung) {
	int laengeStart = wortlaenge(ziel);
	int laengeUrsprung = wortlaenge(ursprung);
	int i = 0;
	int j = 0;
	for (i = laengeStart, j = 0; ursprung[j] != '\0'; i++, j++) {
		ziel[i] = ursprung[j];
	}
	ziel[i] = '\0';
}

void zahlworte(int zahl, char *array) {
	int x = 0;
	for(x = 0; array[x] != '\0'; x++) {
		array[x] = 0;
	}
	int stellen = zahllaenge(zahl);
	int zahlenArray[stellen];

	char minus[] = "minus ";
	if ( zahl < 0 ) {
		stringCat(array, minus);
		zahl *= -1;
	}

	int i = 0;
	for ( i = stellen - 1; i >= 0; i--) {
		zahlenArray[i] = zahl % 10;
		zahl = zahl / 10;
		printf("zahlenArray[%d]: %d\n", i, zahlenArray[i]);
	}

	int j = 0;
	for(j = 0; j < stellen; j++) {
		switch(zahlenArray[j]) {
			case 0:
				stringCat(array, "null ");
				break;
			case 1:
				stringCat(array, "eins ");
				break;
			case 2:
				stringCat(array, "zwei ");
				break;
			case 3:
				stringCat(array, "drei ");
				break;
			case 4:
				stringCat(array, "vier ");
				break;
			case 5:
				stringCat(array, "fünf ");
				break;
			case 6:
				stringCat(array, "sechs ");
				break;
			case 7:
				stringCat(array, "sieben ");
				break;
			case 8:
				stringCat(array, "acht ");
				break;
			case 9:
				stringCat(array, "neun ");
				break;
		}
	}
	array[wortlaenge(array)-1] = '\0';
}

int main() {
	/*
	char wort1[100] = "erstesWort";
	char wort2[100] = "zweitesWort";
	stringCat(wort1, wort2);
	printf("%s", wort1);
	*/
	char feld[100];
	int test = -12;
	zahlworte(test, feld);
	printf("|%s|", feld);

	return 0;
}
