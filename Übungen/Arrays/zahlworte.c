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

void zahlworte(int zahl, char *array) {
	int STELLEN = zahllaenge(zahl);
	int zahlenArray[STELLEN];

	strcpy(array, ""); // Array Inhalt löschen

	if ( zahl < 0 ) {
		strcat(array, "minus ");
		zahl *= -1;
	}

	int i = 0;
	for(i = STELLEN-1; i >= 0; i--) {
		zahlenArray[i] = zahl%10;
		zahl = zahl/10;
		//printf("zahlenArray[%d]: %d\n", i, zahlenArray[i]);
	}

	int j = 0;
	for(j = 0; j < STELLEN; j++) {
		switch(zahlenArray[j]) {
			case 0:
				strcat(array, "null ");
				break;
			case 1:
				strcat(array, "eins ");
				break;
			case 2:
				strcat(array, "zwei ");
				break;
			case 3:
				strcat(array, "drei ");
				break;
			case 4:
				strcat(array, "vier ");
				break;
			case 5:
				strcat(array, "fünf ");
				break;
			case 6:
				strcat(array, "sechs ");
				break;
			case 7:
				strcat(array, "sieben ");
				break;
			case 8:
				strcat(array, "acht ");
				break;
			case 9:
				strcat(array, "neun ");
				break;
		}
	}
	array[strlen(array)-1] = '\0'; // Letzte Leerstelle löschen und Null anhängen
}

int main() {
	char feld[100];
	int test = -12;
	zahlworte(test, feld);
	printf("|%s|", feld);

	return 0;
}
