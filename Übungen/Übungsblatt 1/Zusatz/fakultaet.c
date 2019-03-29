#include <stdio.h>

int fakultaet(int wert) {
	if ( wert < 1 ) {
		return 1;
	} else {
		return wert * fakultaet(wert -1);
	}
}

int main() {

	int n = 0;
	int summe = 1;

	printf("Fakultaet berechnen.\n");
	printf("Geben Sie bitte die zu berechende Zahl ein: ");
	scanf("%i", &n);

	printf("Rekursive berechnung: \n");
	printf("Summe: %i\n\n", fakultaet(n));

	printf("Berechnung mit einer While-Schleife: \n");
	while ( n > 1 ) {
		summe = summe * n--;
		printf("%i * %i = %i\n", summe, n, summe*n );
		printf("Zwischensumme: %i\n", summe*n);
	}	

	return 0;
}
