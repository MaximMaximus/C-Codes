#include <stdio.h>

int main() {

	int n = 0;
	int i = 0;
	int summe = 0;

	printf("Aufsummierungsfunktion\n");
	printf("Summe zwischen 1 und allen Zahlen bis n.");
	printf("Bitte geben Sie einen Wert für n ein: \n");
	printf("n: ");
	scanf("%i", &n);

	
	// Schleife
	for ( i = 1; i <= n; i++ )
	{
		summe = summe + i;
		printf("Zwischensumme: %i \n", summe );
	}
	

	// Gaus 
	printf("Summe: %i\n", (n*(n+1))/2);

	return 0;
}
