#include <stdio.h>

int main() {
	int i = 0;
	int j = 0;
	int hoehe = 0;
	int breite = 0;
		
	printf("Hoehe und Breite eingeben: \n");
	scanf(" %d %d", &hoehe, &breite);
	
	for(i = 0; i < hoehe; i++) {
		for(j = 0; j < breite; j++) {
			if(i == 0 || i == hoehe - 1) printf("* ");
			if(i != 0 && i != hoehe - 1) {
				if(j == 0) printf("*");
				else if(j == breite - 1) printf(" *");
				else printf("  ");
			}
		}
		printf("\n");
	}
	
	return 0;
}
