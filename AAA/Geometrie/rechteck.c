#include <stdio.h>

int main() {
	int y = 0;
	int x = 0;
	
	int hoehe = 10;
	int breite = 10;

	printf("Hoehe und Breite eingeben: \n");
	fflush(stdin);
	scanf(" %d %d", &hoehe, &breite);

	if(hoehe == breite) printf("Quadrat\n");
	else printf("Rechteck\n");

	for(y = 0; y < hoehe; y++) {
		for(x = 0; x < breite; x++) {
			printf("* ");
		}
		printf("\n");
	}


	return 0;
}
